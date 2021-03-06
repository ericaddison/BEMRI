//*************************************
//	File: ptMass.h
//	Project: BEMRI in C++
//	Purpose: Declaration of point mass class
//	Author: Eric Addison
//	Original date: 14Oct13
//*************************************

// This file defines the ptMass class to represent a simple point mass for N-body simulations. This class will contain mass, position, and velocity values.

// linear algebra functionality from the Eigen library, see
// http://eigen.tuxfamily.org/index.php?title=Main_Page

#ifndef PTMASS_H
#define PTMASS_H

#include <iostream>
#include <Eigen/Dense>	// Eigen library for matrix class
using namespace Eigen;

namespace Astro
{
	class ptMass {
	
		public:
			ptMass(double, double[3] , double[3]);	// fulll constructor with double array inputs
			ptMass(double m=1);			// mass only constructor
			void report();				// print out all stats

			double mass;		// mass value
			Vector3d pos;		// position vector -- fixed size vector from Eigen
			Vector3d vel;		// velocity vector
			double &x, &y, &z;		// references for easy access to postions
			double &vx, &vy, &vz;	// easy access to velocities

	};

	// ptMass test function
	void testPtMass();
}	// END namespace Astro

#endif
