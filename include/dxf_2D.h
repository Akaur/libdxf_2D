/**
 *
 *       \file      dxf_2D.h
 *              
 *       \details   This is a header file that declare classes for creating 2D 
 *                  drawings.    
 *
 *       \version   0.2
 *       \date      03/19/2013 01:34:03 PM
 *       Compiler   gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License   GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

/**
 *        \class  base
 *        \brief  Base class defines functions for DXF header, footer and
 *                hatching section.
 */
class base 						 
{
  protected:
    double  xStart,         /**< x-coordinate of starting point(x1, y1, z1) */
            yStart,         /**< y-coordinate of starting point(x1, y1, z1) */
            zStart,         /**< z-coordinate of starting point(x1, y1, z1) */
            xEnd,           /**< x-coordinate of ending point(x2, y2, z2) */
            yEnd,           /**< y-coordinate of ending point(x2, y2, z2) */
            zEnd,           /**< z-coordinate of ending point(x2, y2, z2) */
            xMid,           /**< x-coordinate of center(x, y) for circle */
            yMid,           /**< y-coordinate of center(x, y) for circle */
            radius,         /**< radius of circle */
            startAngle,     /**< start angle of arc */
            endAngle;       /**< end angle of arc */
    ifstream readFile;      /**< object for reading files */
    int     flag,           /**< flag  for hatching */
            edges,          /**< edges of boundary path */
            edge_type,      /**< boundary edge type */
	    color,          /**< color-code[1-256] */
            layerColor,     /**< layer color */
            layerWidth;     /**< layer thickness */ 
    string  dxf_filename,   /**< output dxf filename */
            readwrite,      /**< reads from input file and writes to output file */
            pattern_name,   /**< pattern name for pattern hatching */
            name,           /**< input filename for reading */
            layer,          /**< layer[0-5] */
            layerName,      /**< layer name */
            layerLtype;     /**< layer linetype */

  public :
   ofstream writeFile;      /**< object for writing files */
   
  /// Read DXF header and class sections
  void read_HeaderClass();

  /// Read DXF table and block sections
  void read_TableBlock();

  /// Reads DXF EOF section
  void read_Footer();
	    
  /// Writes Hatch entity start part
  void write_Hatch_Start(int, string, int);
	    
  /// Writes hatch entity end part
  void write_Hatch_End();
};

/**
 *        \class  point
 *        \brief  Point entity class
 */
class point
{
  public:	    
    double  xCo,        /**< x-coordinate of point(x, y, z) */
            yCo,        /**< y-coordinate of point(x, y, z) */
            zCo;        /**< z-coordinate of point(x, y, z) */

  /// Default constructor
  point();
	
  /// Parameterized constructor, default value of z is set to 0.	
  point(double, double y, double z = 0);
};

/**
 *        \class  dxf
 *        \brief  Draw entities in DXF file
 */
class dxf :  public base
{
  public:
  /// Default constructor
  dxf();
	
  /// Parameterised constructor
  dxf(string);

  /// Draw section
  void draw();

  /// Save DXF file
  void save();

  /// Layer section
  void write_Layer(string, int, int, string);

  /// Line entity
  void write_Line(double, double, double, double, double, double,
                  string);

  /// Arc entity
  void write_Arc(double, double, double, double, double, double,
                 string);

  /// Circle entity
  void write_Circle(double, double, double, double, string);

  /// Circle (solid fill) entity
  void write_Circle(double, double, double, double, string, int, int);

  /// Circle (pattern fill) entity
  void write_Circle(double, double, double, double, string, int,
                    string, int);

  /// Hatch circle entity
  void write_Hatch_Circle(double, double, double, double);

  /// Rectangle entity
  void write_Rect(double, double, double, double, double, double, 
                  string);

  /// Rectangle (solid fill)  entity
  void write_Rect(double, double, double, double, double, double,
                  string, int, int);

  /// Rectangle (pattern fill) entity
  void write_Rect(double, double, double, double, double, double, 
                  string, int, string, int);

  /// Hatch rectangle entity
  void write_Hatch_Rect(double, double, double, double, double, 
                        double);
};

/**
 *        \class  layer
 *        \brief  Layer section class
 */
class layer : public base
{
  public :
  /// Default constructor
  layer();

  /// Parameterized constructor
  layer(string, int, int, string, dxf&);
};

/**
 *        \class  line
 *        \brief  Line entity class
 */
class line : public base
{
  public :
  /// Default constructor
  line();

  /// Parameterized constructor
  line(point&, point&,string, dxf&);
};

/**
 *        \class arc
 *        \brief Arc entity class
 */
class arc : public base
{
  public :
  /// Default constructor
  arc();

  /// Parameterized constructor
  arc(point&, double, double, double, string, dxf&);
};

/**
 *        \class  circle
 *        \brief  Circle entity class
 */
class circle : public base
{
  public :
  /// Default constructor
  circle();

  /// Parameterized constructor
  circle(point&, double, string, dxf&);

  /// Parameterized constructor for solid fill.
  circle(point&, double, string, dxf&, int hflag, int hcolor = 256); 

  /// Parameterized constructor for pattern fill
  circle(point&, double, string, dxf&, int hflag, string p_name, 
         int hcolor = 256);		
};

/**
 *        \class  rectangle
 *        \brief  Rectangle entity class
 */
class rectangle : public base
{
  public :
  /// Default constructor
  rectangle();

  /// Parameterized constructor
  rectangle(point&, point&, string, dxf&); 

  /// Parameterized constructor for solid fill
  rectangle(point&, point&, string, dxf&, int hflag, 
            int hcolor = 256); 

  /// Parameterized constructor
  rectangle(point&, point&, string, dxf&, int hflag, string p_name, 
            int hcolor = 256);	
};
