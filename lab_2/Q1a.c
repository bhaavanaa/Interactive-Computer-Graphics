// Using functions available in graphics.h, display the following - a. Point

#include <stdio.h>
#include <graphics.h>  
  
int main() 
{ 
    int gd = DETECT, gm, color; 				// gm is Graphics mode which is a computer display mode that generates image using pixels. DETECT is a macro defined in "graphics.h" header file 
   
    initgraph(&gd, &gm, ""); 					// initgraph initializes the graphics system by loading a graphics driver from disk
  
    putpixel(80, 30, GREEN); 
    putpixel(30, 25, RED); 
    putpixel(75, 40, YELLOW); 
    putpixel(45, 60, BLUE); 
    
    getch(); 
  
    closegraph(); 								// closegraph function closes the graphics mode and deallocates all memory allocated by graphics system
  
    return 0; 
} 