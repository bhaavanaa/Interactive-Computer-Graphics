// Write a C program using graphics.h to draw the following figure. The dimension of the primitives can be chosen as you wish.

#include<stdio.h>
#include <graphics.h>

int main() 
{ 
    int gd = DETECT, gm; 

    int arr[] = {200, 300, 400, 300, 300, 127, 200, 300};		// side length = 200

    initgraph(&gd, &gm, ""); 
  
    drawpoly(4, arr);
    circle(300, 242, 58);										// radius of incircle = 58
    circle(300, 242, 115); 										// radius of circumcircle = 115

    getch(); 
  
    closegraph(); 

    return(0);
} 