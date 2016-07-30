//
//  cl_platform.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "platform.hpp"
#include <algorithm>

namespace cl
{
	
	void defaultErrorCallback (const char* errinfo, const void* private_info, size_t cb, void* user_data)
	{
		fprintf(stderr, "%s\n", errinfo);
	}
	
	
	cl_uint countPlatforms ()
	{
		cl_uint count;
		clReturnValueOnError(clGetPlatformIDs(0, nullptr, &count), 0, "Failed to count platforms.");
		return count;
	}
	
	
	cl_platform_id* platforms ()
	{
		const cl_uint count = countPlatforms ();
		if (count == 0) return nullptr;
		
		cl_platform_id* platforms = (cl_platform_id*) malloc(count * sizeof(cl_platform_id));
		clGetPlatformIDs(count, platforms, nullptr);
		return platforms;
	}
	
	
	cl_int platform(cl_uint index, cl_platform_id &platform)
	{
		const cl_uint platformCount = countPlatforms ();
		
		if (platformCount == 0)
			return CL_INVALID_VALUE;
		
		const cl_uint i = std::min(platformCount, index + 1);
		cl_platform_id* p = platforms ();
		platform = p[i - 1];
		return CL_SUCCESS;
	}
	
	
	size_t infoSize (cl_platform_id platform, cl_platform_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetPlatformInfo(platform, pname, 0, nullptr, &size), 0, "Failed to fetch information about platform");
		return size;
	}
	
	
	void* info (cl_platform_id platform, cl_platform_info pname)
	{
		const size_t size = infoSize(platform, pname);
		if (size == 0) return 0;
		
		void* value = malloc(size);
		clGetPlatformInfo (platform, pname, size, value, nullptr);
		return value;
	}
	
	
	const char* profile (cl_platform_id platform)
	{
		return (char*) info(platform, CL_PLATFORM_PROFILE);
	}
	
	
	const char* version (cl_platform_id platform)
	{
		return (char*) info(platform, CL_PLATFORM_VERSION);
	}
	
	
	const char* name (cl_platform_id platform)
	{
		return (char*) info(platform, CL_PLATFORM_NAME);
	}
	
	
	const char* vendor (cl_platform_id platform)
	{
		return (char*) info(platform, CL_PLATFORM_VENDOR);
	}
	
	
	const char* extensions (cl_platform_id platform)
	{
		return (char*) info(platform, CL_PLATFORM_EXTENSIONS);
	}
	
	
	void printInfo (cl_platform_id platform)
	{
		fprintf(stdout, "Name:      %s\n", name (platform));
		fprintf(stdout, "Profile:   %s\n", profile (platform));
		fprintf(stdout, "Version:   %s\n", version (platform));
		fprintf(stdout, "Vendor:    %s\n", vendor (platform));
	}
	
	
}
