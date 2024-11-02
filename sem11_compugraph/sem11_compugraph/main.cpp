
#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include "texturas/RgbImage.h"
#include "MetodosPoligonos.h"
#include "CodigoBase.h"
#include "franklin.h"
#include "boyita.h"

using namespace std;
#pragma endregion

#pragma region Código de cajon

float camaraX = 30;
float camaraY = 20;
float camaraZ = 7;
float angulo = 0;
GLuint texturas[100];
GLUquadric* quad;

void loadTexturesFromFile(const char* filename, int index) {
    RgbImage theTextMap(filename);
    glGenTextures(1, &texturas[index]);
    glBindTexture(GL_TEXTURE_2D, texturas[index]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, theTextMap.GetNumCols(), theTextMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTextMap.ImageData());
}

void iniciarVentana(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (float)w / (float)h, 1, 200);
}

void inicializarLuces() {
    GLfloat luz_ambiente[] = { 0.35,0.35,0.35,1 };
    GLfloat luz_difusa[] = { 0.5,0.5,0.5,1 };
    GLfloat luz_especular[] = { 0.3,0.3,0.3,1 };

    float posicionLuz[] = { 0,70,60,1 };

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void piso() {

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturas[0]);
    glColor3ub(255,255,255);

    glPushMatrix();
        glTranslated(0, -1, 0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 1); glVertex3d(-50, 0, -50);
            glTexCoord2f(1, 1); glVertex3d(50, 0, -50);
            glTexCoord2f(1, 0);  glVertex3d(50, 0, 50);
            glTexCoord2f(0, 0);  glVertex3d(-50, 0, 50);
        glEnd();
    glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void ejes() {
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(50, 0, 0);
    glColor3ub(0, 255, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 50, 0);
    glColor3ub(0, 0, 255);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 50);
    glEnd();
}

void timer(int t) {

    glutPostRedisplay();

    glutTimerFunc(20, timer, 0);

}

void teclado(int tecla, int x, int y) {

    switch (tecla)
    {
    case 101:
        std::cout << "Manito arriba" << std::endl;
        camaraY += 0.2;
        break;

    case 103:
        std::cout << "Manito abajo" << std::endl;
        camaraY -= 0.2;
        break;

    case 102:
        std::cout << "Patita derecha" << std::endl;
        angulo -= 1;
        break;

    case 100:
        std::cout << "Patita izquierda" << std::endl;
        angulo += 1;
        break;

    }

}



#pragma endregion

#pragma region Metodos de ejemplo de la semana 11
void tierra() {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[2]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
	    glTranslated(0, 25, 0);
        glRotated(-90, 1, 0, 0);
        quad = gluNewQuadric();
        gluQuadricTexture(quad, 1);
        esfera(quad, 12);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
void cubito() {
	glColor3ub(140, 220, 250);
	glPushMatrix();
	    glTranslated(0,7.2, 0);
        cubo(20, 1.28, 0.72, 1.28);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[1]);
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
#pragma endregion

void cargarImagenes() {
    loadTexturesFromFile("Texturas/textura_cuadros.bmp",0);
    loadTexturesFromFile("Texturas/goku.bmp", 1);
    loadTexturesFromFile("Texturas/tierra.bmp", 2);
    loadTexturesFromFile("Texturas/fondito_mar.bmp", 3);
    loadTexturesFromFile("Texturas/arenita_mar.bmp", 20);

    //Texturas - Boyita
    loadTexturesFromFile("Texturas/casa_patricio.bmp", 10);

}

void dibujar() {
    #pragma region No tocar
    inicializarLuces();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glLoadIdentity();
    // Linea para modificar el punto al cual la camara debe enfocar
    gluLookAt(camaraX, camaraY, camaraZ, 0, 0, 0, 0, 1, 0);
    glClearColor(255 / 255.0, 255 / 255.0, 210 / 255.0, 1);
    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    piso();
    ejes();
    #pragma endregion

    // Aqui colocar todo el codigo
    
    //WorkSpace(texturas);
    //Isla(texturas, quad);

    // Metodos de Boyita :D
    //casaPatricio(texturas,quad);
    //burbujitas();
    //coralOne();
    coralTwo();



    // aqui termina

    #pragma region No tocar
    glPopMatrix();
    glutSwapBuffers();
    #pragma endregion
}

#pragma region Metodo main - no tocar
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1100, 750);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bienvenidos a computacion grafica");
    glutReshapeFunc(iniciarVentana);
    cargarImagenes();
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
#pragma endregion
