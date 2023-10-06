#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

float camaraX = -30;
float camaraY = 20;
float camaraZ = 50;

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

// HACIENDO PERSONAJE - 3D:

void pie(float posX) {
	glPushMatrix();
	   glTranslated(posX, 0, 0); // Para tener 2 pies uno ala ISQUIERDA y DERECHA.  | POSICION
	   glScaled(3, 0.5, 3); // x(ancho), y(Altura), z(ancho) | scaled porque el pie esta en el suelo.

	   // Para hacer cilindro:
	   glutSolidSphere(1.5, 50, 50); // radio, slices, stacks| SolidSphere -> Circulo Plano
	glPopMatrix();
}

void pierna(float posX) { // Cilindro
	glPushMatrix();
	    glTranslated(posX, 0, 0); // Para posicionar las 2 piernas.  | POSICION
	    glRotated(-90, 1, 0, 0); // Angulo, X, Y,Z | Para parar el Cilindro.

		// Para hacer cilindro:
	    gluCylinder(gluNewQuadric(), 4, 4, 4, 50, 50); // Radio(base), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void cuerpo() { // Cilindro
	glPushMatrix();
	    glTranslated(0, 3.5, 0); // X,  Y(alto),  Z  | POSICION

	    glScaled(1, 0.7, 1); // Z(tamañoReal), y(achicar), Z(tamañoReal) | Reducir, si es menor a 1 lo Achica.

	    glRotated(-90, 1, 0, 0); // Angulo, X, y,z | Para parar el Cilindro.

		// Para hacer cilindro:
	    gluCylinder(gluNewQuadric(), 8, 6, 10, 50, 50); // Radio(base_ancho), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void brazo(float posX, float rot) { // Cilindro
	glPushMatrix(); 
	    glTranslated(posX, 9, 0); // X,  Y(alto),  Z  | POSICION

	    glRotated(90, 0, 1, 0); // Angulo, X, Y, Z | Para parar el Cilindro-Brazo y ROTAR.
		glRotated(rot, 1, 0, 0); // Angulo, X, Y, Z | Poner VERTICAL

		// Para hacer cilindro:
	    gluCylinder(gluNewQuadric(), 1.5, 1.5, 5, 50, 50); // Radio(base_ancho), radio(superior), Altura, slices, stacks | Cilindro
	glPopMatrix();
}

void mano(float posX) {
	glPushMatrix();
	     glTranslated(posX, 5, 0); // X,  Y(alto),  Z | y 2 Manos si se pone -> posX.

		 glScaled(1, 0.75, 0.65); // Z(tamañoReal), y(Achicar), Z(tamañoReal) | Reducir

		 // Para una esfera solida:
		 glutSolidSphere(2, 50, 50); // radio, slices, stacks| SolidSphere -> Circulo Plano
	glPopMatrix();
}

void corbata() {
	glPushMatrix();
	    glTranslated(0, 7, 6.6); // X, Y(alto), Z  | POSICION

		glRotated(-16, 1, 0, 0); // Angulo, X, Y, Z | para inclinar -16
		glScaled(0.5, 7, 1);

		// Para dibujar un cubo sólido con lados de longitud 1.0
	    glutSolidCube(1);
	glPopMatrix();
}

void bufanda() {
	glPushMatrix();
	    glTranslated(0, 10, 0); // X, Y(alto), Z | POSICION

	    glRotated(-90, 1, 0, 0); // Angulo, X, Y, Z | para inclinar -90
	    glScaled(0.6, 0.6, 0.6); // 0.6 reducir un 60%

		// Para dibujar una dona, anillos, rueda, ETC.
	    glutSolidTorus(1, 10, 50, 50); // 1(radio -> el interior), 10(Radio -> el tamaño), sides, rings
	glPopMatrix();
}

void cabeza() {
	glPushMatrix();
	    glTranslated(0, 15.2, 0); // X, Y(alto), Z | POSICION

	    //glRotated(-90, 1, 0, 0); // Angulo, X, Y, Z | para inclinar -16
	    //glScaled(0.6, 0.6, 0.6); // 0.6 reducir un 60%

		// Dibuja una esfera solida:
	    glutSolidSphere(8.2, 50, 50); // 1(extension - Crecer), slices, stacks
	glPopMatrix();
}

void aroGorra() {
	glPushMatrix();
	    glTranslated(0, 18, 0); // X, Y(alto), Z | POSICION

		glRotated(-90, 1, 0, 0); // Angulo, X, Y, Z | para inclinar -16
		//glScaled(0.6, 0.6, 0.6); // 0.6 reducir un 60%

		// Para dibujar una dona, anillos, rueda, ETC.
		glutSolidTorus(1, 7.3, 50, 50); // 1(radio -> el interior), 10(Radio -> el tamaño), sides, rings
	glPopMatrix();
}

void gorra() {
	glPushMatrix();
	    glTranslated(0, 16, 0); // X, Y(alto), Z | POSICION

		// Dibuja una esfera solida:
		glutSolidSphere(7.9, 50, 50); // 1(extension - crecer), slices, stacks
	glPopMatrix();
}

void pompom() {
	glPushMatrix();
		glTranslated(0, 23.5, 0); // X, Y(alto), Z | POSICION

		// Dibuja una esfera solida:
		glutSolidSphere(1.8, 50, 50); // 1(extension - crecer), slices, stacks
	glPopMatrix();
}

void ojos(float posX, float rot) {
	glPushMatrix();

	    // Translada el objeto a la posición deseada (X: 0, Y: 15, Z: 6.9)
	    glTranslated(posX, 15, 6.9); // X, Y(alto), Z | POSICION

		// Rota el objeto en el plano XY para inclinarlo en -? grados
		glRotated(rot, 0, 0, 1); // Angulo, X, Y, Z | para inclinar -?

		// Escala el objeto: X (0.9, -10%), Y (0.7, -30%), Z (0.6, -40%)
		glScaled(0.9, 0.7, 0.6); 

		//Dibuja una esfera solida de 2.5:
		glutSolidSphere(2.8, 50, 50); // 1(extension - crecer), slices, stacks

	glPopMatrix();
}

void pupila(float posX) {
	glPushMatrix();

	    // Translada el objeto a la posición deseada (X: 0, Y: 15, Z: 6.9)
	    glTranslated(posX, 15, 7.9); // X, Y(alto), Z(mas afuera) | POSICION

		//Dibuja una esfera solida de 1:
		glutSolidSphere(1, 50, 50); // 1(radio - extension - crecer), slices, stacks

	glPopMatrix();
}

void boca() {
	glPushMatrix();

	    // Translada el objeto a la posición deseada (X: 0, Y: 12, Z: 1)
	    glTranslated(0, 12, 7); // Ajusta la posición según tus necesidades

		// Escala el objeto para darle forma a la boca
		glScaled(0.6, 0.4, 0.2); // Ajusta los valores según tus necesidades

		// Dibuja una esfera sólida que representa la boca
		glutSolidSphere(3.5, 50, 50); // Ajusta el radio y la calidad según tus necesidades

	glPopMatrix();
}


// --------------------------------------------------

void dibujar() {

	inicializarLuces();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);

	glClearColor(255 / 255.0, 255 / 255.0, 200 / 255.0, 1); // Color de FONDO amarillo

	glPushMatrix();
	    glRotated(angulo, 0, 1, 0);
		piso();
		ejes();

		// Personaje - 3D:

		glColor3ub(170, 120, 10); // Marron
		pie(3); // derecha.
		pie(-3); // isquierda.

		glColor3ub(250, 141, 0); // Naranja
		pierna(3);
		pierna(-3);

		cuerpo();

		brazo(5, 50);  // 5 derecha | Rotacion 50 grados
		brazo(-5, 130); // -5 isquierda | Rotacion 130 grados

		glColor3ub(104,62, 2); // Marron
		mano(8);
		mano(-8);

		glColor3ub(0, 0, 0); // Negro
		corbata();

		glColor3ub(44, 226, 250); // Celeste
		bufanda();

		glColor3ub(249, 230, 171); // Color PIEL
		cabeza();

		glColor3ub(255, 196, 4); // Celeste
		aroGorra();

		glColor3ub(90, 59, 30); // Marron
		gorra();

		glColor3ub(255, 196, 4); // Celeste
		pompom();

		glColor3ub(255, 255, 255); // Blanco
		ojos(1.7, -45); // Ojo 1 | POSICION y Rotacion
		ojos(-1.7, 45); // Ojo 2

		glColor3ub(0, 0, 0); // Negro
		pupila(1.8);  //  X
		pupila(-1.8); // -X

		glColor3ub(0, 0, 0); // Negro
		boca();

	    // --------------

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
	glutCreateWindow("Semana 7 - DIBUJOS 3D");
	glutReshapeFunc(iniciarVentana);
	glutDisplayFunc(dibujar);
	glutSpecialFunc(teclado);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;

}