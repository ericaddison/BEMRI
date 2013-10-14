//*************************************
//	File: classTest.cpp
//	Project: BEMRI in C++
//	Purpose: testing the BEMRI classes
//	Author: Eric Addison
//	Original date: 14Oct13
//*************************************

// Small program to test functionality of various BEMRI classes
// Runs the test programs included in each class

#include <iostream>
#include "ptMass.h"

int main()
{
	//ptMassTester();
	

	Vector3d x, y;
	x << 1, 2, 3;
	y << -1, 4, 5;

	std::cout << "x - y = : " << (x-y).transpose() << std::endl;

	return 0;
}


