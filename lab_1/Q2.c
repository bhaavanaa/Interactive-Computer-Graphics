// Given two points (x1, y1) and (x2, y2) of a line, and also a point P(x, y), check if P lies below or above or on the line


#include<stdio.h>


void main()
{
	float x1, x2, y1, y2, a;
	int px, py;
	printf("enter coordinates (x1, y1) : ");
	scanf("%f %f", &x1, &y1);
	printf("enter coordinates (x2, y2) : ");
	scanf("%f %f", &x2, &y2);
	printf("enter coordinates of P : ");
	scanf("%d %d", &px, &py);

	if((y2 - y1) > 0)
		a = ((y2 - y1) * px) - ((x2 - x1) * py) + (x2 * y1) - (x1 * y2);
	else
		a = -(((y2 - y1) * px) - ((x2 - x1) * py) + (x2 * y1) - (x1 * y2));		

	if(a < 0)
		printf("P is below the line.\n");
	else if(a > 0)
		printf("P is above the line.\n");
	else
		printf("P is on the line.\n");
}