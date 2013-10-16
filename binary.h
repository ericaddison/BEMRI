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
			binary();						// default constructor
			binary(ptMass *masses[]);		// one of two constructors
			binary(ptMass *a, ptMass *b);	// one of two constructors 
			~binary();						// destructor 
			void setupOrbit();				// set up initial orbital pos and vel

			double calc_E();				// calculate current total energy
			double calc_l();				// calculate current angular momentum magnitude
			double calc_L();				// calculate current ang. mom. vector (also updates magnitude)
			int calc_th();					// calculate theta, true anomaly
			double calc_angles();			// calculate current orientation angles (inc, aop, lan)
			double calc_lifetime();			// calculate Peters' lifetime
		// get/set methods to enforce positive values
			double get_m1() {return m1;}
			double get_m2() {return m2;}
			double get_ecc() {return e;}
			double get_a() {return a;}
			double get_a1() {return a1;}
			double get_a2() {return a2;}
			double get_M() {return M;}
			ptMass* get_comp1() {return comp1;}
			ptMass* get_comp2() {return comp2;}			
			bool set_m1(double m);
			bool set_m2(double m);
			bool set_ecc(double ecc);
			bool set_a(double sma);


		private:
			void recalc_M() { M = m1+m2; };
			void recalc_mu() {mu = m1*m2/(m1+m2);}
			void recalc_sma() {a1 = a*m2/M; a2 = a*m1/M;}
			ptMass *comp1, *comp2;	// the binary component masses, point masses that make up the binary
			double &m1, &m2;		// refs to the masses inside of mass1 and mass2
			double e;		// binary eccentricity
			double a, a1, a2;	// binary semi-major axis for reduced mass and each component (if elliptical)
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
			double &x1, &y1, &z1;		// references for easy access to postions inside of the point masses
			double &vx1, &vy1, &vz1;	// easy access to velocities
			double &x2, &y2, &z2;		// references for easy access to postions inside of the point masses
			double &vx2, &vy2, &vz2;	// easy access to velocities
			Vector3d xCM;	// center of mass position
			Vector3d vCM;	// velocity of center of mass
			bool needDelete;// flag to specify whether ptMasses need to be deleted in destructor
	};

	void testBinary();
} // END namespace Astro

#endif
