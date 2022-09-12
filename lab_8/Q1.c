// Q1. Implement Boundary Fill algorithm(with 4 neighbours) to display boundary of one rectangle and one triangle, given vertices, in red colour
// and then fill the rectangle with blue and triangle with yellow when the mouse click is done inside the regions.
// (Hint: Use (1) glutMouseFunc() to interface mouse with display system;
// (2) getPixel() to get the pixel colour at the given location from frame buffer )


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
int tx1, ty1, tx2, ty2, tx3, ty3;
int minrx, minry, maxrx, maxry;


void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,780,0,420);
}


int absolute(int a)
{
	if(a<0)
		return(-a);
	else
		return(a);
}


int triangle_check(int a, int b)
{
	float a1 = (float)absolute(tx1*(ty2-ty3)+tx2*(ty3-ty1)+tx3*(ty1-ty2))/2;
	float a2 = (float)absolute(a*(ty2-ty3)+tx2*(ty3-b)+tx3*(b-ty2))/2;
	float a3 = (float)absolute(tx1*(b-ty3)+a*(ty3-ty1)+tx3*(ty1-b))/2;
	float a4 = (float)absolute(tx1*(ty2-b)+tx2*(b-ty1)+a*(ty1-ty2))/2;

	// printf("%f %f %f %f\n", a1, a2, a3, a4);

	if(a1 == a2+a3+a4)
		return(1);
	else
		return(0);
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


void boundary_fill_4_rect(int x, int y, float fc[3], float bc[3])
{
	float clr[3];

	getPixel(x, y, clr);

	if((clr[0]!=bc[0] || clr[1]!=bc[1] || clr[2]!=bc[2]) && (clr[0]!=fc[0] || clr[1]!=fc[1] || clr[2]!=fc[2]))
	{
		glColor3fv(fc);
		glBegin(GL_POINTS);

		glVertex2f(x, y);
		glEnd();
      	glFlush();
		boundary_fill_4_rect(x+1, y, fc, bc);
		boundary_fill_4_rect(x-1, y, fc, bc);
		boundary_fill_4_rect(x, y+1, fc, bc);
		boundary_fill_4_rect(x, y-1, fc, bc);
	}
}


void boundary_fill_4_triangle(int x, int y, float fc[3], float bc[3])
{
	float clr[3];

	getPixel(x, y, clr);

	int t = triangle_check(x, y);

	// printf("%f %f %f %f %f %f %f %f %f\n", clr[0], clr[1], clr[2], bc[0], bc[1], bc[2], fc[0], fc[1], fc[2]);

	if((clr[0]!=bc[0] || clr[1]!=bc[1] || clr[2]!=bc[2]) && (clr[0]!=fc[0] || clr[1]!=fc[1] || clr[2]!=fc[2]))
	{
		glColor3fv(fc);
		glBegin(GL_POINTS);

		glVertex2f(x, y);
		glEnd();
      	glFlush();
		boundary_fill_4_triangle(x+1, y, fc, bc);
		boundary_fill_4_triangle(x-1, y, fc, bc);
		boundary_fill_4_triangle(x, y+1, fc, bc);
		boundary_fill_4_triangle(x, y-1, fc, bc);
	}
}


void diagram_rect_triangle()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1366, 0, 768);
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(rx1, ry1);
		glVertex2f(rx2, ry2);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(rx2, ry2);
		glVertex2f(rx3, ry3);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(rx3, ry3);
		glVertex2f(rx4, ry4);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(rx4, ry4);
		glVertex2f(rx1, ry1);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx1, ty1);
		glVertex2f(tx2, ty2);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx2, ty2);
		glVertex2f(tx3, ty3);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx3, ty3);
		glVertex2f(tx1, ty1);
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
			fc[0] = 0, fc[1] = 0; fc[2] = 1.0;

			int x1 = x, y1 = 768-y;

			minrx = min_rectangle(rx1, rx2, rx3, rx4);
			minry = min_rectangle(ry1, ry2, ry3, ry4);
			maxrx = max_rectangle(rx1, rx2, rx3, rx4);
			maxry = max_rectangle(ry1, ry2, ry3, ry4);

			// printf("%d %d %d %d\n", maxrx, maxry, minrx, minry);

			int t = triangle_check(x1, y1);			

			float bc1[3], fc1[3];
			bc1[0] = 1.0, bc1[1] = 0, bc1[2] = 0;
			fc1[0] = 1.0, fc1[1] = 1.0; fc1[2] = 0;

			// printf("\nclick coordinates : %d %d\n", x1, y1);

			if(x1>minrx && x1<maxrx && y1>minry && y1<maxry)
				boundary_fill_4_rect(x1, y1, fc, bc);

			else if(t == 1)
				boundary_fill_4_triangle(x1, y1, fc1, bc1);
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

	tx1 = 500;
	ty1 = 550;

	tx2 = 550;
	ty2 = 450;

	tx3 = 450;
	ty3 = 400;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	init();

	glutCreateWindow("Boundary fill 4 neighbours");

	glutDisplayFunc(diagram_rect_triangle);

	glutMouseFunc(mouse);

	glutMainLoop();

	return(0);
}