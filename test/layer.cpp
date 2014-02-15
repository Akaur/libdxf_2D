#include <iostream>
#include <stdlib.h>
#include "../include/dxf_2D.h" 

using namespace std;

int main()
{
  /* Create DXF file */
  dxf file("layer_line.dxf"); // name of output file
  
  /* write multiple layers */
  layer outer("myLayer", 2, 40, "CONTINUOUS", file);
  layer inner("yourLayer", 3, 5, "DASHED", file);
  
  /* Draw entities */
  file.draw();
  point pt1(10,20), pt2(23,43), pt3(45,12);
  line pipe1(pt1,pt2, "myLayer", file);
  line pipe2(pt1,pt3, "yourLayer", file);
  
  /* save file */
  file.save();
  return 0;
}
