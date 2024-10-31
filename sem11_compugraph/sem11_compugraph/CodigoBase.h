#pragma once
#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
using namespace std;
#pragma endregion

void WorkSpace(GLuint texturas[5])
{

    glColor4ub(15, 104, 247, 180);
    glPushMatrix();
    glTranslated(0, 24, 0);
    glScalef(1,0.5,1);
    rubik(100);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[3]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glTranslated(-12.8, 0, 12.81);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
