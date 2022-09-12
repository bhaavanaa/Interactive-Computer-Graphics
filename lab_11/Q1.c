// Q1. Given n 2D points (xi, yi), for 1<=i<=n, and a clipping rectangle with diagonal vertices, (xmin, ymin) and (xmax, ymax), 
// display(in red) the points that are inside the rectangle


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int xmin, ymin, xmax, ymax, n=10000;


void draw_points()
{
	srand(time(NULL));

	int X, Y;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 0, 0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

		for(int i=0; i<n; i++)
		{
			X = rand()%500-100;
			Y = rand()%500-100;
			if(X<xmax && X>xmin && Y<ymax && Y>ymin)
			{
				glColor3f(1.0, 0, 0);
				glVertex2f(X, Y);
			}
			else
			{
				glColor3f(0, 0, 1.0);
				glVertex2f(X, Y);
			}
		}
		
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	int x1, y1, x2, y2;

	printf("Enter the coordinates of one diagonal vertex: ");
	scanf("%d %d", &x1, &y1);

	printf("Enter the coordinates of the other diagonal vertex: ");
	scanf("%d %d", &x2, &y2);

	if(x1 <= x2)
	{
		xmin = x1;
		xmax = x2;
		ymin = y1;
		ymax = y2;
	}
	else
	{
		xmin = x2;
		xmax = x1;
		ymin = y2;
		ymax = y1;
	}

	glutCreateWindow("Display points inside rectangle");
	glutDisplayFunc(draw_points);
	
	glutMainLoop();
	return(0);
}