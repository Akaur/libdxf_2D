/**
 *       \file      dxf_arc.cpp
 *
 *       \brief     This file define arc class. 
 *                  arc class is used to create arc entity.
 *
 *       \version   0.2
 *       \date      02/15/2014 02:05:23 PM
 *       Compiler   gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License   GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

# include "../include/dxf_2D.h"

/**
 *      \class  arc
 *      \fn     arc :: arc()
 *      \brief  Default constructor
 */
arc :: arc()
{
}

/**
 *      \class  arc
 *      \fn     arc :: arc(point& pt1, double r, double start_ang,
 *                         double end_ang, string dlayer, dxf& d)
 *      \brief  Initialize centre and radius of arc with start and 
 *              end angles, specify the layer and calls 
 *              write_Arc(xStart, yStart, zStart, radius, startAngle, endAngle, 
 *              layer) function of dxf class for writing arc to DXF file.
 */
arc :: arc(point& pt1, double r, double start_ang, double end_ang, 
           string dlayer, dxf& d)
{	
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;	
  radius = r;
  startAngle = start_ang;
  endAngle   = end_ang;
  layer      = dlayer;

  if (d.writeFile.is_open())
  {
    d.write_Arc(xStart, yStart, zStart, radius, startAngle, endAngle,
                layer);
  }
  else
    cout << "\n Arc Entity not write \n";	
}
