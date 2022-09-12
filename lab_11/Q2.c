// Given n lines segments with end points (xi, yi) for 1<=i<=n, and a clipping rectangle with diagonal vertices, (xmin, ymin) and (xmax, ymax), 
// display(in green) the portions of the line segments that are inside the rectangle, using Cohen-Sutherland Line Clipping Algorithm


#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>


int n = 20;

int xmin, ymin, xmax, ymax, p1, q1, p2, q2;
int inside = 0;		// 0000
int left = 1;		// 0001
int right = 2;		// 0010
int bottom = 4;		// 0100
int top = 8;		// 1000


int compute_code(int x, int y)
{
	int code = inside;

	if(x < xmin)
		code |= left;
	else if(x > xmax)
		code |= right;

	if(y < ymin)
		code |= bottom;
	else if(y > ymax)
		code |= top;

	return(code);
}


void draw_lines()
{
	srand(time(NULL));

	int accept;

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);	

	glRecti(xmin, ymin, xmax, ymax);

	glBegin(GL_LINES);

		for(int i=0; i<n; i++)
		{
			p1 = rand()%500-100;
			q1 = rand()%500-100;

			p2 = rand()%500-100;
			q2 = rand()%500-100;

			// p1 = -50, q1 = -100, p2 = 350, q2 = 350;

			int code1 = compute_code(p1, q1);
			int code2 = compute_code(p2, q2);

			// printf("%d %d\n", code1, code2);

			float p11, q11, p22, q22;

			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex2f(p1, q1);
			glVertex2f(p2, q2);

			accept = 0;
			int count=0;
			while(1)
			{	
				if(code1==0 && code2==0)
				{
					accept = 1;
					break;
				}

				else if(code1 & code2)
				{
					break;
				}

				else
				{
					int code_out;
					float p, q;

					if(code1 != 0)
						code_out = code1;
					else
						code_out = code2;

					if(code_out&top)
					{
						p = p1 + (float)(p2-p1)/(q2-q1)*(ymax-q1);
						q = ymax;
					}
					else if(code_out&bottom)
					{
						p = p1 + (float)(p2-p1)/(q2-q1)*(ymin-q1);
						q = ymin;
					}
					else if(code_out&right)
					{
						p = xmax;
						q = q1 + (float)(q2-q1)/(p2-p1)*(xmax-p1);
					}
					else
					{
						p = xmin;
						q = q1 + (float)(q2-q1)/(p2-p1)*(xmin-p1);
					}

					if(code_out==code1)
					{
						p1 = p;
						q1 = q;
						code1 = compute_code(p1, q1);
					}
					else
					{
						p2 = p;
						q2 = q; 
						code2 = compute_code(p2, q2);
					}
				}
			}

			if(accept == 1)
			{
				glColor3f(0.0f, 1.0f, 0.0f);
				glVertex2f(p1, q1);
				glVertex2f(p2, q2);	
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

	int x1, y1, x2, y2;

	printf("Enter the coordinates of one diagonal vertex: ");
	scanf("%d %d", &x1, &y1);

	printf("Enter the coordinates of the other diagonal vertex: ");
	scanf("%d %d", &x2, &y2);

	if(x1 <= x2)
	{
		xmin = x1;
		xmax = x2;
		ymin = y1;
		ymax = y2;
	}
	else
	{
		xmin = x2;
		xmax = x1;
		ymin = y2;
		ymax = y1;
	}

	glutCreateWindow("Display lines inside rectangle");
	glutDisplayFunc(draw_lines);
	
	glutMainLoop();
	return(0);
}