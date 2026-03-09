#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float X, Y, X1, Y1, X2, Y2;
int dx, dy, Pk;

// Function to display the Bresenham line
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
glLineWidth(20.0f);
glPointSize(10.0f);
glBegin(GL_POINTS);

// Calculate differences
dx = (int)(X2 - X1);
dy = (int)(Y2 - Y1);

// Initial decision parameter
Pk = 2 * dy - dx;

X = X1;
Y = Y1;

// Plot the first point (starting point, not printed in table)

glVertex2f(X / 100, Y / 100);

// Bresenham's Line Algorithm implementation
// The table shows: at step K, use current Pk to find next point (Xk+1, Yk+1)
int k;
for (k = 0; k < dx; k++)
{
int currentPk = Pk; // Save Pk before updating (this is what the table shows)

if (Pk < 0)
{
// Case-01: If Pk < 0
// Pk+1 = Pk + 2*dy
// Xk+1 = Xk + 1
// Yk+1 = Yk (Y remains the same)
Pk = Pk + 2 * dy;
X = X + 1;
// Y stays the same
}
else
{
// Case-02: If Pk >= 0
// Pk+1 = Pk + 2*dy - 2*dx
// Xk+1 = Xk + 1
// Yk+1 = Yk + 1
Pk = Pk + 2 * dy - 2 * dx;
X = X + 1;
Y = Y + 1;
}

// Print: K | current Pk (before update) | next point (Xk+1, Yk+1)
// This matches the document table format exactly
printf("K = %d | Pk = %d | Point: (%.0f, %.0f)\n", k, currentPk, X, Y);

glVertex2f(X / 100, Y / 100);
}

glEnd();
glFlush();
}

// Function to initialize OpenGL settings
void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 0.5, 0.0, 0.5, -1.0, 1.0);
}

// Main function
int main(int argc, char** argv)
{
// Input the coordinates for the line
printf("Enter value of (X1, Y1): ");
scanf("%f %f", &X1, &Y1);
printf("Enter value of (X2, Y2): ");
scanf("%f %f", &X2, &Y2);

printf("\n");

// Calculate and display initial values
int ddx = (int)(X2 - X1);
int ddy = (int)(Y2 - Y1);
int P0 = 2 * ddy - ddx;
printf("dy = %d and dx = %d\n", ddy, ddx);
printf("P0 = 2*dy - dx = %d\n\n", P0);

// Initialize GLUT and create a window
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Bresenham Line Drawing");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
