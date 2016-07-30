//
//  cl_base.cpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include "base.hpp"

namespace cl
{
	size_t* get_global_worksize (cl_uint dim, size_t* sizes, size_t* localWorkSize)
	{
		size_t* worksize = new size_t[dim];
		for (cl_uint d = 0; d < dim; d++)
		{
			const size_t rest = sizes[d] % localWorkSize[d];
			worksize[d] = sizes[d] + (0 == rest ? 0 : localWorkSize[d] - rest);
		}
		
		return worksize;
	}
	
	
	const char* to_string(cl_int errcode)
	{
		switch (errcode)
		{
			case CL_DEVICE_NOT_FOUND:
				return __exprToStr(CL_DEVICE_NOT_FOUND);
			case CL_DEVICE_NOT_AVAILABLE:
				return __exprToStr(CL_DEVICE_NOT_AVAILABLE);
			case CL_COMPILER_NOT_AVAILABLE:
				return __exprToStr(CL_COMPILER_NOT_AVAILABLE);
			case CL_MEM_OBJECT_ALLOCATION_FAILURE:
				return __exprToStr(CL_MEM_OBJECT_ALLOCATION_FAILURE);
			case CL_OUT_OF_RESOURCES:
				return __exprToStr(CL_OUT_OF_RESOURCES);
			case CL_OUT_OF_HOST_MEMORY:
				return __exprToStr(CL_OUT_OF_HOST_MEMORY);
			case CL_PROFILING_INFO_NOT_AVAILABLE:
				return __exprToStr(CL_PROFILING_INFO_NOT_AVAILABLE);
			case CL_MEM_COPY_OVERLAP:
				return __exprToStr(CL_MEM_COPY_OVERLAP);
			case CL_IMAGE_FORMAT_MISMATCH:
				return __exprToStr(CL_IMAGE_FORMAT_MISMATCH);
			case CL_IMAGE_FORMAT_NOT_SUPPORTED:
				return __exprToStr(CL_IMAGE_FORMAT_NOT_SUPPORTED);
			case CL_BUILD_PROGRAM_FAILURE:
				return __exprToStr(CL_BUILD_PROGRAM_FAILURE);
			case CL_MAP_FAILURE:
				return __exprToStr(CL_MAP_FAILURE);
			case CL_INVALID_VALUE:
				return __exprToStr(CL_INVALID_VALUE);
			case CL_INVALID_DEVICE_TYPE:
				return __exprToStr(CL_INVALID_DEVICE_TYPE);
			case CL_INVALID_PLATFORM:
				return __exprToStr(CL_INVALID_PLATFORM);
			case CL_INVALID_DEVICE:
				return __exprToStr(CL_INVALID_DEVICE);
			case CL_INVALID_CONTEXT:
				return __exprToStr(CL_INVALID_CONTEXT);
			case CL_INVALID_QUEUE_PROPERTIES:
				return __exprToStr(CL_INVALID_QUEUE_PROPERTIES);
			case CL_INVALID_COMMAND_QUEUE:
				return __exprToStr(CL_INVALID_COMMAND_QUEUE);
			case CL_INVALID_HOST_PTR:
				return __exprToStr(CL_INVALID_HOST_PTR);
			case CL_INVALID_MEM_OBJECT:
				return __exprToStr(CL_INVALID_MEM_OBJECT);
			case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
				return __exprToStr(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
			case CL_INVALID_IMAGE_SIZE:
				return __exprToStr(CL_INVALID_IMAGE_SIZE);
			case CL_INVALID_SAMPLER:
				return __exprToStr(CL_INVALID_SAMPLER);
			case CL_INVALID_BINARY:
				return __exprToStr(CL_INVALID_BINARY);
			case CL_INVALID_BUILD_OPTIONS:
				return __exprToStr(CL_INVALID_BUILD_OPTIONS);
			case CL_INVALID_PROGRAM:
				return __exprToStr(CL_INVALID_PROGRAM);
			case CL_INVALID_PROGRAM_EXECUTABLE:
				return __exprToStr(CL_INVALID_PROGRAM_EXECUTABLE);
			case CL_INVALID_KERNEL_NAME:
				return __exprToStr(CL_INVALID_KERNEL_NAME);
			case CL_INVALID_KERNEL_DEFINITION:
				return __exprToStr(CL_INVALID_KERNEL_DEFINITION);
			case CL_INVALID_KERNEL:
				return __exprToStr(CL_INVALID_KERNEL);
			case CL_INVALID_ARG_INDEX:
				return __exprToStr(CL_INVALID_ARG_INDEX);
			case CL_INVALID_ARG_VALUE:
				return __exprToStr(CL_INVALID_ARG_VALUE);
			case CL_INVALID_ARG_SIZE:
				return __exprToStr(CL_INVALID_ARG_SIZE);
			case CL_INVALID_KERNEL_ARGS:
				return __exprToStr(CL_INVALID_KERNEL_ARGS);
			case CL_INVALID_WORK_DIMENSION:
				return __exprToStr(CL_INVALID_WORK_DIMENSION);
			case CL_INVALID_WORK_GROUP_SIZE:
				return __exprToStr(CL_INVALID_WORK_GROUP_SIZE);
			case CL_INVALID_WORK_ITEM_SIZE:
				return __exprToStr(CL_INVALID_WORK_ITEM_SIZE);
			case CL_INVALID_GLOBAL_OFFSET:
				return __exprToStr(CL_INVALID_GLOBAL_OFFSET);
			case CL_INVALID_EVENT_WAIT_LIST:
				return __exprToStr(CL_INVALID_EVENT_WAIT_LIST);
			case CL_INVALID_EVENT:
				return __exprToStr(CL_INVALID_EVENT);
			case CL_INVALID_OPERATION:
				return __exprToStr(CL_INVALID_OPERATION);
			case CL_INVALID_GL_OBJECT:
				return __exprToStr(CL_INVALID_GL_OBJECT);
			case CL_INVALID_BUFFER_SIZE:
				return __exprToStr(CL_INVALID_BUFFER_SIZE);
			case CL_INVALID_MIP_LEVEL:
				return __exprToStr(CL_INVALID_MIP_LEVEL);
			case CL_INVALID_GLOBAL_WORK_SIZE:
				return __exprToStr(CL_INVALID_GLOBAL_WORK_SIZE);
			default:
				return "Unknown error.";
		}
	};
	
	
	const char* to_string (cl_device_type type)
	{
		switch (type)
		{
			case CL_DEVICE_TYPE_ALL:
				return __exprToStr(CL_DEVICE_TYPE_ALL);
			case CL_DEVICE_TYPE_CPU:
				return __exprToStr(CL_DEVICE_TYPE_CPU);
			case CL_DEVICE_TYPE_GPU:
				return __exprToStr(CL_DEVICE_TYPE_GPU);
			case CL_DEVICE_TYPE_ACCELERATOR:
				return __exprToStr(CL_DEVICE_TYPE_ACCELERATOR);
			case CL_DEVICE_TYPE_CUSTOM:
				return __exprToStr(CL_DEVICE_TYPE_CUSTOM);
			case CL_DEVICE_TYPE_DEFAULT:
				return __exprToStr(CL_DEVICE_TYPE_DEFAULT);
			default:
				return "Unknown device type.";
		}
	}
	
	
	
	
	
	const char* to_string (cl_uint pname)
	{
		switch (pname)
		{
			case CL_PLATFORM_PROFILE:
				return __exprToStr(CL_PLATFORM_PROFILE);
			case CL_PLATFORM_NAME:
				return __exprToStr(CL_PLATFORM_NAME);
			case CL_PLATFORM_VENDOR:
				return __exprToStr(CL_PLATFORM_VENDOR);
			case CL_PLATFORM_EXTENSIONS:
				return __exprToStr(CL_PLATFORM_EXTENSIONS);
				
			case CL_DEVICE_NAME:
				return __exprToStr(CL_DEVICE_NAME);
			case CL_DEVICE_PROFILE:
				return __exprToStr(CL_DEVICE_PROFILE);
			case CL_DEVICE_VENDOR:
				return __exprToStr(CL_DEVICE_VENDOR);
			case CL_DEVICE_VENDOR_ID:
				return __exprToStr(CL_DEVICE_VENDOR_ID);
			case CL_DEVICE_VERSION:
				return __exprToStr(CL_DEVICE_VERSION);
			case CL_DEVICE_ADDRESS_BITS:
				return __exprToStr(CL_DEVICE_ADDRESS_BITS);
			case CL_DEVICE_AVAILABLE:
				return __exprToStr(CL_DEVICE_AVAILABLE);
			case CL_DEVICE_COMPILER_AVAILABLE:
				return __exprToStr(CL_DEVICE_COMPILER_AVAILABLE);
			case CL_DEVICE_DOUBLE_FP_CONFIG:
				return __exprToStr(CL_DEVICE_DOUBLE_FP_CONFIG);
			case CL_DEVICE_ENDIAN_LITTLE:
				return __exprToStr(CL_DEVICE_ENDIAN_LITTLE);
			case CL_DEVICE_ERROR_CORRECTION_SUPPORT:
				return __exprToStr(CL_DEVICE_ERROR_CORRECTION_SUPPORT);
			case CL_DEVICE_EXECUTION_CAPABILITIES:
				return __exprToStr(CL_DEVICE_EXECUTION_CAPABILITIES);
			case CL_DEVICE_EXTENSIONS:
				return __exprToStr(CL_DEVICE_EXTENSIONS);
			case CL_DEVICE_GLOBAL_MEM_CACHE_SIZE:
				return __exprToStr(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
			case CL_DEVICE_GLOBAL_MEM_CACHE_TYPE:
				return __exprToStr(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
			case CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE:
				return __exprToStr(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
			case CL_DEVICE_GLOBAL_MEM_SIZE:
				return __exprToStr(CL_DEVICE_GLOBAL_MEM_SIZE);
#ifdef CL_DEVICE_HALF_FP_CONFIG
			case CL_DEVICE_HALF_FP_CONFIG:
				return __exprToStr(CL_DEVICE_HALF_FP_CONFIG);
#endif
			case CL_DEVICE_IMAGE_SUPPORT:
				return __exprToStr(CL_DEVICE_IMAGE_SUPPORT);
			case CL_DEVICE_IMAGE2D_MAX_HEIGHT:
				return __exprToStr(CL_DEVICE_IMAGE2D_MAX_HEIGHT);
			case CL_DEVICE_IMAGE2D_MAX_WIDTH:
				return __exprToStr(CL_DEVICE_IMAGE2D_MAX_WIDTH);
			case CL_DEVICE_IMAGE3D_MAX_DEPTH:
				return __exprToStr(CL_DEVICE_IMAGE3D_MAX_DEPTH);
			case CL_DEVICE_IMAGE3D_MAX_HEIGHT:
				return __exprToStr(CL_DEVICE_IMAGE3D_MAX_HEIGHT);
			case CL_DEVICE_IMAGE3D_MAX_WIDTH:
				return __exprToStr(CL_DEVICE_IMAGE3D_MAX_WIDTH);
			case CL_DEVICE_LOCAL_MEM_SIZE:
				return __exprToStr(CL_DEVICE_LOCAL_MEM_SIZE);
			case CL_DEVICE_LOCAL_MEM_TYPE:
				return __exprToStr(CL_DEVICE_LOCAL_MEM_TYPE);
			case CL_DEVICE_MAX_CLOCK_FREQUENCY:
				return __exprToStr(CL_DEVICE_MAX_CLOCK_FREQUENCY);
			case CL_DEVICE_MAX_COMPUTE_UNITS:
				return __exprToStr(CL_DEVICE_MAX_COMPUTE_UNITS);
			case CL_DEVICE_MAX_CONSTANT_ARGS:
				return __exprToStr(CL_DEVICE_MAX_CONSTANT_ARGS);
			case CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE:
				return __exprToStr(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
			case CL_DEVICE_MAX_MEM_ALLOC_SIZE:
				return __exprToStr(CL_DEVICE_MAX_MEM_ALLOC_SIZE);
			case CL_DEVICE_MAX_PARAMETER_SIZE:
				return __exprToStr(CL_DEVICE_MAX_PARAMETER_SIZE);
			case CL_DEVICE_MAX_READ_IMAGE_ARGS:
				return __exprToStr(CL_DEVICE_MAX_READ_IMAGE_ARGS);
			case CL_DEVICE_MAX_SAMPLERS:
				return __exprToStr(CL_DEVICE_MAX_SAMPLERS);
			case CL_DEVICE_MAX_WORK_GROUP_SIZE:
				return __exprToStr(CL_DEVICE_MAX_WORK_GROUP_SIZE);
			case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS:
				return __exprToStr(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
			case CL_DEVICE_MAX_WORK_ITEM_SIZES:
				return __exprToStr(CL_DEVICE_MAX_WORK_ITEM_SIZES);
			case CL_DEVICE_MAX_WRITE_IMAGE_ARGS:
				return __exprToStr(CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
			case CL_DEVICE_MEM_BASE_ADDR_ALIGN:
				return __exprToStr(CL_DEVICE_MEM_BASE_ADDR_ALIGN);
			case CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE:
				return __exprToStr(CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
			case CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE:
				return __exprToStr(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
			case CL_DEVICE_PROFILING_TIMER_RESOLUTION:
				return __exprToStr(CL_DEVICE_PROFILING_TIMER_RESOLUTION);
			case CL_DEVICE_QUEUE_PROPERTIES:
				return __exprToStr(CL_DEVICE_QUEUE_PROPERTIES);
			case CL_DEVICE_SINGLE_FP_CONFIG:
				return __exprToStr(CL_DEVICE_SINGLE_FP_CONFIG);
			case CL_GLOBAL:
				return __exprToStr(CL_GLOBAL);
			case CL_LOCAL:
				return __exprToStr(CL_LOCAL);
			default:
				return "Unknown info parameter.";
		}
	}
}