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


  /*  //single Point Drawing
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

//10 edge
    glColor3ub(200, 120, 140);
    glBegin(GL_POLYGON);
    glVertex2f(10, 7.5);
    glVertex2f(7.5, 12.5);
    glVertex2f(10, 17.5);
    glVertex2f(15, 20);
    glVertex2f(20, 20);
    glVertex2f(25, 17.5);
    glVertex2f(27.5, 12.5);
    glVertex2f(25, 7.5);
    glVertex2f(20, 5);
    glVertex2f(15, 5);

    glEnd();

//hexagon
 glColor3f(0.0f, 1.0f, 0.0f);
 glBegin(GL_POLYGON);
 glVertex2f(10, 25);
 glVertex2f(7.5, 30);
 glVertex2f(10, 35);
 glVertex2f(25, 35);
 glVertex2f(27.5, 30);
 glVertex2f(25, 25);

 glEnd();

 //triangle
 glColor3f(1.0f, 0.0f, 0.0f);
 glBegin(GL_TRIANGLES);
 glVertex2f(7.5, 40);
 glVertex2f(17.5, 55);
 glVertex2f(27.5, 40);

 glEnd();

//11edges
glColor3ub(9, 214, 9);
glBegin(GL_POLYGON);
glVertex2f(12.5, 60);
glVertex2f(10, 63.5);
glVertex2f(7.5, 67.5);
glVertex2f(10, 72.5);
glVertex2f(14.5, 75);
glVertex2f(20.5, 75);
glVertex2f(25, 72.5);
glVertex2f(27.5, 67.5);
glVertex2f(25, 62.5);
glVertex2f(22.5, 60);
glVertex2f(17.5,57.5);
glEnd();

//Heptagon
glColor3ub(230, 160, 70);
glBegin(GL_POLYGON);
glVertex2f(40, 5);
glVertex2f(35, 10);
glVertex2f(35, 15);
glVertex2f(45, 20);
glVertex2f(55, 15);
glVertex2f(55, 10);
glVertex2f(50, 5);

glEnd();

//Parralelogram
glColor3ub(240,240,240);
glBegin(GL_QUADS);
glVertex2f(35, 25);
glVertex2f(40, 35);
glVertex2f(55, 35);
glVertex2f(50, 25);

glEnd();

//dodecagon
glColor3ub(160, 120, 110);
glBegin(GL_POLYGON);
glVertex2f(45, 40);
glVertex2f(41, 41);
glVertex2f(37, 43);
glVertex2f(35, 47);
glVertex2f(37, 51);
glVertex2f(40, 54);
glVertex2f(45, 55);
glVertex2f(50, 54);
glVertex2f(53, 51);
glVertex2f(55, 47);
glVertex2f(53, 43);
glVertex2f(49, 41);

glEnd();

//octagon
glColor3f(0.0f, 0.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(45, 60);
glVertex2f(40, 62);
glVertex2f(35, 67);
glVertex2f(40, 72);
glVertex2f(45, 75);
glVertex2f(50, 72);
glVertex2f(55, 67);
glVertex2f(50, 62);
glEnd();


//rectangle
glColor3ub(245, 160, 130);
glBegin(GL_QUADS);
glVertex2f(60, 5);
glVertex2f(60, 20);
glVertex2f(75, 20);
glVertex2f(75, 5);

glEnd();
//nonagon
glColor3ub(252, 244, 3);
glBegin(GL_POLYGON);
glVertex2f(70, 40);
glVertex2f(65, 40);
glVertex2f(62, 43);
glVertex2f(60, 47.5);
glVertex2f(62, 52);
glVertex2f(67.5, 55);
glVertex2f(73, 52);
glVertex2f(75, 47.5);
glVertex2f(73, 43);

glEnd();

//PENTAGON
glColor3ub(3, 215, 252);
glBegin(GL_POLYGON);
glVertex2f(62.5, 60);
glVertex2f(60, 67.5);
glVertex2f(67.5, 75);
glVertex2f(75, 67.5);
glVertex2f(72.5, 60);

glEnd();








 /*glColor3f(1.0f, 0.0f, 0.0f);
 drawText(8, 30, "Triangle");
 glEnd();
*/

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
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Shapes with Text");

    init(); // Setup OpenGL
    glutDisplayFunc(display); // Register display callback
    glutMainLoop(); // Keep the window running
    return 0;
}

