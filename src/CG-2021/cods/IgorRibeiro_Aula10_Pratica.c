#include<windows.h>
#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

GLfloat k = -1.0f;

GLfloat kstep = 0.0125f;

GLfloat z = 1.0f;

GLfloat zstep = 0.0125f;

float angle = 0.0;
float step = 5.0;
float val = PI/360;
float offset = 0;
float stepZoom = 0.01;

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(-2.0, -1.0, -1.0,   //posição da câmera (P_0)
              0.0, 0.0, 0.0,   //para onde a câmera aponta (P_ref)
              0.0, 1.0, 0.0); //vetor view-up (V)
}

void drawCube(){
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
     glEnd();
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
     glEnd();
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
     glEnd();
     glColor3f(1.0,1.0,0.0);
     glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
     glEnd();
     glColor3f(0.0,1.0,1.0);
     glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
     glEnd();
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
     glEnd();
}

void idleFunc(int value)
{
    if(k > 1.0 || k < -1.0)
        kstep = -kstep;

    k += kstep;

    if(z > 2.0 || z < 0.5)
        zstep = -zstep;

    z += zstep;

    angle+=step;

    if(offset>0.5 || offset<=-2.0)
        stepZoom=stepZoom*(-1);
    offset-=stepZoom;

    glutPostRedisplay();
}

void camera1(){
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(-2.0, -1.0, -1.0,   //posição da câmera (P_0)
                0.0, 0.0, 0.0,   //para onde a câmera aponta (P_ref)
                0.0, 1.0, 0.0); //vetor view-up (V)
}

void camera2(){
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(sin(angle*val)+cos(angle*val),-1.0,cos(angle*val)-sin(angle*val),   //posição da câmera (P_0)
          0.0, 0.0, 0.0,   //para onde a câmera aponta (P_ref)
          0.0, 1.0, 0.0); //vetor view-up (V)
}

void camera3(){
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(-2.0, k, -1.0,   //posição da câmera (P_0)
                0.0, k, 0.0,   //para onde a câmera aponta (P_ref)
                0.0, 1.0, 0.0); //vetor view-up (V)
}

void camera4(){
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(offset-2,offset-1,offset-1,
              0.0,0.0,0.0,
              0.0, 1.0, 0.0); //vetor view-up (V)  //vetor view-up
}

void displayFunc() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //desenha o fundo (limpa a janela)

     camera1();
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 4.0);
     glViewport(0, 300, 300, 300);
     drawCube();

     camera2();
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-1, 1.0, -1.0, 1.0, 0.7, 4.0);
     glViewport(300, 300, 300, 300);
     drawCube();

     camera3();
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-1.0, 1.0, -1, 1.0, 1.0, 4.0);
     glViewport(0, 0, 300, 300);
     drawCube();

    camera4();
    glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glMatrixMode(GL_PROJECTION);
     glFrustum(-1.0, 1.0, -1, 1.0, 0.5, 8.0);
     glViewport(300, 0, 300, 300);
     drawCube();

     glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(600,600);
    glutCreateWindow("Viewing 3D");
    glutDisplayFunc(displayFunc);
    glutIdleFunc(idleFunc);
    init();
    glutMainLoop();
    return 0;
}
