#pragma once
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include "texturas/RgbImage.h"
#include "MetodosPoligonos.h"
#include "CodigoBase.h"

#pragma region a
/*
Casa de Patricio
Corales 2 tipos
Casa de Bob Esponja
Bob Esponja
*/
#pragma endregion


// Casa de Patricio UwU
void rocaPatricio(GLuint texturas[100], GLUquadric* quad) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[10]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
		semiEsfera(quad, 10);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void palitos()
{
	glColor3ub(232, 227, 109);
	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.25, 0.25, 3, 50);
	glPopMatrix();

	glColor3ub(102, 82, 44);
	glPushMatrix();
		glTranslated(0, 11.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 13, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();
}

void palitos2()
{
	glColor3ub(232, 227, 109);
	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.25, 0.25, 4.5, 50);
	glPopMatrix();

	glColor3ub(102, 82, 44);
		glPushMatrix();
		glTranslated(0, 11.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 13, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 14.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();
}

void flecha(float posX,float posZ, float rot)
{
	glColor3ub(232, 227, 109);
	glPushMatrix();
		glTranslated(posX, 13.3, posZ);
		glRotated(90, 0, 0, 1);
		glRotated(rot, 1, 0, 0);
		cilindro(0.25, 0.25, 1.5, 50);
	glPopMatrix();

}

void borde(float posX, float posZ, float rot)
{
	glColor3ub(102, 82, 44);
	glPushMatrix();
	glTranslated(posX, 13.3, posZ);
	glRotated(90, 0, 0, 1);
	glRotated(rot, 1, 0, 0);
	cilindro(0.3, 0.3, 0.1, 50);
	glPopMatrix();
}

void veleta()
{
	glPushMatrix();
		palitos();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-12.5, 13.3, 0);
		glRotated(90,0,1,0);
		glRotated(90, 1, 0, 0);
		palitos2();
	glPopMatrix();

		flecha(-2.3,0.15,50);
		flecha(-2.3,-0.15,130);

		borde(-1.2, 1.1, 50);
		borde(-1.2, -1.1, 130);

		flecha(1, -0.7, 0);
		borde(1, -0.7, 0);
		borde(1, 0.7, 0);

		flecha(1.6, -0.7, 0);
		borde(1.6, -0.7, 0);
		borde(1.6, 0.7, 0);

}

void casaPatricio(GLuint texturas[100], GLUquadric* quad)
{
	rocaPatricio(texturas, quad);
	glPushMatrix();
		glRotated(10, 0, 0, 1);
		veleta();
	glPopMatrix();

}

