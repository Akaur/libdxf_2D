/**
 *       \file      dxf_circle.cpp
 *
 *       \brief     This file define circle class. 
 *                  circle class is used to create circle entity with or 
 *                  without hatching.
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
 *      \class  circle
 *      \fn     circle :: circle()
 *      \brief  Default constructor
 */
circle :: circle ()
{
}

/**
 *      \class  circle
 *      \fn     circle :: circle(point& pt1, double r, string dlayer, dxf& d)
 *      \brief  Initializes starting point and radius of circle, specify the 
 *              layer and calls write_Circle(xStart, yStart, zStart, radius, 
 *              layer) function of dxf class for writing circle to DXF file.
 */
circle :: circle(point& pt1, double r, string dlayer, dxf& d)
{	
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;	
  radius = r;
  layer  = dlayer;

  if (d.writeFile.is_open())
  {
    d.write_Circle(xStart, yStart, zStart, radius, layer);
  }
  else
    cout << "\n Circle Entity not write \n";	
}

/**
 *      \class  circle
 *      \fn     circle :: circle(point& pt1, double r, string dlayer, dxf& d, 
 *                               int hflag, int hcolor)
 *      \brief  Initialize starting point and radius of circle, specify the 
 *              layer, flag = 1 for solid fill and calls write_Circle(xStart,
 *              yStart, zStart, radius, layer, flag, color) function 
 *              of dxf class for writing circle (solid fill) entity to DXF file.
 */
circle :: circle (point& pt1, double r,string dlayer, dxf& d, int hflag, 
                  int hcolor)
{
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;
  radius = r;
  layer  = dlayer;
  flag   = hflag;
  color  = hcolor;
  pattern_name = "SOLID";

  if (d.writeFile.is_open())
  {
    d.write_Circle(xStart, yStart, zStart, radius, layer, flag, color);
  }
  else
    cout << "\n Circle (solid fill) entity not write \n";
}

/**
 *      \class  circle
 *      \fn     circle :: circle(point& pt1, double r, string dlayer, dxf& d, 
 *                               int hflag, string p_name, int hcolor)
 *      \brief  Initialize starting point and radius of circle,
 *              specify the layer,  flag = 0 for pattern fill and calls
 *              write_Circle(xStart, yStart, zStart, radius, layer, 
 *              flag, pattern_name, color) function of dxf class for writing 
 *              circle (pattern fill) entity to DXF file.
 */
circle :: circle (point& pt1, double r, string dlayer, dxf& d, int hflag, 
                  string p_name, int hcolor)
{
  xStart  = pt1.xCo;
  yStart  = pt1.yCo;
  zStart  = pt1.zCo;
  radius  = r;
  layer   = dlayer;
  flag    = hflag;
  pattern_name = p_name;
  color   = hcolor;

  if (d.writeFile.is_open())
  {
    d.write_Circle(xStart, yStart, zStart, radius, layer, flag, pattern_name,
                   color);
  }
  else
    cout << "\n Circle (pattern fill) entity not write \n";
}
