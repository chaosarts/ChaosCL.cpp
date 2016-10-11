//
//  env.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 26.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef ChaosCL_env_hpp
#define ChaosCL_env_hpp

#include "base.hpp"
#include <vector>
#include <map>

namespace cl
{
	struct env
	{
	public:
		
		/**
		 * @brief Creates a new environment object
		 */
		env ();
		
		
		/**
		 * @brief Destroys the environment object
		 */
		virtual ~env ();
		
		
		/**
		 * @brief Initializes the environment
		 */
		cl_int init ();
		
		
		/**
		 * @brief Returns the index of the platform to use
		 */
		virtual cl_uint platformIndex () const;
		
		
		/**
		 * @brief Returns the platform used by this environment
		 */
		const cl_platform_id platform () const;
		
		
		/**
		 * @brief Returns the bit mask of device types to retrieve
		 */
		virtual cl_device_type deviceType () const;
		
		
		/**
		 * @brief Returns the count of devices to use for this environment
		 */
		std::vector<cl_device_id> devices () const;
		
		
		/**
		 * @brief Returns the context of this environment
		 */
		const cl_context context () const;
		
		
		/**
		 * @brief Returns a list of all initialized programs
		 */
		std::vector<cl_program> programs () const;
		
		
		/**
		 * @brief Returns all kernels initialized by the environment
		 */
		std::vector<cl_kernel> kernels () const;
		
		
		/**
		 * @breif Returns a list of all available kernel names
		 */
		std::vector<const char*> kernelNames () const;
		
		
		/**
		 * @brief Returns the kernel of given name
		 */
		const cl_kernel kernel (const char*  name) const;
	protected:
		
		/**
		 * @brief Initializes opencl programs
		 * @param errcode
		 * @return A list of programs
		 */
		virtual std::vector<cl_program> initPrograms (cl_int &errcode) = 0;
		
		
		/**
		 * @brief Initializes OpenCL Kernels
		 * @param errcode
		 * @return A list of kernels
		 */
		virtual std::vector<cl_kernel> initKernels (cl_int &errcode) = 0;
		
		
		virtual cl_int prepareOpenCL ();
		
	private:
		
		/**
		 * @brief Indicates whether the environment has been initialized or not
		 */
		bool m_initialized;
		
		/**
		 * @brief Provides the errcode on initialization
		 */
		cl_int m_initErrcode;
		
		/**
		 * @brief Provides the platform of this environment
		 */
		cl_platform_id m_platform;
		
		/**
		 * @brief Provides the devices to use for this environment
		 */
		std::vector<cl_device_id> m_devices;
		
		/**
		 * @brief Provides the context of this environment
		 */
		cl_context m_context;
		
		/**
		 * @brief Provides a list of opencl programs
		 */
		std::vector<cl_program> m_programs;
		
		/**
		 * @brief Provides a name to kernel index map
		 */
		std::map<const char*, cl_uint> m_kernelNameIndexMap;
		
		/**
		 * @brief Provides a list of kernels
		 */
		std::vector<cl_kernel> m_kernels;
	};
}

#endif /* ChaosCL_env_hpp */
