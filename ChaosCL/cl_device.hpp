//
//  cl_device.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_device_hpp
#define cl_device_hpp

#include "cl_base.hpp"

namespace cl
{
	/**
	 * @brief countDevices
	 * Counts the devices of an platform
	 * @param platform
	 * @return
	 */
	cl_uint countDevices (cl_platform_id platform, cl_device_type type);
	
	
	/**
	 * @brief devices
	 * Returns a list of devices
	 * @param platform
	 * @return
	 */
	cl_device_id* devices (cl_platform_id platform, cl_device_type type, cl_uint count = 0);
	
	
	/**
	 * @brief device
	 * @param index
	 * @param platform
	 * @param type
	 * @return
	 */
	cl_int device (cl_platform_id platform, cl_device_type type, cl_uint index, cl_device_id &device);
	
	
	/**
	 * @brief defaultDevice
	 * @param platform
	 * @return
	 */
	cl_int defaultDevice (cl_platform_id platform);
	
	
	/**
	 * @brief gpuDevices
	 * @param platform
	 * @return
	 */
	cl_device_id* gpuDevices (cl_platform_id platform);
	
	
	/**
	 * @brief gpuDevice
	 * @param platform
	 * @param index
	 * @param device
	 * @return
	 */
	cl_int gpuDevice (cl_platform_id platform, cl_uint index, cl_device_id &device);
	
	
	/**
	 * @brief cpuDevices
	 * @param platform
	 * @return
	 */
	cl_device_id* cpuDevices (cl_platform_id platform);
	
	
	/**
	 * @brief cpuDevice
	 * @param platform
	 * @param index
	 * @param device
	 * @return
	 */
	cl_int cpuDevice (cl_platform_id platform, cl_uint index, cl_device_id &device);
	
	
	/**
	 * @brief cpuDevices
	 * @param platform
	 * @return
	 */
	cl_device_id* allDevices (cl_platform_id platform);
	
	
	/**
	 * @brief anyDevice
	 * @param platform
	 * @param index
	 * @param device
	 * @return
	 */
	cl_int anyDevice (cl_platform_id platform, cl_uint index, cl_device_id &device);
	
	
	/**
	 * @brief accDevices
	 * @param platform
	 * @return
	 */
	cl_device_id* accDevices (cl_platform_id platform);
	
	
	/**
	 * @brief accDevice
	 * @param platform
	 * @param index
	 * @param device
	 * @return
	 */
	cl_int accDevice (cl_platform_id platform, cl_uint index, cl_device_id &device);
	
	
	/**
	 * @brief infoSize
	 * @param platform
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_device_id device, cl_device_info pname);
	
	
	/**
	 * @brief info
	 * @param platform
	 * @param pname
	 * @return
	 */
	void* info (cl_device_id device, cl_device_info pname);
	
	
	/**
	 * @brief name
	 * @param device
	 * @return
	 */
	const char* name (cl_device_id device);
	
	
	/**
	 * @brief profile
	 * @param device
	 * @return
	 */
	const char* profile (cl_device_id device);
	
	
	/**
	 * @brief vendor
	 * @param device
	 * @return
	 */
	const char* vendor (cl_device_id device);
	
	
	/**
	 * @brief version
	 * @param device
	 * @return
	 */
	const char* version (cl_device_id device);
	
	
	/**
	 * @brief driverVersion
	 * @param device
	 * @return
	 */
	const char* driverVersion (cl_device_id device);
	
	
	/**
	 * @brief globalMemSize
	 * @param device
	 * @return
	 */
	cl_ulong globalMemSize (cl_device_id device);
	
	
	/**
	 * @brief localMemSize
	 * @param device
	 * @return
	 */
	cl_ulong localMemSize (cl_device_id device);
	
	
	/**
	 * @brief localMemType
	 * @param device
	 * @return
	 */
	cl_device_local_mem_type localMemType (cl_device_id device);
	
	
	/**
	 * @brief Determines if the device is available or not
	 * @param device The device to check
	 * @return True if the device is available, otherwise false
	 */
	cl_bool available (cl_device_id device);
	
	
	/**
	 * @brief printInfo
	 * @param device
	 */
	void printInfo (cl_device_id device);
	
	
	/**
	 * @brief platform
	 * @param device
	 * @return
	 */
	cl_platform_id platform (cl_device_id device);
}

#endif /* cl_device_hpp */
