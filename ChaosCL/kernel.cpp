//
//  cl_kernel.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "kernel.hpp"

namespace cl
{
	size_t infoSize(cl_kernel kernel, cl_kernel_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetKernelInfo (kernel, pname, 0, nullptr, &size), 0, "Failed to get info about kernel");
		return size;
	}
	
	
	void* info (cl_kernel kernel, cl_kernel_info pname)
	{
		const size_t size = infoSize(kernel, pname);
		if (size == 0) return nullptr;
		
		void* info = malloc(size);
		clGetKernelInfo (kernel, pname, size, info, nullptr);
		return info;
	}
	
	
	cl_uint argc (cl_kernel kernel)
	{
		cl_uint count;
		clReturnValueOnError(clGetKernelInfo (kernel, CL_KERNEL_NUM_ARGS, sizeof(cl_uint), &count, nullptr), 0, "Failed to get argument count from kernel");
		return count;
	}
	
	
	const char* name (cl_kernel kernel)
	{
		return (const char*) info(kernel, CL_KERNEL_FUNCTION_NAME);
	}
	
	
	cl_uint referenceCount (cl_kernel kernel)
	{
		cl_uint count;
		clReturnValueOnError(clGetKernelInfo (kernel, CL_KERNEL_REFERENCE_COUNT, sizeof(cl_uint), &count, nullptr), 0, "Failed to get kernel info about reference count");
		return count;
	}
	
	
	cl_context context (cl_kernel kernel)
	{
		cl_context context;
		clReturnValueOnError(clGetKernelInfo (kernel, CL_KERNEL_CONTEXT, sizeof(cl_context), &context, nullptr), 0, "Failed to get kernel info about context");
		return context;
	}
	
	
	cl_program program (cl_kernel kernel)
	{
		cl_program program;
		clReturnValueOnError(clGetKernelInfo (kernel, CL_KERNEL_PROGRAM, sizeof(cl_program), &program, nullptr), 0, "Failed to get kernel info about program");
		return program;
	}
	
	
	void printInfo (cl_kernel kernel)
	{
		fprintf (stdout, "Name:         %s", name(kernel));
		fprintf (stdout, "References:   %ul", referenceCount(kernel));
	}
	
	
	size_t infoSize (cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info pname)
	{
		size_t size;
		clReturnValueOnError(
							 clGetKernelWorkGroupInfo (kernel, device, pname, 0, nullptr, &size), 0,
							 "Failed to get info about kernel work group."
        );
		
		return size;
	}
	
	
	void* info (cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info pname)
	{
		const size_t size = infoSize(kernel, device, pname);
		if (size == 0) return nullptr;
		
		void* value = malloc(size);
		clGetKernelWorkGroupInfo (kernel, device, pname, size, &value, nullptr);
		return value;
	}
	
	
	size_t workGroupSize (cl_kernel kernel, cl_device_id device)
	{
		size_t size = 0;
		clReturnValueOnError(clGetKernelWorkGroupInfo (kernel, device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(size_t), &size, nullptr), 0, "Failed to get kernel work group info about work group size.");
		return size;
	}
	
	
	cl_ulong localMemSize (cl_kernel kernel, cl_device_id device)
	{
		cl_ulong size = 0;
		clReturnValueOnError(clGetKernelWorkGroupInfo (kernel, device, CL_KERNEL_LOCAL_MEM_SIZE, sizeof(cl_ulong), &size, nullptr), 0, "Failed to get kernel work group info about local mem size.");
		return size;
	}
	
	
	cl_ulong privateMemSize (cl_kernel kernel, cl_device_id device)
	{
		cl_ulong size = 0;
		clReturnValueOnError(clGetKernelWorkGroupInfo (kernel, device, CL_KERNEL_PRIVATE_MEM_SIZE, sizeof(cl_ulong), &size, nullptr), 0, "Failed to get kernel work group info about private mem size.");
		return size;
	}
	
	
	void printInfo (cl_kernel kernel, cl_device_id device)
	{
		fprintf (stdout, "Work group size:  %lu\n", workGroupSize (kernel, device));
		fprintf (stdout, "Local memory:     %llu Bytes\n", localMemSize (kernel, device));
		fprintf (stdout, "Private memory:   %llu Bytes\n", privateMemSize (kernel, device));
	}
	
	
	/*
	 +--------------------------------------------------------------------------
	 | Kernel arg functions
	 +--------------------------------------------------------------------------
	 */
	
	
	size_t infoSize(cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetKernelArgInfo (kernel, arg_index, pname, 0, nullptr, &size), 0, "Failed to get info about kernel argument");
		return size;
	}
	
	
	void* info (cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info pname)
	{
		const size_t size = infoSize(kernel, arg_index, pname);
		void* info = malloc(size);
		clGetKernelArgInfo (kernel, arg_index, pname, size, info, nullptr);
		return info;
	}
	
	
	const char* typeOf (cl_kernel kernel, cl_uint arg_index)
	{
		return (char*) info(kernel, arg_index, CL_KERNEL_ARG_TYPE_NAME);
	}
	
	
	const char* name (cl_kernel kernel, cl_uint arg_index)
	{
		return (char*) info(kernel, arg_index, CL_KERNEL_ARG_NAME);
	}
}