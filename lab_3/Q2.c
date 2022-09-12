// Using OpenGL, draw the following figures. The dimensions of the various components in the figures can be considered as you wish, but the overall shape should be the same as the figures given here.
// Draw car


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define PI 22/7

void DrawCar(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		// bottom rectangle	
	glBegin(GL_POLYGON);				
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-0.6, 0);
		glVertex2f(0.6, 0);
		glVertex2f(0.6, -0.4);
		glVertex2f(-0.6, -0.4);
	glEnd();
	glFlush();


	glBegin(GL_POLYGON);				// upper quadrilateral		
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-0.3, 0.0);
		glVertex2f(0.6, 0.0);
		glVertex2f(0.45, 0.4);
		glVertex2f(-0.15, 0.4);
	glEnd();
	glFlush();


	double radius = 0.15;				// right wheel
	float x1 = 0.35, y1 = -0.4;
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for (float angle=0.0f; angle<=360; angle=angle+0.1)
		{
		    float x2 = x1 + cos(angle*PI/180.0)*radius;
		    float y2 = y1 + sin(angle*PI/180.0)*radius;
		    glVertex2f(x2,y2);
		}
	glEnd();
	glFlush();


	x1 = -0.25, y1 = -0.4;				// left wheel
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for (float angle=0.0f; angle<=360; angle=angle+0.1)
		{
		    float x2 = x1 + cos(angle*PI/180.0)*radius;
		    float y2 = y1 + sin(angle*PI/180.0)*radius;
		    glVertex2f(x2,y2);
		}
	glEnd();
	glFlush();


	glBegin(GL_LINES);					// lines
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.3, 0.0);
		glVertex2f(0.6, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.28, 0.02);
		glVertex2f(-0.14, 0.39);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.18, 0.39);
		glVertex2f(-0.14, 0.39);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.44, 0.39);
		glVertex2f(0.2, 0.39);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.44f, 0.39f);
		glVertex2f(0.58f, 0.02f);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.28f, 0.02f);
		glVertex2f(0.18f, 0.02f);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.2f, 0.02f);
		glVertex2f(0.58f, 0.02f);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.2f, 0.02f);
		glVertex2f(0.2f, 0.39f);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.18f, 0.02f);
		glVertex2f(0.18f, 0.39f);
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Car");
	glutDisplayFunc(DrawCar);
	glutMainLoop();
	return(0);
}