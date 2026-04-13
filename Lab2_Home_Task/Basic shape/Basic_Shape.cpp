#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

// 🟡 Simple text drawing function
void drawText(float x, float y, char *text)
{
    glRasterPos2f(x, y);  // Set text position
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);  // Print each character
    }
}

// 🔵 Display callback function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear screen

    // 🟨 Draw yellow title text
    glColor3f(1.0, 1.0, 0.0);
    drawText(30, 90, "Basic Shape Drawing");

/*
//single Point Drawing
glPointSize(10.0f);                 // MUST be float
glColor3ub(255, 255, 255);          // Correct integer color (0–255)
glBegin(GL_POINTS);
    glVertex2f(10.0f, 90.0f);         // Visible with default projection
glEnd();


glBegin(GL_LINES);
        glVertex2f(10.0f, 50.0f); // Start point
        glVertex2f(40.0f, 50.0f); // End point
    glEnd();

//Not filled
glBegin(GL_LINE_LOOP);
        glVertex2f(50.0f, 10.0f); // Bottom left
        glVertex2f(80.0f, 10.0f); // Bottom right
        glVertex2f(65.0f, 40.0f); // Top center
    glEnd();

*/

    // ⚪ White rectangle
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(10, 10);
        glVertex2f(40, 10);
        glVertex2f(40, 40);
        glVertex2f(10, 40);
    glEnd();

    // 🔴 Red triangle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(60, 20);
        glVertex2f(80, 20);
        glVertex2f(70, 50);
    glEnd();

    // 🔵 Blue trapezoid
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(20, 60);
        glVertex2f(50, 60);
        glVertex2f(40, 80);
        glVertex2f(30, 80);
    glEnd();

    // 🟢 Green pentagon
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(70, 60);
        glVertex2f(90, 60);
        glVertex2f(85, 75);
        glVertex2f(75, 85);
        glVertex2f(65, 75);
    glEnd();

    glFlush(); // Render everything
}

// 🟠 Initialize OpenGL settings
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Background color = black

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

// 🔴 Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Shapes with Text");

    init(); // Setup OpenGL
    glutDisplayFunc(display); // Register display callback
    glutMainLoop(); // Keep the window running
    return 0;
}
