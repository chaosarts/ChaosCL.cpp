//
//  cl_platform.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_platform_hpp
#define cl_platform_hpp

#include "cl_base.hpp"

namespace cl
{
	typedef void (*errorCallback) (const char* errinfo, const void* private_info, size_t cb, void* user_data);
	
	
	/**
	 * @brief defaultErrorCallback
	 */
	void defaultErrorCallback (const char* errinfo, const void* private_info, size_t cb, void* user_data);
	
	
	/*
	 +--------------------------------------------------------------------------
	 | Platform functions
	 +--------------------------------------------------------------------------
	 */
	
	
	/**
	 * @brief countPlatforms
	 * Returns the count of available platforms
	 * @return
	 */
	cl_uint countPlatforms ();
	
	
	/**
	 * @brief platformIDs
	 * Returns all available platformIDs
	 */
	cl_platform_id* platforms ();
	
	
	/**
	 * @brief platform
	 * Assigns the referenced value with the platform at given index
	 * @param index
	 * @param platform
	 * @return
	 */
	cl_int platform (cl_uint index, cl_platform_id &platform);
	
	
	/**
	 * @brief infoSize
	 * @param platform
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_platform_id platform, cl_platform_info pname);
	
	
	/**
	 * @brief info
	 * @param platform
	 * @param pname
	 * @return
	 */
	void* info (cl_platform_id platform, cl_platform_info pname);
	
	
	/**
	 * @brief profile
	 * @param platform
	 * @return
	 */
	const char* profile (cl_platform_id platform);
	
	
	/**
	 * @brief version
	 * @param platform
	 * @return
	 */
	const char* version (cl_platform_id platform);
	
	
	/**
	 * @brief name
	 * @param platform
	 * @return
	 */
	const char* name (cl_platform_id platform);
	
	
	/**
	 * @brief vendor
	 * @param platform
	 * @return
	 */
	const char* vendor (cl_platform_id platform);
	
	
	/**
	 * @brief extensions
	 * @param platform
	 * @return
	 */
	const char* extensions (cl_platform_id platform);
	
	
	/**
	 * @brief printInfo
	 * @param platform
	 */
	void printInfo (cl_platform_id platform);
}

#endif /* cl_platform_hpp */
