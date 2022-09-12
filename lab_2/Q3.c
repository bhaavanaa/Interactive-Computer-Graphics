// Write a C program using graphics.h to draw the following smiley.

#include<stdio.h>
#include <graphics.h>

int main() 
{ 
    int gd = DETECT, gm; 

    int left = 250, top = 340, right = 350, bottom = 350;

    initgraph(&gd, &gm, ""); 

  	setcolor(YELLOW);							// main circle
   	circle(300, 300, 100);
   	floodfill(300, 300, YELLOW);

   	setcolor(BLACK);							// left eye
   	circle(260, 275, 20);
   	floodfill(260, 275, BLACK);

   	circle(340, 275, 20);						// right eye
   	floodfill(340, 275, BLACK);

   	setcolor(BLACK);							// mouth
   	rectangle(left, top, right, bottom); 
   	floodfill(251, 341, BLACK);

    getch(); 
  
    closegraph(); 

    return(0);
} 