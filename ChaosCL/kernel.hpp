//
//  cl_kernel.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_kernel_hpp
#define cl_kernel_hpp

#include "base.hpp"

namespace cl
{
	/**
	 * @brief infoSize
	 * @param kernel
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_kernel kernel, cl_kernel_info pname);
	
	
	/**
	 * @brief info
	 * @param kernel
	 * @param pname
	 * @return
	 */
	void* info (cl_kernel kernel, cl_kernel_info pname);
	
	
	/**
	 * @brief argc
	 * @param kernel
	 * @return
	 */
	cl_uint argc (cl_kernel kernel);
	
	
	/**
	 * @brief name
	 * @param kernel
	 * @return
	 */
	const char* name(cl_kernel kernel);
	
	
	/**
	 * @brief referenceCount
	 * @param kernel
	 * @return
	 */
	cl_uint referenceCount (cl_kernel kernel);
	
	
	/**
	 * @brief context
	 * @param kernel
	 * @return
	 */
	cl_context context (cl_kernel kernel);
	
	
	/**
	 * @brief program
	 * @param kernel
	 * @return
	 */
	cl_program program (cl_kernel kernel);
	
	
	/**
	 * @brief printInfo
	 * @param kenrel
	 */
	void printInfo (cl_kernel kernel);
	
	
	/**
	 * @brief infoSize
	 * @param kernel
	 * @param device
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info pname);
	
	
	/**
	 * @brief info
	 * @param device
	 * @param pname
	 * @return
	 */
	void* info (cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info pname);
	
	
	/**
	 * @brief global_worksize
	 * @param kernel
	 * @param device
	 * @return
	 */
	size_t* globalWorksize (cl_kernel kernel, cl_device_id device);
	
	
	/**
	 * @brief workGroupSize
	 * @param kernel
	 * @param device
	 * @return
	 */
	size_t workGroupSize (cl_kernel kernel, cl_device_id device);
	
	
	/**
	 * @brief localMemSize
	 * @param kernel
	 * @param device
	 * @return
	 */
	cl_ulong localMemSize (cl_kernel kernel, cl_device_id device);
	
	
	/**
	 * @brief privateMemSize
	 * @param device
	 * @return
	 */
	cl_ulong privateMemSize (cl_kernel, cl_device_id device);
	
	
	/**
	 * @brief printInfo
	 * @param kernel
	 * @param device
	 */
	void printInfo (cl_kernel kernel, cl_device_id device);
	
	/*
	 +--------------------------------------------------------------------------
	 | Kernel arg functions
	 +--------------------------------------------------------------------------
	 */
	
	
	/**
	 * @brief infoSize
	 * @param kernel
	 * @param index
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info pname);
	
	
	/**
	 * @brief info
	 * @param kernel
	 * @param index
	 * @param pname
	 * @return
	 */
	void* info (cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info pname);
	
	
	/**
	 * @brief typeOf
	 * @param kernel
	 * @param index
	 * @return
	 */
	const char* typeOf (cl_kernel kernel, cl_uint arg_index);
	
	
	/**
	 * @brief nameOf
	 * @param kernel
	 * @param index
	 * @return
	 */
	const char* name (cl_kernel kernel, cl_uint arg_index);
}

#endif /* cl_kernel_hpp */
