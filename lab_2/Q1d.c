// Using functions available in graphics.h, display the following - d. Ellipse

#include<stdio.h>
#include <graphics.h> 

int main() 
{ 
    int gd = DETECT, gm; 
  
    int x = 300, y = 200; 						// location of ellipse 
  
    int start_angle = 0; 						// start and end angles
    int end_angle = 360; 
   
    int x_rad = 100; 							// radius from x axis and y axis
    int y_rad = 40; 

    initgraph(&gd, &gm, ""); 
  
    ellipse(x, y, start_angle, end_angle, x_rad, y_rad); 

    getch(); 
  
    closegraph(); 

    return(0);
} 