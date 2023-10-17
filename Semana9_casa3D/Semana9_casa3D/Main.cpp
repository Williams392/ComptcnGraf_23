#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

/*float camaraX = -30;
float camaraY = 10;
float camaraZ = 50;

float radio = sqrt(pow(camaraX, 2) + pow(camaraZ, 2));
float angulo = acos(camaraX/radio);
float centroY = 10;*/

float camaraX = -30;
float camaraY = 20;
float camaraZ = 50;

float angulo = 0;

void iniciarVentana(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (float)w / (float)h, 1, 200);

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
	glColor3ub(230, 230, 230);
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
	glColor3ub(230, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(50, 0, 0);
	glColor3ub(0, 250, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 50, 0);

	glColor3ub(0, 0, 250);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 50);
	glEnd();

	glPopMatrix();

}


void base() {

	glPushMatrix();
	glColor3ub(178, 111, 43);
	glTranslated(0, 5, 0);
	glutSolidCube(10);
	glPopMatrix();

}

void triangulo(float posZ) {
	glPushMatrix();
	glTranslated(0, 10, posZ);
	glBegin(GL_TRIANGLES);
	glVertex3d(-5, 0, 0);
	glVertex3d(5, 0, 0);
	glVertex3d(0, 5, 0);
	glEnd();
	glPopMatrix();
}

void tejado(float giro) {
	glPushMatrix();
	glColor3ub(215, 111, 0);
	glTranslated(0, 10, 5);
	glRotated(giro, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3d(-5, 0, 0);
	glVertex3d(0, 5, 0);
	glVertex3d(0, 5, -10);
	glVertex3d(-5, 0, -10);
	glEnd();
	glPopMatrix();
}

void barra(float posX, float posZ, float rot) {

	glPushMatrix();
	glColor3ub(130, 80, 60);
	glTranslated(posX, 12, posZ);
	glRotated(rot, 0, 0, 1);
	glScaled(8, 1, 1);
	glutSolidCube(1);
	glPopMatrix();

}

void barraLateral(float posX) {

	glPushMatrix();
	glColor3ub(130, 80, 60);
	glTranslated(posX, 10, 0);
	glScaled(1, 1, 10);
	glutSolidCube(1);
	glPopMatrix();

}

void marcoPuerta(int rojo, int verde, int azul) {
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslated(0, 4, 5);
	glScaled(5, 8, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void Puerta() {
	glPushMatrix();
	marcoPuerta(225, 225, 225);
	glPushMatrix();
	glTranslated(0, 0.7, 0.07);
	glScaled(0.7, 0.8, 1);
	marcoPuerta(0, 0, 0);
	glPopMatrix();
	glPopMatrix();
	//manija
	glPushMatrix();
	glColor3ub(252, 200, 10);
	glTranslated(1.3, 4, 5.5);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();
}

void dibujar() {
	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);
	glClearColor(255 / 255.0, 255 / 255.0, 200 / 255.0, 1);
	glPushMatrix();
	glRotated(angulo, 0, 1, 0);
	piso();
	ejes();
	base();
	triangulo(5);
	triangulo(-5);
	tejado(0);
	tejado(-90);
	barra(-2.7, 5, 45);
	barra(2.7, 5, -45);
	barra(-2.7, -5, 45);
	barra(2.7, -5, -45);
	barraLateral(5);
	barraLateral(-5);
	Puerta();

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

	/*
	switch (tecla) {

	case 100:
		angulo += 0.05;
		break;
	case 102:
		angulo -= 0.05;
		break;
	case 101:
		camaraY += 1;
		break;
	case 103:
		camaraY -= 1;
		break;
	case 104:
		radio -= 2;
		break;
	case 105:
		radio += 2;
		break;
	case 106:
		centroY += 2;
		break;
	case 107:
		centroY-= 2;
		break;

	}
	*/

}



int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1081, 762);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Semana 7 - DIBUJOS 3D");
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;

}


