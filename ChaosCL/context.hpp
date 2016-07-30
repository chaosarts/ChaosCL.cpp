//
//  cl_context.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 22.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef cl_context_hpp
#define cl_context_hpp

#include "base.hpp"

namespace cl
{
	typedef void (*context_pfn_notify)(const char *, const void *, size_t, void *);
	
	/**
	 * @brief infoSize
	 * @param context
	 * @return
	 */
	size_t infoSize (cl_context context, cl_context_info pname);
	
	
	/**
	 * @brief info
	 * @param context
	 * @return
	 */
	void* info (cl_context context, cl_context_info pname);
	
	
	/**
	 * @brief devices
	 * @param context
	 * @return
	 */
	cl_device_id* devices (cl_context context);
}

#endif /* cl_context_hpp */
