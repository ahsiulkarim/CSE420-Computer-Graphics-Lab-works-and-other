#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Global variables
float cx, cy, r;

// Plot all 8 symmetric points of the circle
void plotCirclePoints(float x, float y)
{
    glVertex2f((cx + x) / 100, (cy + y) / 100);
    glVertex2f((cx - x) / 100, (cy + y) / 100);
    glVertex2f((cx + x) / 100, (cy - y) / 100);
    glVertex2f((cx - x) / 100, (cy - y) / 100);
    glVertex2f((cx + y) / 100, (cy + x) / 100);
    glVertex2f((cx - y) / 100, (cy + x) / 100);
    glVertex2f((cx + y) / 100, (cy - x) / 100);
    glVertex2f((cx - y) / 100, (cy - x) / 100);
}

// display() only draws - NO printf here
// GLUT calls display() multiple times, so printing must stay out
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3.0f);

    glBegin(GL_POINTS);

    // Step 1: Initialize x, y and decision parameter Pk = 3 - 2*r
    float x = 0;
    float y = r;
    int Pk = 3 - 2 * (int)r;

    // Plot initial 8 symmetric points
    plotCirclePoints(x, y);

    // Step 2: Loop until x >= y
    while (x < y)
    {
        x = x + 1;   // Always increment x

        if (Pk < 0)
        {
            // Inside circle -> move East only
            Pk = Pk + 4 * (int)x + 6;
        }
        else
        {
            // Outside circle -> move East and South
            y = y - 1;
            Pk = Pk + 4 * ((int)x - (int)y) + 10;
        }

        // Plot 8 symmetric points for new (x, y)
        plotCirclePoints(x, y);
    }

    glEnd();
    glFlush();
}

// Print table ONCE - called only from main()
void printTable(void)
{
    float x = 0;
    float y = r;
    int Pk = 3 - 2 * (int)r;

    printf("Bresenham Circle Drawing Algorithm\n");
    printf("Center: (%.0f, %.0f)  Radius: %.0f\n\n", cx, cy, r);
    printf("Initial point: (%.0f, %.0f)  P0 = %d\n\n", x, y, Pk);

    printf("Step  x          y          Pk\n");
    printf("-------------------------------\n");

    int step = 0;

    while (x < y)
    {
        int currentPk = Pk;   // Save Pk before update
        x = x + 1;

        if (Pk < 0)
        {
            Pk = Pk + 4 * (int)x + 6;
        }
        else
        {
            y = y - 1;
            Pk = Pk + 4 * ((int)x - (int)y) + 10;
        }

        printf("%-5d %-10.0f %-10.0f %-5d\n", step, x, y, currentPk);
        step++;
    }
}

// Initialize OpenGL settings
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.0, 1.0);
}

// Main function
int main(int argc, char** argv)
{
    // Input center and radius
    printf("Enter center coordinates (cx cy): ");
    scanf("%f %f", &cx, &cy);

    printf("Enter radius r: ");
    scanf("%f", &r);

    printf("\n");

    // Print table ONCE before opening the window
    printTable();

    // Open OpenGL window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
