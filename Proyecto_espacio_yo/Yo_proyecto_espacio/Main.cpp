#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>

// Agrengando las nuevas librerias:
#include "texturas/RgbImage.h"
#include <vector>

using namespace std;

float camaraX = -10;
float camaraY = 40;
float camaraZ = 85;

float radio = 66.72;
float angulo = 2.23;
float centroY = 10;

struct Estrella {
	float x, y, z;
};

std::vector<Estrella> estrellas;

// ----------------------------------------------------------------------------------

GLuint texturas[10]; // un arreglo de 5 elementos -> 5 imagenes

// Planetas:
//float giroTierra = 0;
GLUquadric* quad;

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

// 2: cargarImagenes al metodo -> main
void cargarImagenes() {
	loadTexturesFromFile("texturas/fondo_1.bmp", 0);
	loadTexturesFromFile("texturas/moon.bmp", 1);

	loadTexturesFromFile("texturas/tierra.bmp", 2);
	loadTexturesFromFile("texturas/marte.bmp", 3);
	loadTexturesFromFile("texturas/sol.bmp", 4);
	loadTexturesFromFile("texturas/saturno.bmp", 5);
}

// ----------------------------------------------------------------------------------


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

/*
void piso() {
	glColor3ub(150, 150, 150);
	glPushMatrix();
	glTranslated(0, -0.1, 0);
	glBegin(GL_POLYGON);
	glVertex3d(-90, 0, -90);
	glVertex3d(90, 0, -90);
	glVertex3d(90, 0, 90);
	glVertex3d(-90, 0, 90);
	glEnd();
	glPopMatrix();
} */

void piso() { // Modificando Piso con imagen:

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[1]);

	glColor3ub(255, 255, 255); // IMPORTANTE: Siempre trabajar con el color blanco en Texturas.
	glPushMatrix();
	glTranslated(0, -0.1, 0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1); glVertex3d(-90, 0, -90);
	glTexCoord2f(1, 1); glVertex3d(90, 0, -90);
	glTexCoord2f(1, 0); glVertex3d(90, 0, 90);
	glTexCoord2f(0, 0); glVertex3d(-90, 0, 90);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
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

/*--------------------------------------------------------------
# Estructura - Project:
--------------------------------------------------------------*/

void paredes() {

	// llamando imagen de goku:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[0]); // Textura del espacio

	glColor3ub(255, 255, 255);
	glPushMatrix();
	glBegin(GL_QUADS);

	// Pared frontal
	glTexCoord2f(0, 0); glVertex3d(-90, 0, -90);
	glTexCoord2f(1, 0); glVertex3d(90, 0, -90);
	glTexCoord2f(1, 1); glVertex3d(90, 90, -90);
	glTexCoord2f(0, 1); glVertex3d(-90, 90, -90);

	// Pared trasera
	glTexCoord2f(0, 0); glVertex3d(-90, 0, 90);
	glTexCoord2f(1, 0); glVertex3d(90, 0, 90);
	glTexCoord2f(1, 1); glVertex3d(90, 90, 90);
	glTexCoord2f(0, 1); glVertex3d(-90, 90, 90);

	// Pared izquierda
	glTexCoord2f(0, 0); glVertex3d(-90, 0, -90);
	glTexCoord2f(1, 0); glVertex3d(-90, 0, 90);
	glTexCoord2f(1, 1); glVertex3d(-90, 90, 90);
	glTexCoord2f(0, 1); glVertex3d(-90, 90, -90);

	// Pared derecha
	glTexCoord2f(0, 0); glVertex3d(90, 0, -90);
	glTexCoord2f(1, 0); glVertex3d(90, 0, 90);
	glTexCoord2f(1, 1); glVertex3d(90, 90, 90);
	glTexCoord2f(0, 1); glVertex3d(90, 90, -90);

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0); // Desactivar la textura
}

/*--------------------------------------------------------------
# Planetas:
--------------------------------------------------------------*/

void sol() {

	// Agregando imagen:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[4]);
	glColor3ub(255, 255, 255);

	glPushMatrix();
	    glTranslatef(-45, 35, -50.0); // x, y, z

		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		gluSphere(quad, 15, 50, 50);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void planetaTierra() {

	// Agregando imagen:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[2]);
	glColor3ub(255, 255, 255);

	glPushMatrix();
	    glTranslatef(-10, 30, -50.0); // x, y, z

		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		gluSphere(quad, 5, 50, 50);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void luna() {

	// Agregando imagen:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[1]);
	glColor3ub(255, 255, 255);

	glPushMatrix();
	    glTranslatef(-8, 17, -50.0); // x, y, z

		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		gluSphere(quad, 3.5, 50, 50);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void planetaSaturno() {

	// Agregando imagen:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[5]);
	glColor3ub(255, 255, 255);

	glPushMatrix();
	    glTranslatef(30, 30, -40.0); // x, y, z
		//glRotatef(50, -3, 0.0, 0.0);
		glRotatef(-115, -1, 0.0, 0.0);

		// Dibujar Saturno:
		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		gluSphere(quad, 8, 50, 50);

		//glColor3f(0.4588, 0.3607, 0.2705); // Marrón oscuro (aproximado)
		//glutSolidSphere(8, 100, 100);
		//glRotatef(50, -3, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix(); // Dibujar el anillo de Saturno
	    glTranslatef(30, 30, -40.0); // x, y, z

	    //glScaled(1.15, 1, 1);  // Escala el objeto: X (1.15, +15%)
		glScaled(1, 1, 1);
		glRotatef(-115, -1, 0.0, 0.0); // Inclinar los anillos

	    glColor3f(0.5, 0.5, 0.5); // Color 
	    glutSolidTorus(0.8, 12, 50, 50); // anillo 1
    glPopMatrix();

	glPushMatrix(); // Dibujar el anillo de Saturno
	    glTranslatef(30, 30, -40.0); // x, y, z
	   

	    //glScaled(1.35, 1.20, 1.20);  // Escala el objeto: X (1.15, +15%)
		glScaled(1.20, 1.20, 1.20);
		glRotatef(-115, -1, 0.0, 0.0); // Inclinar los anillos


	    glColor3f(255, 0.5, 0.5); // Color 
	    glutSolidTorus(0.8, 12, 50, 50); // anillo 1
	glPopMatrix();
}

void planetas() {

	sol();
	planetaSaturno();

	planetaTierra();
	luna();

}

/*--------------------------------------------------------------
# Astronauta:
--------------------------------------------------------------*/
void bota(double posX) {
	glPushMatrix();
	glTranslated(posX, 0.2, 0);
	glScaled(1, 0.9, 1.5);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(posX, 0.2, -0.46);
	glScaled(0.9, 1, 1);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1, 1, 0.8, 50, 50);
	glPopMatrix();
}
void pierna(double posX) {
	glPushMatrix();
	glTranslated(posX, 1, -0.46);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1.04, 1.04, 5, 50, 50);
	glPopMatrix();
}
void cuerpo() {
	glPushMatrix();
	glTranslated(0, 7, -0.46);
	glScaled(1.1, 1, 0.7);
	glRotated(-90, 1, 0, 0);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 6, -0.46);
	glScaled(1, 1, 0.6);
	glRotated(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 2.3, 2.6, 4, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 9.6, -0.46);
	glScaled(1.15, 1, 0.7);
	glRotated(-90, 1, 0, 0);
	glutSolidSphere(2.3, 50, 50);
	glPopMatrix();
}
void casco() {
	glPushMatrix();
	glTranslated(0, 13.6, 0.24);
	glScaled(1, 1, 0.5);
	glRotated(10, 1, 0, 0);
	glutSolidTorus(1.06, 1.08, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 13.6, -0.6);
	glutSolidSphere(2.2, 50, 50);
	glPopMatrix();
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glTranslated(0, 13.58, -0.3);
	glutSolidSphere(2.04, 50, 50);
	glPopMatrix();
}
void brazo(double posX, int rot, int romHombro) {
	glPushMatrix();
	glTranslated(posX, 10.6, 0);
	glRotated(romHombro, 0, 0, 1);
	glScaled(1, 1.5, 1);
	glutSolidSphere(0.6, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(posX, 10.6, 0);
	glRotated(rot, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 0.7, 0.68, 2.7, 50, 50);
	glPopMatrix();
}
void antebrazo(double posX) {
	glPushMatrix();
	glTranslated(posX, 8.2, 0);
	glRotated(90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 0.68, 0.65, 2.5, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslated(posX, 5.8, 0);
	glScaled(1, 1, 1);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
}

void astronauta() {
	glPushMatrix();
	glColor3ub(255, 255, 255);
	bota(1.2);
	bota(-1.2);
	pierna(1.2);
	pierna(-1.2);
	cuerpo();
	brazo(-2, -20, -60);
	brazo(2, 20, 60);
	antebrazo(3);
	antebrazo(-3);
	casco();
	glPopMatrix();
}


// --------- 

void dibujar() {

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(radio * cos(angulo), camaraY, radio * sin(angulo), 0, centroY, 0, 0, 1, 0);
	//glClearColor(255 / 255.0, 255 / 255.0, 208 / 255.0, 1); // amarillos palido:
	glClearColor(0.2, 0.2, 0.15, 1); // Color de fondo oscuro y pálido
	glPushMatrix();

	piso();
	ejes();

	// Project:

	paredes();
	planetas();
	astronauta();

	// -------

	glPopMatrix();
	glutSwapBuffers();

}

void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}

void teclado(int tecla, int x, int y) {

	//cout << "Angulo: " << angulo << " Camara Y: " << camaraY << " Radio: "
		//<< radio << " CentroY: " << centroY << "\n";

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
	glutCreateWindow("Project - Astraonauta");
	cargarImagenes();
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
