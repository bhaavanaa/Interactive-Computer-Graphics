// Q2. Implement midpoint line drawing algorithm and display one line segment in each of the eight octants.


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


void MLDA()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	int flag, new_x0, new_y0, new_x1, new_y1;

	int mx = X1 - X0;
	int my = Y1 - Y0;

	float slope;
	clock_t time_start, time_end;

	time_start = clock();

	if(mx == 0)
	{
		slope = 999;
	}
	else
	{
		slope = (float)my/mx;
	}

	if(0 <= slope && slope <= 1)
	{
		new_x0 = X0;
		new_y0 = Y0;
		new_x1 = X1;
		new_y1 = Y1;
		flag = 0;
	}
	else if(1 < slope)
	{
		new_x0 = Y0;
		new_y0 = X0;
		new_x1 = Y1;
		new_y1 = X1;
		flag = 1;
	}
	else if(-1 >= slope)
	{
		new_x0 = -Y0;
		new_y0 = X0;
		new_x1 = -Y1;
		new_y1 = X1;
		flag = 2;
	}
	else if(-1 <= slope && slope <= 0)
	{
		new_x0 = -X0;
		new_y0 = Y0;
		new_x1 = -X1;
		new_y1 = Y1;
		flag = 3;
	}
	else if(0 < slope && slope <= 1)
	{
		new_x0 = -X0;
		new_y0 = -Y0;
		new_x1 = -X1;
		new_y1 = -Y1;
		flag = 4;
	}
	else if(1 < slope)
	{
		new_x0 = -Y0;
		new_y0 = -X0;
		new_x1 = -Y1;
		new_y1 = -X1;
		flag = 5;
	}
	else if(slope < -1)
	{
		new_x0 = Y0;
		new_y0 = -X0;
		new_x1 = Y1;
		new_y1 = -X1;
		flag = 6;
	}
	else
	{
		new_x0 = X0;
		new_y0 = -Y0;
		new_x1 = X1;
		new_y1 = -Y1;
		flag = 7;
	}

	// printf("%d %d %d %d %d %f\n", new_x0, new_y0, new_x1, new_y1, flag, slope);

	int minx, miny, maxx, maxy;

	if(new_x0 <= new_x1)
	{
		minx = new_x0;
		miny = new_y0;
		maxx = new_x1;
		maxy = new_y1;
	}
	else
	{
		minx = new_x1;
		miny = new_y1;
		maxx = new_x0;
		maxy = new_y0;
	}

	int dx = maxx - minx;
	int dy = maxy - miny;

	int d = 2*dy - dx;

	int de = 2*dy;
	int dne = 2*(dy - dx);

	int x = minx;
	int y = miny;

	//printf("Flag = %d\n", flag);

	if(flag == 0)
	{
		//printf("(%d, %d)\n", x, y);
		glVertex2f(x, y);
	}
	else if(flag==1)
	{
		//printf("(%d, %d)\n", y, x);
		glVertex2f(y, x);
	}
	else if(flag==2)
	{
		//printf("(%d, %d)\n", y, -x);
		glVertex2f(y, -x);
	}
	else if(flag==3)
	{
		//printf("(%d, %d)\n", -x, y);
		glVertex2f(-x, y);
	}
	else if(flag==4)
	{
		//printf("(%d, %d)\n", -x, -y);
		glVertex2f(-x, -y);
	}
	else if(flag==5)
	{
		//printf("(%d, %d)\n", -y, -x);
		glVertex2f(-y, -x);
	}
	else if(flag==6)
	{
		//printf("(%d, %d)\n", -y, x);
		glVertex2f(-y, x);
	}
	else
	{
		//printf("(%d, %d)\n", x, -y);
		glVertex2f(x, -y);
	}

	while(x < maxx)
	{
		if(d <= 0)
		{
			d = d + de;
		}
		else
		{
			d = d + dne;
			y = y + 1;
		}
		x = x + 1;

		if(flag == 0)
		{
			//printf("(%d, %d)\n", x, y);
			glVertex2f(x, y);
		}
		else if(flag==1)
		{
			//printf("(%d, %d)\n", y, x);
			glVertex2f(y, x);
		}
		else if(flag==2)
		{
			//printf("(%d, %d)\n", y, -x);
			glVertex2f(y, -x);
		}
		else if(flag==3)
		{
			//printf("(%d, %d)\n", -x, y);
			glVertex2f(-x, y);
		}
		else if(flag==4)
		{
			//printf("(%d, %d)\n", -x, -y);
			glVertex2f(-x, -y);
		}
		else if(flag==5)
		{
			//printf("(%d, %d)\n", -y, -x);
			glVertex2f(-y, -x);
		}
		else if(flag==6)
		{
			//printf("(%d, %d)\n", -y, x);
			glVertex2f(-y, x);
		}
		else
		{
			//printf("(%d, %d)\n", x, -y);
			glVertex2f(x, -y);
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

	glutCreateWindow("Midpoint line drawing algorithm line");
	glutDisplayFunc(MLDA);
	
	glutMainLoop();
	return(0);
}