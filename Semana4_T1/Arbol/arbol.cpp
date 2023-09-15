#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init()
{
    glClearColor(0.92, 0.92, 0.94, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 800);
}
void star()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(100, 370);
    glVertex2f(278, 370);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(278, 370);
    glVertex2f(330, 538);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(330, 538);
    glVertex2f(382, 370);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(560, 370);
    glVertex2f(382, 370);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(560, 370);
    glVertex2f(418, 268);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(472, 100);
    glVertex2f(418, 268);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(472, 100);
    glVertex2f(330, 203);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(188, 100);
    glVertex2f(330, 203);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(188, 100);
    glVertex2f(242, 268);
    glEnd();

    glColor3f(0.97, 0.02, 0.03);
    glBegin(GL_LINES);
    glVertex2f(242, 268);
    glVertex2f(100, 370);
    glEnd();

    glFlush();
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Star");
    init();
    glutDisplayFunc(star);
    glutMainLoop();
}
