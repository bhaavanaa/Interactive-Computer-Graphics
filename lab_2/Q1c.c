// Using functions available in graphics.h, display the following - c. Circle

#include<stdio.h>
#include <graphics.h> 

int main() 
{ 
    int gd = DETECT, gm; 
  
    initgraph(&gd, &gm, ""); 
  
    circle(200, 200, 100);

    getch(); 
  
    closegraph(); 

    return(0);
} 