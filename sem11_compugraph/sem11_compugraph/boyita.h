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

// Corales - 2 tipos


// Tipo 1 xd 
void puntosCoral(float x, float y, float z) {
	glColor3ub(222, 200, 7); // Color amarillo

	glPushMatrix();
	glTranslated(x, y, z);
	esfera(0.1, 10);  // Esfera pequeña para el punto
	glPopMatrix();
}

void coralBase()
{
	glColor3ub(196, 39, 24);

	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	cilindro(0.5, 1, 6, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 6, 0);
	glRotated(-90, 1, 0, 0);
	dona(0.5, 1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	dona(0.4, 0.5, 10, 10);
	glPopMatrix();


	puntosCoral(0.5, 3, 0.5);
	puntosCoral(-0.63, 4, -0.63);
	puntosCoral(0.7, 5, -0.7);
	puntosCoral(-0.55, 6, 0.55);
	puntosCoral(-0.1, 5, 0.9);


	puntosCoral(1, 6.5, 0);
	puntosCoral(-1, 6.5, 0);
	puntosCoral(0, 6.5, 1);
	puntosCoral(0, 6.5, -1);


}

void coralOne()
{
	glPushMatrix();
	glScaled(2, 1.5, 2);
	coralBase();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.5, 0);
	glRotated(-40, 0, 0, 1);
	glScaled(1.2, 1, 1.2);
	coralBase();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.5, 0);
	glRotated(40, 0, 0, 1);
	glScaled(1.2, 1, 1.2);
	coralBase();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 0);
	glRotated(40, 1, 0, 0);
	glScaled(1.2, 1, 1.2);
	coralBase();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 0);
	glRotated(-40, 1, 0, 0);
	glScaled(1.2, 1, 1.2);
	coralBase();
	glPopMatrix();

}



// Detallito :)
void burbujitas()
{

	glColor3ub(185, 220, 239);

	for (int i = 0; i < 100; ++i) {
		float x = (rand() % 100 - 50) / 25.0f;
		float y = i * 0.15f;
		float z = (rand() % 100 - 50) / 25.0f;

		glPushMatrix();
		glTranslated(x, y, z);
		esfera(0.1, 10);
		glPopMatrix();
	}
}