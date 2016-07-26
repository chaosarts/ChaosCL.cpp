//
//  cl_platform.hpp
//  ChaosCL
//
//  Created by Fu Lam Diep on 24.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#ifndef platform_hpp
#define platform_hpp

#include <ChaosCL/cl_base.hpp>
#include <ChaosCL/cl_platform.hpp>
#include <gtest/gtest.h>

class Platform : public virtual testing::Test
{
public:
	
	/**
	 * Provides the platform
	 */
	cl_platform_id platform;
};


TEST_F(Platform, Base)
{
	ASSERT_GT(cl::countPlatforms(), 0);
	ASSERT_EQ(cl::platform(0, platform), CL_SUCCESS);
	
	cl::printInfo(platform);
}

#endif /* cl_platform_hpp */
