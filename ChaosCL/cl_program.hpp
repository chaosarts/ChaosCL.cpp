//
//  cl_program.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_program_hpp
#define cl_program_hpp

#include "cl_base.hpp"

namespace cl
{
	/**
	 * @brief infoSize
	 * @param program
	 * @return
	 */
	size_t infoSize (cl_program program, cl_program_info pname);
	
	
	/**
	 * @brief info
	 * @param program
	 * @param pname
	 * @return
	 */
	void* info (cl_program program, cl_program_info pname);
	
	
	/**
	 * @brief buildInfoSize
	 * @param program
	 * @param pname
	 * @return
	 */
	size_t infoSize (cl_program program, cl_device_id device, cl_program_build_info pname);
	
	
	/**
	 * @brief buildInfo
	 * @param program
	 * @param pname
	 * @return
	 */
	void* info (cl_program program, cl_device_id device, cl_program_build_info pname);
	
	
	/**
	 * @brief buildStatus
	 * @param program
	 * @return
	 */
	cl_build_status buildStatus (cl_program program, cl_device_id device);
	
	
	/**
	 * @brief buildOptions
	 * @param program
	 * @return
	 */
	const char* buildOptions (cl_program program, cl_device_id device);
	
	
	/**
	 * @brief buildLog
	 * @param program
	 * @return
	 */
	const char* buildLog (cl_program program, cl_device_id device);
	
	
	/**
	 * @brief printInfo
	 * @param program
	 * @param device
	 */
	void printInfo (cl_program program, cl_device_id device);
}

#endif /* cl_program_hpp */
