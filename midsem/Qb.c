// Qb. Write a C/OpenGl program to plot sinx


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define PI 3.14159265358979323846


int amplitude;											// amplitude of the wave
int x_start, x_end;										// start and end 'x' values of the sine wave


void draw_sine()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);							// setting the color of the point as white
	gluOrtho2D(-780, 780, -420, 420);	
	
	glBegin(GL_POINTS);	

		for(float k=x_start; k<=x_end; k=k+1)			// running with step size 1 for plotting the value of sin(x)
		{
			float x = k;
			float y = amplitude*sin(k*PI/180.0);		// sin(theta) 
			glVertex2f(round(x), round(y));				// plotting the point
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

	printf("Enter the amplitude of the sine wave : ");
	scanf("%d", &amplitude);

	printf("Enter the start and end values of 'x' of the sine wave : ");
	scanf("%d %d", &x_start, &x_end);

	glutCreateWindow("Sine wave");
	glutDisplayFunc(draw_sine);
	
	glutMainLoop();
	return(0);
}
