/**
 *       \file      dxf_point.cpp
 *
 *       \brief     This file defines point class.
 *                  point class is used to initialize xCo, yCo and zCo 
 *                  coordinates of point.
 *
 *       \version   0.1
 *       \date      03/19/2013 09:30:23 PM
 *       Compiler   gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License   GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

# include "../include/dxf_2D.h"

/**
 *      \class  point
 *      \fn     point :: point()
 *      \brief  Default constructor
 */
point :: point()
{
}

/**
 *      \class  point
 *      \fn     point :: point()
 *      \brief  Initializes xCo, yCo, zCo coordintes of point
 */
point :: point(double x, double y, double z)
{
  xCo = x;
  yCo = y;
  zCo = z;
}
