#include <iostream>
#include <stdlib.h>
#include "../include/dxf_2D.h" 

using namespace std;

int main()
{	
  dxf file("beam_design.dxf");   // name of output file

  int beamWidth  = 300;	         // beam width
  int beamDepth	= 600;	         // beam depth
  int diaSteelComp = 16;         // diameter of steel comp
  int radSteelComp = diaSteelComp/2;		
  int diaSteelTension = 25;      // diameter of steel tension
  int radSteelTension = diaSteelTension/2;		
  int noSteelComp    = 9;       // no. of steel comp
  int noSteelTension = 4;       // no. of steel tension
  int clearCover = 40;          // clearcover
  double xTension = clearCover + radSteelTension;
  double yTension = clearCover + radSteelTension;
  double xComp = clearCover + radSteelComp ;
  double yComp = beamDepth - (clearCover + radSteelComp);

  point	pt1(0,0),
        pt2(beamWidth, beamDepth);

  rectangle beam( pt1, pt2, "Layer1", file);

  point	pt3(clearCover,clearCover),
        pt4((beamWidth - clearCover), (beamDepth - clearCover));

  rectangle stirrup(pt3, pt4, "Layer1", file);
		
  circle *Tension[noSteelTension]; 		
  for (int i = 0; i < noSteelTension; i++)
  {	
    point ptTension(xTension, yTension);
    Tension[i] = new circle(ptTension, radSteelTension, "Layer1", file,
                            1, 1);
    xTension = xTension + 65.3;
  }

  circle *Comp[noSteelComp];
  for (int i = 0; i < noSteelComp; i++)
  {	
    point ptComp(xComp, yComp);
    Comp[i] = new circle(ptComp, radSteelComp, "Layer1", file, 1, 1);
    xComp = xComp + 102;

    if (xComp > (beamWidth - clearCover))
    {	
      yComp = yComp - 30;
      xComp = 102;		
    }			
  }
  file.save();
  return 0;
}
