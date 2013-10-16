//*************************************
//	File: ptMass.cpp
//	Project: BEMRI in C++
//	Purpose: Implementation of point mass class
//	Author: Eric Addison
//	Original date: 14Oct13
//*************************************

// This file implements the ptMass class defined in ptMass.h

#include "ptMass.h"

namespace Astro
{

	// mass only constructor
	ptMass::ptMass(double m) : x(pos[0]), y(pos[1]), z(pos[2]), vx(vel[0]), vy(vel[1]), vz(vel[2])
	{
		mass = m;
	
		pos << 0, 0, 0;		// Comma-initialization of Eigen matrix
		vel << 0, 0, 0;		// set both pos and vel to zero

	}

	// full constructor with double arrays
	ptMass::ptMass(double m, double p[3], double v[3]) : x(pos[0]), y(pos[1]), z(pos[2]), vx(vel[0]), vy(vel[1]), vz(vel[2])
	{
		mass = m;
	
		pos << p[0], p[1], p[2];		// Comma-initialization of Eigen matrix
		vel << v[0], v[1], v[2];		// set both pos and vel to input vlaues
	}

	// report(): output all data associated with this ptMass
	void ptMass::report()
	{
		std::cout << "mass = " << mass << "\nposition = [" << pos.transpose() << "]\nvelocity = [" << vel.transpose() << "]" << std::endl;
	}

	// test function
	void testPtMass()
	{
		using namespace Eigen;
		using std::cout;

		double x[3] = {1, 2, 3};
		double v[3] = {1, -1, 0};
	
		ptMass m1, m2(10), m3(5,x,v);

		cout << "m1 mass: " << m1.mass << "\n";

		cout << "m1 report:\n";
		m1.report();
	
		cout << "\nm2 report:\n";
		m2.report();

		cout << "\nm3 report:\n";
		m3.report();
		
		cout << "\nchanging m3 elemetns...\n";
		m3.vx = 10; m3.z = 1000;
		m3.report();
		

		return;
	}

}	// END namespace Astro
