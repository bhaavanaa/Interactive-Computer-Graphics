#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
  

int x, y; 
float i, j,k; 
  

void myInit (void) 
{ 
    
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor3f(0.0, 1.0, 0.0); 
      
    glPointSize(5.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
      
    gluOrtho2D(-768, 768, -420, 420); 
} 
  

// Function to display animation 
void display (void) 
{ 
    for (j = 0; j < 10000; j += 0.006) 
    { 
        glClear(GL_COLOR_BUFFER_BIT); 
        glBegin(GL_POINTS); 
          
        for (i = 0;i < 6.29;i += 0.001) 
        { 
            x = 200 * cos(i); 
            y = 200 * sin(i);
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);
            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        // 7 loops to draw parallel latitude 
        for (i = 1.17; i < 1.97; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -150 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.07; i < 2.07; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -200 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0); 
           
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.05; i < 2.09; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -250 + 300 * sin(i); 
           	glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
           
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.06; i < 2.08; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -300 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.10; i < 2.04; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -350 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.16; i < 1.98; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -400 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 1.27; i < 1.87; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -450 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        // Loop is to draw vertical line 
        for (i = 200; i >=- 200; i--) 
        {  
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(0, i); 
            glColor3f(0.0, 1.0, 0.0); 
            
            glVertex2i(- 600*cos(j), i / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((- 600 * cos(j)-200*cos(5*j)), (i / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        // 3 loops to draw vertical ellipse (similar to longitude) 
        for (i = 0;i < 6.29; i += 0.001) 
        { 
            x = 70 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 0; i < 6.29; i += 0.001) 
        { 
            x = 120 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
           
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        for (i = 0; i < 6.29; i += 0.001) 
        { 
            x = 160 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0); 
            
            glVertex2i(x / 2 - 600*cos(j), y / 2 - 60*sin(j)); 
            glColor3f(1.0, 1.0, 1.0);

            glVertex2i((x / 8 - 600 * cos(j)-200*cos(5*j)), (y / 8 - 60 * sin(j))-60*sin(5*j));
        } 
          
        glEnd(); 
        glFlush(); 
    } 
} 
  
// Driver Program 
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1360, 768); 
    glutInitWindowPosition(0, 0); 
 
    glutCreateWindow("Revolution"); 
  
    myInit(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
}