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
		 * @brief Returns the bit mask of device types to retrieve
		 */
		virtual cl_device_type deviceType () const;
		
		
		/**
		 * @brief Returns the count of devices to use for this environment
		 */
		cl_uint numDevices () const;
		
		
		/**
		 * @brief Returns the context of this environment
		 */
		cl_context context () const;
		
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
		 * @brief Provides the number of devices granted for this environmnt
		 */
		cl_uint m_numDevices;
		
		/**
		 * @brief Provides the platform of this environment
		 */
		cl_platform_id m_platform;
		
		/**
		 * @brief Provides the devices to use for this environment
		 */
		cl_device_id* m_devices;
		
		/**
		 * @brief Provides the context of this environment
		 */
		cl_context m_context;
	};
}

#endif /* ChaosCL_env_hpp */
