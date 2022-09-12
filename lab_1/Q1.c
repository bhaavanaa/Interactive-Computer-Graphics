// Q1. Given four corners of a rectangle, and also a point P, check if P lies inside the rectangle.


#include<stdio.h>
#include<stdlib.h>


float area(float x1, float x2, float x3, float y1, float y2, float y3)
{
	float a = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.0;
	if(a < 0)
		return(-a);
	else 
		return(a);
}


void main()
{
	float x1, x2, x3, x4, y1, y2, y3, y4;
	int px, py;

	printf("enter coordinates of vertex 1 : ");
	scanf("%f %f", &x1, &y1);
	printf("enter coordinates of vertex 2 : ");
	scanf("%f %f", &x2, &y2);
	printf("enter coordinates of vertex 3 : ");
	scanf("%f %f", &x3, &y3);
	printf("enter coordinates of vertex 4 : ");
	scanf("%f %f", &x4, &y4);
	printf("enter coordinates of point P : ");
	scanf("%d %d", &px, &py);

	float a1 = area(x1, x2, px, y1, y2, py);
	float a2 = area(x2, x3, px, y2, y3, py);
	float a3 = area(x3, x4, px, y3, y4, py);
	float a4 = area(x4, x1, px, y4, y1, py);
	float sum = a1 + a2 + a3 + a4;

	float a = 2 * area(x1, x2, x3, y1, y2, y3);
	
	if(a == sum)
		printf("P is inside the rectangle.\n");
	else
		printf("P is outside the rectangle.\n");
}