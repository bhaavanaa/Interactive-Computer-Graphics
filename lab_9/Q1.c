// Implement Poly Fill algorithm in OpenGL to rasterise polygon region, and observe the effect of dropping horizontal edge, and also observe how vertical edges are displayed
// a. First implement the algorithm using the floating point operations inside any loop(ie using x=x+1/m)


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,780,0,420);
}


void polyfill()
{
	
}


void draw_diagram(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1366, 0, 768);
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(420, 400);
		glVertex2f(620, 600);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(620, 600);
		glVertex2f(820, 400);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(820, 400);
		glVertex2f(720, 200);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(720, 200);
		glVertex2f(620, 400);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(620, 400);
		glVertex2f(520, 200);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(520, 200);
		glVertex2f(420, 400);
	glEnd();

	glFlush();

	polyfill();
}








int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	init();
	glutCreateWindow("Polyfill");
	glutDisplayFunc(draw_diagram);
	glutMainLoop();
	return(0);
}