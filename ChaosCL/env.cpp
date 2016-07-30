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
#include <algorithm>

namespace cl
{
	env::env () : m_initialized(false), m_initErrcode(CL_SUCCESS),
		m_numDevices(0), m_platform(NULL), m_devices(NULL), m_context(NULL)
	{
		
	}
	
	
	env::~env ()
	{
		if (m_devices != nullptr) free(m_devices);
		clSafeReleaseContext(m_context);
	}
	
	
	cl_int env::init ()
	{
		if (!m_initialized)
		{
			m_initialized = true;
			
			clReturnErrcodeOnError(platform(platformIndex(), m_platform), "Failed to get platform.");
			
			m_initErrcode = clGetDeviceIDs(m_platform, deviceType(), 0, NULL, &m_numDevices);
			clReturnErrcodeOnError(m_initErrcode, "Failed to get device ids.");
			
			m_devices = (cl_device_id*) malloc(sizeof(cl_device_id) * m_numDevices);
			clGetDeviceIDs(m_platform, deviceType(), m_numDevices, m_devices, NULL);
			
			clCreateContext(NULL, m_numDevices, m_devices, NULL, NULL, &m_initErrcode);
			clReturnErrcodeOnError(m_initErrcode, "Failed to create context.");
			
			
#ifdef DEBUG
			fprintf(stdout, "# Platform information\n");
			printInfo(m_platform);
			
			fprintf(stdout, "\n");
			for (cl_uint i = 0; i < m_numDevices; i++)
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
	
	
	cl_device_type env::deviceType() const
	{
		return CL_DEVICE_TYPE_ALL;
	}
	
	
	cl_uint env::numDevices () const
	{
		return m_numDevices;
	}
	
	
	cl_context env::context () const
	{
		return m_context;
	}
}