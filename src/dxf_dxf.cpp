/**
 *       \file      dxf_dxf.cpp
 *
 *       \brief     This file define dxf class.
 *                  dxf class is used to draw multiple entites in a  DXF file.
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
 *      \class  dxf
 *      \fn     dxf :: dxf()
 *      \brief  Default constructor
 */
dxf :: dxf ()
{
}

/**
 *      \class  dxf
 *      \fn     dxf :: dxf(string filename)
 *      \brief  Constructor opens the filename for writing and writes DXF 
 *              header to it. 
 */
dxf  :: dxf (string filename)
{	
  dxf_filename = filename;
  writeFile.open(dxf_filename.c_str());
  read_Header();
}

/**
 *      \class  dxf
 *      \fn     dxf :: save()
 *      \brief  Constructor closes DXF file after writing DXF footer to it. 
 */
void dxf :: save()
{	
  read_Footer();
  writeFile.close();
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Line(double xStart, double yStart, double zStart, 
 *                                double xEnd, double yEnd, double zEnd, 
 *                                string layer)
 *      \brief  Writes line entity to DXF file.
 */
void dxf :: write_Line(double xStart, double yStart, double zStart, double xEnd,
                       double yEnd, double zEnd, string layer)
{	
  writeFile << " 0 \nLINE"
               "\n 5 \n43"
               "\n 100 \nAcDbEntity"
               "\n 100 \nAcDbLine"
               "\n 8 \n" << layer <<
               "\n 62 \n256"
               "\n 370 \n-1"
               "\n 6 \nByLayer"
               "\n 10 \n" << xStart <<
               "\n 20 \n" << yStart << 
               "\n 30 \n" << zStart <<
               "\n 11 \n" << xEnd << 
               "\n 21 \n" << yEnd <<
               "\n 31 \n" << zEnd <<
               "\n";
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Circle(double xStart, double yStart, double zStart, 
 *                                  double radius, string layer)
 *      \brief  Writes circle entity to DXF file
 */
void dxf :: write_Circle(double xStart, double yStart, double zStart,
                         double radius, string layer)
{
  writeFile << " 0 \nCIRCLE \n 5 \n43"
               "\n 100 \nAcDbEntity"
               "\n 100 \nAcDbCircle"
               "\n 8 \n" << layer << "\n 62 \n256"
               "\n 370 \n-1 \n 6 \nByLayer "
               "\n 10 \n" << xStart << 
               "\n 20 \n" << yStart << 
               "\n 40 \n" << radius <<
               "\n";
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Circle(double xStart, double yStart, double zStart,
 *                                  double radius, string layer, int flag, 
 *                                  int color)
 *      \brief  Writes circle (solid fill) entity to DXF file by calling 
 *              write_Hatch_Start(flag, pattern_name, color), 
 *              write_Hatch_Circle(xStart, yStart, zStart, radius), 
 *              write_Hatch_End() and write_Circle(xStart, yStart, zStart,
 *              radius, layer)	
 */
void dxf :: write_Circle(double xStart, double yStart, double zStart, 
                         double radius, string layer, 
                         int flag, int color)
{
  pattern_name = "SOLID";
  edges        = 1;
  edge_type    = 2;

  write_Hatch_Start(flag, pattern_name, color);
  write_Hatch_Circle(xStart, yStart, zStart, radius);
  write_Hatch_End();	
  write_Circle(xStart, yStart, zStart, radius, layer);	
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Circle(double xStart, double yStart, double zStart, 
 *                                  double radius, string layer, int flag, 
 *                                  string pattern_name, int color)
 *      \brief  Writes circle (pattern fill) entity to DXF file by calling 
 *              write_Hatch_Start(flag, pattern_name, color), 
 *              write_Hatch_Circle(xStart, yStart, zStart, radius), 
 *              write_Hatch_End() and write_Circle(xStart, yStart, zStart,
 *              radius, layer)
 */
void dxf :: write_Circle(double xStart, double yStart, double zStart,
                         double radius, string layer, 
                         int flag, string pattern_name, int color)
{	
  edges     = 1;
  edge_type = 2;

  write_Hatch_Start(flag, pattern_name, color);
  write_Hatch_Circle(xStart, yStart, zStart, radius);
  write_Hatch_End();
  write_Circle(xStart, yStart, zStart, radius, layer);	
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Hatch_Circle(double xStart, double yStart, 
 *                                        double zStart, double radius)
 *      \brief  Writes  hatch circle entity to DXF file.
 */
void dxf :: write_Hatch_Circle(double xStart, double yStart, double zStart,
                               double radius)
{
  writeFile << " 10 \n" << xStart <<
               "\n 20 \n" << yStart <<
               "\n 40 \n" << radius <<
               "\n";
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Rect(double xStart, double yStart, double zStart, 
 *                                double xEnd, double yEnd, double zEnd,
 *                                string layer)
 *      \brief  Writes rectangle entity to DXF file.
 */
void dxf :: write_Rect(double xStart, double yStart, double zStart,
                       double xEnd, double yEnd, double zEnd, string layer)
{
  writeFile << "0\nLWPOLYLINE"
               " \n 5 \n43"
               " \n 100 \nAcDbEntity"
               " \n 100 \nAcDbPolyLine"
               " \n 8 \n" << layer << "\n 62 \n256"
               " \n 90 \n4 \n 70 \n1 \n 43 \n0.0" 
               " \n 10 \n" << xStart <<
               " \n 20 \n" << yStart << 
               " \n 10 \n" << xStart <<
               " \n 20 \n" <<  yEnd << 
               " \n 10 \n" << xEnd <<
               " \n 20 \n" << yEnd << 
               " \n 10 \n" << xEnd << 
               " \n 20 \n" <<yStart<< 
               " \n" ;
}

/**
 *      \class  dxf
 *      \fn     dxf :: write_Rect(double xStart, double yStart, double zStart, 
 *                                double xEnd, double yEnd, double zEnd, 
 *                                string layer, int flag, int color)
 *      \brief  Writes rectangle (solid fill) entity to DXF file by calling
 *              write_Hatch_Start(flag, pattern_name, color), 
 *              write_Hatch_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd), 
 *              write_Hatch_End() and write_Rect(xStart, yStart, zStart, xEnd, 
 *              yEnd, zEnd, layer)
 */
void dxf :: write_Rect(double xStart, double yStart, double zStart,
                       double xEnd, double yEnd, double zEnd, string layer, 
                       int flag, int color)
{
  pattern_name = "SOLID";
  edges        = 4;
  edge_type    = 1;

  write_Hatch_Start(flag, pattern_name, color);
  write_Hatch_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd);
  write_Hatch_End();	
  write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer);
}



/**
 *      \class  dxf
 *      \fn     dxf :: write_Rect(double xStart, double yStart, double zStart, 
 *                                double xEnd, double yEnd, double zEnd, 
 *                                string layer, int flag, string pattern_name, 
 *                                int color)
 *      \brief  Writes rectangle (pattern fill) entity to DXF file by calling 
 *              write_Hatch_Start(flag, pattern_name, color), 
 *              write_Hatch_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd), 
 *              write_Hatch_End() and write_Rect(xStart, yStart, zStart, xEnd, 
 *              yEnd, zEnd, layer)
 */
void dxf :: write_Rect(double xStart, double yStart, double zStart,
                       double xEnd, double yEnd, double zEnd, string layer, 
                       int flag, string pattern_name, int color)
{	
  edges     = 4;
  edge_type = 1;
  
  write_Hatch_Start(flag, pattern_name, color);
  write_Hatch_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd);
  write_Hatch_End();
  write_Rect(xStart, yStart, zStart, xEnd, yEnd, zEnd, layer);
}

/** 
 *      \class  dxf
 *      \fn     dxf :: write_Hatch_Rect(double xStart, double yStart, 
 *                                      double zStart, double xEnd, double yEnd, 
 *                                      double zEnd)
 *      \brief  Writes  hatch rectangle entity to DXF file
 */
void dxf :: write_Hatch_Rect(double xStart, double yStart, double zStart,
                             double xEnd, double yEnd, double zEnd)
{
  writeFile << "10 \n" << xStart <<
               "\n 20 \n" << yStart <<
               "\n 11 \n" << xStart <<
               "\n 21 \n" << yEnd <<
               "\n 72 \n1"
               "\n 10 \n" << xStart <<
               "\n 20 \n" << yEnd <<
               "\n 11 \n" << xEnd <<
               "\n 21 \n" << yEnd <<
               "\n 72 \n1"
               "\n 10 \n" << xEnd <<
               "\n 20 \n" << yEnd <<
               "\n 11 \n" << xEnd <<
               "\n 21 \n" << yStart <<
               "\n 72 \n1"
               "\n 10 \n" << xEnd <<
               "\n 20 \n" << yStart <<
               "\n 11 \n" << xStart <<
               "\n 21 \n" << yStart <<
               "\n";
}
