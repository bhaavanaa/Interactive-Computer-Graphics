// Using OpenGL, draw the following figures. The dimensions of the various components in the figures can be considered as you wish, but the overall shape should be the same as the figures given here.
// Draw house


#include<stdio.h>
#include<GL/glut.h>


void DrawHouse(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glBegin(GL_TRIANGLES);				// roof triangle - pink
		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(-0.4, 0);
		glVertex2f(0.4, 0);
		glVertex2f(0, 0.8);
	glEnd();
	glFlush();


	glBegin(GL_POLYGON);				// house square - blue
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(-0.4, 0);
		glVertex2f(0.4, 0);
		glVertex2f(0.4, -0.8);
		glVertex2f(-0.4, -0.8);
	glEnd();
	glFlush();


	glBegin(GL_POLYGON);				// door rectangle - white		
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-0.1, -0.4);
		glVertex2f(0.1, -0.4);
		glVertex2f(0.1, -0.8);
		glVertex2f(-0.1, -0.8);
	glEnd();
	glFlush();


	glBegin(GL_POLYGON);				// left window square - white
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-0.3, -0.4);
		glVertex2f(-0.2, -0.4);
		glVertex2f(-0.2, -0.5);
		glVertex2f(-0.3, -0.5);
	glEnd();
	glFlush();


	glBegin(GL_POLYGON);				// right window square - white
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0.3, -0.4);
		glVertex2f(0.2, -0.4);
		glVertex2f(0.2, -0.5);
		glVertex2f(0.3, -0.5);
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("House");
	glutDisplayFunc(DrawHouse);
	glutMainLoop();
	return(0);
}