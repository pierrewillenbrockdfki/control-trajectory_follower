/*
 * =====================================================================================
 *
 *       Filename:  TrajectoryControllerNoOrientation.cpp
 *
 *    Description:  Implementation of trajectory controller without orientation control
 *    				from 'Springer handbook of robotics' chapter 34 pg 805
 *
 *        Version:  1.0
 *        Created:  10/13/09 10:30:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ajish Babu, ajish.babu@dfki.de
 *        Company:  DFKI
 *
 * =====================================================================================
 */

#include "TrajectoryControllerNoOrientation.hpp"

using namespace trajectory_follower;

noOrientation::noOrientation ()
{
}  /* -----  end of method noOrientation::noOrientation  (constructor)  ----- */


	void 
noOrientation::setConstants(float l1_val, float K0_val, float R_val, float r_val, double ul, double ll)
{
	l1 = l1_val;
	K0 = K0_val;

	R = R_val;
	r = r_val;

	u_limit = ul; // radians per second
	l_limit = ll; // radians per second 
} 


	float
noOrientation::k (float theta_e )
{
	// k(d,theta_e) = 0 * cos(theta_e)
	return K0 * cos(theta_e);
}		/* -----  end of method noOrientation::k  ----- */


        Eigen::Vector2d	
noOrientation::update (float u1, float d, float theta_e )
{
	double u2 = (-u1*tan(theta_e) / l1) - ( (u1 * k(theta_e) * d) / cos(theta_e));

	vel_right = limit((u1 + R*u2) / r);
	vel_left  = limit((u1 - R*u2) / r);

	return Eigen::Vector2d(u1, u2);
}		/* -----  end of method noOrientation::update  ----- */


        double	
noOrientation::limit ( float val )
{
	if (val > u_limit)
	    return u_limit;
	else if (val < l_limit)
	    return l_limit;
	else
	    return val;
}