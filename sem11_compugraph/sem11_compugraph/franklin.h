
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



// Peque�a formaci�n de arena
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


#pragma region Palmeras

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

	// Segunda capa de la hoja (con un peque�o desplazamiento en Z)
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
		glTranslated(2.4, 68, 2.4); // Posici�n de las hojas sobre el tronco
		glRotated(20, 1, 0, 0);
		glRotated(-16, 0, 0, 1);
		
		glTranslated(0, -0.4, 0.8);
		// Rotar y dibujar m�ltiples hojas
		for (int i = 0; i < 6; ++i) {
			glPushMatrix();
			glRotated(i * 60, 0, 1, 0); // Rotar cada hoja alrededor del eje Y
			glRotated(95, 1, 0, 0);     // Inclinaci�n hacia abajo
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

#pragma endregion

// Arbustito
void arbusto(GLuint texturas[100]) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[89]); // Textura de follaje

	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	
	glPushMatrix();
		// Crear varias esferas para la estructura del arbusto
		glPushMatrix();
		glColor3ub(34, 139, 34);  // Color verde para camuflar con la textura
		glTranslatef(0, 0, 0);
		gluSphere(quad, 3.0, 20, 20);  // Esfera principal
		glPopMatrix();

		// Varias esferas alrededor para una forma irregular
		glPushMatrix();
		glTranslatef(-2, 1, 2);
		gluSphere(quad, 2.0, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2, 1, -2);
		gluSphere(quad, 2.0, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.5, 2, 1.5);
		gluSphere(quad, 1.8, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.5, 2, -1.5);
		gluSphere(quad, 1.5, 20, 20);
		glPopMatrix();

	glPopMatrix();

	gluDeleteQuadric(quad);
	glDisable(GL_TEXTURE_2D);
}

void elArbustito(GLuint texturas[100]) {

	glPushMatrix();
	glTranslated(0, 60, 0);
	arbusto(texturas);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4, 58, 0);
	glRotated(-35, 0, 1, 0);
	arbusto(texturas);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 58, -4);
	glRotated(35, 0, 1, 0);
	arbusto(texturas);
	glPopMatrix();

	glPushMatrix();
	glTranslated(7, 57, 5);
	glRotated(70, 0, 1, 0);
	arbusto(texturas);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4, 58, 4);
	glRotated(20, 0, 1, 0);
	arbusto(texturas);
	glPopMatrix();

}


void cielito(GLuint texturas[100], GLUquadric* quad) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[90]);
	glColor3ub(255, 255, 255);

	glPushMatrix();
		glTranslated(0, 25, 0);
		quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
		esfera(quad, 135);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


// Plankton

void SimBody() {
	glPushMatrix();
		semiEsfera(2);
	glPopMatrix();
}

void CuerpitoPlank() {
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
		cilindro(2.0f, 4.8f);
	glPopMatrix();
}

void Antenitas() {
	glPushMatrix();
		glPushMatrix();
			glTranslated(0.0f, 2.2, 0.0f);
			glRotated(-90, 1, 0, 0);
			glRotated(-8, 0, 1, 0);
			glRotated(6, 1, 0, 0);
			glTranslated(-0.3, 0, 0);
			glTranslated(0, -0.23, 0);
			glRotated(24, 0, 1, 0);
			glRotated(12, 1, 0, 0);
			cilindro(0.08f, 0.01f, 2.3f); 
		glPopMatrix();

		glPushMatrix();
			glRotated(-90, 1, 0, 0);
			glRotated(-8, 0, 1, 0);
			glRotated(6, 1, 0, 0);
			cilindro(0.15f, 0.08f, 2.3f);
		glPopMatrix();
	glPopMatrix();
}

void bracitop() {
	glColor3ub(66, 156, 94);
	glPushMatrix();
		glPushMatrix();
			glTranslated(0.0f, 5.8, 1.8);
			glRotated(16, 1, 0, 0);
			cilindro(0.3, 0.18, 2);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.0f, 6, 6.0f);
			glRotated(125, 1, 0, 0);
			glTranslated(0, -1.6, 1.9);
			glRotated(2, 1, 0, 0);
			cilindro(0.18, 0.14, 2.2);
		glPopMatrix();

		glPushMatrix();

			glTranslated(0.0f, 3.4, 2.2);
			glRotated(125, 1, 0, 0);
			glTranslated(0, -0.05, 0);
			esfera(0.25);
		glPopMatrix();
	glPopMatrix();
}

void patita() {
	glPushMatrix();

		glPushMatrix();
			glTranslated(0.0f, 0.2, 1);
			glRotated(85, 1, 0, 0);
			glTranslated(0, -0.05, 0);
			cilindro(0.3, 0.2, 2.4);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.0f, -2, 1.15);
			esfera(0.28);
		glPopMatrix();

	glPopMatrix();
}

void ojito() {
	
	glPushMatrix();
		glColor3ub(216, 255, 90);
		glPushMatrix();
			glTranslated(-1.88, 6, 0);
			glScaled(0.2, 1, 0.75);
			esfera(1.45);
		glPopMatrix();

		glColor3ub(254, 11, 28);
		glPushMatrix();
			glTranslated(-2.15, 6, 0);
			glScaled(0.2, 1, 0.75);
			esfera(0.85);
		glPopMatrix();
	glPopMatrix();

}

void cejita() {
	glPushMatrix();
		
		glColor3ub(12, 12, 12);
		glPushMatrix();
			glTranslated(-1.78, 7.85, 0);
			glRotated(-20, 0, 0, 1);
			cubo(0.4, 0.2, 1, 5.5);
		glPopMatrix();

	glPopMatrix();
}

void sonrisa() {
	glPushMatrix();

		glColor3ub(12, 12, 12);
		glPushMatrix();
			glTranslated(-1.2, 3.4, 0);
			glRotated(-90, 1, 0, 0);
			glScaled(1, 1.4, 0.5);
			glutSolidTorus(0.6, 0.5, 50, 100);
		glPopMatrix();


		glColor3ub(245, 245, 245);
		glPushMatrix();
		glTranslated(-2.3, 3.4, -0.6);
		cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

		glColor3ub(245, 245, 245);
		glPushMatrix();
		glTranslated(-2.3, 3.4, -0.305);
		cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

		glColor3ub(245, 245, 245);
		glPushMatrix();
			glTranslated(-2.3, 3.4, -0.305);
			cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

		glColor3ub(245, 245, 245);
		glPushMatrix();
			glTranslated(-2.3, 3.4, 0);
			cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-2.3, 3.4, 0.305);
			cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

		glColor3ub(245, 245, 245);
		glPushMatrix();
		glTranslated(-2.3, 3.4, 0.6);
		cubo(0.2, 0.2, 1.4, 1);
		glPopMatrix();

	glPopMatrix();
}

// Variables de personajes
float velocidadPersonaje2 = 2;
float angulo2Pierna1 = 0;
float lado2Pierna1 = 1;
float angulo2Pierna2 = 0;
float lado2Pierna2 = -1;

void Plankton() {

	glPushMatrix();
	glColor4ub(66, 156, 94, 250);
	// parte inferior 
	glPushMatrix();
		glTranslated(0.0f, 2.0f, 0.0f);
		glRotated(-180, 1, 0, 0);
		glScaled(1, 1.2, 1);
		SimBody();
	glPopMatrix();

	// cuerpo
	glPushMatrix();
		glTranslated(0.0f, 2.0f, 0.0f);
		CuerpitoPlank();
	glPopMatrix();

	// cabeza
	glPushMatrix();
		glTranslated(0.0f, 6.8f, 0.0f);
		glScaled(1, 1.2, 1);
		SimBody();
	glPopMatrix();

	// Antenitas
	glPushMatrix();
		glTranslated(-0.3f, 8.6f, 1.0f);
		glScalef(1.0f, 0.85f, 1.0f);
		glRotated(-24, 0, 1, 0);
		glRotated(-12, 0, 0, 1);
		Antenitas();
	glPopMatrix();

	// Antenita izquierda
	glPushMatrix();
		glTranslated(-0.3f, 8.6f, -1.0f);
		glScalef(1.0f, 0.85f, -1.0f); 
		glRotated(-24, 0, 1, 0);
		glRotated(-12, 0, 0, 1);
		Antenitas();
	glPopMatrix();

	// Brazo izquierdo
	glPushMatrix();
		bracitop();
	glPopMatrix();

	// Brazo derecho
	glPushMatrix();
		glRotated(-180, 0, 1, 0);
		bracitop();
	glPopMatrix();

	// patita izquierda movimiento

	glPushMatrix();
	angulo2Pierna1 += (velocidadPersonaje2 * lado2Pierna1);

	if (angulo2Pierna1 >= 0)
	{
		lado2Pierna1 = -1;
	}
	if (angulo2Pierna1 <= -10)
	{
		lado2Pierna1 = 1;
	}

	glTranslated(0.5, 5, -0.1);
	glRotated(angulo2Pierna1, 0, 0, 1);
	glTranslated(0, -5, 0.1);
	patita();
	glPopMatrix();


	// patita derecha movimiento
	glPushMatrix();
	angulo2Pierna2 += (velocidadPersonaje2 * lado2Pierna2);

	if (angulo2Pierna2 <= 0)
	{
		lado2Pierna2 = 1;
	}
	if (angulo2Pierna2 >= 10)
	{
		lado2Pierna2 = -1;
	}
	glTranslated(-0.5, 5, -0.1);
	glRotated(angulo2Pierna2, 0, 0, 1);
	glTranslated(0, -5, 0.1);

	glRotated(-180, 0, 1, 0);
	patita();

	glPopMatrix();



	// ojito
	
	glPushMatrix();
	ojito();
	glPopMatrix();

	glPushMatrix();
		cejita();
	glPopMatrix();

	glPushMatrix();
		sonrisa();
	glPopMatrix();

	glPopMatrix();
}

float posPlanktonZ = -24.5;  // Posici�n inicial de Plankton en Z
float velocidadPlankton = 0.5;  // Velocidad de movimiento en Z
double anguloPlankton = 90;   // �ngulo de rotaci�n inicial
bool detenerPlankton = false;  // Para controlar si Plankton se detiene o sigue
bool pausaAntesDeGiros = false;  // Para controlar la pausa antes de los giros
bool girandoPrimero = false;  // Para controlar el primer giro
bool girandoSegundo = false;  // Para controlar el segundo giro
bool girandoTercero = false;  // Para controlar el tercer giro (para regresar a la rotaci�n original)
bool avanzandoDeNuevo = false;  // Para controlar el regreso al avance en Z

// �ngulos que el usuario ingresa para los giros
double primerGiro = 180;  // Primer �ngulo de giro (puedes modificar este valor)
double segundoGiro = -90;  // Segundo �ngulo de giro (puedes modificar este valor)
double anguloOriginal = 45;  // El �ngulo original de rotaci�n que tendr� Plankton al final (puedes modificar este valor)


void movimientoPlankton()
{
	glPushMatrix();

	// 1. Movimiento en Z (avanzar hasta la posici�n deseada)
	if (!detenerPlankton && posPlanktonZ < -6)  // Modifica el valor de 23 si deseas un rango diferente
	{
		posPlanktonZ += velocidadPlankton / 10.0;  // Mueve a Plankton en Z
	}
	else
	{
		detenerPlankton = true;  // Detiene el movimiento en Z
	}

	// 2. Pausa antes de los giros
	if (detenerPlankton && !pausaAntesDeGiros)
	{
		pausaAntesDeGiros = true;  // Activamos la pausa antes de los giros
	}

	// 3. Giros (todos despu�s de la pausa)
	if (pausaAntesDeGiros)
	{
		// Primer giro
		if (!girandoPrimero)
		{
			if (anguloPlankton < primerGiro)  // Giro de primer valor
			{
				anguloPlankton += velocidadPlankton;  // Gira en el sentido deseado
			}
			else
			{
				anguloPlankton = primerGiro;  // Aseguramos que el �ngulo no pase del primer giro
				girandoPrimero = true;  // Detiene el primer giro
			}
		}
		// Segundo giro
		else if (!girandoSegundo)
		{
			if (anguloPlankton > segundoGiro)  // Giro de segundo valor
			{
				anguloPlankton -= 1;  // Gira en sentido opuesto
			}
			else
			{
				anguloPlankton = segundoGiro;  // Aseguramos que el �ngulo no pase del segundo giro
				girandoSegundo = true;  // Detiene el segundo giro
			}
		}
		// Tercer giro (regresar a la rotaci�n original)
		else if (!girandoTercero)
		{
			if (anguloPlankton < anguloOriginal)  // Regresa a la rotaci�n original
			{
				anguloPlankton += 1;  // Gira hacia la rotaci�n original
			}
			else
			{
				anguloPlankton = anguloOriginal;  // Asegura que el �ngulo vuelva a su valor original
				girandoTercero = true;  // Detiene el tercer giro
			}
		}
	}

	// 4. Despu�s de los giros, avanzar nuevamente en Z
	if (girandoPrimero && girandoSegundo && girandoTercero && !avanzandoDeNuevo)
	{
		if (posPlanktonZ < 20)  // Contin�a avanzando en Z hasta llegar a 28
		{
			posPlanktonZ += 1 / 10.0;
		}
		else
		{
			avanzandoDeNuevo = true;  // Termina el movimiento en Z
		}
	}

	// 5. Aplicar todas las transformaciones a Plankton
	glTranslated(23, -0.5, posPlanktonZ);  // Traslaci�n en Z, manteniendo las otras coordenadas constantes
	glScaled(0.15, 0.15, 0.15);  // Escala de Plankton
	glRotated(anguloPlankton, 0, 1, 0);  // Rotaci�n sobre el eje Y

	Plankton();  // Dibuja a Plankton

	glPopMatrix();  // Restauramos las transformaciones
}

void Isla(GLuint texturas[100], GLUquadric* quad) {

	glPushMatrix();

		// awita sobre el cubito 
        glPushMatrix();
			glTranslated(0, 50, 0);
			glScaled(1, 0.01, 1);
			glRotated(-90, 1, 0, 0);
	        Awita(texturas);
        glPopMatrix();

		// arenita
	    Arena(texturas, quad);

		// las 3 palmeras
		Palmeras(texturas);

		glPushMatrix();
			glTranslated(0, -0.8, 0);
			elArbustito(texturas);
		glPopMatrix();

		glPushMatrix();
			glRotated(135, 0, 1, 0);
			glTranslated(0, -0.6, 0);
			elArbustito(texturas);
		glPopMatrix();

		glPushMatrix();
			glRotated(-75, 0, 1, 0);
			glTranslated(0, -0.4, 0);
			elArbustito(texturas);
		glPopMatrix();

		glPushMatrix();
			glScaled(2, 2, 2);
			glRotated(80, 1, 0, 0);
			glRotated(-90, 1, 0, 0);
			cielito(texturas, quad);
		glPopMatrix();

	glPopMatrix();
}
