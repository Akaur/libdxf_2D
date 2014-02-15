#include <iostream>
#include <stdlib.h>
#include "../include/dxf_2D.h" 

using namespace std;

int main()
{	
  dxf file("layer_line.dxf"); // name of output file
  
  /* write layer */
  layer newlayer("myLayer", 2, 40, "CONTINUOUS", file); 
  
  /* write line */
  point pt1(10,20), pt2(23,43);
  line pipe(pt1,pt2, "myLayer", file);
  
  file.save();
  return 0;
}
