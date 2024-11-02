
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
Arbustito
Cielo despejado(textura con imagen de cielo)
Plankton
*/
#pragma endregion



// Awita
void Awita(GLuint texturas[100]) {
	glColor4ub(15, 104, 247, 100);
	glPushMatrix();
		cubo(100, 1, 1, 0.1);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[85]);
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



// Pequeña formación de arena
void Arena(GLuint texturas[100], GLUquadric* quad) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[86]);
	glColor4ub(250, 250, 250, 250);

	glPushMatrix();
		glTranslated(0, 49, 0);
		glScaled(1.4, 1.2, 1.8);
		semiEsfera(quad, 10);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}



void hojaPalmera(GLuint texturas[100]) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[88]); // Textura para las hojas

	// Primera capa de la hoja
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 5, 1);
	glTexCoord2f(1, 0); glVertex3f(1, 5, 1);
	glEnd();

	// Segunda capa de la hoja (con un pequeño desplazamiento en Z)
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1); glVertex3f(0, 0, -0.08);    // Desplazado en Z
	glTexCoord2f(1, 1); glVertex3f(1, 0, -0.08);
	glTexCoord2f(0, 0); glVertex3f(0, 5, 1 - 0.08);
	glTexCoord2f(1, 0); glVertex3f(1, 5, 1 - 0.08);
	glEnd();

	// Bordes laterales de la hoja para dar grosor
	glBegin(GL_QUADS);
	// Borde izquierdo
	glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0, -0.08);
	glTexCoord2f(0, 0); glVertex3f(0, 5, 1 - 0.08);
	glTexCoord2f(0, 0); glVertex3f(0, 5, 1);

	// Borde derecho
	glTexCoord2f(1, 1); glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(1, 0, -0.08);
	glTexCoord2f(1, 0); glVertex3f(1, 5, 1 - 0.08);
	glTexCoord2f(1, 0); glVertex3f(1, 5, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Palmera(GLuint texturas[100]) {
	GLUquadric* quad = gluNewQuadric(); 

	gluQuadricTexture(quad, GL_TRUE); 
	gluQuadricNormals(quad, GLU_SMOOTH);

	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texturas[87]);

		glColor3ub(255, 255, 255);
		glTranslated(0, 60, 0);
		glRotated(-68.4, 1, 0, 0);
		glRotated(16, 0, 1, 0);

		cilindro(quad, 1.5, 1, 8);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	gluDeleteQuadric(quad); 

	glPushMatrix();
		glTranslated(2.4, 68, 2.4); // Posición de las hojas sobre el tronco
		glRotated(20, 1, 0, 0);
		glRotated(-16, 0, 0, 1);
		
		glTranslated(0, -0.4, 0.8);
		// Rotar y dibujar múltiples hojas
		for (int i = 0; i < 6; ++i) {
			glPushMatrix();
			glRotated(i * 60, 0, 1, 0); // Rotar cada hoja alrededor del eje Y
			glRotated(95, 1, 0, 0);     // Inclinación hacia abajo
			hojaPalmera(texturas);       // Dibujar hoja
			glPopMatrix();
		}
	glPopMatrix();

}


void Palmeras(GLuint texturas[100]) {
	glPushMatrix();
		glTranslated(2, -0.8, 8);
		Palmera(texturas);
	glPopMatrix();

	glPushMatrix();
		glTranslated(10, -26,24);
		glScaled(1.2, 1.5, 1.2);
		glRotated(-20, 1, 0, 0);
		glRotated(10, 0, 0, 1);
		Palmera(texturas);
	glPopMatrix();

	glPushMatrix();
		glTranslated(2, -0.8, -8);
		glRotated(90, 0, 1, 0); 
		Palmera(texturas);
	glPopMatrix();
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

		Palmeras(texturas);

	glPopMatrix();
}
