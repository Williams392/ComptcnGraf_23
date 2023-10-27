// Esfera.h
#pragma once

#include <GL/glut.h>

void cabeza_verde_1() {
    glPushMatrix();
    glTranslated(-3.5, 28, -2);
    glRotated(-90, 11, -10, 0);
    glScaled(1, 1, 1);
    glutSolidSphere(1.5, 100, 100);
    glPopMatrix();
}
