// Using functions available in graphics.h, display the following - e. Triangle

#include<stdio.h>
#include <graphics.h> 

int main() 
{ 
    int gd = DETECT, gm; 

    int arr[] = {300, 120, 350, 200, 200, 350, 300, 120}; 

    initgraph(&gd, &gm, ""); 
  
    drawpoly(4, arr);

    getch(); 
  
    closegraph(); 

    return(0);
} 