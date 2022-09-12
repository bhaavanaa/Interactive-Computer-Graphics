// Qa. Given lengths of major and minor axes, and also the centre of an ellipse, 
// write a program in C or OpenGl to check if the given point P is inside the ellipse.


#include<stdio.h>
#include<math.h>


int h, k;			// center of the ellipse		
int a, b;			// length of major and minor axes of the ellipse
int X, Y;			// point to be evaluated


int main()
{
	printf("Enter the coordinates of the centre of the ellipse h, k : ");		// obtaining the coordinates of the center
	scanf("%d %d", &h, &k);

	printf("Enter the lengths of the major and minor axes a, b : ");			// obtaining the lengths of major and minor axes
	scanf("%d %d", &a, &b);

	printf("Enter the coordinates of the point X, Y : ");						// obtaining the coordinates of the point to be evaluated
	scanf("%d %d", &X, &Y);

	float p = ((float)((X-h)*(X-h))/((a/2)*(a/2))) + ((float)((Y-k)*(Y-k))/((b/2)*(b/2)));		// calculating (x-h)^2/a1^2 + (y-k)^2/b1^2  where a1=a/2, b1=b/2
	// printf("%f\n", p);

	if(p <= 1)																	// if point is inside or on the ellipse, then 'p' <= 1
	{
		printf("Point is inside the ellipse\n");
	}
	else 																		// else the point is outside the ellipse
	{
		printf("Point is not inside the ellipse\n");
	}
}