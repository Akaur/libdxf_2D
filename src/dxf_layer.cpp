/**
 *       \file      dxf_layer.cpp
 *
 *       \brief     This file define layer table section of DXF file structure. 
 *                  layer class is used to create layers.
 *
 *       \version   0.1
 *       \date      03/19/2014 04:12:23 PM
 *       Compiler   gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License   GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

# include "../include/dxf_2D.h"

/**
 *      \class  layer
 *      \fn     layer :: layer()
 *      \brief  Default constructor
 */
layer :: layer ()
{
}

/**
 *      \class  layer
 *      \fn     layer :: layer(string lname, int lcolor, int lwidth,
 *                             string ltype, dxf& d)
 *      \brief  Initialize layer attributes and calls 
 *              write_Layer(layerName, layerColor, layerWidth,
 *              layerLtype) function of dxf class for writing layer
 *              to DXF file.
 */
layer :: layer(string lname, int lcolor, int lwidth, string ltype, dxf& d)
{	
  layerName = lname;
  layerColor = lcolor;
  layerWidth = lwidth;	
  layerLtype = ltype;

  if (d.writeFile.is_open())
  {
    d.write_Layer(layerName, layerColor, layerWidth, layerLtype);
  }
  else
    cout << "\n Layer section not write \n";	
}
