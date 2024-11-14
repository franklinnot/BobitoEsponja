
#pragma region Includes
#pragma once
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
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

void dibujarEjes() {
    glBegin(GL_LINES);

    // Eje X en rojo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100, 0.0, 0.0);

    // Eje Y en verde
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 100, 0.0);

    // Eje Z en azul
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100);

    glEnd();
}

void cilindroDiv(GLdouble radioBase, GLdouble radioTope, GLdouble altura, int divisiones) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radioBase, radioTope, altura, divisiones, divisiones);
    glPopMatrix();
}

void cilindroDiv(GLdouble radio, GLdouble altura, int divisiones) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radio, radio, altura, divisiones, 50);
    
    glPopMatrix();
}

void cilindro(GLdouble radioBase, GLdouble radioTope, GLdouble altura) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radioBase, radioTope, altura, 50, 50);
    glPopMatrix();
}

void cilindro(GLdouble radio, GLdouble altura) {
    glPushMatrix();
    gluCylinder(gluNewQuadric(), radio, radio, altura, 50, 50);
    glPopMatrix();
}

void cilindro(GLUquadric* quad, GLdouble radioBase, GLdouble radioTope, GLdouble altura) {
    glPushMatrix();
    gluCylinder(quad, radioBase, radioTope, altura, 50, 50);
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
    gluSphere(quadcito, radio, 100, 100);
    glPopMatrix();
}

void esfera(GLUquadric* quadcito, GLdouble radio, GLint divisiones) {
    glPushMatrix();
    gluSphere(quadcito, radio, divisiones, divisiones);
    glPopMatrix();
}

void sphere(float radius, const std::vector<std::vector<int>>& colors) {
    // Verifica que los colores de degradado sean válidos
    if (colors.size() != 2 || colors[0].size() < 3 || colors[1].size() < 3) {
        throw std::invalid_argument("Color degradado incorrecto. Se esperan dos colores RGB o RGBA.");
    }

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 100; ++i) {
        float phi = 3.141516 * float(i) / float(100); // Ángulo en vertical
        float y = cosf(phi);
        float r = sinf(phi);

        // Color degradado para el eje vertical
        float t = float(i) / float(100);
        if (colors[0].size() == 4 && colors[1].size() == 4) {
            glColor4ub(
                (1 - t) * colors[0][0] + t * colors[1][0],
                (1 - t) * colors[0][1] + t * colors[1][1],
                (1 - t) * colors[0][2] + t * colors[1][2],
                (1 - t) * colors[0][3] + t * colors[1][3]
            );
        }
        else {
            glColor3ub(
                (1 - t) * colors[0][0] + t * colors[1][0],
                (1 - t) * colors[0][1] + t * colors[1][1],
                (1 - t) * colors[0][2] + t * colors[1][2]
            );
        }

        for (int j = 0; j <= 100; ++j) {
            float theta = 2.0f * 3.141516 * float(j) / float(100); // Ángulo en horizontal
            float x = r * cosf(theta);
            float z = r * sinf(theta);

            // Definimos dos vértices en el mismo ángulo horizontal para formar la banda
            glVertex3f(radius * x, radius * y, radius * z);
            glVertex3f(radius * x, -radius * y, radius * z);
        }
    }
    glEnd();
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

            glVertex3f(x1, y1, z1);  // Primer v�rtice
            glVertex3f(x2, y2, z2);  // Segundo v�rtice
        }
        glEnd();
    }
}

void semiEsferaT(float radius, int slices, int stacks) {
    // Activamos texturizado
    glEnable(GL_TEXTURE_2D);

    // Dibujar la semiesfera
    for (int i = 0; i <= stacks / 2; ++i) {
        // Ángulos para los stacks actuales y el siguiente
        float theta1 = (float)i / stacks * 3.1415;
        float theta2 = (float)(i + 1) / stacks * 3.1415;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = (float)j / slices * 2.0f * 3.1415;

            // Vértices en el primer stack
            float x1 = radius * sinf(theta1) * cosf(phi);
            float y1 = radius * cosf(theta1);
            float z1 = radius * sinf(theta1) * sinf(phi);

            // Coordenadas de textura para el primer vértice
            float u1 = (float)j / slices;
            float v1 = (float)i / stacks;

            glTexCoord2f(u1, v1);
            glVertex3f(x1, y1, z1);

            // Vértices en el segundo stack
            float x2 = radius * sinf(theta2) * cosf(phi);
            float y2 = radius * cosf(theta2);
            float z2 = radius * sinf(theta2) * sinf(phi);

            // Coordenadas de textura para el segundo vértice
            float u2 = (float)j / slices;
            float v2 = (float)(i + 1) / stacks;

            glTexCoord2f(u2, v2);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }

    // Desactivar texturizado
    glDisable(GL_TEXTURE_2D);
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

            glVertex3f(x1, y1, z1);  // Primer v�rtice
            glVertex3f(x2, y2, z2);  // Segundo v�rtice
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









