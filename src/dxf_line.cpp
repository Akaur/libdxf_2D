/**
 *       \file      dxf_line.cpp
 *
 *       \brief     This file define line class.
 *                  line class is used to create line entity.
 *
 *       \version   0.1
 *       \date      03/19/2013 09:10:35 PM
 *       Compiler   gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License   GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

# include "../include/dxf_2D.h" 

/**
 *      \class  line
 *      \fn     line :: line()
 *      \brief  Default constructor
 */
line :: line()
{
}

/**
 *      \class  line
 *      \fn     line :: line(point& pt1, point& pt2, string dlayer, dxf& d)
 *      \brief  Initializes starting and ending points of line, specify the 
 *              layer and calls write_Line(xStart, yStart, zStart, xEnd, yEnd, 
 *              zEnd, layer) function of dxf class for writing line entity to 
 *              DXF file
 */
line :: line (point& pt1, point& pt2, string dlayer, dxf& d)
{	
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;
  xEnd   = pt2.xCo;
  yEnd   = pt2.yCo;
  zEnd   = pt2.zCo;
  layer  = dlayer;

  if (d.writeFile.is_open())
  {
    d.write_Line(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer);
  }
  else
    cout << "\n Line entity not write \n";
}
