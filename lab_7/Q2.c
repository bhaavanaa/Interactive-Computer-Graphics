// Q2. Given the centre (h, k), a half length of major axis ‘a’ and a half length of minor axis ‘b’, 
// display Ellipse(in Yellow colour) centered at (h, k) and with major axis length 2a and minor axis length 2b using midpoint ellipse drawing algorithm .


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int h= 10, k=20, a=100, b=200, i=200, j=300;


void MEDA_ellipse()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);

	int x = 0;
	int y = b;
	int sa = a*a;
	int sb = b*b;
	int d1 = sb - sa*b + 0.25*sa;

	glVertex2f(x+h, y+k);
	glVertex2f(x+h, -y+k);
	glVertex2f(-x+h, y+k);
	glVertex2f(-x+h, -y+k);

	while(sa*(y-0.5) > sb*(x+1))
	{
		if(d1 < 0)							// east
			d1 = d1 + sb*((x<<1)+3);
		else 							    // south east
		{
			d1 = d1 + sb*((x<<1)+3) + sa*(-(y<<1)+2);
			y = y - 1;
		}
		x = x + 1;

		glVertex2f(x+h, y+k);
		glVertex2f(x+h, -y+k);
		glVertex2f(-x+h, y+k);
		glVertex2f(-x+h, -y+k);
	}

	int d2 = sb*(x+0.5)*(x+0.5) + sa*(y-1)*(y-1) - sa*sb;

	while(y > 0)
	{
		if(d2 < 0)							// south east
		{
			d2 = d2 + sb*((x<<1)+2) + sa*(-(y<<1)+3);
			x = x + 1;
		}
		else 								// south
			d2 = d2 + sa*(-(y<<1)+3);
		y = y - 1;

		glVertex2f(x+h, y+k);
		glVertex2f(x+h, -y+k);
		glVertex2f(-x+h, y+k);
		glVertex2f(-x+h, -y+k);
	}

	glBegin(GL_POINTS);
		glVertex2f(i, j);					// hence plot the point
		
	glEnd();
	glFlush();

	glEnd();
	glFlush();
}

	
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	// h = atoi(argv[1]);
	// k = atoi(argv[2]);
	// a = atoi(argv[3]);
	// b = atoi(argv[4]);

	glutCreateWindow("Midpoint ellipse drawing algorithm ellipse");
	glutDisplayFunc(MEDA_ellipse);
	
	glutMainLoop();
	return(0);
}