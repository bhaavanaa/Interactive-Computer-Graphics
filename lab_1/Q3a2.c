// Q3 a. Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle, and a point p(x, y), check if the point P lies inside the triangle. (Design and Implement at least two algorithms to solve the problem ).
// Algorithm 2
// This algorithm is better as the contant for O(n) for this algo, is less compared to the previous one, due to lesser number of operations in this algo.

#include<stdio.h>
#include<stdlib.h>


float area(int x1, int x2, int x3, int y1, int y2, int y3)
{
	float a = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.0;
	if(a < 0)
		return(-a);
	else
		return(a);
}


void main()
{
	float x1, x2, x3, y1, y2, y3;
	int px, py;

	printf("enter coordinates of vertex 1 : ");
	scanf("%f %f", &x1, &y1);
	printf("enter coordinates of vertex 2 : ");
	scanf("%f %f", &x2, &y2);
	printf("enter coordinates of vertex 3 : ");
	scanf("%f %f", &x3, &y3);
	printf("enter coordinates of point P : ");
	scanf("%d %d", &px, &py);

	float a1 = area(x1, x2, px, y1, y2, py);
	float a2 = area(x2, x3, px, y2, y3, py);
	float a3 = area(x3, x1, px, y3, y1, py);
	float sum = a1 + a2 + a3;

	float a = area(x1, x2, x3, y1, y2, y3);

	if(a == sum)
		printf("P is inside the triangle.\n");
	else
		printf("P is outside the triangle.\n");
}