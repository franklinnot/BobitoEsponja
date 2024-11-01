
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
3 Palmeras
Arbustito
Cielo despejado(textura con imagen de cielo)
Plankton
*/
#pragma endregion


// Pequeña formación de arena
void Arena(GLuint texturas[100], GLUquadric* quad) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[20]);
	glColor4ub(250, 250, 250, 250);

	glPushMatrix();
		glTranslated(0, 49, 0);
		glScaled(1.2, 1.2, 1.8);
		semiEsfera(quad, 10);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

// 3 Palmeras

void Palmera(){
	glPushMatrix();
		cilindro();
	glPopMatrix();
}

void Palmeras() {
	glPushMatrix();
		Palmera();
	glPopMatrix();
}

// Awita
void Awita(GLuint texturas[100]) {
	glColor4ub(15, 104, 247, 100);
	glPushMatrix();
		cubo(100, 1, 1, 0.1);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[19]);
	glColor4ub(250, 250, 250, 220);

	glPushMatrix();
		glTranslated(-50, -50, 6);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 1); glVertex3d(0, 100, 0);
			glTexCoord2f(1, 1); glVertex3d(100, 100, 0);
			glTexCoord2f(1, 0);  glVertex3d(100, 0, 0);
			glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
		glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


// Toda la isla
void Isla(GLuint texturas[100], GLUquadric* quad) {

	glPushMatrix();
		
		// arenita
	    Arena(texturas, quad);

		// las 3 palmeras


		// awita sobre el cubito 
        glPushMatrix();
			glTranslated(0, 49, 0);
			glScaled(1, 0.01, 1);
			glRotated(-90, 1, 0, 0);
	        Awita(texturas);
        glPopMatrix();

	glPopMatrix();
}
