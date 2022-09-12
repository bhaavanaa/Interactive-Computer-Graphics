// Q3. Draw Rectangle in Red colour, and implement the Flood Fill algorithm to replace the red colour region to green colour when a mouse click is done at a point inside the rectangle


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
int minrx, minry, maxrx, maxry;


void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,780,0,420);
}


int min_rectangle(int a, int b, int c, int d)
{
	if(a<=b && a<=c && a<=d)
		return(a);
	else if(b<=c && b<=a && b<=d)
		return(b);
	else if(c<=a && c<=b && c<=d)
		return(c);
	else
		return(d);
}


int max_rectangle(int a, int b, int c, int d)
{
	if(a>=b && a>=c && a>=d)
		return(a);
	else if(b>=c && b>=a && b>=d)
		return(b);
	else if(c>=a && c>=b && c>=d)
		return(c);
	else
		return(d);
}


void getPixel(int x, int y, float c[3])
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, c);
}


void flood_fill_4_rect(int x, int y, float fc[3], float bc[3])
{
	float clr[3];

	// printf("%f %f %f %f %f %f %f %f %f\n", clr[0], clr[1], clr[2], fc[0], fc[1], fc[2], bc[0], bc[1], bc[2]);

	getPixel(x, y, clr);

	if((clr[0]==bc[0] && clr[1]==bc[1] && clr[2]==bc[2]) && (clr[0]!=fc[0] || clr[1]!=fc[1] || clr[2]!=fc[2]))
	{
		glColor3fv(fc);
		glBegin(GL_POINTS);

		glVertex2f(x, y);
		glEnd();
      	glFlush();
		flood_fill_4_rect(x+1, y, fc, bc);
		flood_fill_4_rect(x-1, y, fc, bc);
		flood_fill_4_rect(x, y+1, fc, bc);
		flood_fill_4_rect(x, y-1, fc, bc);
	}
}


void diagram_rect()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1366, 0, 768);
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_POLYGON);				
		glColor3f(1.0, 0, 0);
		glVertex2f(rx1, ry1);
		glVertex2f(rx2, ry2);
		glVertex2f(rx3, ry3);
		glVertex2f(rx4, ry4);
	glEnd();
	glFlush();
}


void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
			float bc[3], fc[3];
			bc[0] = 1.0, bc[1] = 0, bc[2] = 0;
			fc[0] = 0, fc[1] = 1.0; fc[2] = 0;

			int x1 = x, y1 = 768-y;

			minrx = min_rectangle(rx1, rx2, rx3, rx4);
			minry = min_rectangle(ry1, ry2, ry3, ry4);
			maxrx = max_rectangle(rx1, rx2, rx3, rx4);
			maxry = max_rectangle(ry1, ry2, ry3, ry4);

			// printf("%d %d %d %d\n", maxrx, maxry, minrx, minry);

			// printf("\nclick coordinates : %d %d\n", x1, y1);

			if(x1>minrx && x1<maxrx && y1>minry && y1<maxry)
				flood_fill_4_rect(x1, y1, fc, bc);
        }
    }
}


int main(int argc, char** argv)
{
	rx1 = 150;
	ry1 = 250;

	rx2 = 150;
	ry2 = 300;

	rx3 = 250;
	ry3 = 300;

	rx4 = 250;
	ry4 = 250;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	init();

	glutCreateWindow("Flood fill 4 neighbours");

	glutDisplayFunc(diagram_rect);

	glutMouseFunc(mouse);

	glutMainLoop();

	return(0);
}