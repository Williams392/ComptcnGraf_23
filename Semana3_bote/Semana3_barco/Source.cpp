#include <GL/glut.h>
#include <math.h> // para usar las variables
#include <ctime> // paras las estrellas

void cielo() {
	glBegin(GL_POLYGON);
	   glColor3ub(253, 40, 6); // Naranja
	   glVertex2d(0, 12);
	   glVertex2d(17, 12);
	   glColor3ub(248, 201, 155);
	   glVertex2d(17, 4);
	   glVertex2d(0, 4);
	glEnd();
}

void mar() {
	glBegin(GL_POLYGON);
	   glColor3ub(250, 42, 9); // naranja
	   glVertex2d(0, 4); // Todo estas medidas por GEOGEBRA
	   glVertex2d(17, 4);
	   glColor3ub(3, 173, 237); // celeste
	   glVertex2d(17, 0);
	   glVertex2d(0, 0);
	glEnd();
}

void sol1() {
	float radio = 3.13;
	float cx, cy;
	glBegin(GL_POLYGON);
	glColor3ub(250, 218, 186);
	for (double i = 0; i < 3.14 * 2; i += 0.001) {
		cx = radio * cos(i);
		cy = radio * sin(i);
		glVertex2d(cx + 2.2, cy + 10.7); // Posicion
	}
	glEnd();
}

void sol2() {
	float radio = 3.13;
	float cx, cy;
	glBegin(GL_POLYGON);
	glColor3ub(218, 94, 84);
	for (double i = 0; i < 3.14 * 2; i += 0.001) {
		cx = radio * cos(i);
		cy = radio * sin(i);
		glVertex2d(cx + 2, cy + 11); // Posicion
	}
	glEnd();
}

void barco() {
	// Sangria posicion (control + z):
	glBegin(GL_POLYGON);

	// BOTE base(geogebra):
	glColor3ub(0, 0, 0); // negro
	   glVertex2d(7, 2.5); // Todo estas medidas por GEOGEBRA
	   glVertex2d(11.5, 2.5);
	   glVertex2d(11, 2);
	   glVertex2d(7.5, 2);
	glEnd();
}

// bote mastil, el palo:
void mastil() {
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0); // negro
	   glVertex2d(9.3, 2.5); // Todo estas medidas por GEOGEBRA(cuidado con el ZOM)
	   glVertex2d(9.3, 5);
	   glVertex2d(9.2, 5); // grueso
	   glVertex2d(9.2, 2.5);
	glEnd();
}

void vela1() {
	glBegin(GL_POLYGON);
	glColor3ub(242, 156, 139); // naranja
	   glVertex2d(9.3, 2.5); // Todo estas medidas por GEOGEBRA(cuidado con el ZOM)
	   glVertex2d(9.3, 5);
	   glVertex2d(10.5, 3.2); // grueso
	   glVertex2d(9.3, 2.5);
	glEnd();
}

void vela2() {
	glBegin(GL_POLYGON);
	glColor3ub(242, 156, 139); //	Naranja
	   glVertex2d(9.2, 2.5); // Todo estas medidas por GEOGEBRA(cuidado con el ZOM)
	   glVertex2d(9.2, 4.5);
	   glVertex2d(8.2, 3.2); // grueso
   	   glVertex2d(9.2, 2.5);
	glEnd();
}

void estrellas() {
	srand(time(NULL));
	glPointSize(5);
	glBegin(GL_POINTS);
	    glColor3ub(250, 150, 250);
	    for (int i = 0; i < 10; i++) {
		    int cx = rand() % (16 - 0 + 1) + 0; // Mitad
		    int cy = rand() % (12 - 6 + 1) + 6; // donde se va mostrar las Est
		    glVertex2d(cx, cy);
	    }
	glEnd();
}

void caballo() {
	// Cuerpo del caballo (rectángulo marrón)
	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19); // Marrón
	glVertex2d(5, 2.5);
	glVertex2d(6, 2.5);
	glVertex2d(6, 4.5);
	glVertex2d(5, 4.5);
	glEnd();

	// Cabeza del caballo (rectángulo marrón)
	glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19); // Marrón
	glVertex2d(4.5, 4.5);
	glVertex2d(6.5, 4.5);
	glVertex2d(6.5, 5);
	glVertex2d(4.5, 5);
	glEnd();

	// Ojos (círculos negros)
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0); // Negro
	for (double i = 0; i < 3.14 * 2; i += 0.001) {
		float cx = 0.2 * cos(i);
		float cy = 0.2 * sin(i);
		glVertex2d(cx + 5.2, cy + 4.75); // Posición del ojo izquierdo
		glVertex2d(cx + 6, cy + 4.75);   // Posición del ojo derecho
	}
	glEnd();

	// Cola (línea marrón)
	glBegin(GL_LINES);
	glColor3ub(139, 69, 19); // Marrón
	glVertex2d(5.5, 4.5);
	glVertex2d(5.5, 5.5);
	glEnd();
}

void barcoComleto() {
	barco();
	mastil();
	vela1();
	vela2();
}

void dibujar(){

	glLoadIdentity();
	gluOrtho2D(0, 17, 0, 12); // tamaño de la img X - Y
	glClear(GL_COLOR_BUFFER_BIT);

	cielo();
	mar();
	sol1();
	sol2();
	barcoComleto();
	estrellas();

	caballo();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1100, 779); // Resolucion de la IMG
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Semana 3");
	glutDisplayFunc(dibujar);

	glutMainLoop();
	return 0;
}