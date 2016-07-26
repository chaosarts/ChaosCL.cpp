//
//  main.cpp
//  ChaosCLTest
//
//  Created by Fu Lam Diep on 24.07.16.
//  Copyright © 2016 Fu Lam Diep. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Platform.hpp"
#include "Device.hpp"
#include "Context.hpp"

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
