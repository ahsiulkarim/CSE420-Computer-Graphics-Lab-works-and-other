#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

// Draw 2D square
void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
}

//Draw 2D Triagle
void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f( 0.0f,  0.25f);   // top
    glVertex2f(-0.2f, -0.15f);   // bottom-left
    glVertex2f( 0.2f, -0.15f);   // bottom-right
    glEnd();
}

//Draw 2D Parallelogram
void drawParallelogram() {
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.1f);
    glVertex2f( 0.15f, -0.1f);
    glVertex2f( 0.25f,  0.1f);
    glVertex2f(-0.05f,  0.1f);
    glEnd();
}


// Draw text
void drawText(const char* text, float r, float g, float b) {
    glColor3f(r, g, b);
    glRasterPos2f(-0.9f, -0.9f);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

/*
// Translation
void translate2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original
    glColor3f(1,1,1);
    drawSquare();

    // Translated
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f);
    glColor3f(1,0.5,0);
    drawSquare();
    glPopMatrix();

    drawText("Translation 2D",1,0.5,0);
    glFlush();
}

// Rotation
void rotate2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    drawSquare();

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0);
    glRotatef(180, 0, 0, 1);
    glColor3f(0,1,0);
    drawSquare();
    glPopMatrix();

    drawText("Rotation 2D",0,1,0);
    glFlush();
}

// Scaling
void scale2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    drawSquare();

    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0);
    glScalef(0.5f, 0.5f, 1);
    glColor3f(0,0,1);
    drawSquare();
    glPopMatrix();

    drawText("Scaling 2D",0,0,1);
    glFlush();
}

// Reflection (Y-axis)
void reflect2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    glTranslatef(0.3f,0,0);
    drawSquare();

    glLoadIdentity();

    GLfloat reflectMatrix[16] = {
        -1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,1
    };

    glMultMatrixf(reflectMatrix);
    glTranslatef(0.3f,0,0);

    glColor3f(1,0,0);
    drawSquare();

    drawText("Reflection 2D",1,0,0);
    glFlush();
}

// Shearing
void shear2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    drawSquare();

    glPushMatrix();
    GLfloat shearMatrix[16] = {
        1,0,0,0,
        0.5,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    glMultMatrixf(shearMatrix);
    glTranslatef(0.5f,0,0);

    glColor3f(1,0.5,0);
    drawSquare();
    glPopMatrix();

    drawText("Shearing 2D",1,0.5,0);
    glFlush();
} */


//Drawing Triangle Rotation and Reflection

//Rotation 2D
void rotateTriangle2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.35f, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    drawTriangle();
    glPopMatrix();

    // Rotated triangle (45 degrees)
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glRotatef(180, 0, 0, 1);
    glColor3f(0, 1, 1);  // cyan
    drawTriangle();
    glPopMatrix();

    drawText("Rotation 2D - Triangle", 0, 1, 1);
    glFlush();
}

//Reflection 2D
void reflectTriangle2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle — placed at +0.35 on X
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    drawTriangle();
    glPopMatrix();

    // Reflected triangle — flip X axis, then place at +0.35
    // Result lands at -0.35 due to reflection
    glPushMatrix();
    GLfloat reflectMatrix[16] = {
        -1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1
    };
    glMultMatrixf(reflectMatrix);
    glTranslatef(0.35f, 0.0f, 0.0f);
    glColor3f(1, 0, 1);  // magenta
    drawTriangle();
    glPopMatrix();

    drawText("Reflection 2D - Triangle", 1, 0, 1);
    glFlush();
}

//Drawing Rotation and Reflection for Parallelogram.

//Rotation
void rotateParallelogram2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original parallelogram
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-0.35f, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    drawParallelogram();
    glPopMatrix();

    // Rotated parallelogram (45 degrees)
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glRotatef(45, 0, 0, 1);
    glColor3f(1, 1, 0);  // yellow
    drawParallelogram();
    glPopMatrix();

    drawText("Rotation 2D - Parallelogram", 1, 1, 0);
    glFlush();
}

//Reflection
void reflectParallelogram2D() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original parallelogram — placed at +0.35 on X
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    drawParallelogram();
    glPopMatrix();

    // Reflected parallelogram — flip X axis, then place at +0.35
    glPushMatrix();
    GLfloat reflectMatrix[16] = {
        -1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1
    };
    glMultMatrixf(reflectMatrix);
    glTranslatef(0.35f, 0.0f, 0.0f);
    glColor3f(1, 0.5f, 0);  // orange
    drawParallelogram();
    glPopMatrix();

    drawText("Reflection 2D - Parallelogram", 1, 0.5, 0);
    glFlush();
}

void setup2D() {
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1); // 2D projection
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);

   /* glutCreateWindow("Translation 2D");
    setup2D();
    glutDisplayFunc(translate2D);

    glutCreateWindow("Rotation 2D");
    setup2D();
    glutDisplayFunc(rotate2D);

    glutCreateWindow("Scaling 2D");
    setup2D();
    glutDisplayFunc(scale2D);

    glutCreateWindow("Reflection 2D");
    setup2D();
    glutDisplayFunc(reflect2D);

    glutCreateWindow("Shearing 2D");
    setup2D();
    glutDisplayFunc(shear2D); */

    //Rotation calling for Triangle and parallelogram.
    glutCreateWindow("Rotation 2D - Triangle");
    setup2D();
    glutDisplayFunc(rotateTriangle2D);

    glutCreateWindow("Reflection 2D - Triangle");
    setup2D();
    glutDisplayFunc(reflectTriangle2D);

    glutCreateWindow("Rotation 2D - Parallelogram");
    setup2D();
    glutDisplayFunc(rotateParallelogram2D);

    glutCreateWindow("Reflection 2D - Parallelogram");
    setup2D();
    glutDisplayFunc(reflectParallelogram2D);

    glutMainLoop();
    return 0;
}
