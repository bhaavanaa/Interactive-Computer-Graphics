// Q1. Implement DDA algorithm for drawing straight line and observe how the lines are drawn when the slope is close to 0, and also when close to infinity.


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>


int X0, Y0, X1, Y1;


float absolute(float x)
{
	if(x < 0)
		return(-x);
	else
		return(x);
}


void DDA()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	clock_t time_start, time_end;

	time_start = clock();

	int mx = X1 - X0;
	int my = Y1 - Y0;

	if(mx!=0 && absolute((float)my/mx)<=1)
	{
		int minx, miny, maxx, maxy;

		if(X0 <= X1)
		{
			minx = X0;
			miny = Y0;
			maxx = X1;
			maxy = Y1;
		}
		else
		{
			minx = X1;
			miny = Y1;
			maxx = X0;
			maxy = Y0;
		}

		float yf = miny;

		glVertex2f(minx, miny);

		float m = (float)my/mx;

		while(minx < maxx)
		{
			minx = minx + 1;
			yf = yf + m;
			int y = round(yf);
			glVertex2f(minx, y);
		}
	}
	else
	{
		int minx, miny, maxx, maxy;

		if(Y0 <= Y1)
		{
			minx = X0;
			miny = Y0;
			maxx = X1;
			maxy = Y1;
		}
		else
		{
			minx = X1;
			miny = Y1;
			maxx = X0;
			maxy = Y0;
		}

		float xf = minx;

		glVertex2f(minx, miny);

		float rm = (float)mx/my;

		while(miny < maxy)
		{
			miny = miny + 1;
			xf = xf + rm;
			int x = round(xf);
			glVertex2f(x, miny);
		}
	}	

	time_end = clock();

	printf("Time taken = %lf\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		
	glEnd();
	glFlush();
}

	
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	X0 = atoi(argv[1]);
	Y0 = atoi(argv[2]);
	X1 = atoi(argv[3]);
	Y1 = atoi(argv[4]);

	glutCreateWindow("DDA algorithm line");
	glutDisplayFunc(DDA);
	
	glutMainLoop();
	return(0);
}