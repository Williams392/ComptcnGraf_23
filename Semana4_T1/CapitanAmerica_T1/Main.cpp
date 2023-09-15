#include <GL/glut.h>
#include <math.h> 

void Escudo1() {
	glBegin(GL_POLYGON); 
	glColor3ub(137, 199, 194); // azul 1
	   glVertex2i(1.17556, 8.50855); // c
	   glVertex2i(2.49699, 9); // f
	   glVertex2i(4.11087, 9); // e
	   glVertex2i(3.79676, 7.03007); // d   
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 140, 169); // azul 2
	    glVertex2i(1.17556, 8.50855); // c
	    glVertex2i(0.20325, 4.21262); // i
	    glVertex2i(2.04607, 3.82773); // h
	    glVertex2i(3.79676, 7.03007); // d
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 141, 164); // azul 3
	   glVertex2i(2, 3.8); // e
	   glVertex2i(0.2, 4.2); // f
	   glVertex2i(0.2, 2.6); // g
	glEnd();
}

void Escudo2() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 158, 108); // rojo 2
	   glVertex2i(4.11087, 9); // e
	   glVertex2i(4.5, 9); // r
	   glVertex2i(4.2411, 7.3612); // w
	   glVertex2i(3.79676, 7.03007); // d
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 70, 59); // rojo 2
	   glVertex2i(3.79676, 7.03007); // d
	   glVertex2i(4.2411, 7.3612); // w
	   glVertex2i(4.22791, 4.38728); // j
	   glVertex2i(2.04607, 3.82773); // h 
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(207, 44, 24); // rojo 2
	   glVertex2i(2.04607, 3.82773); // h 
	   glVertex2i(4.22791, 4.38728); // j
	   glVertex2i(0.21126, 1); // d1
	   glVertex2i(0.19158, 2.60306); // g
	glEnd();
}

// blanco en e medio:
void Escudo3() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255); // color blanco
	   glVertex2i(4.2411, 9); // r
	   glVertex2i(6.66396, 9); // s
	   glVertex2i(5.61117, 4.76431); // v
	   glVertex2i(4.22791, 4.38728); // j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(207, 255, 255); // rojo claro
	   glVertex2i(5.61117, 4.76431); // v
	   glVertex2i(4.22791, 4.38728); // j
	   glVertex2i(0.21126, 1); // d1
	   glVertex2i(0, 0); // C1
	   glVertex2i(2.49618, 0.00985); // K
	glEnd();
}

void Escudo4() { // rojo ultimo 3
	glBegin(GL_POLYGON);
	glColor3ub(255, 74, 49); // rojo
	   glVertex2i(6.66, 9); // s
	   glVertex2i(8.07, 9); // t
	   glVertex2i(7.53954, 5.25422); // u
	   glVertex2i(5.61117, 4.76431); // v
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(200, 29, 18); // rojo
	   glVertex2i(5.61117, 4.76431); // v
	   glVertex2i(7.53954, 5.25422); // u
	   glVertex2i(5.88748, 1.7055); // b1
	   glVertex2i(4.17, 0); // A1
	   glVertex2i(2.49618, 0.00985); // K
	glEnd();
}



void Escudo() {
	Escudo1();
	Escudo2();
	Escudo3();
	Escudo4();
}

void Cuerpo() {

	glBegin(GL_POLYGON);
	glColor3ub(0, 24, 63); // AZUL
	   glVertex2i(7.5166, 5.22321); // A
	   glVertex2i(5.91637, 1.71161); // F
	   glVertex2i(6.65934, 1.17821); // E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(1, 18, 82); // AZUL
	   glVertex2i(7.5166, 5.22321); // A
	   glVertex2i(6.65934, 1.17821); // E
	   glVertex2i(8.16431, 2); // D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(6, 0, 1); // negro
	   glVertex2i(4.16492, 1.26026); // F
	   glVertex2i(2.88523, 0.01009); // G
	   glVertex2i(3.54476, 0.01009); // H
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(102, 104, 105); // Promo
	   glVertex2i(5.91637, 1.71161); // F
	   glVertex2i(5, 0); // H
	   glVertex2i(5.64023, 0); // I
	   glVertex2i(6.65934, 1.17821); // E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(102, 104, 105); // Promo
	   glVertex2i(5.91637, 1.71161); // F
	   glVertex2i(5, 0); // H
	   glVertex2i(5.64023, 0); // I
	   glVertex2i(6.65934, 1.17821); // E
	glEnd();

}


void dibujar() {

	glLoadIdentity();
	gluOrtho2D(0, 16, 0, 9); // tamaño de la img X(16) - Y(9)
	glClear(GL_COLOR_BUFFER_BIT);

	Escudo();
	Cuerpo();

	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(912, 513); // Resolución de la IMG
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Capitan America");
	glutDisplayFunc(dibujar);

	glutMainLoop();
	return 0;
}