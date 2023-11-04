#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <time.h>
#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <vector>


using namespace std;

float camaraX = -30;
float camaraY = 50;//30
float camaraZ = 55;//50

float angulo = 0;

struct Estrella {
	float x, y, z;
};

std::vector<Estrella> estrellas;



void iniciarVentana(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, (float)w / (float)h, 1, 200);

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

void inicializarEstrellas(int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		Estrella estrella;
		estrella.x = rand() % 100 - 50;  // Coordenadas aleatorias entre -50 y 50
		estrella.y = rand() % 100 - 50;
		estrella.z = rand() % 100 - 50;
		estrellas.push_back(estrella);
	}
}


void fondoEspacial() {
	glPushMatrix();
	glDisable(GL_LIGHTING);  // Deshabilitamos la iluminación para dibujar las estrellas
	glColor3f(1.0, 1.0, 1.0);  // Color blanco para las estrellas

	glBegin(GL_POINTS);
	for (const Estrella& estrella : estrellas) {
		glVertex3f(estrella.x, estrella.y, estrella.z);
	}
	glEnd();

	glEnable(GL_LIGHTING);  // Habilitamos nuevamente la iluminación
	glPopMatrix();
}






const int TAMANO_TERRENO = 900; // Tamaño de la cuadrícula
float terreno[TAMANO_TERRENO][TAMANO_TERRENO]; // Alturas del terreno

// Función para inicializar el terreno
void inicializarTerreno() {
	for (int i = 0; i < TAMANO_TERRENO; i++) {
		for (int j = 0; j < TAMANO_TERRENO; j++) {
			terreno[i][j] = ((rand() % 100) / 100.0) * 5; // Variación aleatoria entre 0 y 5
		}
	}
}

void dibujarTerreno() {
	float centro = TAMANO_TERRENO / 2.0;


	glColor3f(109.0f / 255.0f, 159.0f / 255.0f, 184.0f / 255.0f);

	for (int x = 0; x < TAMANO_TERRENO - 1; x++) {
		for (int z = 0; z < TAMANO_TERRENO - 1; z++) {
			float dx = x - centro;
			float dz = z - centro;
			float distancia = sqrt(dx * dx + dz * dz);
			float alturaCurva = -distancia * distancia / (TAMANO_TERRENO); // Cuanto más lejos del centro, más "curvado" hacia abajo estará

			glBegin(GL_QUADS);
			glVertex3f(x, terreno[x][z] + alturaCurva, z);
			glVertex3f(x + 1, terreno[x + 1][z] + alturaCurva, z);
			glVertex3f(x + 1, terreno[x + 1][z + 1] + alturaCurva, z + 1);
			glVertex3f(x, terreno[x][z + 1] + alturaCurva, z + 1);
			glEnd();
		}
	}
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




void planeta1() {
	glPushMatrix();
	glTranslated(-30, 25, -35);  // Cambia estas coordenadas para ajustar la posición del planeta
	glColor3ub(159, 224, 252);  // Color marrón, puedes cambiarlo
	glutSolidSphere(11, 50, 50);  // Radio = 5, ajusta el radio si es necesario
	glPopMatrix();
}

void planeta2() {
	glPushMatrix();
	glTranslated(10, 10, -55);  // Cambia estas coordenadas para ajustar la posición del planeta
	glColor3ub(105, 142, 169);  // Color verde, puedes cambiarlo
	glutSolidSphere(8, 50, 50);  // Radio = 8
	glPopMatrix();
}

void planeta3() {
	glPushMatrix();
	glTranslated(-25, 5, -30);  // Cambia estas coordenadas para ajustar la posición del planeta
	glColor3ub(253, 118, 99);  // Color púrpura, puedes cambiarlo
	glutSolidSphere(4, 50, 50);  // Radio = 4
	glPopMatrix();
}








void saturno() {

	//Espera centrl
	glPushMatrix();
	glTranslated(0, 15.2, 0);
	glColor3ub(178, 220, 244); // Cambio de color para que se parezca a Saturno
	glutSolidSphere(12, 50, 50);
	glPopMatrix();


	// Primero aplica las transformaciones generales que afectan a todo el objeto.
	glPushMatrix();
	glTranslated(0, 18, 0);
	glRotated(-115, 1, 0, 0);

	// Ahora, en lugar de aplicar la escala aquí, vamos a empujar una nueva matriz para cada anillo
	// y aplicar la escala solo a ese anillo específico.

	// Primer anillo (más cercano a Saturno)
	glPushMatrix();  // Empuja una nueva matriz para este anillo
	glScaled(3.15, 3.15, 3.15);
	glColor3ub(234, 247, 253);
	glutSolidTorus(0.45, 6.0, 50, 50);
	glPopMatrix();  // Regresa al estado anterior después de dibujar el anillo

	// Segundo anillo
	glPushMatrix();  // Nuevo estado solo para el segundo anillo
	glScaled(1.1 * 3.15, 1.1 * 3.15, 1.1 * 3.15);  // 3.15 * 1.1 = 3.465
	glColor3ub(226, 243, 252);
	glutSolidTorus(0.45, 6.3, 50, 50);
	glPopMatrix();  // Regresa al estado previo

	// Finalmente, regresamos al estado original antes de la función

	glPopMatrix();
}


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






void dibujar() {

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearColor(4 / 255.0, 33 / 255.0, 47 / 255.0, 1);

	glPushMatrix();


	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat light1_position[] = { 2.0, 2.0, 2.0, 0.0 };
	GLfloat light1_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glEnable(GL_LIGHT1);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005);




	glRotated(angulo, 0, 1, 0);

	fondoEspacial();


	glPushMatrix();
	glTranslated(-600, 120, -80);
	dibujarTerreno();
	glPopMatrix();

	//ejes();

	glPushMatrix();
	glScalef(1.3, 1.3, 1.3);
	glTranslated(60, -20, 0);
	saturno();
	glPopMatrix();

	planeta1();
	planeta2();
	planeta3();

	glPushMatrix();
	glScaled(0.5, 0.5, 0.5);
	glRotated(180, 0, 1, 0);
	glTranslated(0, -80, -40);
	astronauta();
	glPopMatrix();
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
	srand(time(NULL));
	inicializarEstrellas(200);
	glutCreateWindow("T3 - Espacial");
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;

}