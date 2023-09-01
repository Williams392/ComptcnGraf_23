#include <GL/freeglut.h>
#include <math.h>

void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujo del cuerpo de la casa (rectángulo)
    glColor3ub(200, 200, 200);
    glBegin(GL_QUADS);
    glVertex2d(2, 2);
    glVertex2d(8, 2);
    glVertex2d(8, 7);
    glVertex2d(2, 7);
    glEnd();

    // Dibujo del techo (triángulo)
    glColor3ub(150, 75, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(2, 7);
    glVertex2d(8, 7);
    glVertex2d(5, 10);
    glEnd();

    // Dibujo de la puerta (rectángulo)
    glColor3ub(100, 50, 0);
    glBegin(GL_QUADS);
    glVertex2d(4, 2);
    glVertex2d(6, 2);
    glVertex2d(6, 5);
    glVertex2d(4, 5);
    glEnd();

    // Dibujo de la ventana izquierda (rectángulo)
    glColor3ub(100, 100, 255);
    glBegin(GL_QUADS);
    glVertex2d(3, 6);
    glVertex2d(4.5, 6);
    glVertex2d(4.5, 7);
    glVertex2d(3, 7);
    glEnd();

    // Dibujo de la ventana derecha (rectángulo)
    glBegin(GL_QUADS);
    glVertex2d(6.5, 6);
    glVertex2d(8, 6);
    glVertex2d(8, 7);
    glVertex2d(6.5, 7);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Dibujo de una Casa");
    gluOrtho2D(0, 12, 0, 12);
    glutDisplayFunc(dibujar);
    glutMainLoop();
    return 0;
}
