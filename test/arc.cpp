#include <iostream>
#include <stdlib.h>
#include "../include/dxf_2D.h" 

using namespace std;

int main()
{	
  dxf file("arc_design.dxf"); // name of output file

  point	centre(14,14);
  int radius = 16, start_ang = 43, end_ang = 94;
 
  // draw arc
  arc round(centre, radius, start_ang, end_ang, "Layer1", file);

  file.save();
  return 0;
}
