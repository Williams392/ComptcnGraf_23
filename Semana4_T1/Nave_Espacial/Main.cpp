#include<GL/glut.h>
#include<string.h>
//#include<glm\glm.hpp>
#include<math.h>
int id1, id2, id3, id4, id5, i = 0.0, temp = 0, temp1 = 0;
float j = 0.0, h = 0.0, g = 0.0, t = 0.0, l = 0.0, y = 0.0, z = 0.0, c = 0.0, r = 0.0, s = 0.0, q = 0.0, v = 0.0, a = 0.0, s1 = 0.0;
float a1 = 0.0, a2 = 0.0, q1 = 0.0, q2 = 0.0, q3 = 0.0, q4 = 1.0, q5 = 0.0, q6 = 0.0, q7 = 0.0, q8 = 0.0, v1 = 0.0, v2 = 0.0;

char one_str1[] = "Poor Minion !!!!";
char one_str2[] = "He has unknowingly killed his boss.";
char one_str3[] = "And now the boss's assistant is all";
char one_str4[] = "set to destroy his master's killer.";

char two_str1[] = "While chasing, someone throws a";
char two_str2[] = "bomb at the enemy and kills it.";
char two_str3[] = "The Minion is amazed.";
char two_str4[] = "Who did this ?";

char three_str1[] = "The Minion meets his new master.";

char four_str1[] = "At last...............the Minion has";
char four_str2[] = "found a worthy boss named GRU.";
char four_str3[] = "when GRU kills his previous boss,";
char four_str4[] = "who was about to take revenge upon";
char four_str5[] = "minion.";


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(220, 450);
	glColor3f(0.0, 0.0, 0.0);
	char str[] = "Srinivas Institute of Technology";
	glRasterPos2f(384, 950); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str1[] = "Valachil,Mangaluru";
	glRasterPos2f(440.5, 900); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str2[] = "Department of Computer Science and Engineering";
	glRasterPos2f(350, 850); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str3[] = "COMPUTER GRAPHICS AND VISUALIZATION";
	glRasterPos2f(354, 800); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str3[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str4[] = "MINI PROJECT";
	glRasterPos2f(435, 700); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str5[] = "ON";
	glRasterPos2f(485, 600); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str5); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str6[] = "MINION'S : QUEST ";
	glRasterPos2f(360, 500); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str6); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str7[] = "Team Members";
	glRasterPos2f(75, 300); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str7); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str7[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str8[] = "Satvik K S-4sn15cs078";
	glRasterPos2f(50, 250); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str8); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str8[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str9[] = "Shreyas Kumar-4sn15cs085";
	glRasterPos2f(50, 200); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str9); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str10[] = "Project Guide";
	glRasterPos2f(670, 300); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str10); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str10[i]);
	}

	glColor3f(0.0, 0.0, 0.0);
	char str11[] = "Ms.Keerthana S";
	glRasterPos2f(670, 260); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str11); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	char str12[] = "Department of computer science and engineering";
	glRasterPos2f(670, 230); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str12); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str12[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	char str13[] = "SIT,Valachil.";
	glRasterPos2f(670, 200); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str13); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str13[i]);
	}
	glColor3f(0.0, 0.0, 0.0);
	char str14[] = "Press E/e to Continue";
	glRasterPos2f(430, 190); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str14); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]);
	}
	glFlush();
}

void stomach(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.6, 0.5, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}
void stomach1(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}
void head(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}

void ball(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(1.0, 0.0, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}

void face(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.8, 0.6, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}
void draweyeball(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}
void drawlense(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}
void message(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor3f(0.5, 0.5, 0.4);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}
void mouth1(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(1.0, 0.0, 0.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}
void villan1() {
	if (g >= 0.0) {
		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(500, 530 - g);
		glVertex2i(530, 530 - g);
		glVertex2i(520, 600 - g);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(470, 530 - g);
		glVertex2i(500, 530 - g);
		glVertex2i(480, 600 - g);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(400, 390 - g);
		glVertex2i(510, 400 - g);
		glVertex2i(510, 520 - g);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(510, 400 - g);
		glVertex2i(600, 390 - g);
		glVertex2i(510, 520 - g);
		glEnd();

		stomach(500, 410 - g, 60);
		head(500, 500 - g, 40);
		face(500, 490 - g, 30);
		draweyeball(490, 520 - g, 9);
		drawlense(490, 520 - g, 3);
		draweyeball(510, 520 - g, 9);
		drawlense(510, 520 - g, 3);
		mouth1(500, 485 - g, 20);
	}
	g += 0.5;
	glutPostRedisplay();

}
void villan2() {
	if (l <= 300.0) {
		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(500 + l, 530);
		glVertex2i(530 + l, 530);
		glVertex2i(520 + l, 600);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(470 + l, 530);
		glVertex2i(500 + l, 530);
		glVertex2i(480 + l, 600);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(400 + l, 390);
		glVertex2i(510 + l, 400);
		glVertex2i(510 + l, 520);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(510 + l, 400);
		glVertex2i(600 + l, 390);
		glVertex2i(510 + l, 520);
		glEnd();

		stomach(500 + l, 410, 60);
		head(500 + l, 500, 40);
		face(500 + l, 490, 30);
		draweyeball(490 + l, 520, 9);
		drawlense(490 + l, 520, 3);
		draweyeball(510 + l, 520, 9);
		drawlense(510 + l, 520, 3);
		mouth1(500 + l, 485, 20);
		if (c >= 550 && c <= 600) {
			message(800, 600, 10);
			message(850, 650, 20);
			message(900, 700, 50);
			glColor3f(1.0, 1.0, 1.0);
			char str11[] = "Oh... MY GOD..";
			glRasterPos2f(850, 700); //calculate points by refering previous text positions
			for (i = 0; i < strlen(str11); i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[i]);
			}
		}
		c += 1.0;

		l += 0.5;
		glutPostRedisplay();
	}
	else {
		if (c <= 5) {
			l = 300.0;
		}
		c += 1.0;


	}

}

void villan3() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(320, 700);
	glVertex2i(400, 700);
	glVertex2i(400, 710);
	glVertex2i(380, 710);
	glVertex2i(370, 730);
	glVertex2i(380, 760);
	glVertex2i(350, 760);
	glVertex2i(350, 710);
	glVertex2i(320, 710);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(330, 700);
	glVertex2i(340, 650);
	glVertex2i(360, 650);
	glVertex2i(380, 700);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(335, 670);
	glVertex2i(340, 650);
	glVertex2i(360, 650);
	glVertex2i(360, 670);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(340, 670);
	glVertex2i(355, 670);
	glVertex2i(350, 660);
	glEnd();

	stomach1(350, 620, 30);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(300, 630);
	glVertex2i(350, 630);
	glVertex2i(325, 650);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(370, 630);
	glVertex2i(410, 630);
	glVertex2i(385, 650);
	glEnd();
}
void villanfall() {
	if (v1 <= 300) {
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(320, 700 - v1);
		glVertex2i(400, 700 - v1);
		glVertex2i(400, 710 - v1);
		glVertex2i(380, 710 - v1);
		glVertex2i(370, 730 - v1);
		glVertex2i(380, 760 - v1);
		glVertex2i(350, 760 - v1);
		glVertex2i(350, 710 - v1);
		glVertex2i(320, 710 - v1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2i(330, 700 - v1);
		glVertex2i(340, 650 - v1);
		glVertex2i(360, 650 - v1);
		glVertex2i(380, 700 - v1);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(335, 670 - v1);
		glVertex2i(340, 650 - v1);
		glVertex2i(360, 650 - v1);
		glVertex2i(360, 670 - v1);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(340, 670 - v1);
		glVertex2i(355, 670 - v1);
		glVertex2i(350, 660 - v1);
		glEnd();

		stomach1(350, 620 - v1, 30);

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(300, 630 - v1);
		glVertex2i(350, 630 - v1);
		glVertex2i(325, 650 - v1);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(370, 630 - v1);
		glVertex2i(410, 630 - v1);
		glVertex2i(385, 650 - v1);
		glEnd();
	}
	v1 += 1.0;
	glutPostRedisplay();
}

void villan4() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(320, 700);
	glVertex2i(400, 700);
	glVertex2i(400, 710);
	glVertex2i(380, 710);
	glVertex2i(370, 730);
	glVertex2i(380, 760);
	glVertex2i(350, 760);
	glVertex2i(350, 710);
	glVertex2i(320, 710);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(330, 700);
	glVertex2i(340, 650);
	glVertex2i(360, 650);
	glVertex2i(380, 700);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(335, 670);
	glVertex2i(340, 650);
	glVertex2i(360, 650);
	glVertex2i(360, 670);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(340, 670);
	glVertex2i(355, 670);
	glVertex2i(350, 660);
	glEnd();

	stomach1(350, 620, 30);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(300, 630);
	glVertex2i(350, 630);
	glVertex2i(325, 650);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(370, 630);
	glVertex2i(410, 630);
	glVertex2i(385, 650);
	glEnd();
}


void gru() {
	drawlense(900, 700, 30);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(860, 520);
	glVertex2i(940, 520);
	glVertex2i(945, 670);
	glVertex2i(855, 670);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(863, 520);
	glVertex2i(900, 200);
	glVertex2i(937, 520);
	glEnd();

	/*if (q == 100.0) {
		if (q <= 100.0)
		{*/
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(855, 670);
	glVertex2i(840, 650);
	glVertex2i(860, 580);
	glEnd();

	/*}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(855, 670);
		glVertex2i(840, 660);
		glVertex2i(839, 675);
		glVertex2i(860, 660);
		glEnd();
	}
	q += 1.0;
}*/


	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(945, 670);
	glVertex2i(960, 650);
	glVertex2i(940, 580);
	glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}
void drawsun(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * 3.142;
	float r = 1.0, g = 0.6, b = 0.2;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}
void draweye(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 100;
	GLfloat twicePi = 2.0f * 3.142;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor4f(0.8, 0.8, 0.8, 1.0);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}

	glEnd();
}

void minion() {

	if (j >= 0.0) {

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(450, 390 - j);
		glVertex2f(500, 390 - j);
		glVertex2f(510, 410 - j);
		glVertex2f(510, 530 - j);
		glVertex2f(500, 550 - j);
		glVertex2f(450, 550 - j);
		glVertex2f(440, 530 - j);
		glVertex2f(440, 410 - j);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(510, 450 - j);
		glVertex2i(515, 450 - j);
		glVertex2i(515, 450 - j);
		glVertex2i(515, 400 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(513, 400 - j);
		glVertex2i(510, 390 - j);
		glVertex2i(520, 390 - j);
		glVertex2i(517, 400 - j);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(440, 450 - j);
		glVertex2i(436, 450 - j);
		glVertex2i(436, 450 - j);
		glVertex2i(436, 400 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(434, 400 - j);
		glVertex2i(431, 390 - j);
		glVertex2i(441, 390 - j);
		glVertex2i(440, 400 - j);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(440, 510 - j);
		glVertex2i(510, 510 - j);
		glEnd();
		draweye(460, 510 - j, 15);
		draweyeball(460, 510 - j, 9);
		drawlense(460, 510 - j, 3);
		draweye(490, 510 - j, 15);
		draweyeball(490, 510 - j, 9);
		drawlense(490, 510 - j, 3);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450, 390 - j);
		glVertex2i(500, 390 - j);
		glVertex2i(510, 410 - j);
		glVertex2i(510, 430 - j);
		glVertex2i(500, 425 - j);
		glVertex2i(500, 460 - j);
		glVertex2i(450, 460 - j);
		glVertex2i(450, 425 - j);
		glVertex2i(440, 430 - j);
		glVertex2i(440, 410 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450, 390 - j);
		glVertex2i(462, 380 - j);
		glVertex2i(469, 380 - j);
		glVertex2i(470, 390 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(480, 390 - j);
		glVertex2i(482, 380 - j);
		glVertex2i(490, 380 - j);
		glVertex2i(500, 390 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(462, 380 - j);
		glVertex2i(459, 370 - j);
		glVertex2i(469, 370 - j);
		glVertex2i(469, 380 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(482, 380 - j);
		glVertex2i(482, 370 - j);
		glVertex2i(493, 370 - j);
		glVertex2i(490, 380 - j);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(460, 470 - j);
		glVertex2i(490, 470 - j);
		glVertex2i(490, 490 - j);
		glVertex2i(460, 490 - j);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(490, 450 - j);
		glVertex2i(510, 460 - j);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(440, 460 - j);
		glVertex2i(460, 450 - j);
		glEnd();

	}
	temp = j;
	j += 1.0;

	glutPostRedisplay();



}



void minion1() {

	if (t <= 700.0) {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(450 + t, 390);
		glVertex2f(500 + t, 390);
		glVertex2f(510 + t, 410);
		glVertex2f(510 + t, 530);
		glVertex2f(500 + t, 550);
		glVertex2f(450 + t, 550);
		glVertex2f(440 + t, 530);
		glVertex2f(440 + t, 410);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(510 + t, 450);
		glVertex2i(515 + t, 450);
		glVertex2i(515 + t, 450);
		glVertex2i(515 + t, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(513 + t, 400);
		glVertex2i(510 + t, 390);
		glVertex2i(520 + t, 390);
		glVertex2i(517 + t, 400);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(440 + t, 450);
		glVertex2i(436 + t, 450);
		glVertex2i(436 + t, 450);
		glVertex2i(436 + t, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(434 + t, 400);
		glVertex2i(431 + t, 390);
		glVertex2i(441 + t, 390);
		glVertex2i(440 + t, 400);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(440 + t, 510);
		glVertex2i(510 + t, 510);
		glEnd();
		draweye(460 + t, 510, 15);
		draweyeball(460 + t, 510, 9);
		drawlense(460 + t, 510, 3);
		draweye(490 + t, 510, 15);
		draweyeball(490 + t, 510, 9);
		drawlense(490 + t, 510, 3);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450 + t, 390);
		glVertex2i(500 + t, 390);
		glVertex2i(510 + t, 410);
		glVertex2i(510 + t, 430);
		glVertex2i(500 + t, 425);
		glVertex2i(500 + t, 460);
		glVertex2i(450 + t, 460);
		glVertex2i(450 + t, 425);
		glVertex2i(440 + t, 430);
		glVertex2i(440 + t, 410);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450 + t, 390);
		glVertex2i(462 + t, 380);
		glVertex2i(469 + t, 380);
		glVertex2i(470 + t, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(480 + t, 390);
		glVertex2i(482 + t, 380);
		glVertex2i(490 + t, 380);
		glVertex2i(500 + t, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(462 + t, 380);
		glVertex2i(459 + t, 370);
		glVertex2i(469 + t, 370);
		glVertex2i(469 + t, 380);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(482 + t, 380);
		glVertex2i(482 + t, 370);
		glVertex2i(493 + t, 370);
		glVertex2i(490 + t, 380);
		glEnd();
		if (r != 1000.0) {
			glBegin(GL_POLYGON);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(460 + t, 470);
			glVertex2i(490 + t, 470);
			glVertex2i(490 + t, 490);
			glVertex2i(460 + t, 490);
			glEnd();
			r += 1.0;
		}
		else {
			drawlense(1170, 480, 7);
			message(1100, 500, 30);
			glColor3f(1.0, 1.0, 1.0);
			char str1[] = "Oh!!..";
			glRasterPos2f(1080, 500); //take midpoint of gluOrtho2D
			for (i = 0; i < strlen(str1); i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
			}
		}
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(490 + t, 450);
		glVertex2i(510 + t, 460);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(440 + t, 460);
		glVertex2i(460 + t, 450);
		glEnd();

		t += 1.0;
		glutPostRedisplay();

	}
	else
	{
		t = 700.0;
		glTranslatef(0, 0, 0);
		minion1();
		glTranslatef(0, 0, 0);

	}
}
void minionwalk() {
	if (v2 <= 700.0) {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(550 + v2, 390);
		glVertex2f(600 + v2, 390);
		glVertex2f(610 + v2, 410);
		glVertex2f(610 + v2, 530);
		glVertex2f(600 + v2, 550);
		glVertex2f(550 + v2, 550);
		glVertex2f(540 + v2, 530);
		glVertex2f(540 + v2, 410);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(610 + v2, 450);
		glVertex2i(615 + v2, 450);
		glVertex2i(615 + v2, 450);
		glVertex2i(615 + v2, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(613 + v2, 400);
		glVertex2i(610 + v2, 390);
		glVertex2i(620 + v2, 390);
		glVertex2i(617 + v2, 400);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(540 + v2, 450);
		glVertex2i(536 + v2, 450);
		glVertex2i(536 + v2, 450);
		glVertex2i(536 + v2, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(534 + v2, 400);
		glVertex2i(531 + v2, 390);
		glVertex2i(541 + v2, 390);
		glVertex2i(540 + v2, 400);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(540 + v2, 510);
		glVertex2i(610 + v2, 510);
		glEnd();
		draweye(560 + v2, 510, 15);
		draweyeball(560 + v2, 510, 9);
		drawlense(560 + v2, 510, 3);
		draweye(590 + v2, 510, 15);
		draweyeball(590 + v2, 510, 9);
		drawlense(590 + v2, 510, 3);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(550 + v2, 390);
		glVertex2i(600 + v2, 390);
		glVertex2i(610 + v2, 410);
		glVertex2i(610 + v2, 430);
		glVertex2i(600 + v2, 425);
		glVertex2i(600 + v2, 460);
		glVertex2i(550 + v2, 460);
		glVertex2i(550 + v2, 425);
		glVertex2i(540 + v2, 430);
		glVertex2i(540 + v2, 410);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(550 + v2, 390);
		glVertex2i(562 + v2, 380);
		glVertex2i(569 + v2, 380);
		glVertex2i(570 + v2, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(580 + v2, 390);
		glVertex2i(582 + v2, 380);
		glVertex2i(590 + v2, 380);
		glVertex2i(600 + v2, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(562 + v2, 380);
		glVertex2i(559 + v2, 370);
		glVertex2i(569 + v2, 370);
		glVertex2i(569 + v2, 380);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(582 + v2, 380);
		glVertex2i(582 + v2, 370);
		glVertex2i(593 + v2, 370);
		glVertex2i(590 + v2, 380);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(560 + v2, 470);
		glVertex2i(590 + v2, 470);
		glVertex2i(590 + v2, 490);
		glVertex2i(560 + v2, 490);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(590 + v2, 450);
		glVertex2i(610 + v2, 460);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(540 + v2, 460);
		glVertex2i(560 + v2, 450);
		glEnd();
	}
	else
	{
		v2 = 700.0;
		glTranslatef(0, 0, 0);
		minionwalk();
		glTranslatef(0, 0, 0);
	}
	v2 += 1.0;
	glutPostRedisplay();

}
void minion2() {
	if (s <= 100.0) {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(450 + s, 390);
		glVertex2f(500 + s, 390);
		glVertex2f(510 + s, 410);
		glVertex2f(510 + s, 530);
		glVertex2f(500 + s, 550);
		glVertex2f(450 + s, 550);
		glVertex2f(440 + s, 530);
		glVertex2f(440 + s, 410);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(510 + s, 450);
		glVertex2i(515 + s, 450);
		glVertex2i(515 + s, 450);
		glVertex2i(515 + s, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(513 + s, 400);
		glVertex2i(510 + s, 390);
		glVertex2i(520 + s, 390);
		glVertex2i(517 + s, 400);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(440 + s, 450);
		glVertex2i(436 + s, 450);
		glVertex2i(436 + s, 450);
		glVertex2i(436 + s, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(434 + s, 400);
		glVertex2i(431 + s, 390);
		glVertex2i(441 + s, 390);
		glVertex2i(440 + s, 400);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(440 + s, 510);
		glVertex2i(510 + s, 510);
		glEnd();
		draweye(460 + s, 510, 15);
		draweyeball(460 + s, 510, 9);
		drawlense(460 + s, 510, 3);
		draweye(490 + s, 510, 15);
		draweyeball(490 + s, 510, 9);
		drawlense(490 + s, 510, 3);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450 + s, 390);
		glVertex2i(500 + s, 390);
		glVertex2i(510 + s, 410);
		glVertex2i(510 + s, 430);
		glVertex2i(500 + s, 425);
		glVertex2i(500 + s, 460);
		glVertex2i(450 + s, 460);
		glVertex2i(450 + s, 425);
		glVertex2i(440 + s, 430);
		glVertex2i(440 + s, 410);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(450 + s, 390);
		glVertex2i(462 + s, 380);
		glVertex2i(469 + s, 380);
		glVertex2i(470 + s, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(480 + s, 390);
		glVertex2i(482 + s, 380);
		glVertex2i(490 + s, 380);
		glVertex2i(500 + s, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(462 + s, 380);
		glVertex2i(459 + s, 370);
		glVertex2i(469 + s, 370);
		glVertex2i(469 + s, 380);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(482 + s, 380);
		glVertex2i(482 + s, 370);
		glVertex2i(493 + s, 370);
		glVertex2i(490 + s, 380);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(460 + s, 470);
		glVertex2i(490 + s, 470);
		glVertex2i(490 + s, 490);
		glVertex2i(460 + s, 490);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(490 + s, 450);
		glVertex2i(510 + s, 460);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(20.0);
		glVertex2i(440 + s, 460);
		glVertex2i(460 + s, 450);
		glEnd();

		if (s == 100) {
			if (s1 <= 100) {
				message(500, 500, 30);
				glColor3f(1.0, 1.0, 1.0);
				char str1[] = "Boss.....";
				glRasterPos2f(480, 500); //take midpoint of gluOrtho2D
				for (i = 0; i < strlen(str1); i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
				}
			}
			s1 += 1.0;
		}

	}
	else {
		s = 100.0;
		glTranslatef(0, 0, 0);
		minion2();
		glTranslatef(0, 0, 0);
	}
	/*else if(s > 300.0)
	{

		glTranslatef(0, 0, 0);
		minionwalk();
		glTranslatef(0, 0, 0);
	}*/
	s += 1.0;
	glutPostRedisplay();

}

void minion3() {
	if (q <= 100.0) {
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(450 + q, 390);
		glVertex2f(500 + q, 390);
		glVertex2f(510 + q, 410);
		glVertex2f(510 + q, 530);
		glVertex2f(500 + q, 550);
		glVertex2f(450 + q, 550);
		glVertex2f(440 + q, 530);
		glVertex2f(440 + q, 410);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(510 + q, 450);
		glVertex2i(515 + q, 450);
		glVertex2i(515 + q, 450);
		glVertex2i(515 + q, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(513 + q, 400);
		glVertex2i(510 + q, 390);
		glVertex2i(520 + q, 390);
		glVertex2i(517 + q, 400);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(440 + q, 450);
		glVertex2i(436 + q, 450);
		glVertex2i(436 + q, 450);
		glVertex2i(436 + q, 400);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(434 + q, 400);
		glVertex2i(431 + q, 390);
		glVertex2i(441 + q, 390);
		glVertex2i(440 + q, 400);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(440 + q, 510);
		glVertex2i(510 + q, 510);
		glEnd();
		draweye(460 + q, 510, 15);
		draweyeball(460 + q, 510, 9);
		drawlense(460 + q, 510, 3);
		draweye(490 + q, 510, 15);
		draweyeball(490 + q, 510, 9);
		drawlense(490 + q, 510, 3);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(450 + q, 390);
		glVertex2i(500 + q, 390);
		glVertex2i(510 + q, 410);
		glVertex2i(510 + q, 430);
		glVertex2i(500 + q, 425);
		glVertex2i(500 + q, 460);
		glVertex2i(450 + q, 460);
		glVertex2i(450 + q, 425);
		glVertex2i(440 + q, 430);
		glVertex2i(440 + q, 410);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(450 + q, 390);
		glVertex2i(462 + q, 380);
		glVertex2i(469 + q, 380);
		glVertex2i(470 + q, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(480 + q, 390);
		glVertex2i(482 + q, 380);
		glVertex2i(490 + q, 380);
		glVertex2i(500 + q, 390);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(462 + q, 380);
		glVertex2i(459 + q, 370);
		glVertex2i(469 + q, 370);
		glVertex2i(469 + q, 380);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(482 + q, 380);
		glVertex2i(482 + q, 370);
		glVertex2i(493 + q, 370);
		glVertex2i(490 + q, 380);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(460 + q, 470);
		glVertex2i(490 + q, 470);
		glVertex2i(490 + q, 490);
		glVertex2i(460 + q, 490);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(490 + q, 450);
		glVertex2i(510 + q, 460);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(20.0);
		glVertex2i(440 + q, 460);
		glVertex2i(460 + q, 450);
		glEnd();

		q += 1.0;
		glutPostRedisplay();

	}
	else
	{
		q = 100.0;
		glTranslatef(0, 0, 0);
		minion3();
		glTranslatef(0, 0, 0);

	}
}


void clouds(void) {
	if (h <= 1000) {
		drawCircle(500.0 + h, 600.0, 50.0);
		drawCircle(520.0 + h, 640.0, 50.0);
		drawCircle(550.0 + h, 600.0, 50.0);

		drawCircle(300 + h, 800, 10);
		drawCircle(305 + h, 805, 10);
		drawCircle(310 + h, 800, 10);

		drawCircle(900 + h, 800, 25);
		drawCircle(910 + h, 810, 25);
		drawCircle(920 + h, 800, 25);



		drawCircle(500 - h, 600, 50);
		drawCircle(520 + h, 640, 50);
		drawCircle(550 + h, 600, 50);

		drawCircle(300 + h, 800, 10);
		drawCircle(305 - h, 805, 10);
		drawCircle(310 - h, 800, 10);

		drawCircle(900 - h, 800, 25);
		drawCircle(910 - h, 810, 25);
		drawCircle(920 - h, 800, 25);


		h += 0.2;
		glutPostRedisplay();

	}
	else {
		i = -500;
		glutPostRedisplay();
	}

}

void sun(void) {
	drawsun(915, 845, 40);

}
void sun1(void) {
	drawsun(250, 945, 40);

}

void board() {
	glBegin(GL_POLYGON);

	glColor3f(0.698, 0.133, 0.133);
	glVertex2i(0, 800);
	glVertex2i(300, 800);
	glVertex2i(300, 600);
	glVertex2i(0, 600);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 790);
	glVertex2i(290, 790);
	glVertex2i(290, 610);
	glVertex2i(10, 610);

	glEnd();
}

void scene1(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(0.5);

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);

	glVertex2i(0, 0);

	glVertex2i(1400, 0);

	glVertex2i(1400, 400);

	glVertex2i(0, 400);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.0, 0.0, 0.0);

	glVertex2i(0, 0);

	glVertex2i(1400, 0);

	glVertex2i(1400, 400);

	glVertex2i(0, 400);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);

	glVertex2i(200, 0);

	glVertex2i(800, 0);

	glVertex2i(600, 400);

	glVertex2i(400, 400);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0.5, 0.5, 0.4);

	glVertex2i(200, 0);

	glVertex2i(800, 0);

	glVertex2i(600, 400);

	glVertex2i(400, 400);

	glEnd();



	glBegin(GL_POLYGON);


	glColor3f(1.0, 1.0, 1.0);

	glVertex2i(0, 400);

	glVertex2i(1300, 400);

	glColor3f(0.2, 0.3, 1.0);

	glVertex2i(1300, 1300);

	glVertex2i(0, 1300);

	glEnd();


}

void board1() {
	glBegin(GL_POLYGON);

	glColor3f(0.698, 0.133, 0.133);
	glVertex2i(0, 800);
	glVertex2i(300, 800);
	glVertex2i(300, 600);
	glVertex2i(0, 600);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 790);
	glVertex2i(290, 790);
	glVertex2i(290, 610);
	glVertex2i(10, 610);

	glEnd();

}

void scene2() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);


	glColor3f(1.0, 1.0, 1.0);

	glVertex2i(0, 400);

	glVertex2i(1300, 400);

	glColor3f(0.2, 0.3, 1.0);

	glVertex2i(1300, 1300);

	glVertex2i(0, 1300);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.8, 0.7, 0.6);

	glVertex2i(0, 350);

	glVertex2i(1300, 350);

	glVertex2i(1300, 400);

	glVertex2i(0, 400);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);

	glVertex2i(0, 0);

	glVertex2i(1300, 0);

	glVertex2i(1300, 350);

	glVertex2i(0, 350);

	glEnd();

}

void board2() {
	glBegin(GL_POLYGON);

	glColor3f(0.698, 0.133, 0.133);
	glVertex2i(0, 500);
	glVertex2i(300, 500);
	glVertex2i(300, 300);
	glVertex2i(0, 300);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 490);
	glVertex2i(290, 490);
	glVertex2i(290, 310);
	glVertex2i(10, 310);

	glEnd();
}

void scene3() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);


	glColor3f(1.0, 1.0, 1.0);

	glVertex2i(0, 0);

	glVertex2i(1300, 0);

	glColor3f(0.2, 0.3, 0.9);

	glVertex2i(1300, 400);

	glVertex2i(0, 400);

	glEnd();

	glBegin(GL_POLYGON);


	glColor3f(1.0, 1.0, 1.0);

	glVertex2i(0, 400);

	glVertex2i(1300, 400);

	glColor3f(0.2, 0.3, 1.0);

	glVertex2i(1300, 1300);

	glVertex2i(0, 1300);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.6, 0.0);

	glVertex2i(0, 600);

	glVertex2i(300, 600);

	glVertex2i(350, 550);

	glVertex2i(320, 500);

	glVertex2i(400, 300);

	glVertex2i(0, 300);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.6, 0.0);

	glVertex2i(1300, 600);

	glVertex2i(800, 600);

	glVertex2i(900, 550);

	glVertex2i(950, 500);

	glVertex2i(850, 300);

	glVertex2i(1300, 300);

	glEnd();
	if (a1 <= 1000) {
		glBegin(GL_LINES);

		glColor3f(0.0, 0.0, 0.0);

		glVertex2i(300, 595);

		glVertex2i(820, 595);

		glEnd();
	}
	a1 += 1.0;

}

void board3() {
	glBegin(GL_POLYGON);

	glColor3f(0.698, 0.133, 0.133);
	glVertex2i(0, 500);
	glVertex2i(300, 500);
	glVertex2i(300, 300);
	glVertex2i(0, 300);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 490);
	glVertex2i(290, 490);
	glVertex2i(290, 310);
	glVertex2i(10, 310);

	glEnd();
}

void scene4() {
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.0, 1.0);
	glVertex2i(0, 0);
	glVertex2i(1300, 0);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(1300, 900);
	glVertex2i(0, 900);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0, 380);;
	glVertex2i(1300, 380);
	glVertex2i(1300, 0);
	glVertex2i(0, 0);
	glEnd();
}


void secondpage(void) {

	scene1();
	sun();
	clouds();
	board();
	minion();

	glColor3f(0, 0, 0);
	glRasterPos2f(15, 760); //calculate points by refering previous text positions
	for (i = 0; i < strlen(one_str1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, one_str1[i]);

	glRasterPos2f(15, 700); //calculate points by refering previous text positions
	for (i = 0; i < strlen(one_str2); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, one_str2[i]);

	glRasterPos2f(15, 660); //calculate points by refering previous text positions
	for (i = 0; i < strlen(one_str3); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, one_str3[i]);

	glRasterPos2f(15, 620); //calculate points by refering previous text positions
	for (i = 0; i < strlen(one_str4); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, one_str4[i]);


	if (temp >= 200) {

		villan1();
	}
	temp += 1.0;


	glColor3f(1.0, 1.0, 1.0);
	char str14[] = "Press F/f to Continue";
	glRasterPos2f(430, 190); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str14); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]);
	}

	glFlush();
}
void thirdpage() {
	float q = 0.0;
	scene2();

	sun1();
	clouds();
	board1();

	glColor3f(0, 0, 0);
	glRasterPos2f(15, 760); //calculate points by refering previous text positions
	for (i = 0; i < strlen(two_str1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, two_str1[i]);

	glRasterPos2f(15, 720); //calculate points by refering previous text positions
	for (i = 0; i < strlen(two_str2); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, two_str2[i]);

	glRasterPos2f(15, 680); //calculate points by refering previous text positions
	for (i = 0; i < strlen(two_str3); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, two_str3[i]);

	glRasterPos2f(15, 620); //calculate points by refering previous text positions
	for (i = 0; i < strlen(two_str4); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, two_str4[i]);


	glTranslatef(-450, 0, 0);
	minion1();
	glTranslatef(450, 0, 0);
	if (temp1 >= 500) {
		glTranslatef(-500, 0, 0);
		villan2();
		glTranslatef(500, 0, 0);
		if (temp1 >= 100) {
			if (y <= 600 && z <= 600) {
				ball(900 - y, 900 - z, 30);
				draweyeball(890 - y, 920 - z, 2);
			}
			y += 1.0;
			z += 0.5;
			glutPostRedisplay();
		}
		temp1 += 1.0;
	}
	temp1 += 1.0;

	glColor3f(0.0, 0.0, 0.0);
	char str14[] = "Press A/a to Continue";
	glRasterPos2f(430, 190); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str14); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]);
	}

	glFlush();
}
void bombstack() {
	ball(200, 620, 20);
	ball(230, 620, 20);
	ball(215, 640, 20);
}

void bombstack1() {
	if (a <= 700) {
		ball(110 + a, 640, 20);
		ball(140 + a, 640, 20);
		ball(125 + a, 680, 20);
	}
	else {
		a = 700.0;
		if (a2 <= 100) {
			ball(790, 595, 20);
			ball(840, 640, 20);
			ball(825, 680, 20);
		}
		else {
			ball(840, 640, 20);
			ball(825, 680, 20);
		}
		a2 += 1.0;
	}
	a += 1.0;

}
void bubble() {
	message(450, 800, 80);
	glColor3f(1.0, 1.0, 1.0);
	char str1[] = "???...take this bombs";
	char str2[] = "to other side of bridge.";
	glRasterPos2f(380, 800); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
	}
	glRasterPos2f(380, 780); //take midpoint of gluOrtho2D
	for (i = 0; i < strlen(str2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
	}
}
void fourthpage() {
	scene3();
	board2();
	if (q5 <= 600) {
		glColor3f(0, 0, 0);
		glRasterPos2f(15, 400); //calculate points by refering previous text positions
		for (i = 0; i < strlen(three_str1); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, three_str1[i]);
	}
	else {
		glColor3f(0.0, 0.0, 0.0);
		char str1[] = "Accidentally minion drops a bomb on";
		char str2[] = "the bridge,an kills the new boss.";
		glRasterPos2f(15, 400); //take midpoint of gluOrtho2D
		for (i = 0; i < strlen(str1); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
		}
		glRasterPos2f(15, 380);
		for (i = 0; i < strlen(str2); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
		}
	}
	q5 += 1.0;
	if (q2 <= 1000) {
		villan3();
		if (q >= 150) {
			if (q1 < 100) {
				bubble();
			}
			q1 += 1.0;
		}
		q += 1.0;
	}
	else {
		villanfall();
		if (q4 >= 500) {
			message(750, 700, 30);

			glColor3f(1.0, 1.0, 1.0);
			char str1[] = "Oh no....";;
			glRasterPos2f(740, 700); //take midpoint of gluOrtho2D
			for (i = 0; i < strlen(str1); i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
			}
		}
		q4 += 1.0;
	}
	q2 += 1.0;
	if (q3 <= 200) {
		glTranslatef(-450, 227, 0);
		minion2();
		glTranslatef(450, -227, 0);
	}
	else {
		glTranslatef(-450, 227, 0);
		minionwalk();
		glTranslatef(450, -227, 0);
	}
	q3 += 1.0;
	if (v >= 200) {
		bombstack1();
	}
	else {
		bombstack();
	}
	v += 1.0;
	glColor3f(0.0, 0.0, 0.0);
	char str14[] = "Press B/b to Continue";
	glRasterPos2f(430, 190); //calculate points by refering previous text positions
	for (i = 0; i < strlen(str14); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str14[i]);
	}
	glFlush();
}
void smallbomb() {
	if (q7 <= 150) {
		drawlense(800 - q7, 600, 5);
	}
	q7 += 1.0;
	glutPostRedisplay();

}
void fifthpage() {
	scene4();
	minion3();
	board3();
	if (q8 <= 600) {
		glTranslatef(300, 0, 0);
		villan4();
		glTranslatef(-300, 0, 0);
	}
	q8 += 1.0;
	if (q6 <= 100) {
		message(740, 800, 65);
		glColor3f(1.0, 1.0, 1.0);
		char str1[] = "I will not spare you.";
		char str2[] = "Freak..";
		glRasterPos2f(680, 800); //take midpoint of gluOrtho2D
		for (i = 0; i < strlen(str1); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
		}
		glRasterPos2f(680, 780); //take midpoint of gluOrtho2D
		for (i = 0; i < strlen(str2); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
		}
	}
	else if (q6 <= 400) {
		message(800, 800, 50);
		glColor3f(1.0, 1.0, 1.0);
		char str1[] = "Whaaaaaat???";
		glRasterPos2f(750, 800); //take midpoint of gluOrtho2D
		for (i = 0; i < strlen(str1); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
		}
	}
	else if (q6 > 400) {
		gru();
		smallbomb();
	}
	q6 += 1.0;
	glColor3f(0, 0, 0);
	glRasterPos2f(15, 450); //calculate points by refering previous text positions
	for (i = 0; i < strlen(four_str1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, four_str1[i]);

	glRasterPos2f(15, 420); //calculate points by refering previous text positions
	for (i = 0; i < strlen(four_str2); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, four_str2[i]);
	glRasterPos2f(15, 390); //calculate points by refering previous text positions
	for (i = 0; i < strlen(four_str3); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, four_str3[i]);
	glRasterPos2f(15, 360); //calculate points by refering previous text positions
	for (i = 0; i < strlen(four_str4); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, four_str4[i]);
	glRasterPos2f(15, 330); //calculate points by refering previous text positions
	for (i = 0; i < strlen(four_str5); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, four_str5[i]);

	/*glTranslatef(-450, 227, 0);
	minion2();
	glTranslatef(450, -227, 0);*/
	glFlush();
}
void myinit1() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(20.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);
}
void myinit2() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(20.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);
}

void myinit3() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(20.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);
}
void myinit4() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(20.0);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);
}
void keys3(unsigned char key, int x, int y)
{
	if (key == 'B' || key == 'b')
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1300, 900);
		id5 = glutCreateWindow("Minions");
		glutDestroyWindow(id4);
		glClearColor(0.0, 0.0, 1.0, 0.0);
		glutDisplayFunc(fifthpage);
		myinit4();
	}

}

void keys2(unsigned char key, int x, int y)
{
	if (key == 'A' || key == 'a')
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1300, 900);
		id4 = glutCreateWindow("Minions");
		glutDestroyWindow(id3);
		glClearColor(0.0, 0.0, 1.0, 0.0);
		glutKeyboardFunc(keys3);
		glutDisplayFunc(fourthpage);
		myinit3();
	}

}

void keys1(unsigned char key, int x, int y)
{
	if (key == 'F' || key == 'f')
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1300, 900);
		id3 = glutCreateWindow("Minions");
		glutDestroyWindow(id2);
		glClearColor(0.5, 0.5, 1.0, 0.0);
		glutKeyboardFunc(keys2);
		glutDisplayFunc(thirdpage);
		myinit2();
	}

}



void keys(unsigned char key, int x, int y)
{
	if (key == 'E' || key == 'e')
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1300, 900);
		id2 = glutCreateWindow("Minions");
		glutDestroyWindow(id1);
		glClearColor(0.5, 0.5, 1.0, 0.0);
		glutKeyboardFunc(keys1);
		glutDisplayFunc(secondpage);
		myinit1();
	}

}
void myinit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLineWidth(20.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); //pixels on the screen
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 900);
	glutInitWindowPosition(0.0, 0.0);
	id1 = glutCreateWindow("Minions");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	myinit();
	glutMainLoop();
}