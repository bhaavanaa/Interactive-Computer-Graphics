// Qc. Write a C/OpenGl program to plot all the points with integer coordinates in the upper half 
// of the circular disc with radius and center at (0, 0).


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int r;													// radius of the circular disc


void draw_semicircle()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);							// setting the color of the point as white
	gluOrtho2D(-780, 780, -420, 420);	
	
	glBegin(GL_POINTS);

		for(int i=-r; i<=r; i++)						// for every point in the range of -r to r for x
		{
			for(int j=0; j<=r; j++)						// for every point in the range of 0 to r for y since it is only the upper half of the circular disc
			{
				int p = i*i + j*j - r*r;				// check if the point is inside the circle
				
				if(p <= 0)								// if p<=0, then point lies inside or on the circle
				{
					glVertex2f(i, j);					// hence plot the point
				}
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

	printf("Enter the radius of the circle 'r' : ");	// obtain the radius of the circular disc from the user
	scanf("%d", &r);

	glutCreateWindow("Semicircle");
	glutDisplayFunc(draw_semicircle);
	
	glutMainLoop();
	return(0);
}
