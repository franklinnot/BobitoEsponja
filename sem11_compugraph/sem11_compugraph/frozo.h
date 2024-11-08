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

/* Casa genérica, casa calamardo, cielo de fondo de bikini, patricio*/

void casagenerica(GLUquadric* quad) {
    
    glColor3ub(83, 150, 166);

    //casas
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0); 
    cilindroDiv(2, 2, 7, 20); 
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 6, 0);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0); 
    cilindroDiv(2, 2.8, 4, 20);
    glPopMatrix();
    
    //techodelacasa
    glPushMatrix();
    glTranslated(0, 10.8, 0); 
    glRotatef(90, 1, 0, 0);
    gluDisk(gluNewQuadric(), 0, 2.8 * 1.2, 20, 1);
    glPopMatrix();

    //chimenea
    glPushMatrix();
    glScalef(1.2f,1.0f,1.2f);
    glTranslated(-0.2, 10.8, 0);
    glRotatef(-90,1,0,0);
    glRotatef(-10, 0, 1, 0);
    cilindroDiv(0.5, 0.5, 1.5, 20); 
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5, 11.5, 0);
    glScalef(1.2f, 1.0f, 1.2f);
    glRotatef(-90, 1, 0, 0);
    cilindroDiv(0.5, 1, 2, 10); 
    glPopMatrix();
    
    // Chimenea? horizontal
    glPushMatrix();
    glTranslated(1.2, 5.0, 1.5);
    glRotatef(40, 0, 1, 0); 
    cilindroDiv(0.5, 0.5, 4, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.5, 4.5, 4.4);
    glScalef(1.2f, 1.0f, 1.2f);
    glRotatef(-90, 1, 0, 0);
    cilindroDiv(0.5, 1, 4, 10);
    glPopMatrix();

    // Dibujar la puerta
    glPushMatrix();
    glTranslated(0, 1.5, 2.4);
    glScalef(1.4f, 3.0f, 0.0f); 
    glColor3ub(139, 69, 19); 
    glutSolidCube(1.0);
    glPopMatrix();
    //adornopuerta
    glPushMatrix();
    glTranslated(0, 2, 2.4); 
    glRotatef(180, 1, 0, 0);
    glScaled(1.4, 1.4, 0.1);
    glColor3ub(255, 255, 255); 
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 2, 2.4);
    glScaled(0.5, 0.5, 0.5);
    glRotatef(90, 0, 0, 1);
    glColor3ub(45, 104, 184);
    dona(0.2f, 0.6f, 20, 20);
    glPopMatrix();

    //marco ventana
    glPushMatrix();
    glTranslated(-1.9, 7.5, 2);  
    glScaled(0.5, 0.5, 0.5);
    glRotatef(10, 0, 0, 1);
    glRotatef(140, 0, 1, 0); 
    glColor3ub(45, 104, 184);  
    dona(0.4f, 1.6f, 20, 20);  
    glPopMatrix();
    //vidrio
    glPushMatrix();
    glTranslated(-1.9, 7.5, 2);
    glRotatef(10, 0, 0, 1);
    glRotatef(140, 0, 1, 0);
    glScaled(3, 3, 0.1);
    glColor3ub(255, 255, 255); 
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

}



void casacalamardo(GLuint texturas[100],GLUquadric* quad) {
    //casa
    glPushMatrix();
    glTranslated(0, 0, 0); // Ajustar la posición del cuerpo
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(11,51,123); // Color del cuerpo
    cilindroDiv(1.5, 0.8, 4, 20); // Llamada al método cilindro
    glPopMatrix();
    //techodelacasa
    glPushMatrix();
    glTranslated(0, 4.8, 0);
    glRotatef(90, 1, 0, 0);
    gluDisk(gluNewQuadric(), 0, 0.8 * 1.2, 20, 1);
    glPopMatrix();

    //ventanasmarco
    glPushMatrix();
    glTranslated(0.5, 3, 1.2); 
    glScaled(0.5, 0.5, 0.5);
    glRotatef(90, 0, 0, 1); 
    glColor3ub(45, 104, 184);  
    dona(0.2f, 0.6f, 20, 20);  
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5, 3, 1.2);  
    glScaled(0.5, 0.5, 0.5);
    glRotatef(90, 0, 0, 1);
    glColor3ub(45, 104, 184);  
    dona(0.2f, 0.6f, 20, 20);  
    glPopMatrix();

    //cejas
    glPushMatrix();
    glTranslated(0.8, 3.5, 1.2); 
    glScaled(1.2, 1.2, 0.8);
    glRotatef(-90, 0, 1, 0);
    glColor3ub(108, 212, 249); 
    cilindroDiv(0.1, 0.1, 1.3, 10); 
    glPopMatrix();

    //nariz
    glPushMatrix();
    glTranslated(0, 2, 1.3); 
    glScaled(1.2, 1.2, 1);
    glRotatef(-95, 1, 0, 0);
    glColor3ub(108, 212, 249); 
    cilindroDiv(0.4, 0.1, 1.2, 10); 
    glPopMatrix();

    //puerta
    glPushMatrix();
    glTranslated(0, 0.7, 1.7); 
    glRotatef(170, 1, 0, 0);
    glScalef(1.0f, 1.4f, 0.1f);
    glColor3ub(139, 69, 19);
    glutSolidCube(1.0);
    glPopMatrix();

    //ojos
    glPushMatrix();
    glTranslated(0.5, 3, 1.25);
    glScaled(1, 1, 0.1);
    glColor3ub(255, 255, 255);
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5, 3, 1.25); 
    glScaled(1, 1, 0.1);
    glColor3ub(255, 255, 255); 
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    //orejas
    glPushMatrix();
    glTranslated(1.2, 2, 0); 
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(11, 51, 123);
    cilindroDiv(0.4, 0.4, 1.1, 20); 
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.2, 2, 0);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(11, 51, 123);
    cilindroDiv(0.4, 0.4, 1.1, 20);
    glPopMatrix();
}

void cielofondodebikini(GLuint texturas[100], GLUquadric* quad) {
 
}


void patricio(GLuint texturas[100],GLUquadric* quad) {

    // Cabeza
    glPushMatrix();
    glTranslated(0, 8.5, 0);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1.4, 0, 0); // Rotar 90 grados alrededor del eje X para que esté vertical
    glColor3ub(252,154,156);
    cilindroDiv(1, 0.3, 3, 20); // Llamada al método cilindro
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 11.9, 0);
    glScaled(0.04, 0.04, 0.04);
    semiEsfera(quad,10);
    glPopMatrix();

    // Cuerpo
    glPushMatrix();
    glTranslated(0, 5, 0); // Ajustar la posición del cuerpo
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(252, 154, 156); // Color del cuerpo
    cilindroDiv(2,1, 3, 20); // Llamada al método cilindro
    glPopMatrix();

    //cinturaabajo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[41]);
    glColor3ub(250, 250, 250);
    glPushMatrix();
        glTranslated(0, 5, 0);
        glRotatef(180, 1, 0, 0);
        glScaled(0.24, 0.24, 0.24);
        semiEsfera(quad, 10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(0.7, 2.2, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(93, 224, 0); // Color de las piernas
    cilindroDiv(0.6, 0.6, 1.5, 20); // Llamada al método cilindro
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.7, 2.2, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(93, 224, 0); // Color de las piernas
    cilindroDiv(0.6, 0.6, 1.5, 20); // Llamada al método cilindro
    glPopMatrix();




    // Brazo derecho
    glPushMatrix();
    glTranslated(1.4, 6.5, 0);
    glRotatef(60, 0, 1, 0);
    glColor3ub(252, 154, 156); // Color piel
    cilindroDiv(0.9, 0, 4, 20); // Llamada al método cilindro
    glPopMatrix();

    // Brazo izquierdo
    glPushMatrix();
    glTranslated(-1.4, 6.5, 0);
    glRotatef(-60, 0, 1, 0);
    glColor3ub(252, 154, 156); // Color piel
    cilindroDiv(0.9, 0, 4, 20); // Llamada al método cilindro
    glPopMatrix();

    // Pierna derecha
    glPushMatrix();
    glTranslated(0.7, 1, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(252, 154, 156); // Color de las piernas
    cilindroDiv(0.5, 0.5, 4, 20); // Llamada al método cilindro
    glPopMatrix();

    // Pierna izquierda
    glPushMatrix();
    glTranslated(-0.7, 1, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(252, 154, 156); // Color de las piernas
    cilindroDiv(0.5, 0.5, 4, 20); // Llamada al método cilindro
    glPopMatrix();

    //ojos
    glPushMatrix();
    glTranslated(0.4, 8, 1.3); // Posición del ojo derecho
    glScaled(2, 3, 1);
    glColor3ub(255,255,255); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.4, 8, 1.3); // Posición del ojo izquierdo
    glScaled(2,3,1);
    glColor3ub(255,255,255); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    // pupilas
    glPushMatrix();
    glTranslated(0.4, 8, 1.4); // Posición del ojo derecho
    glColor3ub(0, 0, 0); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.4, 8, 1.4); // Posición del ojo izquierdo
    glColor3ub(0, 0, 0); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    // Boca
    glPushMatrix();
    glTranslated(0, 7, 1.5); // Posición de la boca
    glScaled(2,3,1);
    glColor3ub(255, 0, 0); // Color de la boca
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();
}
