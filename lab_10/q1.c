// Using built-in functions in OpenGL , draw polygon with 5 vertices of your choice and then
// do the following and display the results-
// a. Translate the polygon with vector (a,b)
// b. Rotate the polygon with given theta
// c. Scale the polygon with the given scaling factor


#include<stdio.h>
#include<GL/glut.h>


float a, b, theta, scaling_factor;

void DrawPolygon(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

	glBegin(GL_POLYGON);				
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(200, 100);
		glVertex2f(200, 0);
		glVertex2f(100, -100);
	glEnd();
	glFlush();
}


void translation(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

	glTranslatef(a, b, 0);
	glBegin(GL_POLYGON);				
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(200, 100);
		glVertex2f(200, 0);
		glVertex2f(100, -100);
	glEnd();
	glFlush();	
}


void rotation(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

	glRotatef(theta, 0, 0, 1);
	glBegin(GL_POLYGON);				
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(200, 100);
		glVertex2f(200, 0);
		glVertex2f(100, -100);
	glEnd();
	glFlush();	
}


void scaling(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

	glScalef(scaling_factor, scaling_factor, scaling_factor);
	glBegin(GL_POLYGON);				
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(200, 100);
		glVertex2f(200, 0);
		glVertex2f(100, -100);
	glEnd();
	glFlush();	
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Polygon");
	glutDisplayFunc(DrawPolygon);
	
	int choice;

	printf("1-translation\n2-rotation\n3-scaling\nEnter your choice : ");
	scanf("%d", &choice);

	if(choice == 1)
	{
		printf("Enter the vector(a, b) for translating : ");
		scanf("%f %f", &a, &b);
		glutCreateWindow("Translation");
		glutDisplayFunc(translation);
	}
	
	else if(choice == 2)
	{
		printf("Enter the value of theta : ");
		scanf("%f", &theta);
		glutCreateWindow("Rotation");
		glutDisplayFunc(rotation);
	}

	else if(choice == 3)
	{
		printf("Enter the scaling factor : ");
		scanf("%f", &scaling_factor);
		glutCreateWindow("Scaling");
		glutDisplayFunc(scaling);
	}

	else
	{
		printf("Wrong option\n");
	}

	glutMainLoop();

	return(0);
}
