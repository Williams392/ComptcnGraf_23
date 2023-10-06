#include <GL/glut.h>
#include <math.h> // para usar las variables

float camaraX = -20;
float camaraY = 10;
float camaraZ = 20;

void iniciarVentana(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, (float)w / (float)h, 1, 200);// lente de la camara Ancho y Alto
}

void inicializarLuces() { // luces en el ambiente:
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

void dibujar() {

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);

	glPushMatrix();
	glColor3ub(140, 30, 220);
	glTranslated(20, 0, 0); // posicion
	glutSolidCube(4);
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1081, 762); // Resolucion de la IMG ancho y alto
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Semana 5 - Dibujos 3D");

	glutReshapeFunc(iniciarVentana);// inicializar mi ventana en 3D
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}