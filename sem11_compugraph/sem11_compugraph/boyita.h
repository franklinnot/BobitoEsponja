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
		cilindro(0.25, 0.25, 3);
	glPopMatrix();

	glColor3ub(102, 82, 44);
	glPushMatrix();
		glTranslated(0, 11.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 13, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();
}

void palitos2()
{
	glColor3ub(232, 227, 109);
	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.25, 0.25, 4.5);
	glPopMatrix();

	glColor3ub(102, 82, 44);
		glPushMatrix();
		glTranslated(0, 11.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 13, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 14.5, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.3, 0.3, 0.1);
	glPopMatrix();
}

void flecha(float posX,float posZ, float rot)
{
	glColor3ub(232, 227, 109);
	glPushMatrix();
		glTranslated(posX, 13.3, posZ);
		glRotated(90, 0, 0, 1);
		glRotated(rot, 1, 0, 0);
		cilindro(0.25, 0.25, 1.5);
	glPopMatrix();

}

void borde(float posX, float posZ, float rot)
{
	glColor3ub(102, 82, 44);
	glPushMatrix();
	glTranslated(posX, 13.3, posZ);
	glRotated(90, 0, 0, 1);
	glRotated(rot, 1, 0, 0);
	cilindro(0.3, 0.3, 0.1);
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
void puntosCoral(float x, float y, float z) 
{
	
	glPushMatrix();
	glTranslated(x, y, z);
	esfera(0.1, 10);  
	glPopMatrix();
}

void coralBase()
{
	glColor3ub(196, 39, 24);

	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	cilindro(0.5, 1, 6);
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

	glColor3ub(222, 200, 7);

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
// Tipo 2 :D
void tubosCoral()
{
	glColor3ub(185, 220, 239);

	glPushMatrix();
	glTranslated(0, 0, -1.2);
	glRotated(-90, 1, 0, 0);
	glScaled(0.2, 0.2, 10);
	dona(1, 2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 0, -1.2);
	glRotated(-90, 1, 0, 0);
	glScaled(0.2, 0.2, 9);
	dona(1, 2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 0, -1.2);
	glRotated(-90, 1, 0, 0);
	glScaled(0.2, 0.2, 8);
	dona(1, 2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3, 0, -1.2);
	glRotated(-90, 1, 0, 0);
	glScaled(0.2, 0.2, 7);
	dona(1, 2, 50, 50);
	glPopMatrix();
}

void coralTwo()
{
	glColor3ub(70, 124, 161);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(-90, 1, 0, 0);
	glScaled(1, 0.2, 6);
	dona(1, 3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 0, 0);
	glRotated(-90, 1, 0, 0);
	glScaled(1, 0.2, 5);
	dona(1, 3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 0, 0);
	glRotated(-90, 1, 0, 0);
	glScaled(1, 0.2, 4);
	dona(1, 3, 50, 50);
	glPopMatrix();

	tubosCoral();

	glPushMatrix();
	glTranslated(3, 0, 2.4);
	glScaled(1, 0.5, 1);
	tubosCoral();
	glPopMatrix();

	glColor3ub(196, 92, 106);
	glPushMatrix();
		glScaled(3, 3, 3);
		puntosCoral(-1, 1, 0.2);
		puntosCoral(-1.2, 1, 0.2);
		puntosCoral(-1.4, 1, 0.15);
		puntosCoral(-1.6, 1, 0.1);

		puntosCoral(1.5, 0.5, -0.2);
		puntosCoral(1.7, 0.3, -0.15);

		puntosCoral(1.3, 1, 0.15);
		puntosCoral(1.3, 1.4, 0.15);
	glPopMatrix();
}


// Casa de Bob Esponja 
void bordeP(float posX,float posY, float rot)
{
	glColor3ub(149, 39, 0);
	glPushMatrix();
	glTranslated(posX, posY, 0);
	glRotated(90, 0, 1, 0);
	glRotated(rot, 1, 0, 0);
	cilindro(9.7, 9.7, 0.15);
	glPopMatrix();
}

void bordeP()
{
	glPushMatrix();
		glScaled(1.05, 1, 0.9);
		bordeP(1.8, 6.4, 130);
	glPopMatrix();

	glPushMatrix();
		glScaled(0.85, 1, 0.77);
		bordeP(3.8, 9, 130);
	glPopMatrix();

	glPushMatrix();
		glScaled(0.6, 1, 0.6);
		bordeP(6.7, 11.2, 120);
	glPopMatrix();

	glPushMatrix();
		glScaled(1.2, 1, 0.98);
		bordeP(0.8, 3.8, 135);
	glPopMatrix();

	glPushMatrix();
		glScaled(1.12, 1, 0.99);
		bordeP(-0.25, 1, 130);
	glPopMatrix();

}

void pineapple()
{
	glColor3ub(248, 136, 0);
	glPushMatrix();
		glScaled(1.2,2,1.2);
		semiEsfera(8);
	glPopMatrix();

	bordeP();
	glPushMatrix();
	glScaled(-1, 1, 1);
	bordeP();
	glPopMatrix();
}

void ventana()
{
	glColor3ub(95, 141, 226);
	glPushMatrix();
		glTranslated(0, 10, 15);
		glScaled(1,1,0.5);
		dona(0.7, 2, 50, 50);
	glPopMatrix();


	glColor3ub(185, 246, 255);
	glPushMatrix();
		glTranslated(0, 10, 14.5);
		glScaled(1, 1, 0.25);
		esfera(2);
	glPopMatrix();

	glColor3ub(87, 102, 147);
	glPushMatrix();
		glTranslated(0, 12, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5,10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 8, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(2, 11, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2, 11, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(2, 9, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2, 9, 15.3);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();
}

void puerta()
{
	glColor3ub(95, 141, 226);
	glPushMatrix();
		glTranslated(0, 1.5, 9.6);
		glRotated(-10, 1, 0, 0);
		glScaled(1, 2, 0.6);
		dona(0.7, 2, 50, 50);
	glPopMatrix();

	glColor3ub(87, 102, 147);
		glPushMatrix();
		glTranslated(0, 1.5, 9.6);
		glRotated(-10, 1, 0, 0);
		glScaled(1, 2, 0.25);
		esfera(2);
	glPopMatrix();

	glColor3ub(100, 135, 230);
	glPushMatrix();
		glTranslated(0, 1.5, 10);
		glRotated(-10, 1, 0, 0);
		glScaled(1.5, 3.5, 0.6);
		dona(0.3, 1, 50, 50);
	glPopMatrix();
	
	glColor3ub(87, 102, 147);
	glPushMatrix();
		glTranslated(0, 6.2, 9.2);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(1.7, 5, 9.2);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-1.7, 5, 9.2);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(2.4, 3, 9.6);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2.4, 3, 9.6);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(2.4, 1, 9.9);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2.4, 1, 9.9);
		glScaled(0.5, 0.5, 0.25);
		esfera(0.5, 10);
	glPopMatrix();
}

void timon()
{
	glColor3ub(48, 90, 186);
	glPushMatrix();
		glTranslated(0, 10, 15);
		glRotated(-10, 1, 0, 0);
		glScaled(0.5,0.5,0.25);
		dona(1.5, 2, 30, 100);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 15);
		glRotated(-10, 1, 0, 0);
		glScaled(0.2, 1.5, 0.2);
		esfera(2);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 15);
		glRotated(-10, 1, 0, 0);
		glRotated(60, 0, 0, 1);
		glScaled(0.2, 1.5, 0.2);
		esfera(2);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 10, 15);
		glRotated(-10, 1, 0, 0);
		glRotated(120, 0, 0, 1);
		glScaled(0.2, 1.5, 0.2);
		esfera(2);
	glPopMatrix();

}

void tubo()
{
	glColor3ub(87, 102, 147);
	glPushMatrix();
		glTranslated(0, 10, 0);
		glRotated(90, 0, 1, 0);
		cilindro(0.5, 0.9, 6);
	glPopMatrix();

	glPushMatrix();
		glTranslated(6, 10, 0);
		esfera(0.9);
	glPopMatrix();

	glPushMatrix();
		glTranslated(6, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.8, 1.1, 3);
	glPopMatrix();

	glPushMatrix();
		glTranslated(6, 10, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.5, 1, 5);
	glPopMatrix();


}

void pi()
{
	glColor3ub(149, 39, 0);

	glPushMatrix();
		glTranslated(0, 10, 7.5);
		glRotated(-13, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 13.5, 5.1);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-4.5, 6, 7.6);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(4.5, 6.5, 7.5);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-6, 7.8, 5.8);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(6, 7.8, 5.8);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-3.2, 13, 4.6);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslated(3.2, 13, 4.6);
		glRotated(-25, 1, 0, 0);
		glScaled(0.2, 1, 0.2);
		esfera(0.5);
	glPopMatrix();
}

void hoja()
{
	glPushMatrix();
		glScaled(1.5, 5, 0.5);
		esfera(1);
	glPopMatrix();
}

void hojitas()
{
	glPushMatrix();
		glTranslated(0, 19, 0);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2, 17, 0);
		glRotated(10,0,0,1);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(2, 17, 0);
		glRotated(-10, 0, 0, 1);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(3, 16, 0);
		glRotated(-30, 0, 0, 1);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-3, 16, 0);
		glRotated(30, 0, 0, 1);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(-4, 14, 0);
		glRotated(40, 0, 0, 1);
		hoja();
	glPopMatrix();

	glPushMatrix();
		glTranslated(4, 14, 0);
		glRotated(-40, 0, 0, 1);
		hoja();
	glPopMatrix();
}

void casaBobEsponja()
{
	pineapple();

	glPushMatrix();
		glTranslated(-1, 2, 0.8);
		glRotated(-21.8, 1, 0, 0);
		glRotated(-13, 0, 1, 0);
		glScaled(0.6, 0.6, 0.6);
		ventana();
	glPopMatrix();

	glPushMatrix();
		glTranslated(1, -4, 2.8);
		glRotated(-21, 1, 0, 0);
		glRotated(25, 0, 1, 0);
		glScaled(0.6, 0.6, 0.6);
		ventana();
	glPopMatrix();

	puerta();

	glPushMatrix();
		glTranslated(0, -2, 4);
		glScaled(0.4, 0.4, 0.4);
		timon();
	glPopMatrix();

	glPushMatrix();
		glTranslated(3, 5.2, 5.3);
		glScaled(0.6, 0.6, 0.6);
		tubo();
	glPopMatrix();
	
	pi();

	glPushMatrix();
		glScaled(1, 1, -1);
		pi();
	glPopMatrix();

	glColor3ub(98, 168, 40);
	hojitas();

	glColor3ub(57, 94, 60);

	glPushMatrix();
		glTranslated(0, 0, 0.1);
		glScaled(1, 1, 0.5);
		hojitas();
	glPopMatrix();

	glPushMatrix();
		glTranslated(0, 0, -0.1);
		glScaled(1, 1, 0.5);
		hojitas();
	glPopMatrix();
}

// Bob Esponja :D
void zapato(float posX)
{
	glPushMatrix();
		glTranslated(posX, 0, 1);
		glScaled(1, 0.7, 1.6);
		esfera(1);
	glPopMatrix();

}

void media(float posX)
{
	glColor3ub(255, 255, 255);
	glPushMatrix();
		glTranslated(posX, 0, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.4, 0.4, 4.5);
	glPopMatrix();

	glColor3ub(234, 89, 71);
	glPushMatrix();
		glTranslated(posX, 3, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.43, 0.43, 0.1);
	glPopMatrix();

	glColor3ub(94, 132, 182);
	glPushMatrix();
		glTranslated(posX, 3.7, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.43, 0.43, 0.1);
	glPopMatrix();
}

void pierna(float posX)
{
	glPushMatrix();
		glTranslated(posX, 4.4, 0);
		glRotated(-90, 1, 0, 0);
		cilindro(0.4, 0.4, 3);
	glPopMatrix();

}

void pantalon()
{
	glPushMatrix();
		glTranslated(0, 7.7, 0);
		cubo(2, 5, 0.9, 1.5);
	glPopMatrix();
}

void pantalon(float posX)
{
	glPushMatrix();
	glTranslated(posX, 5.5, 0);
	glRotated(-90, 1, 0, 0);
	cilindro(1, 0.5, 2.5);
	glPopMatrix();
}

void camisa()
{
	glPushMatrix();
		glTranslated(0, 8.7, 0);
		cubo(2, 4.9, 1, 1.4);
	glPopMatrix();
}

void camisa(float posX, float rot)
{
	glPushMatrix();
		glTranslated(posX, 9.5, 1);
		glRotated(rot,0,0,1);
		cubo(1, 1, 0.05, 1);
	glPopMatrix();
}

void correa(float posX, float posZ)
{
	glColor3ub(0, 0, 0);
		glPushMatrix();
		glTranslated(posX, 7.7, posZ);
		cubo(1, 1.1, 0.3, 1.1);
	glPopMatrix();
}

void cara()
{
	glPushMatrix();
		glTranslated(0, 14.2, 0);
		cubo(2, 5, 4.5, 1.5);
	glPopMatrix();
}

void corbata()
{
	glPushMatrix();
		glTranslated(0, 8.8, 1.5);
		glScaled(0.6,1.3,0.25);
		esfera(1, 6);
	glPopMatrix();
	
}

void brazo(float posX, float rot)
{
	glPushMatrix();
		glTranslated(posX, 13, 0);
		glRotated(90, 0, 1, 0);
		glRotated(rot, 1, 0, 0);
		cilindro(0.3,0.3,6);
	glPopMatrix();
}

void dedo(float posX, float posY, float rot)
{
	glPushMatrix();
		glTranslated(posX, posY, 0);
		glRotated(rot,0,0,1);
		glScaled(0.6, 2, 0.6);
		esfera(0.4);
	glPopMatrix();
}

void mano(float posX)
{
	glPushMatrix();
		glTranslated(posX, 8.2, 0);
		glScaled(1, 1, 0.5);
		esfera(0.6);
	glPopMatrix();

	dedo(8.5,8.2, 90);
	dedo(7.5, 7.8, 130);
	dedo(7.9, 7.5, 0);
	dedo(8.5, 7.7, 30);

	glPushMatrix();
		glScalef(-1, 1, 1);  
		dedo(8.5, 8.2, 90);   
		dedo(7.5, 7.8, 130);  
		dedo(7.9, 7.5, 0);    
		dedo(8.5, 7.7, 30);   
	glPopMatrix();


}

void mangas(float posX, float rot)
{
	glPushMatrix();
		glTranslated(posX, 12.5, 0);
		glRotated(90, 0, 1, 0);
		glRotated(rot, 1, 0, 0);
		cilindro(0.3, 0.9, 2.5);
	glPopMatrix();
}

void pestaña(float posX, float posY)
{
	glPushMatrix();
		glTranslated(posX, posY, 1.4);
		cubo(1, 0.3, 1, 0.25);
	glPopMatrix();
}

void ojo(float posX)
{
	glPushMatrix();
		glTranslated(posX, 15.5, 1.5);
		glScaled(1, 1, 0.25);
		esfera(1.6);
	glPopMatrix();
}

void iris(float posX)
{
	glPushMatrix();
		glTranslated(posX, 15.3, 1.8);
		glScaled(1, 1, 0.25);
		esfera(0.85);
	glPopMatrix();
}

void pupila(float posX)
{
	glPushMatrix();
		glTranslated(posX, 15.35, 2);
		glScaled(1, 1, 0.25);
		esfera(0.3);
	glPopMatrix();
}

void boca()
{
	glPushMatrix();
		glTranslated(0, 13.4, 1);
		glRotated(180, 1, 0, 0);
		glRotated(-10, 1, 0, 0);
		glScaled(1.4,0.7,0.25);
		semiEsfera(3);
	glPopMatrix();
}

void diente(float posX, float posZ)
{
	glPushMatrix();
		glTranslated(posX, 13.3, posZ);
		cubo(1, 0.7, 0.7, 0.25);
	glPopMatrix();
}

void menton(float posX, float posZ)
{
	glPushMatrix();
		glTranslated(posX, 11, posZ);
		cubo(1, 2, 0.1, 0.25);
	glPopMatrix();
}

void cachetito(float posX)
{
	glPushMatrix();
		glTranslated(posX, 13.5, 1.5);
		glScaled(1, 1, 0.5);
		esfera(0.8);
	glPopMatrix();
}

void nariz()
{
	glPushMatrix();
	glTranslated(0, 14.2, 1.5);
	glRotated(90, 1, 0, 0);
	glScaled(0.7, 2.5, 0.7);
	esfera(0.7);
	glPopMatrix();
}

void lengua() 
{
	glPushMatrix();
	glTranslated(0, 11.5, 1.1);
	//glRotated(180, 1, 0, 0);
	//glRotated(-10, 1, 0, 0);
	glScaled(0.5, 0.6, 0.25);
	semiEsfera(3);
	glPopMatrix();
}



// Variables de personajes
float velocidadPersonaje = 4;
float anguloPierna1 = 0;
float ladoPierna1 = 1;
float anguloPierna2 = 0;
float ladoPierna2 = -1;

void bobEsponja()
{
	// Movimiento pierna 1
	glPushMatrix();
	anguloPierna1 += (velocidadPersonaje * ladoPierna1);

	if (anguloPierna1 >= 20)
	{
		ladoPierna1 = -1;
	}
	if (anguloPierna1 <= -20)
	{
		ladoPierna1 = 1;
	}

	glTranslated(0.5, 5, -0.1);
	glRotated(anguloPierna1, 1, 0, 0);
	glTranslated(0, -5, 0.1);

	glColor3ub(0, 0, 0);
	zapato(2.5);

	media(2.5);

	glColor3ub(255, 238, 57);
	pierna(2.5);

	glColor3ub(156, 73, 41);
	pantalon(2.5);

	glPopMatrix();


	//Movimiento pierna 2

	glPushMatrix();
	anguloPierna2 += (velocidadPersonaje * ladoPierna2);

	if (anguloPierna2 <= -20)
	{
		ladoPierna2 = 1;
	}
	if (anguloPierna2 >= 20)
	{
		ladoPierna2 = -1;
	}
	glTranslated(-0.5, 5, -0.1);
	glRotated(anguloPierna2, 1, 0, 0);
	glTranslated(0, -5, 0.1);

	glColor3ub(0, 0, 0);
	zapato(-2.5);

	media(-2.5);

	glColor3ub(255, 238, 57);
	pierna(-2.5);

	glColor3ub(156, 73, 41);
	pantalon(-2.5);

	glPopMatrix();


	glColor3ub(0, 0, 0);
	//zapato(2.5);
	//zapato(-2.5);

	camisa(1.5, 30);
	camisa(0.8, -30);
	camisa(-1.5, -30);
	camisa(-0.8, 30);

	correa(1, 1);
	correa(-1, 1);
	correa(3, 1);
	correa(-3, 1);

	correa(1, -1);
	correa(-1, -1);
	correa(3, -1);
	correa(-3, -1);

	correa(-4.5, 0);
	correa(4.5, 0);

	pupila(1.6);
	pupila(-1.6);

	pestaña(-1, 17);
	pestaña(1, 17);

	pestaña(-1.75, 17.1);
	pestaña(1.75, 17.1);

	pestaña(2.5, 17);
	pestaña(-2.5, 17);


	//media(2.5);
	//media(-2.5);

	glColor3ub(255, 238, 57);
	//pierna(2.5);
	//pierna(-2.5);
	cara();
	brazo(4, 50);
	brazo(-4, 130);
	mano(-8);
	mano(8);
	menton(0, 1.4);
	cachetito(3.3);
	cachetito(-3.3);
	nariz();

	glColor3ub(156, 73, 41);
	pantalon();
	//pantalon(2.5);
	//pantalon(-2.5);

	glColor3ub(255, 255, 255);
	camisa();
	mangas(4.5, 50);
	mangas(-4.5, 130);
	ojo(-1.65);
	ojo(1.65);
	diente(-0.5, 1.7);
	diente(0.5, 1.7);



	glColor3ub(191, 47, 47);
	corbata();

	glColor3ub(98, 200, 236);
	iris(-1.61);
	iris(1.61);

	glColor3ub(84, 25, 13);
	boca();

	glColor3ub(255, 183, 188);
	lengua();
}



float posZBob = 28;        // Posición inicial de Bob en Z
float posXBob = -30;       // Posición inicial de Bob en X
bool detenerBob = false;   // Control para detener el movimiento de Bob en Z
bool detenerBobX = false;  // Control para detener el movimiento de Bob en X
bool pausaAntesDeRotar = false;  // Control para la pausa antes de la rotación
bool moverEnX = false;     // Control para iniciar el movimiento en X después de la rotación
bool rotarOtraVez = false; // Control para rotar nuevamente
bool giroFinal = false;    // Control para el giro final
float anguloBob = 180;           // Ángulo inicial de rotación
float primerGiro1 = 90;         // Primer ángulo de giro
float giroFinalAngulo = 0;   // Ángulo del giro final
bool avanzarZFinal = false; // Control para el avance final en Z
bool detenerZFinal = false; // Control para detener el avance final en Z
bool rotarUltimaVez = false; // Control para el último giro

// Nuevo ángulo para el último giro
float ultimoGiroAngulo = 90; // Ángulo para el último giro

// Control para el avance final en X
bool avanzarXFinal = false; // Control para el avance final en X
bool detenerXFinal = false; // Control para detener el avance final en X

void BobCamina()
{
	glPushMatrix();

	// 1. Movimiento en Z hasta alcanzar la posición deseada
	if (!detenerBob && posZBob > 10)  // Avanzar hasta posZMax
	{
		posZBob -= 0.1;  // Avanza Bob en Z
	}
	else
	{
		detenerBob = true;  // Detiene el movimiento cuando se alcanza posZMax
	}

	// 2. Pausa antes de la rotación (después de detener el movimiento en Z)
	if (detenerBob && !pausaAntesDeRotar)
	{
		pausaAntesDeRotar = true;  // Activa la pausa antes de rotar
	}

	// 3. Primer rotación después de avanzar en Z
	if (pausaAntesDeRotar)
	{
		// Primer giro
		if (anguloBob < primerGiro1)  // Primer giro
		{
			anguloBob += 0.1;  // Incrementa el ángulo
		}
		else
		{
			anguloBob = primerGiro1;  // Asegura que el ángulo no pase del primer giro
			moverEnX = true;  // Activa el movimiento en X después de la rotación
		}
	}

	// 4. Movimiento en X después de la rotación
	if (moverEnX && !detenerBobX)
	{
		if (posXBob < -4)  // Si la posición de X es menor que el tope
		{
			posXBob += 0.1;  // Avanza Bob en X
		}
		else
		{
			detenerBobX = true;  // Detiene el movimiento cuando se alcanza el tope en X
			rotarOtraVez = true; // Activa el control para rotar nuevamente
		}
	}

	// 5. Giro final después de detenerse en X
	if (rotarOtraVez && detenerBobX)
	{
		if (anguloBob < giroFinalAngulo)
		{
			anguloBob += 0.1;  // Incrementa el ángulo para el giro final
		}
		else
		{
			anguloBob = giroFinalAngulo;  // Finaliza el giro
			giroFinal = true;  // Marca el giro como completado
			avanzarZFinal = true; // Activa el movimiento en Z nuevamente
		}
	}

	// 6. Avance final en Z hasta el tope
	if (avanzarZFinal && !detenerZFinal)
	{
		if (posZBob < 18) // Avanza hasta el tope definido
		{
			posZBob += 0.1; // Continúa avanzando en Z
		}
		else
		{
			detenerZFinal = true; // Detiene el avance final
			rotarUltimaVez = true; // Activa el último giro
		}
	}

	// 7. Último giro


	// 8. Avance final en X hasta el tope
	if (avanzarXFinal && !detenerXFinal)
	{
		if (posXBob < 25) // Avanza hasta el tope definido
		{
			posXBob += 0.1; // Continúa avanzando en X
		}
		else
		{
			detenerXFinal = true; // Detiene el avance final en X
		}
	}
	
	if (rotarUltimaVez && detenerZFinal)
	{
		if (anguloBob > ultimoGiroAngulo)
		{
			anguloBob -= 0.1;  // Decrementa el ángulo para el último giro
		}
		else
		{
			anguloBob = ultimoGiroAngulo;  // Finaliza el último giro
			avanzarXFinal = true; // Activa el movimiento en X nuevamente
		}
	}

	// Aplicamos la traslación, la escala y la rotación
	glTranslated(posXBob, -1, posZBob);  // Traslación en Z y X
	glScaled(0.1, 0.1, 0.1);             // Escala de Bob Esponja
	glRotated(anguloBob, 0, 1, 0);       // Rotación sobre el eje Y

	bobEsponja();  // Dibuja a Bob Esponja

	glPopMatrix();  // Restauramos las transformaciones
}









void roquita(GLuint texturas[100]) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[11]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
	semiEsferaT(10, 6, 25); // radio, slices, stacks
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}
//Alga
float tiempo = 0.0f;

void algaAnimada(float altura, int segmentos) {
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= segmentos; ++i) {
		float t = (float)i / segmentos; // Proporción actual de la altura
		float y = t * altura;

		float desplazamiento = sin(t * 3.1415 + tiempo) * 0.3;

		float ancho = 0.8 * (1.2 - t); 

		// Vértices del TRIANGLE_STRIP
		glVertex3f(-ancho + desplazamiento, y, 0.0f);
		glVertex3f(ancho + desplazamiento, y, 0.0f);
	}
	glEnd();
}

void alga() {
	tiempo += 0.05;
	glColor3ub(110, 133, 53);
	algaAnimada(15, 20);

	glColor3ub(118, 226, 49);
	glPushMatrix();
		glTranslated(2, 0, 0);
		glScaled(1, 0.8, 1);
		algaAnimada(15, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-2, 0, 0);
		glScaled(1, 0.8, 1);
		algaAnimada(15, 20);
	glPopMatrix();

	glColor3ub(82, 173, 31);
	glPushMatrix();
		glTranslated(-1, 0, 0.5);
		glScaled(1, 0.5, 1);
		algaAnimada(15, 20);
	glPopMatrix();

	glPushMatrix();
		glTranslated(1, 0, 0.5);
		glScaled(1, 0.5, 1);
		algaAnimada(15, 20);
	glPopMatrix();
	
}


// Medusa

// Posiciones de la medusa
float posXMedusa = 0.0f;
float posYMedusa = 4.0f;  // Comienza a una altura de 4
float posZMedusa = 0.0f;

// Velocidades de la medusa
float velocidadX = 0.02f;
float velocidadY = 0.01f;
float velocidadZ = 0.015f;

// Limites de movimiento
float limiteX = 5.0f;
float limiteY = 6.0f;
float limiteZ = 5.0f;



void movimiento()
{
	// Actualización de la posición
	posXMedusa += velocidadX;
	posYMedusa += velocidadY;
	posZMedusa += velocidadZ;

	// Movimiento en el eje X (izquierda/derecha)
	if (posXMedusa > limiteX || posXMedusa < -limiteX) {
		velocidadX = -velocidadX;  // Invertir dirección
	}

	// Movimiento en el eje Y (arriba/abajo)
	if (posYMedusa > limiteY || posYMedusa < 2.0f) {  // Limitar el rango inferior
		velocidadY = -velocidadY;  // Invertir dirección
	}

	// Movimiento en el eje Z (adelante/atrás)
	if (posZMedusa > limiteZ || posZMedusa < -limiteZ) {
		velocidadZ = -velocidadZ;  // Invertir dirección
	}
}


void tentaculo(float longitud, int segmentos, float tiempoOffset) {
	glColor3ub(237, 162, 185);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= segmentos; ++i) {
		float t = (float)i / segmentos;
		float y = -t * longitud; 

		float desplazamiento = sin(t * 3.1415 * 2 + tiempo + tiempoOffset) * 0.1;

		glVertex3f(desplazamiento, y, 0);
	}
	glEnd();
}

void medusa(GLuint texturas[100]) {
	
	glPushMatrix();

	glTranslated(posXMedusa, posYMedusa, posZMedusa);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[12]);
	glColor3ub(250, 250, 250);

	glPushMatrix();
		glTranslated(0, 4, 0);
		semiEsferaT(2, 50, 50);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	// Tentáculos
	int numeroDeTentaculos = 10;
	for (int i = 0; i < numeroDeTentaculos; ++i) {
		glPushMatrix();
		float angulo = (2 * 3.1415 / numeroDeTentaculos) * i;
		glTranslated(sin(angulo) * 0.5, 4, cos(angulo) * 0.5);
		glScaled(2,1.5,2);
		tentaculo(2, 30, angulo);
		glPopMatrix();
	}

	glPopMatrix();
}


void medusaMoviendose(GLuint texturas[100])
{
	movimiento();
	tiempo += 0.05;
	medusa(texturas);
}
