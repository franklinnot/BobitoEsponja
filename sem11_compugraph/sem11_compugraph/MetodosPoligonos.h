
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

void barril_chavo(float radioBase, float radioTope, float altura, int divisiones) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radioBase, radioTope, altura, divisiones, divisiones);
    glPopMatrix();
}

void canica(GLdouble radio, GLint divisiones) {
    glPushMatrix();
    glutSolidSphere(radio, divisiones, divisiones);
    glPopMatrix();
}

void canica(GLdouble radio) {
    glPushMatrix();
    glutSolidSphere(radio, 50, 50);
    glPopMatrix();
}

void canica(GLUquadric* quadcito, GLdouble radio) {
    glPushMatrix();
    gluSphere(quadcito, radio, 50, 50);
    glPopMatrix();
}

void canica(GLUquadric* quadcito, GLdouble radio, GLint divisiones) {
    glPushMatrix();
    gluSphere(quadcito, radio, divisiones, divisiones);
    glPopMatrix();
}

void rubik(float escalaX, float escalaY, float escalaZ) {
    glPushMatrix();
    glScalef(escalaX, escalaY, escalaZ);
    glutSolidCube(1);
    glPopMatrix();
}
void rubik(float size, float escalaX, float escalaY, float escalaZ) {
    glPushMatrix();
    glScalef(escalaX, escalaY, escalaZ);
    glutSolidCube(size);
    glPopMatrix();
}

void donut(float radioInterior, float radioExterior, int lados, int anillos) {
    glPushMatrix();
    glutSolidTorus(radioInterior, radioExterior, lados, anillos);
    glPopMatrix();
}

void bolcito(float radius, int slices, int stacks) {
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










