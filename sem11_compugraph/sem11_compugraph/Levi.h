#pragma once
#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include "texturas/RgbImage.h"
#include "MetodosPoligonos.h"
#include "CodigoBase.h"
#include "franklin.h"
using namespace std;
#pragma endregion

void techo()
{
    glPushMatrix();
    glColor3ub(140, 83, 62);
    glRotated(0, 1, 0, 0);
    glTranslated(0, 20, 0);

    gluCylinder(gluNewQuadric(), 10, 10, 30, 50, 50);
    glPopMatrix();
}

void base(GLfloat width, GLfloat height, GLfloat depth, GLuint textureID) {
    GLfloat halfWidth = width / 2.0f;
    GLfloat halfHeight = height / 2.0f;
    GLfloat halfDepth = depth / 2.0f;

    // Habilitar textura y establecer color blanco
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor3ub(255, 255, 255);

    // Cara frontal
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0, 1); glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(1, 1); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(1, 0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0, 0); glVertex3f(-halfWidth, halfHeight, halfDepth);
    glEnd();

    // Cara trasera
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0, 1); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1, 1); glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(1, 0); glVertex3f(halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(0, 0); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glEnd();

    // Cara izquierda
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 1); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1, 1); glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(1, 0); glVertex3f(-halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0, 0); glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glEnd();

    // Cara derecha
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 1); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1, 1); glVertex3f(halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(1, 0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0, 0); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glEnd();

    // Cara superior
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0, 1); glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(1, 1); glVertex3f(-halfWidth, halfHeight, halfDepth);
    glTexCoord2f(1, 0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0, 0); glVertex3f(halfWidth, halfHeight, -halfDepth);
    glEnd();

    // Cara inferior
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(0, 1); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1, 1); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1, 0); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(0, 0); glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void pilares()
{

    glDisable(GL_TEXTURE_2D);
    //pilar1
    glPushMatrix();
    glTranslated(21, 10, -10);
    base(3, 20, 4, 61);
    glPopMatrix();

    //pilar2
    glPushMatrix();
    glTranslated(21, 10, 12);
    base(3, 20, 4, 61);
    glPopMatrix();
    //pilar3

    glPushMatrix();
    glTranslated(-21, 10, 12);
    base(3, 20, 4, 61);
    glPopMatrix();
    //pilar4

    glPushMatrix();
    glTranslated(-21, 10, -10);
    base(3, 20, 4, 61);
    glPopMatrix();
}

void socalos()
{
    //Socalo1
    glPushMatrix();
    glTranslated(15, 1, 5);
    base(20, 3, 20, 61);
    glPopMatrix();

    //Socalo2
    glPushMatrix();
    glTranslated(-15, 1, 5);
    base(20, 3, 20, 61);
    glPopMatrix();

    //Socalo3
    glPushMatrix();
    glTranslated(0, 1, -10);
    base(50, 3, 10, 61);
    glPopMatrix();
}


