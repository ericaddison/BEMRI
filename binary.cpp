//*************************************
//	File: binary.cpp
//	Project: BEMRI in C++
//	Purpose: Implementation of binary class
//	Author: Eric Addison
//	Original date: 14Oct13
//*************************************

// This file holds the implementation of all the binary class methods

#include "binary.h"
#include <iostream>

namespace Astro
{

	static const double G = 1.0;

	binary::binary() : comp1(new ptMass), comp2(new ptMass), m1(comp1->mass), m2(comp2->mass), x1(comp1->x), y1(comp1->y), z1(comp1->z), vx1(comp1->vx), vy1(comp1->vy), vz1(comp1->vz), x2(comp2->x), y2(comp2->y), z2(comp2->z), vx2(comp2->vx), vy2(comp2->vy), vz2(comp2->vz)
	/// default constructor
	{
		recalc_M(); recalc_mu(); recalc_sma();
		needDelete = true;
	}

	binary::binary(ptMass *masses[]) : comp1(new ptMass), comp2(new ptMass), m1(comp1->mass), m2(comp2->mass), x1(comp1->x), y1(comp1->y), z1(comp1->z), vx1(comp1->vx), vy1(comp1->vy), vz1(comp1->vz), x2(comp2->x), y2(comp2->y), z2(comp2->z), vx2(comp2->vx), vy2(comp2->vy), vz2(comp2->vz)
	/// constructor with array of two pointers-to-ptMasses
	{
		comp1 = masses[0];					// assign the ptMasses pointers
		comp2 = masses[1];					// also for comp2
		recalc_M(); recalc_mu(); recalc_sma();
		needDelete = false;		
	}

	binary::binary(ptMass *a, ptMass *b) : comp1(new ptMass), comp2(new ptMass), m1(comp1->mass), m2(comp2->mass), x1(comp1->x), y1(comp1->y), z1(comp1->z), vx1(comp1->vx), vy1(comp1->vy), vz1(comp1->vz), x2(comp2->x), y2(comp2->y), z2(comp2->z), vx2(comp2->vx), vy2(comp2->vy), vz2(comp2->vz)
	/// constructor with two individual ptMass pointers
	{
		comp1 = a;							// assign the ptMasses pointers
		comp2 = b;							// also for comp2
		recalc_M(); recalc_mu(); recalc_sma();
		needDelete = false;
	}

	binary::~binary()
	/// destructor
	{
		if( needDelete )
		{
			delete comp1;
			delete comp2;
		}
	}

	double binary::calc_E()
	/// calculate internal binary energy, i.e. K + V
	{
		//Go into rest frame of mass 1 and calculate E	
		Vector3d muX = comp2->pos - comp1->pos;	// position of reduced mass relative to comp1
		Vector3d muV = comp2->vel - comp1->vel;	// velocity of reduced mass relative to comp1

		// assign new energy
		E = 0.5 * mu * muV.dot(muV) - G*mu*M/muX.norm();	// kinetic + potential
		return E;
	}


	bool binary::set_m1(double m)
	{
		if (m > 0) 
		{
			m1 = m;
			recalc_M(); recalc_mu();		
			return true;
		}
		return false;

	}

	bool binary::set_m2(double m)
	{
		if (m > 0) 
		{
			m2 = m;
			recalc_M(); recalc_mu(); recalc_sma();		
			return true;
		}
		return false;
	}

	bool binary::set_ecc(double ecc)
	{
		if (ecc >= 0) {e = ecc; return true;}
		else {return false;}
	}

	bool binary::set_a(double sma)
	{
		if (a > 0) 
		{
			a = sma; 
			recalc_sma();
			return true;
		}
		return false;
	}

	// test function for binary class
	void testBinary()
	{
		ptMass comp1, comp2;

		comp1.pos << 5,5,5;		
		comp1.vel << -1, 2, 3;
		comp2.vel << 1, 4, 1;

		binary b;
		b.set_m1(5);
	std::cout << "m1 from binary = " << comp1.mass << "\n";	 
		
	}

} // END namespace Astro
