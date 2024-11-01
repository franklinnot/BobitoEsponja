
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
	glBindTexture(GL_TEXTURE_2D, texturas[2]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
		glColor3ub(190, 123, 129);
		glTranslated(0, 50, 0);
		glScaled(0.75, 1.2, 1.4);

		semiEsfera(quad, 10);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

// Toda la isla
void Isla(GLuint texturas[100], GLUquadric* quad) {

	glPushMatrix();
	Arena(texturas, quad);
	glPopMatrix();
}
