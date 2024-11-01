
#pragma region Includes
#pragma once
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include "texturas/RgbImage.h"
#include "MetodosPoligonos.h"
#include "CodigoBase.h"
using namespace std;
#pragma endregion


#pragma region Elementos a desarrolar
/*
Pequeña formación de arena
3 Palmeras
Arbustito
La textura del agua se encontrará en la parte superior del cubo
Cielo despejado(textura con imagen de cielo)
Plankton
*/
#pragma endregion


// Pequeña formación de arena
void Arena(GLuint texturas[100], GLUquadric* quad) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[20]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
		glTranslated(0, 50, 0);
		glScaled(1.2, 1.2, 1.8);
		semiEsfera(quad, 10);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

// 3 Palmeras
void Palmeras() {

}

// Awita
void Awita(GLuint texturas[100]) {
	glColor3ub(140, 220, 250);
	glPushMatrix();
	glTranslated(0, 7.2, 0);
	cubo(20, 1.28, 0.72, 1.28);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[19]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
	glTranslated(-12.8, 0, 12.81);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
	glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
	glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
	glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

// Toda la isla
void Isla(GLuint texturas[100], GLUquadric* quad) {

	glPushMatrix();
	    Arena(texturas, quad);
        glPushMatrix();
		glScaled(1, 0.1, 1);
		glRotated(-90, 1, 0, 0);
	        Awita(texturas);
        glPopMatrix();
	glPopMatrix();
}
