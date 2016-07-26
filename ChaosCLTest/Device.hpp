//
//  Device.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 24.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef Device_hpp
#define Device_hpp

#include "Platform.hpp"
#include <ChaosCL/cl_device.hpp>

class Device : public virtual Platform
{
public:
	
	cl_device_id device;
	
	void SetUp ()
	{
		cl::platform(0, platform);
	}
};


TEST_F(Device, Base)
{
	ASSERT_GT(cl::countDevices(platform, CL_DEVICE_TYPE_ALL), 0);
	ASSERT_EQ(cl::anyDevice(platform, 0, device), CL_SUCCESS);
	ASSERT_EQ(cl::platform(device), platform);
	
	cl::printInfo(device);
}

#endif /* Device_hpp */
