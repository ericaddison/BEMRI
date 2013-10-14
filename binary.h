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

class binary{

	public:
		binary(ptMass masses[]);		// only constructor  
		initialize();					// set up initial orbital pos and vel

	private:
		ptMass *m1, *m2;// the point masses that make up the binary

		double e;		// binary eccentricity
		double a;		// binary semi-major axis (if elliptical)
		double E;		// binary total energy
		double l;		// binary angular mometum magnitude
		double aop;		// argument of periapse angle
		double inc;		// inclination angle
		double lan;		// longitude of ascending node angle
		Vector3d xCM;	// center of mass position
		Vector3d vCM;	// velocity of center of mass
};
