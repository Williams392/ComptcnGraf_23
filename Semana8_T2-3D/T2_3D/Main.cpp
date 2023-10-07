#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

float camaraX = -30;
float camaraY = 20;
float camaraZ = 40;

float angulo = 0;

void iniciarVentana(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)w / (float)h, 1, 200);

}

void inicializarLuces() {

	GLfloat luz_ambiente[] = { 0.35, 0.35, 0.35,1 };
	GLfloat luz_difusa[] = { 0.5, 0.5, 0.5,1 };
	GLfloat luz_especular[] = { 0.3, 0.3, 0.3,1 };

	float posicionLuz[] = { 0,70,60,1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void piso() {
	glPushMatrix();
	glTranslated(0, -0.1, 0);
	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230); // PLOMO
	glVertex3d(-50, 0, -50);
	glVertex3d(50, 0, -50);
	glVertex3d(50, 0, 50);
	glVertex3d(-50, 0, 50);
	glEnd();
	glPopMatrix();
}
void ejes() {
	glPushMatrix();
	glBegin(GL_LINES);

	glColor3ub(230, 0, 0); // Rojo - X
	glVertex3d(0, 0, 0);
	glVertex3d(50, 0, 0);

	glColor3ub(0, 250, 0); // Verde - Y
	glVertex3d(0, 0, 0);
	glVertex3d(0, 50, 0);

	glColor3ub(0, 0, 250); // Azul - Z
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 50);

	glEnd();
	glPopMatrix();
}
void paredAmarilla() { // 3 PUNTOS:
	glBegin(GL_QUADS);

	// Pared frontal
	glColor3ub(245, 218, 78);  // Amarillo
	glVertex3d(-50, 0, -50);
	glVertex3d(50, 0, -50);
	glColor3ub(190, 86, 105); // Rojo
	glVertex3d(50, 50, -50);  // Altura de la pared
	glVertex3d(-50, 50, -50);

	// Pared trasera
	glColor3ub(245, 218, 78);  // Amarillo
	glVertex3d(-50, 0, 50);
	glVertex3d(50, 0, 50);
	glColor3ub(190, 86, 105); // Rojo
	glVertex3d(50, 50, 50);  // Altura de la pared
	glVertex3d(-50, 50, 50);

	// Pared izquierda
	glColor3ub(245, 218, 78);  // Amarillo
	glVertex3d(-50, 0, -50);
	glVertex3d(-50, 0, 50);
	glColor3ub(190, 86, 105); // Rojo
	glVertex3d(-50, 50, 50);  // Altura de la pared
	glVertex3d(-50, 50, -50);

	// Pared derecha
	glColor3ub(245, 218, 78);  // Amarillo
	glVertex3d(50, 0, -50);
	glVertex3d(50, 0, 50);
	glColor3ub(190, 86, 105); // Rojo
	glVertex3d(50, 50, 50);  // Altura de la pared
	glVertex3d(50, 50, -50);

	glEnd();
}


// PERSONAJE 3D - T2:

void Circulo1_Amarillo() {
	glPushMatrix();
	glTranslated(0, 10, 0); // X, Y(alto), Z | POSICION

	// Dibuja una esfera solida:
	glutSolidSphere(10, 100, 100); // 1(extension - Crecer), slices, stacks
	glPopMatrix();
}

void Circulo2_White() {
	glPushMatrix();
	glTranslated(0, 10, 0); // X, Y(alto), Z | POSICION

	glRotated(50, 10, 25, 0); // Angulo, X, Y, Z | Poner VERTICAL

	glScaled(0.82, 1.05, 1.05); // X, Y, Z | 0.6 reducir un 82%

	// Dibuja una esfera solida:
	glutSolidSphere(10, 100, 100); // 1(extension - Crecer), slices, stacks
	glPopMatrix();
}

// PERSONAJE NEGRO: --------------
void pie_Negro_1() { // Derecho
	glPushMatrix();
	glTranslated(3, 20, 2.5); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(50, 50, 20, 0); // Angulo, X, Y, Z | Poner VERTICAL

	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void pie_Negro_2() { // Isquierdo
	glPushMatrix();
	glTranslated(1, 20.8, 2.5); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(20, 10, 0, 0); // Angulo, X, Y, Z | Poner VERTICAL

	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void pierna_1() { // Cilindro - izquierda
	glPushMatrix();
	glTranslated(1.2, 21.5, 2.5); // X, Y, Z | Para posicionar las 2 piernas.  | POSICION
	glRotated(-90, 30, -10, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	// Para hacer cilindro:
	gluCylinder(gluNewQuadric(), 0.6, 0.6, 2, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void pierna_2() { // Cilindro - derecho
	glPushMatrix();
	glTranslated(3.3, 20.8, 2.5); // X, Y, Z | Para posicionar las 2 piernas.  | POSICION
	glRotated(-90, 30, -10, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	// Para hacer cilindro:
	gluCylinder(gluNewQuadric(), 0.6, 0.6, 2, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void cuerpo() { // ESFERA
	glPushMatrix();
	glTranslated(3.5, 24.5, 2.5); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	glRotated(-90, 50, -20, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	glScaled(1, 1, 1); // X, Y, Z | 0.6 reducir un 60%

	glutSolidSphere(2.3, 100, 100);
	glPopMatrix();
}

void cabeza() { // ESFERA
	glPushMatrix();
	glTranslated(3.5, 28, 2.5); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(90, 10, 0, 0); // Angulo, X, Y, Z | Para parar la esfera.
	glRotated(-90, 11, -10, 0);   // Angulo, X, Y, Z | Inclinar hacia la derecha.


	glScaled(1, 1, 1); // X, Y, Z | 0.6 reducir un 60%

	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();
}

void mano_1() { // ESFERA
	glPushMatrix();
	glTranslated(0.5, 24, 2.5); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(90, 10, 0, 0); // Angulo, X, Y, Z | Para parar la esfera.
	glRotated(-90, 11, -10, 0);  // Angulo, X, Y, Z | Inclinar hacia la derecha.


	glScaled(1, 1, 1); // X, Y, Z | 0.6 reducir un 60%

	glutSolidSphere(0.6, 100, 100);
	glPopMatrix();
}

void brazo_1() { // Cilindro - izquierda
	glPushMatrix();
	glTranslated(0.5, 24, 2.5); // X, Y, Z | Para posicionar las 2 piernas.  | POSICION
	glRotated(-90, 11, -10, 0);  // Angulo, X, Y,Z | Para parar el Cilindro.

	// Para hacer cilindro:
	gluCylinder(gluNewQuadric(), 0.5, 0.5, 2.5, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}


// PERSONA 2: --------------------

void pie_verde_1() { // Derecho
	glPushMatrix();
	glTranslated(-5, 20, -2); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(50, 50, 20, 0); // Angulo, X, Y, Z | Poner VERTICAL

	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void pie_verde_2() { // Isquierdo
	glPushMatrix();
	glTranslated(-1, 20.8, -2); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(20, 10, 0, 0); // Angulo, X, Y, Z | Poner VERTICAL

	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}

void pierna_verde_1() { // Cilindro - izquierda
	glPushMatrix();
	glTranslated(-1.2, 21.5, -2); // X, Y, Z | Para posicionar las 2 piernas.  | POSICION
	glRotated(90, -10, -10, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	// Para hacer cilindro:
	gluCylinder(gluNewQuadric(), 0.6, 0.6, 2, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void pierna_verde_2() { // Cilindro - derecho
	glPushMatrix();
	glTranslated(-5, 20.8, -2); // X, Y, Z | Para posicionar las 2 piernas.  | POSICION
	glRotated(-90, 30, -10, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	// Para hacer cilindro:
	gluCylinder(gluNewQuadric(), 0.6, 0.6, 2, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void cuerpo_verde_1() { // ESFERA
	glPushMatrix();
	glTranslated(-3.5, 24.5, -2); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	glRotated(-90, 50, -20, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

	glScaled(1, 1, 1); // X, Y, Z | 0.6 reducir un 60%

	glutSolidSphere(2.3, 100, 100);
	glPopMatrix();
}

void cabeza_verde_1() { // ESFERA
	glPushMatrix();
	glTranslated(-3.5, 28, -2); // X, Y, Z | Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION

	//glRotated(90, 10, 0, 0); // Angulo, X, Y, Z | Para parar la esfera.
	glRotated(-90, 11, -10, 0);   // Angulo, X, Y, Z | Inclinar hacia la derecha.


	glScaled(1, 1, 1); // X, Y, Z | 0.6 reducir un 60%

	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();
}

// -----------------------------


void dibujar() {

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);

	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	piso();
	ejes();
	paredAmarilla();

	// Personaje 3D:

	glColor3ub(212, 221, 42);  // Amarillo
	Circulo1_Amarillo();

	glColor3ub(245, 245, 245);  // Blanco
	Circulo2_White();

	glColor3ub(149, 137, 157); // PLOMO
	pie_Negro_1();
	pie_Negro_2();

	glColor3ub(0, 0, 0);  // Negro
	pierna_1();
	pierna_2();

	cuerpo();

	glColor3ub(142, 179, 185);  // Celeste Oscuro
	cabeza();

	mano_1();

	glColor3ub(0, 0, 0);  // Negro

	brazo_1();


	// PERSONA 2:

	glColor3ub(0, 0, 0);  // Negro
	pie_verde_1();
	pie_verde_2();
	pierna_verde_1();
	pierna_verde_2();

	glColor3ub(0, 216, 0);  // verde claro:
	cuerpo_verde_1();

	glColor3ub(245, 245, 245);  // Branco
	cabeza_verde_1();
	
	//-------------

	glPopMatrix();

	glutSwapBuffers();

}

void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(20, timer, 20);
}

void teclado(int tecla, int x, int y) {

	switch (tecla) {
	case 101:
		camaraY += 0.2;
		break;
	case 103:
		camaraY += -0.2;
		break;
	case 100:
		angulo -= 1;
		break;
	case 102:
		angulo += 1;
		break;

	}
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1081, 762);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Semana 8 - DIBUJOS 3D");
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;

}