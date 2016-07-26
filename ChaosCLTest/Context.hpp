//
//  Context.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 24.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Context_h
#define Context_h

#include "Device.hpp"
#include <ChaosCL/cl_context.hpp>

class Context : public virtual Device
{
public:
	
	cl_context context;
	
	void SetUp ()
	{
		Device::SetUp();
		cl::anyDevice(platform, 0, device);
	}
};


TEST_F(Context, Base)
{
	cl_int errcode = 0;
	cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &errcode);
	
}

#endif /* Context_h */
