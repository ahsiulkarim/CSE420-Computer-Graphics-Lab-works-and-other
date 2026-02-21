// Add these lines at the very top
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "freeglut.lib")

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

// Function to draw a circle
void drawCircle(float cx, float cy, float radius){
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * (M_PI / 180.0f);
        float x = radius * cos(theta) + cx;
        float y = radius * sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

// Display callback function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky - Light blue background
    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
    glVertex2f(0, 40);
    glVertex2f(0, 100);
    glVertex2f(100, 100);
    glVertex2f(100, 40);
    glEnd();

    // Ground - Brown/Orange
    glColor3ub(204, 102, 51);
    glBegin(GL_QUADS);
    glVertex2f(0, 30);
    glVertex2f(0, 40);
    glVertex2f(100, 40);
    glVertex2f(100, 30);
    glEnd();

    // Grass patches - Green (left side)
    glColor3ub(34, 139, 34);
    glBegin(GL_QUADS);
    glVertex2f(0, 38);
    glVertex2f(0, 40);
    glVertex2f(15, 40);
    glVertex2f(15, 38);
    glEnd();

    // Grass patches - Green (right side)
    glColor3ub(34, 139, 34);
    glBegin(GL_QUADS);
    glVertex2f(85, 38);
    glVertex2f(85, 40);
    glVertex2f(100, 40);
    glVertex2f(100, 38);
    glEnd();

    // Road - Dark gray
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, 30);
    glVertex2f(100, 30);
    glVertex2f(100, 0);
    glEnd();

    // Road lane markings (white dashed lines)
    glColor3f(1.0, 1.0, 1.0);
    // Lane 1
    glBegin(GL_QUADS);
    glVertex2f(10, 14);
    glVertex2f(10, 16);
    glVertex2f(20, 16);
    glVertex2f(20, 14);
    glEnd();

    // Lane 2
    glBegin(GL_QUADS);
    glVertex2f(30, 14);
    glVertex2f(30, 16);
    glVertex2f(40, 16);
    glVertex2f(40, 14);
    glEnd();

    // Lane 3
    glBegin(GL_QUADS);
    glVertex2f(50, 14);
    glVertex2f(50, 16);
    glVertex2f(60, 16);
    glVertex2f(60, 14);
    glEnd();

    // Lane 4
    glBegin(GL_QUADS);
    glVertex2f(70, 14);
    glVertex2f(70, 16);
    glVertex2f(80, 16);
    glVertex2f(80, 14);
    glEnd();

    // Sun - Yellow/Orange circle
    glColor3ub(255, 204, 0);
    drawCircle(17, 85, 5);

    // Birds - Simple V shapes
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    // Bird 1
    glBegin(GL_LINE_STRIP);
    glVertex2f(36, 75);
    glVertex2f(38, 73);
    glVertex2f(40, 75);
    glEnd();

    // Bird 2
    glBegin(GL_LINE_STRIP);
    glVertex2f(42, 68);
    glVertex2f(44, 66);
    glVertex2f(46, 68);
    glEnd();

    // Left Building Complex (Main building)
    glColor3ub(178, 76, 76);
    glBegin(GL_QUADS);
    glVertex2f(10, 40);
    glVertex2f(10, 75);
    glVertex2f(40, 75);
    glVertex2f(40, 40);
    glEnd();

    // Building top section
    glColor3ub(165, 68, 68);
    glBegin(GL_QUADS);
    glVertex2f(16, 70);
    glVertex2f(16, 75);
    glVertex2f(34, 75);
    glVertex2f(34, 70);
    glEnd();

    // Windows for left building (5x6 grid)
    glColor3ub(40, 40, 40);
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 5; col++) {
            float x = 12 + col * 5.5;
            float y = 42 + row * 4.5;
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x, y + 3);
            glVertex2f(x + 3, y + 3);
            glVertex2f(x + 3, y);
            glEnd();
        }
    }

    // Middle Building
    glColor3ub(155, 60, 60);
    glBegin(GL_QUADS);
    glVertex2f(40, 40);
    glVertex2f(40, 65);
    glVertex2f(62, 65);
    glVertex2f(62, 40);
    glEnd();

    // Windows for middle building (4x5 grid)
    glColor3ub(40, 40, 40);
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 4; col++) {
            float x = 43 + col * 4.5;
            float y = 42 + row * 4.5;
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x, y + 3);
            glVertex2f(x + 3, y + 3);
            glVertex2f(x + 3, y);
            glEnd();
        }
    }

    // Right Building (Tallest with orange top section)
    glColor3ub(178, 76, 76);
    glBegin(GL_QUADS);
    glVertex2f(62, 40);
    glVertex2f(62, 80);
    glVertex2f(82, 80);
    glVertex2f(82, 40);
    glEnd();

    // Top orange section
    glColor3ub(255, 140, 70);
    glBegin(GL_QUADS);
    glVertex2f(68, 70);
    glVertex2f(68, 77);
    glVertex2f(79, 77);
    glVertex2f(79, 70);
    glEnd();

    // Border for orange section
    glColor3ub(200, 100, 50);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(68, 70);
    glVertex2f(68, 77);
    glVertex2f(79, 77);
    glVertex2f(79, 70);
    glEnd();

    // Windows for right building (3x5 grid)
    glColor3ub(40, 40, 40);
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 3; col++) {
            float x = 65 + col * 5.5;
            float y = 42 + row * 5;
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x, y + 3.5);
            glVertex2f(x + 3, y + 3.5);
            glVertex2f(x + 3, y);
            glEnd();
        }
    }

    // Lamp Post
    glColor3ub(50, 50, 50);
    glBegin(GL_QUADS);
    glVertex2f(8, 30);
    glVertex2f(8, 47);
    glVertex2f(9, 47);
    glVertex2f(9, 30);
    glEnd();

    // Lamp base
    glColor3ub(30, 30, 30);
    drawCircle(8.5, 31, 1.5);

    // Lamp light
    glColor3ub(255, 255, 200);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * (M_PI / 180.0f);
        float x = 3 * cos(theta) + 8.5;
        float y = 2 * sin(theta) + 47;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

// Initialize OpenGL settings
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("City Scene - EWU Campus");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
