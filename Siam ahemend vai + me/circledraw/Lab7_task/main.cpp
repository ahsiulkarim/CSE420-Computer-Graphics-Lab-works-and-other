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

// FIX 1: display() only draws - NO printf here
// GLUT calls display() multiple times, which caused the table to repeat
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3.0f);

    glBegin(GL_POINTS);

    float x = 0;
    float y = r;
    int p = 1 - (int)r;

    // Plot initial point
    plotCirclePoints(x, y);

    // Draw all circle points
    while (x < y)
    {
        x = x + 1;

        if (p < 0)
        {
            p = p + 2 * (int)x + 1;
        }
        else
        {
            y = y - 1;
            p = p + 2 * (int)x - 2 * (int)y + 1;
        }

        plotCirclePoints(x, y);
    }

    glEnd();
    glFlush();
}

// FIX 2: Print table only ONCE from main() using this separate function
void printTable(void)
{
    float x = 0;
    float y = r;
    int p = 1 - (int)r;

    printf("Midpoint Circle Drawing Algorithm\n");
    printf("Center: (%.0f, %.0f)  Radius: %.0f\n\n", cx, cy, r);
    printf("Initial point: (%.0f, %.0f)  P0 = %d\n\n", x, y, p);

    // FIX 3: "Step" header printed on its own line, no stray characters
    printf("Step  x          y          Pk\n");
    printf("-------------------------------\n");

    int step = 0;

    while (x < y)
    {
        int currentPk = p;
        x = x + 1;

        if (p < 0)
        {
            p = p + 2 * (int)x + 1;
        }
        else
        {
            y = y - 1;
            p = p + 2 * (int)x - 2 * (int)y + 1;
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

    // Print table ONCE here before opening the window
    printTable();

    // Open OpenGL window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
