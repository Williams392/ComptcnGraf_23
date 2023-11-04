#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>

#include "Texturas/RgbImage.h"

using namespace std;

float camaraX = -20;
float camaraY = 34;
float camaraZ = 40;

float radio = 66.72;
float angulo = 2.23;
float centroY = 10;

// ------
GLuint texturas[5]; // un arreglo de 5 elementos -> 5 imagenes

GLUquadric* quad;

float velocidad = 0.5;
int ladoX = 1;
float posCubox = 0;

float giroTierra = 0;

// 1. CargarTexturasDesdeArchivo:
void loadTexturesFromFile(const char* filename, int index) { // filename -> Nombre del archivo
	RgbImage theTextMap(filename);
	glGenTextures(1, &texturas[index]);
	glBindTexture(GL_TEXTURE_2D, texturas[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, theTextMap.GetNumCols(),
		theTextMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTextMap.ImageData());
}
// 2.
void cargarImagenes() {
	loadTexturesFromFile("texturas/tierra.bmp", 0);
	loadTexturesFromFile("texturas/piso.bmp", 1);
	loadTexturesFromFile("texturas/pared.bmp", 2);
}
// ------
void iniciarVentana(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (float)w / (float)h, 1, 200);
}
void inicializarLuces() {

	GLfloat luz_ambiente[] = { 0.2,0.2,0.2,1 };
	GLfloat luz_difusa[] = { 0.2,0.2,0.2,1 };
	GLfloat luz_especular[] = { 0.1,0.1,0.1,1 };

	float reflejo[] = { 0,0,0,1 };
	float posicionLuz[] = { 0,70,0,1 };
	int sombra = 128;

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, reflejo);
	glMateriali(GL_FRONT, GL_SHININESS, sombra);
	glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);

	//Luces Piso
	GLfloat light_ambient1[] = { 0.1,0.1,0.1,1 };
	GLfloat light_diffuse1[] = { 0.1,0.1,0.1,1 };
	GLfloat light_specular1[] = { 0.1,0.1,0.1,1 };

	float posicionLuz1[] = { -50,0,0,1 };
	float posicionLuz2[] = { 0,0,50,1 };
	float posicionLuz3[] = { 50,0,0,1 };
	float posicionLuz4[] = { 0,0,-50,1 };

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_POSITION, posicionLuz1);

	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT2, GL_POSITION, posicionLuz2);

	glEnable(GL_LIGHT3);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT3, GL_POSITION, posicionLuz3);

	glEnable(GL_LIGHT4);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT3, GL_POSITION, posicionLuz4);

}
void piso() {
	glPushMatrix();
	glColor3ub(190, 190, 190);
	glTranslated(0, -0.1, 0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 4); glVertex3d(-50, 0, -50);
	glTexCoord2f(4, 4); glVertex3d(50, 0, -50);
	glTexCoord2f(4, 0); glVertex3d(50, 0, 50);
	glTexCoord2f(0, 0); glVertex3d(-50, 0, 50);
	glEnd();
	glPopMatrix();

}
void ejes() {
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(50, 0, 0);

	glColor3ub(0, 255, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 50, 0);

	glColor3ub(0, 0, 255);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 50);
	glEnd();
	glPopMatrix();
}

// --------------------------
void tierra() {
	
	giroTierra += 0.5;

	glPushMatrix();
	    glRotated(giroTierra, 0, 1, 0);
		glTranslated(10, 0, 0);

	    // Agregando imagen:
	    glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, texturas[0]);
		glColor3ub(255, 255, 255);

		glPushMatrix();

		glTranslated(0, 25, 0);
		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		gluSphere(quad, 5, 50, 50);

		glPopMatrix();

		// Desabilitando la pintura -  para que no salga negro:
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void paredes() {

	// Pared 1 x- :
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[2]);

	glPushMatrix();

	glColor3ub(255, 255, 255);
	glTranslated(-50, -0.1, 0);
	glRotated(90, 0, 1, 0);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0.6); glVertex3d(-50, 15, 0);
	glTexCoord2d(4, 0.6); glVertex3d(50, 15, 0);
	glTexCoord2d(4, 0); glVertex3d(50, 0, 0);
	glTexCoord2d(0, 0); glVertex3d(-50, 0, 0);
	glEnd();
	glPopMatrix();

	// Pared 2 x+ :
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[2]);

	glPushMatrix();

	glColor3ub(255, 255, 255);
	glTranslated(50,-0.1, 0); // posicion
	glRotated(90, 0, 1, 0);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0.6); glVertex3d(-50, 15, 0);
	glTexCoord2d(4, 0.6); glVertex3d(50, 15, 0);
	glTexCoord2d(4, 0); glVertex3d(50, 0, 0);
	glTexCoord2d(0, 0); glVertex3d(-50, 0, 0);
	glEnd();
	glPopMatrix();

	// Pared 3 y+ :
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[2]);

	glPushMatrix();

	glColor3ub(255, 255, 255);
	glTranslated(0, -0.1, 50); // posicion
	glRotated(180, 0, 1, 0);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0.6); glVertex3d(-50, 15, 0);
	glTexCoord2d(4, 0.6); glVertex3d(50, 15, 0);
	glTexCoord2d(4, 0); glVertex3d(50, 0, 0);
	glTexCoord2d(0, 0); glVertex3d(-50, 0, 0);
	glEnd();
	glPopMatrix();

	// Pared 4 y- :
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[2]);

	glPushMatrix();

	glColor3ub(255, 255, 255);
	glTranslated(0, -0.1, -50); // posicion
	glRotated(-180, 0, 1, 0);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0.6); glVertex3d(-50, 15, 0);
	glTexCoord2d(4, 0.6); glVertex3d(50, 15, 0);
	glTexCoord2d(4, 0); glVertex3d(50, 0, 0);
	glTexCoord2d(0, 0); glVertex3d(-50, 0, 0);
	glEnd();
	glPopMatrix();

	// Desabilitando la pintura -  para que no salga negro:
	glDisable(GL_TEXTURE_2D);

}
void cuboRojo() {

	if (posCubox > 48) {
		ladoX = -1;
	}
	if (posCubox < -48) {
		ladoX = 1;
	}
	posCubox += velocidad * ladoX;

	glColor3ub(255, 0, 0);
	glPushMatrix();
	    glTranslated(posCubox, 2, 0);
	    glutSolidCube(4);
	glPopMatrix();

}
// --------------------------

void dibujar() {

	/* Ejemplo de como esto se dibuja a cada rato:
	velocidad++;
	cout << velocidad << endl;
	*/

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(radio * cos(angulo), camaraY, radio * sin(angulo), 0, centroY, 0, 0, 1, 0);
	glClearColor(255 / 255.0, 255 / 255.0, 208 / 255.0, 1);
	glPushMatrix();

	piso();
	ejes();

	// Projectos 3D:
	tierra();
	paredes();
	cuboRojo();

	glPopMatrix();
	glutSwapBuffers();

}

void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}

void teclado(int tecla, int x, int y) {

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
	case 105:
		radio += 2;
		break;
	case 104:
		radio -= 2;
		break;
	case 106:
		centroY += 2;
		break;
	case 107:
		centroY -= 2;
		break;
	}

}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1009, 711);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Semana 10");
	cargarImagenes();
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}