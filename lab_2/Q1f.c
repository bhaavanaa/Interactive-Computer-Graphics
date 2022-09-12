// Using functions available in graphics.h, display the following - f. Rectangle

#include<stdio.h>
#include <graphics.h> 

int main() 
{ 
    int gd = DETECT, gm; 
 
    int left = 150, top = 150, right = 400, bottom = 340; 			// location of left, top, right, bottom (x1, y1, x3, y3)

    initgraph(&gd, &gm, ""); 
  
    rectangle(left, top, right, bottom); 

    getch(); 
  
    closegraph(); 

    return(0);
} 