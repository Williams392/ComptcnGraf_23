#include <GL/glut.h>
#include <math.h>

void Circulo(int r, float red, float green, float blue)
{
    int cx = 400; // centro
    int cy = 300; // centro
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = cx + r * cos(angle); 
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void Estrella()
{
    int cx = 400; // centro
    int cy = 300; // centro 

    float outerRadius = 10; // Radio  estrella
    float innerRadius = 30; // Radio  estrella

    float rotation = 72.0; // Ángulo de rotación 
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = -18; i <= 360; i += rotation) {
        float angle = i * 3.14159 / 180;
        float x = cx + outerRadius * cos(angle); // vértices exteriores
        float y = cy + outerRadius * sin(angle);
        glVertex2f(x, y);

        angle += rotation / 2 * 3.14159 / 180;
        x = cx + innerRadius * cos(angle); // vértices interiores
        y = cy + innerRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void dibujarEscudo()
{
    Circulo(267, 0.8, 0.1, 0.1);
    Circulo(217, 1.0, 1.0, 1.0);
    Circulo(167, 0.8, 0.1, 0.1);
    Circulo(117, 0.0, 0.0, 1.0);
    Estrella(); // centro del escudo
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    dibujarEscudo();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Escudo Capitan América");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
