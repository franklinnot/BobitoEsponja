
#pragma region Includes
#pragma once
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
using namespace std;
#pragma endregion

void dibujarEjes(float tamano) {
    glBegin(GL_LINES);

    // Eje X en rojo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(tamano, 0.0, 0.0);

    // Eje Y en verde
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, tamano, 0.0);

    // Eje Z en azul
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, tamano);

    glEnd();
}

void cilindro(float radioBase, float radioTope, float altura, int divisiones) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radioBase, radioTope, altura, divisiones, divisiones);
    glPopMatrix();
}

#pragma region Esfera
void esfera(GLdouble radio, GLint divisiones) {
    glPushMatrix();
    glutSolidSphere(radio, divisiones, divisiones);
    glPopMatrix();
}

void esfera(GLdouble radio) {
    glPushMatrix();
    glutSolidSphere(radio, 50, 50);
    glPopMatrix();
}

void esfera(GLUquadric* quadcito, GLdouble radio) {
    glPushMatrix();
    gluSphere(quadcito, radio, 50, 50);
    glPopMatrix();
}

void esfera(GLUquadric* quadcito, GLdouble radio, GLint divisiones) {
    glPushMatrix();
    gluSphere(quadcito, radio, divisiones, divisiones);
    glPopMatrix();
}

#pragma endregion

#pragma region Cubo

void cubo(GLfloat size) {
    GLfloat halfSize = size / 2.0f;

    // Cara frontal
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-halfSize, -halfSize, halfSize);  
    glVertex3f(halfSize, -halfSize, halfSize);  
    glVertex3f(halfSize, halfSize, halfSize);  
    glVertex3f(-halfSize, halfSize, halfSize);  
    glEnd();

    // Cara trasera
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize); 
    glVertex3f(-halfSize, halfSize, -halfSize); 
    glVertex3f(halfSize, halfSize, -halfSize);  
    glVertex3f(halfSize, -halfSize, -halfSize);  
    glEnd();

    // Cara izquierda
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize); 
    glVertex3f(-halfSize, -halfSize, halfSize); 
    glVertex3f(-halfSize, halfSize, halfSize);  
    glVertex3f(-halfSize, halfSize, -halfSize);
    glEnd();

    // Cara derecha
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(halfSize, -halfSize, -halfSize); 
    glVertex3f(halfSize, halfSize, -halfSize);  
    glVertex3f(halfSize, halfSize, halfSize);   
    glVertex3f(halfSize, -halfSize, halfSize);   
    glEnd();

    // Cara superior
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-halfSize, halfSize, -halfSize); 
    glVertex3f(-halfSize, halfSize, halfSize);   
    glVertex3f(halfSize, halfSize, halfSize);    
    glVertex3f(halfSize, halfSize, -halfSize);  
    glEnd();


    // Cara inferior
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize); 
    glVertex3f(halfSize, -halfSize, halfSize);  
    glVertex3f(-halfSize, -halfSize, halfSize);  
    glEnd();
}
void cubo(float escalaX, float escalaY, float escalaZ) {
    glPushMatrix();
        glScalef(escalaX, escalaY, escalaZ);
        cubo(10.0f);
    glPopMatrix();
}
void cubo(float size, float escalaX, float escalaY, float escalaZ) {
    glPushMatrix();
    glScalef(escalaX, escalaY, escalaZ);
    cubo(size);
    glPopMatrix();
}
#pragma endregion

void dona(float radioInterior, float radioExterior, int lados, int anillos) {
    glPushMatrix();
    glutSolidTorus(radioInterior, radioExterior, lados, anillos);
    glPopMatrix();
}

#pragma region SemiEsfera

void semiEsfera(float radius, int slices, int stacks) {
    for (int i = 0; i <= stacks / 2; ++i) {
        float theta1 = (float)i / stacks * 3.1415;
        float theta2 = (float)(i + 1) / stacks * 3.1415;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = (float)j / slices * 2.0f * 3.1415;

            float x1 = radius * sinf(theta1) * cosf(phi);
            float y1 = radius * cosf(theta1);
            float z1 = radius * sinf(theta1) * sinf(phi);

            float x2 = radius * sinf(theta2) * cosf(phi);
            float y2 = radius * cosf(theta2);
            float z2 = radius * sinf(theta2) * sinf(phi);

            glVertex3f(x1, y1, z1);  // Primer vértice
            glVertex3f(x2, y2, z2);  // Segundo vértice
        }
        glEnd();
    }
}

void semiEsfera(float radius) {
    int slices = 100;
    int stacks = 100;
    for (int i = 0; i <= stacks / 2; ++i) {
        float theta1 = (float)i / stacks * 3.1415;
        float theta2 = (float)(i + 1) / stacks * 3.1415;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = (float)j / slices * 2.0f * 3.1415;

            float x1 = radius * sinf(theta1) * cosf(phi);
            float y1 = radius * cosf(theta1);
            float z1 = radius * sinf(theta1) * sinf(phi);

            float x2 = radius * sinf(theta2) * cosf(phi);
            float y2 = radius * cosf(theta2);
            float z2 = radius * sinf(theta2) * sinf(phi);

            glVertex3f(x1, y1, z1);  // Primer vértice
            glVertex3f(x2, y2, z2);  // Segundo vértice
        }
        glEnd();
    }
}


void semiEsfera(GLUquadric* quad, GLdouble radio) {
    glPushMatrix();
    glRotatef(180, 0.0, 0.0, 1.0);

    glEnable(GL_CLIP_PLANE0);
    GLdouble equation[] = { 0.0, -1.0, 0.0, 0.0 }; 
    glClipPlane(GL_CLIP_PLANE0, equation);

    quad = gluNewQuadric();
    gluQuadricTexture(quad, 1);
    gluSphere(quad, radio, 50, 50);
    gluDeleteQuadric(quad);

    glDisable(GL_CLIP_PLANE0);
    glPopMatrix();
}



#pragma endregion









