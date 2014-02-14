/**
 *       \file      dxf_rect.cpp
 *
 *       \brief     This file define rectangle class.
 *                  rectangle class is used to create rectangle with or without
 *                  hatching.
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
 *      \class  rectangle
 *      \fn     rectangle :: rectangle()
 *      \brief  Default constructor
 */
rectangle :: rectangle()
{
}

/**
 *      \class  rectangle
 *      \fn     rectangle :: rectangle(point& pt1, point& pt2, string dlayer, 
 *                                     dxf& d)
 *      \brief  Initializes starting and ending points of rectangle, specify 
 *              the layer and calls write_Rect(xStart, yStart, zStart, xEnd, 
 *              yEnd, zEnd, layer) function of dxf class for writing rectangle
 *              entity to DXF file
 */
rectangle :: rectangle (point& pt1, point& pt2, string dlayer, dxf& d)
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
    d.write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer);
  }
  else
    cout << "\n Rectangle entity not write \n";
}

/**
 *      \class  rectangle
 *      \fn     rectangle :: rectangle(point& pt1, point& pt2, string dlayer, 
 *                                     dxf&, int hflag, int hcolor)
 *      \brief  Initialize starting and ending points of rectangle,
 *              specify the layer, flag = 1 for solid fill and calls
 *              write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer, 
 *              flag, color) function of dxf class for writing rectangle (solid
 *              fill) entity to DXF file
 */
rectangle :: rectangle (point& pt1, point& pt2, string dlayer, dxf& d, int hflag, 
                        int hcolor)
{
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;
  xEnd   = pt2.xCo;
  yEnd   = pt2.yCo;
  zEnd   = pt2.zCo;
  layer  = dlayer;
  flag   = hflag;
  color  = hcolor;
  pattern_name = "SOLID";

  if (d.writeFile.is_open())
  {
    d.write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer, flag, 
                 color);
  }
  else
    cout << "\n Rectangle (solid fill) entity not write \n";
}

/**
 *      \class  rectangle
 *      \fn     rectangle :: rectangle(point& pt1, point& pt2, string dlayer, 
 *                                     string filename, int hflag, 
 *                                     string p_name, int hcolor)
 *      \brief Initialize starting and ending points of rectangle,
 *              specify the layer, flag = 0 for pattern fill and calls
 *              write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer, 
 *              flag, pattern_name, color) function of dxf class for writing
 *              rectangle(pattern fill) entity to DXF file.
 */
rectangle :: rectangle (point& pt1, point& pt2, string dlayer, dxf& d, int hflag, 
                        string p_name, int hcolor)
{
  xStart = pt1.xCo;
  yStart = pt1.yCo;
  zStart = pt1.zCo;
  xEnd   = pt2.xCo;
  yEnd   = pt2.yCo;
  zEnd   = pt2.zCo;
  layer  = dlayer;
  flag   = hflag;
  pattern_name = p_name;
  color  = hcolor;
 
  if (d.writeFile.is_open())
  {
    d.write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer, flag, 
                 pattern_name, color);
  }
  else
    cout << "\n Rectangle (pattern fill) entity not write \n";
}
