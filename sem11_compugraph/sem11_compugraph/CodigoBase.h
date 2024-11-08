#pragma once
#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
using namespace std;
#pragma endregion

void WorkSpace()
{
    glColor4ub(15, 104, 247, 120);
    glPushMatrix();
    glTranslated(0, 25, 0);
    glScalef(1,0.5,1);
    cubo(100);
    glPopMatrix();

}

