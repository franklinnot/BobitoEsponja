#pragma region Includes
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <iostream>
#include "texturas/RgbImage.h"
#include "MetodosPoligonos.h"
#include "CodigoBase.h"
#include "Levi.h"
#include "franklin.h"
#include "boyita.h"
#include "frozo.h"
using namespace std;
#pragma endregion

#pragma region Codigo de cajon

float camaraX = 20;
float camaraY = 20;
float camaraZ = 20;
float camaraTargetX = 0;
float camaraTargetY = 8;
float camaraTargetZ = 0;
float anguloHorizontal = 0.0f;
float anguloVertical = 0.0f;
float distanciaCamara = 20.0f;

int mouseX, mouseY;
bool isMousePressed = false;
bool isRightMousePressed = false;

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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, theTextMap.GetNumCols(), 
        theTextMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTextMap.ImageData());
}

void iniciarVentana(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (float)w / (float)h, 1, 500);
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
	glBindTexture(GL_TEXTURE_2D, texturas[63]);
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

// Función para actualizar la posición de la cámara
void actualizarCamara() {
    camaraX = camaraTargetX + distanciaCamara * cos(anguloVertical) * sin(anguloHorizontal);
    camaraY = camaraTargetY + distanciaCamara * sin(anguloVertical);
    camaraZ = camaraTargetZ + distanciaCamara * cos(anguloVertical) * cos(anguloHorizontal);
}

// Función de manejo del teclado
void teclado(int tecla, int x, int y) {
    switch (tecla) {
    case 101: // Flecha hacia arriba
        camaraTargetY += 1.0f;
        break;
    case 103: // Flecha hacia abajo
        camaraTargetY -= 1.0f;
        break;
    case 102: // Flecha derecha
        anguloHorizontal += 0.05f;
        break;
    case 100: // Flecha izquierda
        anguloHorizontal -= 0.05f;
        break;
    case '+': // Tecla de más para acercar
        distanciaCamara *= 0.9f;
        break;
    case '-': // Tecla de menos para alejar
        distanciaCamara /= 0.9f;
        break;
    }
    actualizarCamara();
    glutPostRedisplay();
}

// Función de manejo del mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isMousePressed = true;
            mouseX = x;
            mouseY = y;
        }
        else if (state == GLUT_UP) {
            isMousePressed = false;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            isRightMousePressed = true;
            mouseX = x;
            mouseY = y;
        }
        else if (state == GLUT_UP) {
            isRightMousePressed = false;
        }
    }
    else if (button == 3) { // Scroll hacia arriba
        distanciaCamara *= 0.9f;
        actualizarCamara();
        glutPostRedisplay();
    }
    else if (button == 4) { // Scroll hacia abajo
        distanciaCamara /= 0.9f;
        actualizarCamara();
        glutPostRedisplay();
    }
}

// Función para manejar el movimiento del mouse
void mouseMotion(int x, int y) {
    if (isMousePressed) {
        // Movimiento de rotación con el botón izquierdo
        int deltaX = x - mouseX;
        int deltaY = y - mouseY;

        anguloHorizontal += deltaX * 0.005f;
        anguloVertical += deltaY * 0.005f;

        // Limitar el ángulo vertical para no pasar sobre la cámara
        if (anguloVertical > 1.5f) anguloVertical = 1.5f;
        if (anguloVertical < -1.5f) anguloVertical = -1.5f;

        mouseX = x;
        mouseY = y;

        actualizarCamara();
        glutPostRedisplay();
    }
    else if (isRightMousePressed) {
        // Movimiento de desplazamiento con el botón derecho
        int deltaX = x - mouseX;
        int deltaY = y - mouseY;

        // Desplazamiento en el eje X y Z en función de la orientación de la cámara
        float desplazamientoX = deltaX * 0.1f * cos(anguloHorizontal);
        float desplazamientoZ = deltaX * 0.1f * sin(anguloHorizontal);

        // Ajustar los valores para el movimiento en X y Z
        camaraX += desplazamientoX;
        camaraZ += desplazamientoZ;
        camaraTargetX += desplazamientoX;
        camaraTargetZ += desplazamientoZ;

        // Actualizar la posición del mouse
        mouseX = x;
        mouseY = y;

        actualizarCamara();
        glutPostRedisplay();
    }
}

#pragma endregion

//Metodos de clase

#pragma region Codigo de jesus

void pista()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[65]);
    //Imprtante el color para que aparezca la imagen 
    glColor3ub(255, 255, 255);

    glPushMatrix();
        glRotated(90, 90, 0,1);
    glBegin(GL_POLYGON);
    //Agregamos la imagen con gltexcoord2f en las medidas establecidas
    glTexCoord2f(0, 1); glVertex3d(0, 10.8, 0);
    glTexCoord2f(1, 1);	glVertex3d(12.2, 10.8, 0);
    glTexCoord2f(1, 0); glVertex3d(12.2, 0, 0);
    glTexCoord2f(0, 0); glVertex3d(0, 0, 0);

    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void calles()
{

    glPushMatrix();
    glTranslated(-51, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-42, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-33, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-24, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    glRotated(1, 1, 0, 0);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-6, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(12, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(21, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(30, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 0, 0);
    glScaled(0.8, 0.8, 0.8);
    pista();
    glPopMatrix();


}


void callesCrustaceo()
{

    glPushMatrix();
        glTranslated(-51, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-42, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-33, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-24, 0, 0);
        glScaled(0.8,0.8,0.8);
        glRotated(1,1,0,0);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-15, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-6, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(3, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(12, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(21, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(30, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(39, 0, 0);
        glScaled(0.8,0.8,0.8);
        pista();
    glPopMatrix();


}

void madera()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[61]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void banderas()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[66]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void puertaLev()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[68]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void ventanas()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[68]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void ventanafrontalder()
{
            glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[69]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void ventanafrontalizq()
{
            glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[70]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void ventanalateral()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[67]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void pilaresverticales()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[71]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
        glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
        glTexCoord2f(1, 0);  glVertex3d(25.6, 0, 0);
        glTexCoord2f(0, 0);  glVertex3d(0, 0, 0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void techo()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[61]);
    glColor3ub(255, 255, 255);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE); 
    gluCylinder(quad, 10, 10, 30, 50, 50); 
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);
}

void Pilaresuperiores()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[61]);
    glColor3ub(255, 255, 255);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    glEnable(GL_CLIP_PLANE0);
    GLdouble ecuacionPlano[4] = { 0.0, 1.0, 0.0, 0.0 };
    glClipPlane(GL_CLIP_PLANE0, ecuacionPlano);
    glPushMatrix();
        glutSolidTorus(1.0, 3.0, 50, 50); // Radio menor 1.0, radio mayor 3.0
        gluDeleteQuadric(quad);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_TEXTURE_2D);
}

void chimeneabase()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[72]);
    glColor3ub(255, 255, 255);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 10, 10, 30, 50, 50);
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);
}

void tapachimenea()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[72]);
    glColor3ub(255, 255, 255);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluDisk(quad, 0, 1, 32, 32);
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);
}

void curstaceo_cascarudo()
{
    //Local
    glPushMatrix();
    glTranslated(0, 10, 1);
    base(40, 20, 20, 61);
    glPopMatrix();

    socalos();

    pilares();

    //madera anterior
    glPushMatrix();
    glTranslated(-19.2, 3, -9.5);
    glScaled(1.6, 1.2, 0);
    madera();
    glPopMatrix();

    //banderas
    glPushMatrix();
    glTranslated(-20, 13, 11.5);
    glScaled(1.6, 0.5, 0);
    banderas();
    glPopMatrix();

    //ventanas laterales
    glPushMatrix();
    glTranslated(-20.5, 2, 10);
    glRotated(90, 0, 1, 0);
    glScaled(0.7, 1.8, 0);
    ventanalateral();
    glPopMatrix();

    glPushMatrix();
    glTranslated(20.5, 2, 10);
    glRotated(90, 0, 1, 0);
    glScaled(0.7, 1.8, 0);
    ventanalateral();
    glPopMatrix();

    //Puerta
    glPushMatrix();
    glTranslated(-6, -1, 11.5);
    glRotated(1, 1, 90, 1);
    glScaled(0.5, 1, 0);
    puertaLev();
    glPopMatrix();

    //Ventanas frontales
    glPushMatrix();
    glTranslated(6, -1, 11.5);
    glRotated(1, 90, 90, 1);
    glScaled(0.6, 1, 0);
    ventanafrontalder();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-20, -1, 11.5);
    glRotated(1, 90, 90, 1);
    glScaled(0.6, 1, 0);
    ventanafrontalizq();
    glPopMatrix();

    //Cubierta madera
        //cubierta derecha
    glPushMatrix();
    glTranslated(5, 2.8, 10);
    glRotated(90, 1, 0, 0);
    glScaled(0.79, 0.4, 1);
    madera();

    glPopMatrix();

    glPushMatrix();
    glTranslated(5, 3, 15.2);
    glRotated(180, 1, 0, 0);
    glScaled(0.79, 0.25, 1);
    madera();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.95, -1, 15.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.28, 0.28, 1);
    madera();
    glPopMatrix();

    //cubierta izquierda
    glPushMatrix();
    glTranslated(-25, 2.8, 10);
    glRotated(90, 1, 0, 0);
    glScaled(0.79, 0.4, 1);
    madera();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-25, 3, 15.2);
    glRotated(180, 1, 0, 0);
    glScaled(0.79, 0.25, 1);
    madera();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.7, -1, 15.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.28, 0.28, 1);
    madera();
    glPopMatrix();

    //cubierta trasera

    glPushMatrix();
    glTranslated(-25, 2.8, -15.3);
    glRotated(90, 1, 0, 0);
    glScaled(1.97, 0.5, 1);
    madera();
    glPopMatrix();

    glPushMatrix();
    glTranslated(25.5, -1, -15.3);
    glRotated(180, 0, 1, 0);
    glScaled(1.97, 0.3, 1);
    madera();
    glPopMatrix();

    //cubierta lateral derecha

    glPushMatrix();
    glTranslated(25.1, 2.8, 10);
    glRotated(-90, 1, 0, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.75, 0.4, 1);
    madera();
    glPopMatrix();

    glPushMatrix();
    glTranslated(25.1, -1, 15.2);
    glRotated(90, 0, 1, 0);
    glScaled(1.19, 0.28, 1);
    madera();
    glPopMatrix();

    //cubierta lateral izquierda
    glPushMatrix();
    glTranslated(-20.1, 2.8, 10);
    glRotated(-90, 1, 0, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.75, 0.35, 1);
    madera();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-25.1, -1, 15.2);
    glRotated(90, 0, 1, 0);
    glScaled(1.19, 0.28, 1);
    madera();
    glPopMatrix();

    //Pilares verticales
    // 
       //Frontal izquierdo
    glPushMatrix();
    glTranslated(-22.8, 2.8, 14.2);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-22.8, 2.8, 9.9);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-22.8, 2.7, 14.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-19.4, 2.7, 14.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    //Frontal derecho
    glPushMatrix();
    glTranslated(19.4, 2.8, 14.2);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();

    glPopMatrix();
    glPushMatrix();
    glTranslated(19.5, 2.8, 9.9);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(22.7, 2.8, 14.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(19.4, 2.8, 14.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    //Anterior izquierdo
    glPushMatrix();
    glTranslated(-22.5, 2.8, -12.2);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-22.5, 2.8, -7.9);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(22.7, 2.8, -7.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(19.4, 2.8, -7.8);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    //Anterior derecho
    glPushMatrix();
    glTranslated(19.5, 2.8, -12.2);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(19.5, 2.8, -7.9);
    glScaled(0.13, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-22.6, 2.8, -7.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-19.3, 2.8, -7.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.19, 1.22, 1);
    pilaresverticales();
    glPopMatrix();

    //Techo
    glPushMatrix();
        glTranslated(-19.5, 18, 1);
        glRotated(90, 0, 1, 0);
        glScaled(1.02, 1.1, 1.3);
        techo();
    glPopMatrix();

    //Lateralessupriores

    glPushMatrix();
        glTranslated(21, 20, 1);
        glRotated(90, 0, 1, 0);
        glScaled(3.6, 3.5, 3);
        Pilaresuperiores();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-21, 20, 1);
        glRotated(90, 0, 1, 0);
        glScaled(3.6, 3.5, 3);
        Pilaresuperiores();
    glPopMatrix();
    //Chimenea
        //
    glPushMatrix();
    glTranslated(-10, 28, 1);
    glRotated(-90, 1, 0, 0);
    glScaled(0.2, 0.2, 0.2);
    chimeneabase();
    glPopMatrix();
        //Tapa chimnea
    glPushMatrix();
    glTranslated(-10, 34, 1);
    glRotated(-90, 1, 0, 0);
    glScaled(2, 2, 2);
    tapachimenea();
    glPopMatrix();



}
#pragma endregion

#pragma region Codigo de jair

void cargarImagenes() {
    loadTexturesFromFile("Texturas/textura_cuadros.bmp",0);

     //Texturas - Boyita
    loadTexturesFromFile("Texturas/casa_patricio.bmp", 10);
    loadTexturesFromFile("Texturas/roquita.bmp", 11);
    loadTexturesFromFile("Texturas/medusa.bmp", 12);
    //Jose
    loadTexturesFromFile("Texturas/shortpatricio.bmp", 41);
    loadTexturesFromFile("Texturas/casacalamardo.bmp", 42);
    loadTexturesFromFile("Texturas/texturamadera.bmp", 43);

    // texturas - jesus
    loadTexturesFromFile("Texturas/madera.bmp", 61);
    loadTexturesFromFile("Texturas/fondito_mar.bmp", 62);
    loadTexturesFromFile("Texturas/arena.bmp", 63);
    loadTexturesFromFile("Texturas/pista.bmp", 65);
    loadTexturesFromFile("Texturas/BanderaCrustaceo.bmp", 66);
    loadTexturesFromFile("Texturas/ventanalateral.bmp", 67);
    loadTexturesFromFile("Texturas/puerta.bmp", 68);
    loadTexturesFromFile("Texturas/ventanafrontalderecha.bmp", 69);
    loadTexturesFromFile("Texturas/ventanafrontalizquierda.bmp", 70);
    loadTexturesFromFile("Texturas/maderah.bmp", 71);
    loadTexturesFromFile("Texturas/chimenea.bmp", 72);
    
    // texturas - franklin
    loadTexturesFromFile("Texturas/awita.bmp", 85);
    loadTexturesFromFile("Texturas/arenita_mar.bmp", 86); 
    loadTexturesFromFile("Texturas/maderita.bmp", 87);
    loadTexturesFromFile("Texturas/palmerita.bmp", 88);
    loadTexturesFromFile("Texturas/arbustito.bmp", 89);
    loadTexturesFromFile("Texturas/cielito.bmp", 90);



    // texturas - jair
    loadTexturesFromFile("Texturas/balde.bmp", 19);
    loadTexturesFromFile("Texturas/manija.bmp", 20);
    loadTexturesFromFile("Texturas/ancla.bmp", 21);
    loadTexturesFromFile("Texturas/pan.bmp", 22);
    loadTexturesFromFile("Texturas/queso.bmp", 23);
    loadTexturesFromFile("Texturas/lechuga.bmp", 24);
    loadTexturesFromFile("Texturas/carne.bmp", 25);
    loadTexturesFromFile("Texturas/guante.bmp", 26);

}
void mano() {

    glPushMatrix();
    glTranslated(-30, 30, 23);
    glScaled(0.3, 0.4, 0.5);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(9, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-31, 30, 23);
    glScaled(0.3, 0.4, 0.5);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(9, 16, 20);
    glPopMatrix();



    glPushMatrix();
    glTranslated(-30.5, 35, 23);
    glScaled(0.5, 0.4, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 8, 8, 10.5, 30, 30); // Aumentar los radios a 6
    glPopMatrix();



    glPushMatrix();
    glTranslated(-30, 30, 20);
    glScaled(0.5, 0.5, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 16, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 22, 20);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 30, 22);
    glScaled(0.5, 0.5, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 16, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 22, 22);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 30, 24);
    glScaled(0.5, 0.5, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 16, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 22, 24);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-30, 30, 26);
    glScaled(0.5, 0.5, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 16, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    glPushMatrix();
    glTranslated(-30, 22, 26);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-32.5, 26, 22);
    glScaled(0.5, 0.5, 0.3);
    glRotated(5, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 3, 3, 16, 30, 30); // Aumentar los radios a 6
    glPopMatrix();

    glPushMatrix();
    glTranslated(-32.5, 26, 22);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-32.5, 25.5, 27);
    glutSolidSphere(1.5, 16, 20);
    glPopMatrix();






}
void baldecarnada() {

    glPushMatrix();
    glColor3ub(87, 106, 205);
    glRotated(0, 0, 1, 0);
    glTranslated(30, 18, -22.5);
    mano();
    glPopMatrix();


    //balde
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[19]);
    glColor3ub(255, 255, 255);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluQuadricNormals(quad, GLU_SMOOTH);
    glPushMatrix();
    glTranslated(0, 29, 0);
    glRotated(90, 1, 0, 0);
    glRotated(180, 0, 0, 1);
    glScaled(1.2, 1.5, 1.2);
    gluCylinder(quad, 10, 8, 25, 35, 30);
    glPopMatrix();
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);


    //manija
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[20]);
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslated(0, 29, 0);   
    glRotated(90, 0, 1, 0);
    glScalef(1.0f, 1.0f, 0.5f); 
    glScaled(1, 1, 4);
    glutSolidTorus(0.5, 13, 40, 50);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}
void dibujarDedo(float x, float y, float z, float tamano) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(tamano, 10, 10);  // Dedo como esfera
    glPopMatrix();
}
void dibujarDisco(float radioInterior, float radioExterior, int cortes) {
    GLUquadric* quadric = gluNewQuadric();
    gluDisk(quadric, radioInterior, radioExterior, cortes, 1);
    gluDeleteQuadric(quadric);
}



void hamburguesa() {

    // pan2
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[22]);
    glColor3ub(255, 255, 255);

    // Crear un quadric para la esfera
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE); // Activar el mapeo de textura
    gluQuadricNormals(quad, GLU_SMOOTH); // Suavizar las normales

    glPushMatrix();
    glTranslated(-25, 10, -25);
    glScaled(1.2, 0.75, 1.2);
    glRotated(270, 1, 0, 0);

    // Dibujar la esfera con textura
    gluSphere(quad, 15, 19, 15);

    glPopMatrix();

    // Liberar el quadric y deshabilitar la textura
    gluDeleteQuadric(quad);
    glDisable(GL_TEXTURE_2D);

    //Queso1
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[23]);
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslated(-25, 10, -25);
    glScaled(0.9, 0.03, 0.9);
    glRotated(270, 1, 0, 0);
    glutSolidCube(35);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //Queso2
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[23]);
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslated(-25, 10, -25);
    glScaled(0.9, 0.03, 0.9);
    glRotated(215, 0, 1, 0);
    glutSolidCube(35);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //lechuga
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[24]);
    glPushMatrix();
    glTranslated(-25, 10, -25);
    glScaled(1.2, 0.35, 1.2);
    glColor3ub(116, 156, 23);
    glRotated(270, 1, 0, 0);
    glutSolidTorus(5, 10.5, 20, 32);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //Carne
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[25]);
    glPushMatrix();
    glTranslated(-25, 8, -25);
    glScaled(1.2, 0.75, 1.2);
    glColor3ub(159, 34, 4);
    glRotated(270, 1, 0, 0);
    glutSolidTorus(5, 11, 20, 32);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);




}

void anclalateral() {


    //Cono
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, 10, 15.5);
    glScaled(5, 4, 4);
    glRotated(270, 1, 0, 0);
    glutSolidCone(1.0f, 2.0f, 20, 20); // radio, altura, slices, stacks
    glPopMatrix();

    //EXTREMO
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); // Color gris oscuro para el balde
    glTranslated(11, 10, 15.5);
    glScaled(0.5, 0.5, 0.5);  // Escalar la forma en un factor de 2 en cada eje
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 6, 5, 15, 30, 30); // Aumentar los radios a 6
    glPopMatrix();



    //enganche

    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, 2, 15.5);
    glScaled(0.5, 0.5, 0.5);
    glRotated(55, 1, 0, 0);
    glutSolidSphere(6, 17, 30);
    glPopMatrix();




    // CURVA
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, 1, 16);
    glScaled(0.5, 0.5, 0.5);
    glRotated(55, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 6, 7, 20, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    //enganche

    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, -7, 22);
    glScaled(0.5, 0.5, 0.5);
    glRotated(55, 1, 0, 0);
    glutSolidSphere(8, 16, 20);
    glPopMatrix();





    //base
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, -7, 20);
    glScaled(0.5, 0.5, 0.5);
    gluCylinder(gluNewQuadric(), 7, 12, 40, 30, 30); // Aumentar los radios a 6
    glPopMatrix();



    //lado largo
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, 35, 40);
    glScaled(0.5, 0.5, 0.5);
    glRotated(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 4, 12, 80, 30, 30); // Aumentar los radios a 6
    glPopMatrix();


    // Cilindro m�s ancho
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslated(11, 35, 17);
    glScaled(0.5, 0.5, 0.5);
    gluCylinder(gluNewQuadric(), 6, 3, 50, 30, 30); // Aumentar los radios a 6
    glPopMatrix();

    glPushMatrix();
    glTranslated(11, 35, 18);
    glColor3f(0.2f, 0.2f, 0.2f);
    glRotated(270, 1, 0, 0);
    glutSolidSphere(3.5, 16, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(10, 42, 40);
    glRotated(90, 0, 1, 0);
    glColor3f(0.2f, 0.2f, 0.2f);
    glutSolidTorus(1, 5, 16, 32);
    glPopMatrix();


 


}
void ancla() {
   anclalateral();


  glPushMatrix();
  glTranslated(22, 0, 80);
  glRotated(180, 0, 1, 0);
  anclalateral();
  glPopMatrix();

}
void anclatextura() {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturas[21]);
        glPushMatrix();
        ancla();  // Llama a la función ancla sin "void"
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }


void cielofondodebikini() {

    //CARA 1
    glPushMatrix(); // Guarda el estado actual de la matriz
    glTranslated(-35, 0, 35); // Traslación al punto 50 del eje X

    // Fondo de cielo
    glColor4ub(15, 104, 247, 0);
    glPushMatrix();
    glTranslated(150, 150, 0);
    glScalef(1, 0.5, 1);
    cubo(100);
    glPopMatrix();

    // Textura de fondo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[62]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glTranslated(-12.8, 0, 12.81);
    glScalef(4.0, 4.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0); glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0); glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //CARA2

    glPopMatrix(); // Restaura el estado de la matriz

    glPushMatrix(); // Guarda el estado actual de la matriz
    glTranslated(-35, 0, -60); 

    // Fondo de cielo
    glColor4ub(15, 104, 247, 0);
    glPushMatrix();
    glTranslated(150, 150, 0);
    glScalef(1, 0.5, 1);
    cubo(100);
    glPopMatrix();

    // Textura de fondo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[62]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glTranslated(-12.8, 0, 12.81);
    glScalef(4.0, 4.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0); glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0); glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix(); // Restaura el estado de la matriz

    //CARA 3
    glPushMatrix(); // Guarda el estado actual de la matriz
    glTranslated(60, 0, 40); // Traslación al punto 50 del eje X

    // Fondo de cielo
    glColor4ub(15, 104, 247, 0);
    glPushMatrix();
    glTranslated(150, 150, 0);
    glScalef(1, 0.5, 1);
    cubo(100);
    glPopMatrix();

    // Textura de fondo en una cara rotada
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[62]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glTranslated(-12.8, 0, 12.81);

    // Aplica rotación (90 grados alrededor del eje Y para cambiar de cara)
    glRotated(90, 0, 1, 0); // Cambia los ángulos y ejes según necesites (eje Y en este caso)
    glScalef(4.0, 4.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0); glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0); glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix(); // Restaura el estado de la matriz

    //CARA 3
    glPushMatrix(); // Guarda el estado actual de la matriz
    glTranslated(-35, 0, 40); // Traslación al punto 50 del eje X

    // Fondo de cielo
    glColor4ub(15, 104, 247, 0);
    glPushMatrix();
    glTranslated(150, 150, 0);
    glScalef(1, 0.5, 1);
    cubo(100);
    glPopMatrix();

    // Textura de fondo en una cara rotada
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturas[62]);
    glColor3ub(250, 250, 250);

    glPushMatrix();
    glTranslated(-12.8, 0, 12.81);

    // Aplica rotación (90 grados alrededor del eje Y para cambiar de cara)
    glRotated(90, 0, 1, 0); // Cambia los ángulos y ejes según necesites (eje Y en este caso)
    glScalef(4.0, 4.0, 1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 1); glVertex3d(0, 14.4, 0);
    glTexCoord2f(1, 1); glVertex3d(25.6, 14.4, 0);
    glTexCoord2f(1, 0); glVertex3d(25.6, 0, 0);
    glTexCoord2f(0, 0); glVertex3d(0, 0, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix(); // Restaura el estado de la matriz
}


#pragma endregion

void dibujar() {
    #pragma region No tocar
    inicializarLuces();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glLoadIdentity();
    // Linea para modificar el punto al cual la camara debe enfocar
    gluLookAt(camaraX, camaraY, camaraZ, camaraTargetX, camaraTargetY, camaraTargetZ, 0, 1, 0);
    glClearColor(255 / 255.0, 255 / 255.0, 210 / 255.0, 1);
    glPushMatrix();
    piso();
    #pragma endregion

   // Aqui colocar todo el codigo

   glPushMatrix();
   glTranslated(0, -2, 0);
   WorkSpace();
   glPopMatrix();

    #pragma region Metodos de franklin
    Isla(texturas, quad);

    #pragma endregion

    #pragma region Metodos de boyita
   
    //glPushMatrix();
    //burbujitas();
    //glPopMatrix();

    //glPushMatrix();
    //coralOne();
    //glPopMatrix();

    //glPushMatrix();
    //coralTwo();
    //glPopMatrix();

    glPushMatrix();
        glTranslated(-28, -0.75, 28);
        glScaled(0.35, 0.35, 0.35);
        dibujarEjes(50);
        casaBobEsponja();
    glPopMatrix();


    //glPushMatrix();
    //glTranslated(0, -1, -4);
    //glScaled(0.3, 0.3, 0.3);
    //bobEsponja();
    //glPopMatrix();

    //glPushMatrix();
    //glTranslated(20, -1, -12);
    //glScaled(2, 2, 2);
    //glRotated(-15, 0, 1 , 0);
    //casacalamardo(texturas,quad);
    //glPopMatrix();

    //glPushMatrix();
    //glTranslated(-20, 0, -8);
    //glScaled(0.5, 0.5, 0.5);
    //casaPatricio(texturas, quad);
    //glPopMatrix();
    //glPopMatrix();

    //roquita(texturas);
    //alga();

    tiempo += 0.05;
    medusa(texturas);

    #pragma endregion

    #pragma region Metodos de jose
    //casagenerica(quad);
    //patricio(texturas,quad);
    cielofondodebikini();
    #pragma endregion

    #pragma region Metodos de jesus
    glPushMatrix();
        glTranslated(30, 0, 27);
        glScaled(0.2, 0.2, 0.2);
        glRotated(-110, 0, 1 , 0);
        curstaceo_cascarudo();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, -0.85, -4);
        calles();
    glPopMatrix();
    #pragma endregion

    #pragma region Metodos de jair
    // casa de plankton
    glPushMatrix();
         glTranslated(28, 0, -24);
         glScaled(0.3, 0.3, 0.3);
         glRotated(26, 0, 1, 0);
         baldecarnada();
     glPopMatrix();

     //glPushMatrix();
     //    glTranslated(-22, 0, -2);
     //    glRotated(105, 0, 1, 0);
     //    glScaled(0.2, 0.2, 0.2);
     //    Plankton();
     //glPopMatrix();

    // carrito burger
    glPushMatrix();
        glRotated(90, 0, 1, 0);
        glScaled(0.1, 0.1, 0.1);
        hamburguesa();
    glPopMatrix();

    //// anclita
    //glPushMatrix();
    //    glTranslated(10, 0, -30);
    //    glRotated(55, 0, 1, 0);
    //    glScaled(0.4, 0.4, 0.4);
    //        glPushMatrix();
    //        glTranslated(-2, 8, -2);
    //        glRotated(25, 0, 1, 0);
    //        ancla();
    //        glPopMatrix();
    //glPopMatrix();
    #pragma endregion

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
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutTimerFunc(0, timer, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
#pragma endregion
