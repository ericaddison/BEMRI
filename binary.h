//*************************************
//	File: binary.h
//	Project: BEMRI in C++
//	Purpose: Declaration of binary class
//	Author: Eric Addison
//	Original date: 14Oct13
//*************************************

// Binary class. This class holds all information relating to the binary parameters
// between a pair of ptMasses. It does not actually contain it's own ptMasses, but 
// only pointers to them. In this way, it can be thought of more as a tool to
// determine the relationship of two point masses in terms of a binary system.
// i.e. create a binary object for a pair of masses to determine what kind of 
// binary they form
//
// Can also be used to initialize the pos and vel of point masses to an arbitrary
// location in an orbit given the parameters currently stored in binary

#ifndef BINARY_H
#define BINARY_H

#include "ptMass.h"
#include <Eigen/Dense>	// Eigen library for matrix class
using namespace Eigen;


namespace Astro
{
	class binary{

		public:
			binary(ptMass *masses[]);		// one of two constructors
			binary(ptMass *a, ptMass *b);	// one of two constructors  
			void setupOrbit();				// set up initial orbital pos and vel

			double calc_E();				// calculate current total energy
			double calc_l();				// calculate current angular momentum magnitude
			double calc_L();				// calculate current ang. mom. vector (also updates magnitude)
			int calc_th();					// calculate theta, true anomaly
			double calc_angles();			// calculate current orientation angles (inc, aop, lan)
			double calc_lifetime();			// calculate Peters' lifetime

		private:
			ptMass *m1, *m2;// the point masses that make up the binary

			double e;		// binary eccentricity
			double a;		// binary semi-major axis (if elliptical)
			double E;		// binary total energy
			double l;		// binary angular mometum magnitude
			Vector3d L;		// angular momentum vector
			double theta;	// true anomaly
			double aop;		// argument of periapse angle
			double inc;		// inclination angle
			double lan;		// longitude of ascending node angle
			double M;		// total mass
			double mu;		// reduced mass
			double T;		// peters' lifetime
			Vector3d xCM;	// center of mass position
			Vector3d vCM;	// velocity of center of mass
	};

	void testBinary();
} // END namespace Astro

#endif
