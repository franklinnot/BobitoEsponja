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


#pragma region 
//Codigo de cajon

#pragma region Codigo de cajon

float camaraX = 30;
float camaraY = 50;
float camaraZ = 30;
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

void teclado(int tecla, int x, int y) {

    switch (tecla)
    {
    case 101:
        std::cout << "Manito arriba" << std::endl;
        camaraY += 2;
        break;

    case 103:
        std::cout << "Manito abajo" << std::endl;
        camaraY -= 2;
        break;

    case 102:
        std::cout << "Patita derecha" << std::endl;
        angulo -= 2;
        break;

    case 100:
        std::cout << "Patita izquierda" << std::endl;
        angulo += 2;
        break;
    }
}

#pragma endregion

//Metodos de clase

#pragma region Metodos de ejemplo de la semana 11

//Levi

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
        glTranslated(-6, -1, 10);

        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-6, -1, 20.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-6, -1, 30.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-6, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(40, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(30, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(20, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(10, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-10, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-20, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-30, -1, 40.5);
        pista();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-40, -1, 40.5);
        pista();
        glPopMatrix();
        glPushMatrix();
        glTranslated(-50, -1, 40.5);
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

void puerta()
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

    calles();

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
    puerta();
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

void cargarImagenes() {
    loadTexturesFromFile("Texturas/textura_cuadros.bmp",0);

     //Texturas - Boyita
    loadTexturesFromFile("Texturas/casa_patricio.bmp", 10);

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
    gluLookAt(camaraX, camaraY, camaraZ, 0, 5, 0, 0, 1, 0);
    glClearColor(255 / 255.0, 255 / 255.0, 210 / 255.0, 1);
    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    piso();
    ejes();
    #pragma endregion
    // Aqui colocar todo el codigo

    WorkSpace(texturas);

    #pragma region Metodos de franklin
    Isla(texturas, quad);

    glPushMatrix();
        glTranslated(0, 5, 0);
        glRotated(-180, 0, 1, 0);
        Plankton();
    glPopMatrix();
    #pragma endregion

    #pragma region Metodos de boyita
    //casaPatricio(texturas,quad);
    //burbujitas();
    //coralOne();
    //coralTwo();
    //casaBobEsponja();
    //bobEsponja();
    #pragma endregion

    #pragma region Metodos de jose
    //casagenerica(quad);
    //patricio(texturas,quad);
    //casacalamardo(texturas, quad);
    #pragma endregion

    // Jesus
    //curstaceo_cascarudo();

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
