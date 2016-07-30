//
//  cl_context.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "context.hpp"

namespace cl
{	
	size_t infoSize (cl_context context, cl_context_info pname)
	{
		size_t size;
		clReturnValueOnError(clGetContextInfo(context, pname, 0, nullptr, &size), 0, "Failed to get infor about context.");
		return size;
	}
	
	
	void* info (cl_context context, cl_context_info pname)
	{
		const size_t size = infoSize(context, pname);
		if (size == 0) return nullptr;
		
		void* value = malloc(size);
		clGetContextInfo(context, pname, size, value, nullptr);
		return value;
	}
	
	
	cl_device_id* devices (cl_context context)
	{
		return (cl_device_id*) info(context, CL_CONTEXT_DEVICES);
	}
	
}