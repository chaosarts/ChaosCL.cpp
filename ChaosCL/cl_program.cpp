//
//  cl_program.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "cl_program.hpp"

namespace cl
{
	size_t infoSize(cl_program program, cl_program_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetProgramInfo (program, pname, 0, nullptr, &size), 0, "Failed to get info about program");
		return size;
	}
	
	
	void* info (cl_program program, cl_program_info pname)
	{
		const size_t size = infoSize(program, pname);
		void* info = malloc(size);
		clGetProgramInfo (program, pname, size, info, nullptr);
		return info;
	}
	
	
	size_t infoSize (cl_program program, cl_device_id device, cl_program_build_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetProgramBuildInfo (program, device, pname, 0, nullptr, &size), 0, "Failed to get size for build info");
		return size;
	}
	
	
	void* info (cl_program program, cl_device_id device, cl_program_build_info pname)
	{
		const size_t size = infoSize (program, device, pname);
		if (size == 0) return nullptr;
		
		void* value = malloc(size);
		clGetProgramBuildInfo (program, device, pname, size, value, nullptr);
		return value;
	}
	
	
	cl_build_status buildStatus (cl_program program, cl_device_id device)
	{
		cl_build_status status;
		clReturnValueOnError(clGetProgramBuildInfo (program, device, CL_PROGRAM_BUILD_STATUS, sizeof(cl_build_status), &status, nullptr), 0, "Failed to get build status.");
		return status;
	}
	
	
	const char* buildOptions (cl_program program, cl_device_id device)
	{
		return (const char*) info(program, device, CL_PROGRAM_BUILD_OPTIONS);
	}
	
	
	const char* buildLog (cl_program program, cl_device_id device)
	{
		return (const char*) info(program, device, CL_PROGRAM_BUILD_LOG);
	}
	
	
	void printInfo (cl_program program, cl_device_id device)
	{
		cl_build_status info = buildStatus (program, device);
		
		switch (info)
		{
			case CL_BUILD_ERROR:
				fprintf(stdout, "Status: %s\n", __exprToStr(CL_BUILD_ERROR));
				break;
			case CL_BUILD_IN_PROGRESS:
				fprintf(stdout, "Status: %s\n", __exprToStr(CL_BUILD_IN_PROGRESS));
				break;
			case CL_BUILD_SUCCESS:
				fprintf(stdout, "Status: %s\n", __exprToStr(CL_BUILD_SUCCESS));
				break;
			case CL_BUILD_NONE:
				fprintf(stdout, "Status: %s\n", __exprToStr(CL_BUILD_NONE));
				break;
			default:
				fprintf(stdout, "Status: Unknown status");
		}
		
		fprintf(stdout, "Options:\n%s\n", buildOptions (program, device));
		fprintf(stdout, "Log:\n%s\n", buildLog (program, device));
	}
}