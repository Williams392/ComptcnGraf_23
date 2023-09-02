#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float angle = 3.1416f * i / 180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void display() {
  

    ///....Árbol circular del lado izquierdo en el patio de comidas.....6 ///
    glColor3ub(139, 146, 22);
    circle(3, 6, 280, 101);
    glColor3ub(139, 146, 22);
    circle(5, 12, 275, 111);
    glColor3ub(139, 146, 22);
    circle(5, 12, 285, 111);
    glColor3ub(139, 146, 22);
    circle(5, 12, 290, 106);
    glColor3ub(139, 146, 22);
    circle(5, 12, 270, 121);


    glColor3ub(181, 106, 76);
    circle(5, 12, 275, 123);
    glColor3ub(139, 146, 22);
    circle(5, 12, 276, 123);
    glColor3ub(139, 146, 22);
    circle(5, 12, 280, 141);
    glColor3ub(139, 146, 22);
    circle(4, 10, 275, 136);
    glColor3ub(181, 106, 76);
    circle(4, 10, 277, 134);

    glColor3ub(139, 146, 22);
    circle(4, 10, 278, 133);

    glColor3ub(139, 146, 22);
    circle(5, 12, 290, 131);
    glColor3ub(139, 146, 22);
    circle(5, 12, 285, 131);
    glColor3ub(181, 106, 76);
    circle(5, 12, 284, 126);
    glColor3ub(139, 146, 22);
    circle(5, 12, 283, 125);
    glColor3ub(139, 146, 22);
    circle(5, 12, 295, 121);
    glColor3ub(181, 106, 76);
    circle(5, 12, 290, 116);
    glColor3ub(139, 146, 22);
    circle(5, 12, 289, 116);
    glColor3ub(139, 146, 22);
    circle(5, 12, 280, 119);
    glColor3ub(139, 146, 22);
    circle(5, 12, 292, 141);



    glColor3ub(227, 91, 137);         ///Full..........Food court .........comp.
    circle(1, 2, 280, 119);
    glColor3ub(227, 91, 137);
    circle(1, 2, 280, 133);
    glColor3ub(227, 91, 137);
    circle(1, 2, 290, 133);
    glColor3ub(227, 91, 137);
    circle(1, 2, 295, 128);
    glColor3ub(227, 91, 137);
    circle(1, 2, 269, 119);
    glColor3ub(227, 91, 137);
    circle(1, 2.5, 275, 134);
    glColor3ub(227, 91, 137);
    circle(1, 1.5, 276, 110);
    glColor3ub(227, 91, 137);
    circle(1, 2.5, 290, 106);
    glColor3ub(227, 91, 137);
    circle(1, 3, 295, 119);
    glColor3ub(227, 91, 137);
    circle(1, 3, 285, 103);


    glBegin(GL_TRIANGLE_FAN);  ///tree.........beside Food Court ........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285, 90);
    glVertex2f(288, 90);
    glVertex2f(287, 100);
    glVertex2f(282, 130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///tree.........beside Food Court........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285, 90);
    glVertex2f(288, 90);
    glVertex2f(284, 100);
    glVertex2f(278, 110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///tree.........Food Court........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(284, 90);
    glVertex2f(288, 90);
    glVertex2f(289, 110);
    glVertex2f(292, 140);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //  dando el tamaño de la ventana en dirección X e Y
    glutInitWindowSize(1450, 750);
    glutInitWindowPosition(100, 0);
    // Dando nombre a la ventana
    glutCreateWindow("Ciudad de alta tecnología -> Comas");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}