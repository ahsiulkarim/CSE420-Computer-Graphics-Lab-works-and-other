#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float xc_bres, yc_bres, r_bres;

void PlotCirclePoints(float xc, float yc, float x, float y) {
    // 8-way symmetry plotting
    glBegin(GL_POINTS);
    glVertex2f((xc + x) / 100, (yc + y) / 100);
    glVertex2f((xc - x) / 100, (yc + y) / 100);
    glVertex2f((xc + x) / 100, (yc - y) / 100);
    glVertex2f((xc - x) / 100, (yc - y) / 100);
    glVertex2f((xc + y) / 100, (yc + x) / 100);
    glVertex2f((xc - y) / 100, (yc + x) / 100);
    glVertex2f((xc + y) / 100, (yc - x) / 100);
    glVertex2f((xc - y) / 100, (yc - x) / 100);
    glEnd();
}

void displayBresenham(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green color for Bresenham
    glPointSize(5.0f);

    int x = 0;
    int y = r_bres;
    int d = 3 - 2 * r_bres; // Integer-based decision parameter

    PlotCirclePoints(xc_bres, yc_bres, x, y);

    while (x < y) {
        x++;
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        PlotCirclePoints(xc_bres, yc_bres, x, y);
    }
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    printf("Enter Center (x, y): ");
    scanf("%f %f", &xc_bres, &yc_bres);
    printf("Enter Radius: ");
    scanf("%f", &r_bres);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Circle Drawing");
    init();
    glutDisplayFunc(displayBresenham);
    glutMainLoop();
    return 0;
}
