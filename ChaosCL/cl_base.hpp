//
//  cl_base.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_base_hpp
#define cl_base_hpp

#include <cstdio>

// All OpenCL headers
#if defined(WIN32)
#include <CL/opencl.h>
#elif defined (__APPLE__) || defined(MACOSX)
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define __exprToStr(x) #x
#define array_len(a) (sizeof(a)/sizeof(a[0]))

#define clLogOnError(expr, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stdout, "CL Error: %s [%s]\n", message, cl::to_string(__err_code));}}

#define clReturnValueOnError(expr, value, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stderr, "CL Error: %s [%s]\n", message, cl::to_string(__err_code)); return value;}}
#define clReturnErrcodeOnError(expr, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stderr, "CL Error: %s [%s]\n", message, cl::to_string(__err_code)); return __err_code;}}
#define clReturnOnError(expr, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stderr, "CL Error: %s [%s]\n", message, cl::to_string(__err_code)); return;}}
#define clBreakOnError(expr, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stderr, "CL Error: %s [%s]\n", message, cl::to_string(__err_code)); break;}}
#define clContinueOnError(expr, message) {cl_int __err_code = (expr); if (__err_code != CL_SUCCESS) {fprintf(stderr, "CL Error: %s [%s]\n", message, cl::to_string(__err_code)); continue;}}

#define clThrowOnError(expr, message) {cl_int __err_code = (expr); if (CL_SUCCESS != __err_code) {throw (message);}}

#define clSafeReleaseKernel(ptr) do {if(ptr){ clReleaseKernel(ptr); ptr = NULL; }} while(0)
#define clSafeReleaseProgram(ptr) do {if(ptr){ clReleaseProgram(ptr); ptr = NULL; }} while(0)
#define clSafeReleaseMemObject(ptr) do {if(ptr){ clReleaseMemObject(ptr); ptr = NULL; }} while(0)
#define clSafeRealeaseSampler(ptr) do {if(ptr){ clReleaseSampler(ptr); ptr = NULL; }} while(0)
#define clSafeReleaseContext(context) {if (context) {clReleaseContext(context); context = NULL;}}

namespace cl
{
	/**
	 * @brief Returns an approriate global worksize for dim dimensions according to
	 * data element count n and localWorkSize
	 * @param n The count of elements to process
	 * @param dim The count of dimensions (1, 2 or 3)
	 * @param localWorkSize List of local work sizes
	 * @return
	 */
	size_t* get_global_worksize (cl_uint dim, size_t* sizes, size_t* localWorkSize);
	
	
	/**
	 * @brief to_string
	 * @param errcode
	 * @return
	 */
	const char* to_string (cl_int errcode);
	
	
	/**
	 * @brief to_string
	 * @param pname
	 * @return
	 */
	const char* to_string (cl_platform_info pname);
	
	
	/**
	 * @brief to_string
	 * @param pname
	 * @return
	 */
	const char* to_string (cl_device_type type);
	
	
	/**
	 * @brief to_string
	 * @param pname
	 * @return
	 */
	const char* to_string (cl_device_info pname);
}


#endif /* cl_base_hpp */
