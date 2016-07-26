//
//  cl_device.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "cl_device.hpp"
#include <algorithm>

namespace cl
{	
	cl_uint countDevices (cl_platform_id platform, cl_device_type type)
	{
		cl_uint count;
		clReturnValueOnError(clGetDeviceIDs(platform, type, cl_uint(0), nullptr, &count), 0, "Failed to count devices");
		return count;
	}
	
	
	cl_device_id* devices (cl_platform_id platform, cl_device_type type, cl_uint count)
	{
		const cl_uint deviceCount = countDevices (platform, type);
		if (deviceCount == 0) return nullptr;
		
		cl_uint realCount = count > 0 ? std::min(count, deviceCount) : deviceCount;
		
		cl_device_id* devices = (cl_device_id*) malloc (deviceCount * sizeof(cl_device_id));
		clGetDeviceIDs(platform, type, realCount, devices, nullptr);
		
		return devices;
	}
	
	
	cl_int device (cl_platform_id platform, cl_device_type type, cl_uint index, cl_device_id &device)
	{
		const cl_uint i = std::min(countDevices (platform, type), index + 1);
		if (i == 0) return CL_DEVICE_NOT_FOUND;
		cl_device_id* d = devices(platform, type);
		device = d[i - 1];
		return CL_SUCCESS;
	}
	
	
	cl_int defaultDevice (cl_platform_id platform, cl_device_id &device)
	{
		return cl::device (platform, CL_DEVICE_TYPE_DEFAULT, 0, device);
	}
	
	
	cl_device_id* gpuDevices (cl_platform_id platform)
	{
		return devices (platform, CL_DEVICE_TYPE_GPU);
	}
	
	
	cl_int gpuDevice (cl_platform_id platform, cl_uint index, cl_device_id &device)
	{
		return cl::device (platform, CL_DEVICE_TYPE_GPU, index, device);
	}
	
	
	cl_device_id* cpuDevices (cl_platform_id platform)
	{
		return devices (platform, CL_DEVICE_TYPE_CPU);
	}
	
	
	cl_int cpuDevice (cl_platform_id platform, cl_uint index, cl_device_id &device)
	{
		return cl::device (platform, CL_DEVICE_TYPE_CPU, index, device);
	}
	
	
	cl_device_id* accDevices (cl_platform_id platform)
	{
		return devices (platform, CL_DEVICE_TYPE_ACCELERATOR);
	}
	
	
	cl_int accDevice (cl_platform_id platform, cl_uint index, cl_device_id &device)
	{
		return cl::device (platform, CL_DEVICE_TYPE_ACCELERATOR, index, device);
	}
	
	
	cl_device_id* allDevices (cl_platform_id platform)
	{
		return devices (platform, CL_DEVICE_TYPE_ALL);
	}
	
	
	cl_int anyDevice (cl_platform_id platform, cl_uint index, cl_device_id &device)
	{
		return cl::device (platform, CL_DEVICE_TYPE_ALL, index, device);
	}
	
	
	size_t infoSize (cl_device_id device, cl_device_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetDeviceInfo (device, pname, size_t(0), nullptr, &size), 0, "Faild to get information about device");
		return size;
	}
	
	
	void* info (cl_device_id device, cl_device_info pname)
	{
		const size_t size = infoSize(device, pname);
		if (size == 0) return nullptr;
		
		void* info = malloc(size);
		clGetDeviceInfo (device, pname, size, info, nullptr);
		return info;
	}
	
	
	const char* name (cl_device_id device)
	{
		return (char*) info(device, CL_DEVICE_NAME);
	}
	
	
	const char* profile (cl_device_id device)
	{
		return (char*) info(device, CL_DEVICE_PROFILE);
	}
	
	
	const char* vendor (cl_device_id device)
	{
		return (char*) info(device, CL_DEVICE_VENDOR);
	}
	
	
	const char* version (cl_device_id device)
	{
		return (char*) info(device, CL_DEVICE_VERSION);
	}
	
	
	const char* driverVersion (cl_device_id device)
	{
		return (char*) info(device, CL_DRIVER_VERSION);
	}
	
	
	cl_uint computeUnits (cl_device_id device)
	{
		cl_uint value = 0;
		clReturnValueOnError(clGetDeviceInfo (device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &value, nullptr),
							 0, "Failed to get device info about compute units");
		return value;
	}
	
	cl_ulong globalMemSize (cl_device_id device)
	{
		cl_ulong size = 0;
		clReturnValueOnError(clGetDeviceInfo (device, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &size, nullptr),
							 0, "Failed to get device info about global mem size");
		return size;
	}
	
	
	cl_ulong localMemSize (cl_device_id device)
	{
		cl_ulong size = 0;
		clReturnValueOnError(clGetDeviceInfo (device, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(cl_ulong), &size, nullptr),
							 0, "Failed to get device info about local mem size");
		return size;
	}
	
	
	cl_device_local_mem_type localMemType (cl_device_id device)
	{
		cl_device_local_mem_type type = 0;
		clReturnValueOnError(clGetDeviceInfo (device, CL_DEVICE_LOCAL_MEM_TYPE, sizeof(cl_device_local_mem_type), &type, nullptr),
							 0, "Failed to get device info about local mem type");
		return type;
	}
	
	
	cl_bool available (cl_device_id device)
	{
		cl_bool available;
		clReturnValueOnError(clGetDeviceInfo (device, CL_DEVICE_AVAILABLE, sizeof(cl_bool), &available, nullptr),
							 CL_FALSE, "Failed to get device info of availability.");
		return available;
	}
	
	
	void printInfo (cl_device_id device)
	{
		fprintf(stdout, "Name:          %s\n", name (device));
		fprintf(stdout, "Profile:       %s\n", profile (device));
		fprintf(stdout, "Version:       %s\n", version (device));
		fprintf(stdout, "Vendor:        %s\n", vendor (device));
		fprintf(stdout, "Driver:        %s\n", driverVersion (device));
		fprintf(stdout, "Units:         %ul\n", computeUnits (device));
		fprintf(stdout, "Global memory: %llu Bytes\n", globalMemSize (device));
		fprintf(stdout, "Local memory:  %llu Bytes (%s)\n", localMemSize (device), to_string(localMemType(device)));
		fprintf(stdout, "Available:     %s", available(device) == CL_TRUE ? "Yes" : "No");
	}
	
	
	cl_platform_id platform (cl_device_id device)
	{
		cl_platform_id* platform = (cl_platform_id*) info (device, CL_DEVICE_PLATFORM);
		return *platform;
	}}
