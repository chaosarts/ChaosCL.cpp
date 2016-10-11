//
//  env.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 26.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "env.hpp"
#include "platform.hpp"
#include "device.hpp"
#include "program.hpp"
#include "kernel.hpp"
#include <algorithm>
#include <ChaosCore/map_func.hpp>

namespace cl
{
	env::env () : m_initialized(false), m_initErrcode(CL_SUCCESS),
		m_platform(NULL), m_context(NULL)
	{
		
	}
	
	
	env::~env ()
	{
		std::vector<cl_kernel>::iterator kernel_it = m_kernels.begin();
		while (kernel_it != m_kernels.end())
		{
			clSafeReleaseKernel(*kernel_it);
			kernel_it++;
		}
		
		std::vector<cl_program>::iterator program_it = m_programs.begin();
		while (program_it != m_programs.end())
		{
			clSafeReleaseProgram(*program_it);
			program_it++;
		}
		
		clSafeReleaseContext(m_context);
	}
	
	
	cl_int env::init ()
	{
		if (!m_initialized)
		{
			m_initialized = true;
			
			clReturnErrcodeOnError(cl::platform(platformIndex(), m_platform), "Failed to get platform.");
			
			cl_uint numDevices;
			m_initErrcode = clGetDeviceIDs(m_platform, deviceType(), 0, NULL, &numDevices);
			clReturnErrcodeOnError(m_initErrcode, "Failed to get device ids.");
			
			cl_device_id* devices = (cl_device_id*) malloc(sizeof(cl_device_id) * numDevices);
			clGetDeviceIDs(m_platform, deviceType(), numDevices, devices, NULL);
			
			m_devices = std::vector<cl_device_id>(devices, devices + numDevices);
			
			m_context = clCreateContext(NULL, numDevices, m_devices.data(), NULL, NULL, &m_initErrcode);
			clReturnErrcodeOnError(m_initErrcode, "Failed to create context.");
			
			std::vector<cl_program> programs = initPrograms(m_initErrcode);
			clReturnErrcodeOnError(m_initErrcode, "Failed to initialize program");
			
			for (cl_uint i = 0; i < programs.size(); i++)
			{
				clContinueOnError(clBuildProgram(programs[i], numDevices, m_devices.data(), nullptr, nullptr, nullptr), "Failed to build program");
				m_programs.push_back(programs[i]);
			}
			
			m_kernels = initKernels (m_initErrcode);
			clReturnErrcodeOnError(m_initErrcode, "Failed to initialize kernels");
			
			for (cl_uint i = 0; i < m_kernels.size(); i++)
			{
				const char* kernelName = name(m_kernels[i]);
				m_kernelNameIndexMap[kernelName] = i;
			}
			
#ifdef DEBUG
			fprintf(stdout, "# Platform information\n");
			printInfo(m_platform);
			
			fprintf(stdout, "\n");
			for (cl_uint i = 0; i < numDevices; i++)
			{
				fprintf(stdout, "## Device information (#%i)\n", i);
				printInfo(m_devices[i]);
				fprintf(stdout, "\n");
			}
#endif
		}
		
		return m_initErrcode;
	}
	
	
	cl_uint env::platformIndex () const
	{
		return 0;
	}
	
	
	const cl_platform_id env::platform () const
	{
		return m_platform;
	}
	
	
	cl_device_type env::deviceType() const
	{
		return CL_DEVICE_TYPE_ALL;
	}
	
	
	std::vector<cl_device_id> env::devices() const
	{
		return m_devices;
	}
	
	
	const cl_context env::context () const
	{
		return m_context;
	}
	
	
	std::vector<cl_program> env::programs() const
	{
		return m_programs;
	}
	
	
	std::vector<cl_kernel> env::kernels () const
	{
		return m_kernels;
	}
	
	
	std::vector<const char*> env::kernelNames () const
	{
		const char** keys = chaos::map_keys<const char*, cl_uint>(m_kernelNameIndexMap);
		return std::vector<const char*>(keys, keys + m_kernels.size());
	}
	
	
	const cl_kernel env::kernel (const char* name) const
	{
		std::map<const char*, cl_uint>::const_iterator it = m_kernelNameIndexMap.find(name);
		if (it == m_kernelNameIndexMap.end()) return nullptr;
		return m_kernels[it->second];
	}
	
	
	cl_int env::prepareOpenCL ()
	{
		return CL_SUCCESS;
	}
}