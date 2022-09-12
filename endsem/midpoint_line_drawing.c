// Q. Given a line segment, not necessarily in one octant completely, implement midpoint line drawing algorithm to draw the line.


// import the required libraries
#include<stdio.h>		
#include<GL/glut.h>
#include<math.h>


// initialize the endpoints of line as global variables
int X0, Y0, X1, Y1;


// function to draw the line using midpoint line drawing algorithm
void MLDA()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	
	glBegin(GL_POINTS);	

	int flag, new_x0, new_y0, new_x1, new_y1; 		// flag-to set the octant where the line is present, new variables are the points transformed to the octant 0

	int mx = X1 - X0;								// difference in x coordinates
	int my = Y1 - Y0;								// difference in y coordinates

	float slope;
	
	if(mx == 0)										
	{
		slope = 999;								// if the slope is infinite, initialize it as 0 (to avoid error)	
	}
	else
	{
		slope = (float)my/mx;						// else it is the slope of the line
	}

	if(0 <= slope && slope <= 1)			// 0th octant
	{
		new_x0 = X0;
		new_y0 = Y0;
		new_x1 = X1;
		new_y1 = Y1;
		flag = 0;
	}
	else if(1 < slope)						// 1st octant
	{
		new_x0 = Y0;
		new_y0 = X0;
		new_x1 = Y1;
		new_y1 = X1;
		flag = 1;
	}
	else if(-1 >= slope)					// 2nd octant
	{
		new_x0 = -Y0;
		new_y0 = X0;
		new_x1 = -Y1;
		new_y1 = X1;
		flag = 2;
	}
	else if(-1 <= slope && slope <= 0)		// 3rd octant
	{
		new_x0 = -X0;
		new_y0 = Y0;
		new_x1 = -X1;
		new_y1 = Y1;
		flag = 3;
	}
	else if(0 < slope && slope <= 1)		// 4th octant
	{
		new_x0 = -X0;
		new_y0 = -Y0;
		new_x1 = -X1;
		new_y1 = -Y1;
		flag = 4;
	}
	else if(1 < slope)						// 5th octant
	{
		new_x0 = -Y0;
		new_y0 = -X0;
		new_x1 = -Y1;
		new_y1 = -X1;
		flag = 5;
	}
	else if(slope < -1)						// 6th octant
	{
		new_x0 = Y0;
		new_y0 = -X0;
		new_x1 = Y1;
		new_y1 = -X1;
		flag = 6;
	}
	else									// 7th octant
	{
		new_x0 = X0;
		new_y0 = -Y0;
		new_x1 = X1;
		new_y1 = -Y1;
		flag = 7;
	}

	// printf("%d %d %d %d %d %f\n", new_x0, new_y0, new_x1, new_y1, flag, slope);

	int minx, miny, maxx, maxy;				// set the minx, miny and maxx, maxy based on the x coordinates

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

	int dx = maxx - minx;					// difference in the x coordinates
	int dy = maxy - miny;					// difference in the y coordinates

	int d = 2*dy - dx;						// initializing the value of d

	int de = 2*dy;							// initializing the value for de (when east point is selected)
	int dne = 2*(dy - dx);					// initializing the value for dne (when north-east point is selected)

	int x = minx;							// starting from the (minx, miny) point to draw the line
	int y = miny;

	//printf("Flag = %d\n", flag);

	if(flag == 0)							// plot the first point 
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

	while(x < maxx)							// going through every x coordinate between minx and maxx
	{
		if(d <= 0)							// if the east point is chosen
		{
			d = d + de;
		}
		else								// if the north-east point is chosen
		{
			d = d + dne;
			y = y + 1;						// increment the y value too
		}
		x = x + 1;							// increment x value

		if(flag == 0)							// plot the new point accordingly based on the flag variable obtained previously
		{
			printf("(%d, %d)\n", x, y);
			glVertex2f(x, y);
		}
		else if(flag==1)
		{
			printf("(%d, %d)\n", y, x);
			glVertex2f(y, x);
		}
		else if(flag==2)
		{
			printf("(%d, %d)\n", y, -x);
			glVertex2f(y, -x);
		}
		else if(flag==3)
		{
			printf("(%d, %d)\n", -x, y);
			glVertex2f(-x, y);
		}
		else if(flag==4)
		{
			printf("(%d, %d)\n", -x, -y);
			glVertex2f(-x, -y);
		}
		else if(flag==5)
		{
			printf("(%d, %d)\n", -y, -x);
			glVertex2f(-y, -x);
		}
		else if(flag==6)
		{
			printf("(%d, %d)\n", -y, x);
			glVertex2f(-y, x);
		}
		else
		{
			printf("(%d, %d)\n", x, -y);
			glVertex2f(x, -y);
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

	printf("enter the coordinates of one endpoint of line : ");
	scanf("%d %d", &X0, &Y0);

	printf("enter the coordinates of other endpoint of line : ");
	scanf("%d %d", &X1, &Y1);

	glutCreateWindow("Midpoint line drawing algorithm line");
	glutDisplayFunc(MLDA);
	
	glutMainLoop();
	return(0);
}