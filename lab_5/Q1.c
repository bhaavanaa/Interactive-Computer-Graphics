// Given the end points (x1, y1) and (x2, y2) of a line segment, find slope m, and y-intercept b.
// Compute the value of y=mx+b for each integer value of x starting from x1 to x2 and plot (round(x), round(y)) with the step size 5. 
// Repeat the plotting for step size 4, step size 3, step, size 1. 
// What do you observe on these 5 plots
// a. When m>1, check if your program works
// b. When line segment is horizontal or vertical, check if your program works


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x1, yy1, x2, y2;


float absolute(float a)
{
	if(a<0)
		return(-a);
	else
		return(a);
}

float minimum(float a, float b)
{
	if(a<=b)
		return(a);
	else
		return(b);
}


float maximum(float a, float b)
{
	if(a>=b)
		return(a);
	else
		return(b);
}


void draw_point5()
{
	int mx = x2 - x1;
	int my = y2 - yy1;

	int step_size = 5;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

		if(mx == 0)
		{
			float b = 0;
			printf("slope m = inf, y-intercept b = %f\n", b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				glVertex2f(round(x1), round(y));
			}
		}

		else if(my == 0)
		{
			float m = 0;
			float b = yy1;
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = yy1;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)<=1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = m*x + b;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)>1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				float x = (y - b)/m;
				glVertex2f(round(x), round(y));
			}
		}		
		
	glEnd();
	glFlush();
}


void draw_point4()
{
	int mx = x2 - x1;
	int my = y2 - yy1;

	int step_size = 4;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

		if(mx == 0)
		{
			float b = 0;
			printf("slope m = inf, y-intercept b = %f\n", b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				glVertex2f(round(x1), round(y));
			}
		}

		else if(my == 0)
		{
			float m = 0;
			float b = yy1;
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = yy1;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)<=1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = m*x + b;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)>1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				float x = (y - b)/m;
				glVertex2f(round(x), round(y));
			}
		}			
		
	glEnd();
	glFlush();
}


void draw_point3()
{
	int mx = x2 - x1;
	int my = y2 - yy1;

	int step_size = 3;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

		if(mx == 0)
		{
			float b = 0;
			printf("slope m = inf, y-intercept b = %f\n", b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				glVertex2f(round(x1), round(y));
			}
		}

		else if(my == 0)
		{
			float m = 0;
			float b = yy1;
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = yy1;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)<=1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = m*x + b;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)>1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				float x = (y - b)/m;
				glVertex2f(round(x), round(y));
			}
		}		
		
	glEnd();
	glFlush();
}


void draw_point1()
{
	int mx = x2 - x1;
	int my = y2 - yy1;

	int step_size = 1;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

		if(mx == 0)
		{
			float b = 0;
			printf("slope m = inf, y-intercept b = %f\n", b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				glVertex2f(round(x1), round(y));
			}
		}

		else if(my == 0)
		{
			float m = 0;
			float b = yy1;
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = yy1;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)<=1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int x=minimum(x1, x2); x<=maximum(x1, x2); x=x+step_size)
			{
				float y = m*x + b;
				glVertex2f(round(x), round(y));
			}
		}

		else if(absolute((float)my/mx)>1)
		{
			float m = (float)my/mx;
			float b = yy1 - (m * x1);
			printf("slope m = %f, y-intercept b = %f\n", m, b);

			for(int y=minimum(yy1, y2); y<=maximum(yy1, y2); y=y+step_size)
			{
				float x = (y - b)/m;
				glVertex2f(round(x), round(y));
			}
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

	x1 = atoi(argv[1]);
	yy1 = atoi(argv[2]);
	x2 = atoi(argv[3]);
	y2 = atoi(argv[4]);

	glutCreateWindow("Line-step_size-5");
	glutDisplayFunc(draw_point5);
	
	glutCreateWindow("Line-step_size-4");
	glutDisplayFunc(draw_point4);

	glutCreateWindow("Line-step_size-3");
	glutDisplayFunc(draw_point3);
	
	glutCreateWindow("Line-step_size-1");
	glutDisplayFunc(draw_point1);
	glutMainLoop();
	return(0);
}