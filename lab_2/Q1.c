#include <stdio.h>
#include <graphics.h>  
 

void point1() 
{ 
    int gd = DETECT, gm, color; 				// gm is Graphics mode which is a computer display mode that generates image using pixels. DETECT is a macro defined in "graphics.h" header file 
   
    initgraph(&gd, &gm, ""); 					// initgraph initializes the graphics system by loading a graphics driver from disk
  
    putpixel(80, 30, GREEN); 
    putpixel(30, 25, RED); 
    putpixel(75, 40, YELLOW); 
    putpixel(45, 60, BLUE); 
    
    getch(); 
  
    closegraph(); 								// closegraph function closes the graphics mode and deallocates all memory allocated by graphics system
} 


void line1() 
{ 
    int gd = DETECT, gm; 
  
    initgraph(&gd, &gm, ""); 
  
    
    line(150, 150, 450, 150); 				// line for x1, y1, x2, y2 
   
    line(150, 200, 450, 200); 				// line for x1, y1, x2, y2
  
    line(150, 250, 450, 250); 				// line for x1, y1, x2, y2

    line(150, 300, 450, 300); 				// line for x1, y1, x2, y2 
  
    getch(); 
  
    closegraph(); 
} 


void circle1() 
{ 
    int gd = DETECT, gm; 
  
    initgraph(&gd, &gm, ""); 
  
    circle(200, 200, 100);					// (x1, y1) of centre, radius

    getch(); 
  
    closegraph(); 
} 


void ellipse1() 
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
} 


void triangle1() 
{ 
    int gd = DETECT, gm; 

    int arr[] = {300, 120, 350, 200, 200, 350, 300, 120}; 

    initgraph(&gd, &gm, ""); 
  
    drawpoly(4, arr);

    getch(); 
  
    closegraph(); 
} 


void rectangle1() 
{ 
    int gd = DETECT, gm; 
 
    int left = 150, top = 150, right = 400, bottom = 340; 			// location of left, top, right, bottom (x1, y1, x3, y3)

    initgraph(&gd, &gm, ""); 
  
    rectangle(left, top, right, bottom); 

    getch(); 
  
    closegraph(); 
}


int main() 
{ 
   int x; 

	printf("Enter 1-Point,\n2-Line,3-Circle\n4-Ellipse\n5-Triangle\n6-Rectangle\n7-exit\nEnter your option: ");
	scanf("%d", &x);

	switch(x)
	{ 
		case 1: printf("Option is point\n"); 
		       	point1(); 
		       	break;
		case 2: printf("Option is line\n"); 
		       	line1(); 
		       	break;
		case 3: printf("Option is circle\n"); 
		       	circle1();
		       	break;
		case 4: printf("Option is ellipse\n"); 
		       	ellipse1();
		       	break;
		case 5: printf("Option is triangle\n"); 
		       	triangle1();
		       	break;
		case 6: printf("Option is rectangle\n"); 
		       	rectangle1();
		       	break;
		default: printf("Option other than the above\n"); 
		         break;   
	} 
	return 0; 
}  