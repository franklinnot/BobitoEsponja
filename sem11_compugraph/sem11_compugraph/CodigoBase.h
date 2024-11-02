#pragma once
#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
using namespace std;
#pragma endregion

void WorkSpace(GLuint texturas[100])
{

    glColor4ub(15, 104, 247, 100);
    glPushMatrix();
    glTranslated(0, 25, 0);
    glScalef(1,0.5,1);
    cubo(100);
    glPopMatrix();

}
