// Q2. Implement the Boundary Fill algorithm(with 8 neighbours) to display triangle with given vertices, and observe if leaking happens. 
// To fix the leaking, For each boundary point, make all four neighbours of it as boundary points, and then run the Boundary fill algorithm.


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>


int tx1, ty1, tx2, ty2, tx3, ty3;


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


void getPixel(int x, int y, float c[3])
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, c);
}


void boundary_fill_8_triangle(int x, int y, float fc[3], float bc[3])
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
		boundary_fill_8_triangle(x+1, y, fc, bc);
		boundary_fill_8_triangle(x-1, y, fc, bc);
		boundary_fill_8_triangle(x, y+1, fc, bc);
		boundary_fill_8_triangle(x, y-1, fc, bc);
		boundary_fill_8_triangle(x-1, y+1, fc, bc);
		boundary_fill_8_triangle(x+1, y+1, fc, bc);
		boundary_fill_8_triangle(x-1, y-1, fc, bc);
		boundary_fill_8_triangle(x+1, y-1, fc, bc);
	}
}


void diagram_triangle()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1366, 0, 768);
	glMatrixMode(GL_MODELVIEW);

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

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx1+1, ty1);
		glVertex2f(tx2+1, ty2);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx2+1, ty2);
		glVertex2f(tx3+1, ty3);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(tx3+1, ty3);
		glVertex2f(tx1+1, ty1);
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
		
			int x1 = x, y1 = 768-y;

			int t = triangle_check(x1, y1);			

			float bc1[3], fc1[3];
			bc1[0] = 1.0, bc1[1] = 0, bc1[2] = 0;
			fc1[0] = 1.0, fc1[1] = 1.0; fc1[2] = 0;

			// printf("\nclick coordinates : %d %d\n", x1, y1);

			if(t == 1)
				boundary_fill_8_triangle(x1, y1, fc1, bc1);
        }
    }
}


int main(int argc, char** argv)
{
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

	glutCreateWindow("Boundary fill 8 neighbours");

	glutDisplayFunc(diagram_triangle);

	glutMouseFunc(mouse);

	glutMainLoop();

	return(0);
}