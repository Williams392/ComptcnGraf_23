#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

void init()
{
    glClearColor(0.8, 0.8, 0.8, 1.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 900, 0.0, 600);
}

void home()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9, 0.6, 0.4); // Change the wall color
    glBegin(GL_POLYGON);
    glVertex2i(200, 500);
    glVertex2i(600, 500);
    glVertex2i(700, 350);
    glVertex2i(300, 350);
    glEnd();

    glColor3f(0.8, 0.1, 0.2); // Change the roof color
    glBegin(GL_TRIANGLES);
    glVertex2i(200, 500);
    glVertex2i(100, 350);
    glVertex2i(300, 350);
    glEnd();

    glColor3f(0.2, 0.5, 0.5); 
    glBegin(GL_POLYGON);
    glVertex2i(100, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 100);
    glVertex2i(100, 100);
    glEnd();

    glColor3f(0.7, 0.3, 0.6); // Change the middle rectangle color
    glBegin(GL_POLYGON);
    glVertex2i(150, 250);
    glVertex2i(250, 250);
    glVertex2i(250, 100);
    glVertex2i(150, 100);
    glEnd();

    glColor3f(0.4, 0.7, 0.2); // Change the right rectangle color
    glBegin(GL_POLYGON);
    glVertex2i(300, 350);
    glVertex2i(700, 350);
    glVertex2i(700, 100);
    glVertex2i(300, 100);
    glEnd();

    // Calcular el centro del segundo rectángulo
    float centro_x = (300 + 700) / 2.0f; // Adjusted the rectangle corner points
    float centro_y = (100 + 350) / 2.0f; // Adjusted the rectangle corner points

    // Agregar un círculo en el centro del segundo rectángulo
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    int num_segments = 100;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = centro_x + 75 * cosf(theta); // Increased the radius to 75 for better visibility
        float y = centro_y + 75 * sinf(theta); // Increased the radius to 75 for better visibility
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("2D CASA ");
    init();
    glutDisplayFunc(home);
    glutMainLoop();

    return 0;
}








// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
