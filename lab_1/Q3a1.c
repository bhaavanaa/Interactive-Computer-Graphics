// Q3 a. Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle, and a point p(x, y), check if the point P lies inside the triangle. (Design and Implement at least two algorithms to solve the problem ).
// Algorithm 1


#include<stdio.h>


void main()
{
	float x1, x2, x3, y1, y2, y3, a, b, c, f, g, h;
	int px, py;
	printf("enter coordinates (x1, y1) : ");
	scanf("%f %f", &x1, &y1);
	printf("enter coordinates (x2, y2) : ");
	scanf("%f %f", &x2, &y2);
	printf("enter coordinates (x3, y3) : ");
	scanf("%f %f", &x3, &y3);
	printf("enter coordinates of P : ");
	scanf("%d %d", &px, &py);

	if((y2 - y1) > 0)															// wrt AB for P
		f = ((y2 - y1) * px) - ((x2 - x1) * py) + (x2 * y1) - (x1 * y2);
	else
		f = -(((y2 - y1) * px) - ((x2 - x1) * py) + (x2 * y1) - (x1 * y2));

	if((y2 - y1) > 0)															// wrt AB for C
		c = ((y2 - y1) * x3) - ((x2 - x1) * y3) + (x2 * y1) - (x1 * y2);
	else
		c = -(((y2 - y1) * px) - ((x2 - x1) * py) + (x2 * y1) - (x1 * y2));

	if((y3 - y2) > 0)															// wrt BC for P
		g = ((y3 - y2) * px) - ((x3 - x2) * py) + (x3 * y2) - (x2 * y3);
	else
		g = -(((y3 - y2) * px) - ((x3 - x2) * py) + (x3 * y2) - (x2 * y3));

	if((y3 - y2) > 0)															// wrt BC for A
		a = ((y3 - y2) * x1) - ((x3 - x2) * y1) + (x3 * y2) - (x2 * y3);
	else
		a = -(((y3 - y2) * x1) - ((x3 - x2) * y1) + (x3 * y2) - (x2 * y3));

	if((y1 - y3) > 0)															// wrt CA for P
		h = ((y1 - y3) * px) - ((x1 - x3) * py) + (x1 * y3) - (x3 * y1);
	else
		h = -(((y1 - y3) * px) - ((x1 - x3) * py) + (x1 * y3) - (x3 * y1));

	if((y1 - y3) > 0)															// wrt CA for B
		b = ((y1 - y3) * x2) - ((x1 - x3) * y2) + (x1 * y3) - (x3 * y1);
	else
		b = -(((y1 - y3) * x2) - ((x1 - x3) * y2) + (x1 * y3) - (x3 * y1));

	if(f*c >= 0 && g*a >= 0 && h*b >= 0)
		printf("P is inside the triangle.\n");
	else
		printf("P is outside the triangle.\n");
}