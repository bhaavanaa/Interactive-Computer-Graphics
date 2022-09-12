// Given the parameter of a and b of ellipse x = a cos(theta); y = b sin(theta), 
// plot the points (round(x), round(y)) for theta varies from 0 to 2*PI, with various step sizes and observe the quality of the plot. 
// Also check if circle is plotted when a=b.


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define PI 3.14159265358979323846

int a, b;

void draw_point5()
{
	int step_size = 5;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	for(float k=0.0f; k<=360; k=k+step_size)
	{
		float x = a*cos(k*PI/180.0);
		float y = b*sin(k*PI/180.0);
		glVertex2f(round(x), round(y));
	}
		
	glEnd();
	glFlush();
}


void draw_point4()
{
	int step_size = 4;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	for(float k=0.0f; k<=360; k=k+step_size)
	{
		float x = a*cos(k*PI/180.0);
		float y = b*sin(k*PI/180.0);
		glVertex2f(round(x), round(y));
	}
		
	glEnd();
	glFlush();
}


void draw_point3()
{
	int step_size = 3;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	for(float k=0.0f; k<=360; k=k+step_size)
	{
		float x = a*cos(k*PI/180.0);
		float y = b*sin(k*PI/180.0);
		glVertex2f(round(x), round(y));
	}
		
	glEnd();
	glFlush();
}


void draw_point1()
{
	int step_size = 1;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	for(float k=0.0f; k<=360; k=k+step_size)
	{
		float x = a*cos(k*PI/180.0);
		float y = b*sin(k*PI/180.0);
		glVertex2f(round(x), round(y));
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

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	glutCreateWindow("Ellipse-step_size-5");
	glutDisplayFunc(draw_point5);
	
	glutCreateWindow("Ellipse-step_size-4");
	glutDisplayFunc(draw_point4);

	glutCreateWindow("Ellipse-step_size-3");
	glutDisplayFunc(draw_point3);
	
	glutCreateWindow("Ellipse-step_size-1");
	glutDisplayFunc(draw_point1);
	glutMainLoop();
	return(0);
}