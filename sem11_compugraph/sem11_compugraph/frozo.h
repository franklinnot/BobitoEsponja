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

/* Casa gen�rica, casa calamardo, cielo de fondo de bikini, patricio*/

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
    glTranslated(0, 0, 0); // Ajustar la posici�n del cuerpo
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(11,51,123); // Color del cuerpo
    cilindroDiv(1.5, 0.8, 4, 20); // Llamada al m�todo cilindro
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

void pantalonPatricio(float posX)
{
    glPushMatrix();
    glTranslated(posX, 2.2, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(93, 224, 0); // Color de las piernas
    cilindroDiv(0.6, 0.6, 1.5, 20); // Llamada al m�todo cilindro
    glPopMatrix();

}
void piernaPatricio(float posX)
{
    // Pierna derecha
    glPushMatrix();
    glTranslated(posX, 1, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(252, 154, 156); // Color de las piernas
    cilindroDiv(0.5, 0.5, 4, 20); // Llamada al m�todo cilindro
    glPopMatrix();
}

// Variables de personajes
float velocidadPersonaje3 = 5;
float angulo3Pierna1 = 0;
float lado3Pierna1 = 1;
float angulo3Pierna2 = 0;
float lado3Pierna2 = -1;

void patricio(GLuint texturas[100],GLUquadric* quad) {

    // Cabeza
    glPushMatrix();
    glTranslated(0, 8.5, 0);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1.4, 0, 0); // Rotar 90 grados alrededor del eje X para que est� vertical
    glColor3ub(252,154,156);
    cilindroDiv(1, 0.3, 3, 20); // Llamada al m�todo cilindro
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 11.9, 0);
    glScaled(0.04, 0.04, 0.04);
    semiEsfera(quad,10);
    glPopMatrix();

    // Cuerpo
    glPushMatrix();
    glTranslated(0, 5, 0); // Ajustar la posici�n del cuerpo
    glScaled(1.2, 1.2, 1.2);
    glRotatef(-90, 1, 0, 0);
    glColor3ub(252, 154, 156); // Color del cuerpo
    cilindroDiv(2,1, 3, 20); // Llamada al m�todo cilindro
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


    // Movimiento pierna 1
    glPushMatrix();
        angulo3Pierna1 += (velocidadPersonaje3 * lado3Pierna1);
        if (angulo3Pierna1 >= 25)
        {
            lado3Pierna1 = -1;
        }
        if (angulo3Pierna1 <= -25)
        {
            lado3Pierna1 = 1;
        }

        glTranslated(0.5, 5, -0.1);
        glRotated(angulo3Pierna1, 1, 0, 0);
        glTranslated(0, -5, 0.1);

        pantalonPatricio(0.7);
        piernaPatricio(0.7);
    glPopMatrix();
    
    //Movimiento pierna 2

    glPushMatrix();
        angulo3Pierna2 += (velocidadPersonaje3 * lado3Pierna2);

        if (angulo3Pierna2 <= -25)
        {
            lado3Pierna2 = 1;
        }
        if (angulo3Pierna2 >= 25)
        {
            lado3Pierna2 = -1;
        }
        glTranslated(-0.5, 5, -0.1);
        glRotated(angulo3Pierna2, 1, 0, 0);
        glTranslated(0, -5, 0.1);

        pantalonPatricio(-0.7);
        piernaPatricio(-0.7);

    glPopMatrix();


    // Brazo derecho
    glPushMatrix();
    glTranslated(1.4, 6.5, 0);
    glRotatef(60, 0, 1, 0);
    glColor3ub(252, 154, 156); // Color piel
    cilindroDiv(0.9, 0, 4, 20); // Llamada al m�todo cilindro
    glPopMatrix();

    // Brazo izquierdo
    glPushMatrix();
    glTranslated(-1.4, 6.5, 0);
    glRotatef(-60, 0, 1, 0);
    glColor3ub(252, 154, 156); // Color piel
    cilindroDiv(0.9, 0, 4, 20); // Llamada al m�todo cilindro
    glPopMatrix();


    //ojos
    glPushMatrix();
    glTranslated(0.4, 8, 1.3); // Posici�n del ojo derecho
    glScaled(2, 3, 1);
    glColor3ub(255,255,255); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.4, 8, 1.3); // Posici�n del ojo izquierdo
    glScaled(2,3,1);
    glColor3ub(255,255,255); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    // pupilas
    glPushMatrix();
    glTranslated(0.4, 8, 1.4); // Posici�n del ojo derecho
    glColor3ub(0, 0, 0); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.4, 8, 1.4); // Posici�n del ojo izquierdo
    glColor3ub(0, 0, 0); // Color de los ojos
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    // Boca
    glPushMatrix();
    glTranslated(0, 7, 1.5); // Posici�n de la boca
    glScaled(2,3,1);
    glColor3ub(255, 0, 0); // Color de la boca
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();
}





// Variables globales
float posPatricioZ = 30;        // Posición inicial de Patricio en Z
float posPatricioX = -6;        // Posición inicial de Patricio en X
bool detenerPatricio = false;   // Control para detener el movimiento de Patricio en Z
bool pausaAntesDeRotar1 = false; // Control para la pausa antes de la rotación
bool moverEnX1 = false;          // Control para iniciar el movimiento en X después de la rotación
float anguloPatricio = 180;     // Ángulo inicial de rotación
float primerGirox = 90;         // Primer ángulo de giro
float tiempoTranscurrido = 0.0f; // Variable para contar el tiempo transcurrido
bool animacionesIniciadas = false; // Controla si las animaciones han comenzado

void caminapatricio(GLuint texturas[100], GLUquadric* quad)
{
    // Aseguramos que las animaciones solo comiencen después de 5 segundos
    if (!animacionesIniciadas)
    {
        tiempoTranscurrido += 0.01f; // Aumenta el tiempo transcurrido en cada cuadro (ajustar según el tiempo de frame)

        if (tiempoTranscurrido >= 4.0f) // Si han pasado 5 segundos
        {
            animacionesIniciadas = true; // Inicia las animaciones
        }
    }

    // 1. Siempre dibujamos a Patricio, pero sus movimientos solo inician después de los 5 segundos
    glPushMatrix();

    // 2. Si las animaciones han comenzado, realizamos el movimiento
    if (animacionesIniciadas)
    {
        // 1. Movimiento en Z hasta alcanzar la posición deseada
        if (!detenerPatricio && posPatricioZ > 20)  // Avanzar hasta posZMax
        {
            posPatricioZ -= 0.1;  // Avanza Patricio en Z
        }
        else
        {
            detenerPatricio = true;  // Detiene el movimiento cuando se alcanza posZMax
        }

        // 2. Pausa antes de la rotación (después de detener el movimiento en Z)
        if (detenerPatricio && !pausaAntesDeRotar1)
        {
            pausaAntesDeRotar1 = true;  // Activa la pausa antes de rotar
        }

        // 3. Primer rotación después de avanzar en Z
        if (pausaAntesDeRotar1)
        {
            // Primer giro
            if (anguloPatricio < primerGirox)  // Primer giro
            {
                anguloPatricio += 0.1;  // Incrementa el ángulo
            }
            else
            {
                anguloPatricio = primerGirox;  // Asegura que el ángulo no pase del primer giro
                moverEnX1 = true;  // Activa el movimiento en X después de la rotación
            }
        }

        // 4. Movimiento en X después de la rotación
        if (moverEnX1)
        {
            if (posPatricioX < 25)  // Si la posición de X es menor que el tope
            {
                posPatricioX += 0.1;  // Avanza Patricio en X
            }
        }
    }

    // Aplicamos la traslación, la escala y la rotación
    glTranslated(posPatricioX, -1.2, posPatricioZ);  // Traslación en Z y X
    glScaled(0.3, 0.3, 0.3);                         // Escala de Patricio
    glRotated(anguloPatricio, 0, 1, 0);              // Rotación sobre el eje Y

    patricio(texturas, quad);  // Dibuja a Patricio

    glPopMatrix();  // Restauramos las transformaciones
}





