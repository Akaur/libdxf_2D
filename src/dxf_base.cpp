/**
 *       \file      dxf_base.cpp
 *
 *       \brief     This file define base class.
 *                  base class is used to write header, footer and 
 *                  common hatching part to DXF file.
 *
 *       \version   0.1
 *       \date      03/19/2013 09:30:23 PM
 *       Compiler  gcc
 *
 *       \author    Avneet Kaur, kauravneet958@gmail.com
 *        License  GNU General Public License
 *      \copyright  Copyright (c) 2013, GreatDevelopers
 *                  https://github.com/GreatDevelopers
 */

# include "../include/dxf_2D.h"

/** 
 *      \class  base
 *      \fn     base :: read_HeaderClass()
 *      \brief  Open "dxf_headerclass.txt" file for reading and write
 *              the header and class sections to DXF file.
 */
void base :: read_HeaderClass()
{	
  name = "./src/dxf_headerclass.txt";
  readFile.open(name.c_str());
  
  if ((writeFile.is_open()) && (readFile.is_open()))
  {	
    while (getline(readFile, readwrite, '\n'))
    {  
      writeFile << readwrite << endl;
    }
    readFile.close();  
  }
  else
    cout << "\n No header and class sections write \n";
}

/** 
 *      \class  base
 *      \fn     base :: read_TableBlock()
 *      \brief  Opens "dxf_tableblock.txt" file for reading and write
 *              the table and block sections to DXF file.
 */
void base :: read_TableBlock()
{
  name = "./src/dxf_tableblock.txt";
  readFile.open(name.c_str());
  
  if ((writeFile.is_open()) && (readFile.is_open()))
  {	
    while (getline(readFile, readwrite, '\n'))
    {  
      writeFile << readwrite << endl;
    }
    readFile.close();  
  }
  else
    cout << "\n No header and class sections write \n";
}

/** 
 *      \class  base
 *      \fn     base :: read_Footer()
 *      \brief  Opens "dxf_footer.txt" for reading and writes the footer 
 *              of DXF file
 */
void base :: read_Footer()
{	
  name = "./src/dxf_footer.txt";
  readFile.open(name.c_str());

  if ((writeFile.is_open()) && (readFile.is_open()))
  {	
    while (getline(readFile, readwrite, '\n' ))
    {  
      writeFile << readwrite << endl ;
    } 
    readFile.close();
  }
  else 
    cout << "\n No footer write \n";
}

/**
 *      \class  base
 *      \fn     base :: write_Hatch_Start(int flag,string pattern_name, int color)
 *      \brief  Writes the common start part of hatch entity to the
 *              the entity section of DXF output file.
 */
void base :: write_Hatch_Start(int flag, string pattern_name, int color)
{   
  writeFile << "0 \nHATCH \n 8 \n0" 
               "\n 62 \n" << color <<
               "\n 370 \n-1 \n 6 \nByLayer"
               "\n 100 \nAcDbEntity" 
               "\n 100 \nAcDbHatch"
               "\n 2 \n" << pattern_name <<
               "\n 70 \n" << flag << 
               "\n 91 \n1 \n 92 \n1"
               "\n 93 \n" << edges <<
               "\n 72 \n" << edge_type <<
               "\n";
}
	
/**
 *      \class  base
 *      \fn     base :: write_Hatch_End()
 *      \brief  Writes the common end part of hatch entity to the
 *      entity section of output DXF file
 */
void base :: write_Hatch_End()
{
  writeFile << "50 \n0.0 \n 51 \n360.0"
               "\n 97 \n0 \n 52 \n60"
               "\n 41 \n1.0 \n";
}
