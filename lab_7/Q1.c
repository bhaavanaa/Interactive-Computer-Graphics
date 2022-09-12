// Q1. Given the centre (a, b) and radius r, display circle( in red colour) 
// centered at (a, b) and with radius r using midpoint circle drawing algorithm.


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int a, b, r;


void MCDA_circle()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	int x = 0;
	int y = r;
	int d = 1 - r;

	glVertex2f(x+a, y+b);

	while(y > x)
	{
		if(d < 0)						// east
			d = d + 2*x + 3;
		else							// south east												
		{
			d = d + 2*(x - y) + 5;
			y = y - 1;
		}
		x = x + 1;
		glVertex2f(x+a, y+b);
		glVertex2f(x+a, -y+b);
		glVertex2f(-x+a, y+b);
		glVertex2f(-x+a, -y+b);
		glVertex2f(y+a, x+b);
		glVertex2f(y+a, -x+b);
		glVertex2f(-y+a, x+b);
		glVertex2f(-y+a, -x+b);
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
	r = atoi(argv[3]);

	glutCreateWindow("Midpoint circle drawing algorithm circle");
	glutDisplayFunc(MCDA_circle);
	
	glutMainLoop();
	return(0);
}