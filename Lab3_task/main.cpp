#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
// 🟡 Simple text drawing function
void drawText(float x, float y, char *text){
glRasterPos2f(x, y); // Set text position
for (int i = 0; text[i] != '\0'; i++){
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]); // Print each character
   }
 }

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

// 🔵 Display callback function
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT); // Clear screen
// 🟡 Draw yellow title text
glColor3f(1.0, 1.0, 0.0);
drawText(30, 90, "Basic Shape Drawing");

//Lab3_task

//Green rectangle
glColor3ub(70, 235, 52);
glBegin(GL_QUADS);
glVertex2f(0,0);
glVertex2f(0,30);
glVertex2f(100,30);
glVertex2f(100,0);
glEnd();


//Gray rectangle
glColor3ub(158, 132, 104);
glBegin(GL_QUADS);
glVertex2f(0,30);
glVertex2f(0,50);
glVertex2f(100,50);
glVertex2f(100,30);
glEnd();


//Sky blue rectangle
glColor3ub(169, 210, 232);
glBegin(GL_QUADS);
glVertex2f(0,50);
glVertex2f(0,100);
glVertex2f(100,100);
glVertex2f(100,50);
glEnd();

//Red sum
glColor3ub(194,27,12);
drawCircle(87,85,8);

//House rectangel
glColor3ub(212, 167, 19);
glBegin(GL_QUADS);
glVertex2f(32,20);
glVertex2f(32,50);
glVertex2f(48,50);
glVertex2f(48,20);
glEnd();

//Roop Triangle
glColor3ub(217, 127, 17);
glBegin(GL_TRIANGLES);
glVertex2f(30,50);
glVertex2f(40,70);
glVertex2f(50,50);
glEnd();

//Door
glColor3ub(125,75,15);
glBegin(GL_QUADS);
glVertex2f(39,20);
glVertex2f(39,30);
glVertex2f(41,30);
glVertex2f(41,20);
glEnd();

//Windowsleft
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(34,35);
glVertex2f(34,37);
glVertex2f(36,37);
glVertex2f(36,35);
glEnd();

//WindowsRight
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(44,35);
glVertex2f(44,37);
glVertex2f(46,37);
glVertex2f(46,35);
glEnd();

//Gray long part of the tree
glColor3ub(66,51,37);
glBegin(GL_QUADS);
glVertex2f(68,20);
glVertex2f(69,40);
glVertex2f(73,40);
glVertex2f(73,20);
glEnd();

//Green leaf
glColor3b(39,94,51);
drawCircle(71,50,10);

//Cloud circle1
glColor3f(1.0f,1.0f,1.0f);
drawCircle(13,79,5);

//Cloud Circle2
glColor3f(1.0f,1.0f,1.0f);
drawCircle(18,82 ,5);

//Cloud Circle3
glColor3f(1.0f,1.0f,1.0f);
drawCircle(23,79 ,5);

/*glColor3f(1.0f, 0.0f, 0.0f);
drawText(8, 30, "Triangle");
glEnd();
*/
glFlush(); // Render everything
}
// 🟡 Initialize OpenGL settings
void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Background color = black
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}
// 🔴Main function
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
