// Using functions available in graphics.h, display the following - b. Line

#include<stdio.h>
#include <graphics.h> 
   
int main() 
{ 
    int gd = DETECT, gm; 
  
    initgraph(&gd, &gm, ""); 
  
    
    line(150, 150, 450, 150); 				// line for x1, y1, x2, y2 
   
    line(150, 200, 450, 200); 				// line for x1, y1, x2, y2
  
    line(150, 250, 450, 250); 				// line for x1, y1, x2, y2

    line(150, 300, 450, 300); 				// line for x1, y1, x2, y2 
  
    getch(); 
  
    closegraph(); 

    return(0);
} 