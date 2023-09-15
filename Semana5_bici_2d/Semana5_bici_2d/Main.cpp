#include <GL/glut.h>
#include <math.h> // para usar las variables


void piso() {

	glColor3ub(252, 232, 143);

	glBegin(GL_POLYGON);

	glVertex2d(0, 2);

	glVertex2d(14, 2);

	glVertex2d(14, 0);

	glVertex2d(0, 0);

	glEnd();


}


void rueda1() {

	float radio = 1.7;

	float cx, cy;


	glColor3ub(252, 232, 143);

	glBegin(GL_POLYGON);

	for (double i = 0; i < 3.14159 * 2; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 4.98, cy + 3.7);

	}

	glEnd();


}


void rueda1_semicirculo() {

	float radio = 1.7;

	float cx, cy;


	glColor3ub(252, 215, 2);

	glBegin(GL_POLYGON);

	for (double i = -2.2; i < 1.1; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 4.98, cy + 3.7);

	}

	glEnd();

}


void rueda2() {

	float radio = 1.7;

	float cx, cy;


	glColor3ub(96, 41, 81);

	glBegin(GL_POLYGON);

	for (double i = 0; i < 3.14159 * 2; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 11.37, cy + 3.7);

	}

	glEnd();

}

void rueda2_interna() {

	float radio = 1.3;

	float cx, cy;


	glColor3ub(254, 254, 254);

	glBegin(GL_POLYGON);

	for (double i = 0; i < 3.14159 * 2; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 11.37, cy + 3.7);

	}

	glEnd();

}


void rueda2_interna2() {

	float radio = 1.3;

	float cx, cy;


	glColor3ub(3, 127, 135);

	glBegin(GL_POLYGON);

	for (double i = 0; i < 3.14159; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 11.37, cy + 3.7);

	}

	glEnd();

}



void rueda3() {

	float radio = 0.55;

	float cx, cy;


	glColor3ub(96, 41, 81);

	glBegin(GL_POLYGON);

	for (double i = 0; i < 3.14159 * 2; i += 0.01) {

		cx = radio * cos(i);

		cy = radio * sin(i);

		glVertex2d(cx + 8.13, cy + 3.7);

	}

	glEnd();

}


void dibujar() {


	glLoadIdentity();

	gluOrtho2D(0, 14, 0, 10); // tamaño de la img X - Y GeoGebra

	glClear(GL_COLOR_BUFFER_BIT);


	glClearColor(254 / 255.0, 252 / 255.0, 214 / 255.0, 1); // Fondo Negro


	piso();

	rueda1();

	rueda1_semicirculo();

	rueda2();

	rueda2_interna();

	rueda2_interna2();

	rueda3();


	glFlush();


}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1081, 762); // Resolución de la IMG
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Semana 5 - Círculos y Transparencias");
	glutDisplayFunc(dibujar);
	glutMainLoop();

	return 0;
}