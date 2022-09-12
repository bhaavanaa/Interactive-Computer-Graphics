// Q4 a. Given three vertices: (x1, y1), (x2, y2) and (x3, y3) of a triangle, find integer coordinates of all points inside or on the triangle.


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


float area(int x1, int x2, int x3, int y1, int y2, int y3)
{
	float a = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.0;
	if(a < 0)
		return(-a);
	else
		return(a);
}


int check(float x1, float x2, float x3, float y1, float y2, float y3, int px, int py)
{
	float a1 = area(x1, x2, px, y1, y2, py);
	float a2 = area(x2, x3, px, y2, y3, py);
	float a3 = area(x3, x1, px, y3, y1, py);
	float sum = a1 + a2 + a3;

	float a = area(x1, x2, x3, y1, y2, y3);

	if(a == sum)
		return(1);
	else
		return(0);
}


void main()
{
	float x1, x2, x3, y1, y2, y3, maxx, maxy;

	printf("enter coordinates of vertex 1 : ");
	scanf("%f %f", &x1, &y1);
	printf("enter coordinates of vertex 2 : ");
	scanf("%f %f", &x2, &y2);
	printf("enter coordinates of vertex 3 : ");
	scanf("%f %f", &x3, &y3);

	if(x1 >= x2 && x1 >= x3)
		maxx = x1;
	else if(x2 >= x3 && x2 >= x1)
		maxx = x2;
	else
		maxx = x3;

	if(y1 >= y2 && y1 >= y3)
		maxy = y1;
	else if(y2 >= y3 && y2 >= y1)
		maxy = y2;
	else
		maxy = y3;

	printf("The points on or inside the triangle are-\n");
	for(int i = 0; i <= maxx; i++)
	{
		for(int j = 0; j <= maxy; j++)
		{
			if(check(x1, x2, x3, y1, y2, y3, i, j) == 1)
				printf("(%d, %d)\n", i, j);
		}
	}
}