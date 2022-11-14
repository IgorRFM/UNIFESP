#include <windows.h>
#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angX = 0.0;
float angY = 0.0;
int opcao = 0;

float vel = 0.0, velMax=100;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0);
     glPushMatrix();
}

void glTriangulos(){
     glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 1, 0);
    glEnd();
}

void glQuadrado(){
     glBegin(GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(-1, 0, 0);
        glVertex3f(-1, 1, 0);
        glVertex3f(0, 1, 0);
    glEnd();
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(0.0,0.0,1.0);

     glPopMatrix();
     glPushMatrix();

     glRotatef(angX,0.0,0.0,1.0);
     //glRotatef(angY,0.0,1.0,0.0);

    glPushMatrix();
        glRotatef(0,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,0.0,0.0);
        glTriangulos();
    glPopMatrix();

    glPushMatrix();
        glRotatef(0,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glQuadrado();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glTriangulos();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glQuadrado();
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glTriangulos();
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glQuadrado();
    glPopMatrix();

    glPushMatrix();
        glRotatef(270,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,1.0,0.0);
        glTriangulos();
    glPopMatrix();

    glPushMatrix();
        glRotatef(270,0.0,0.0,1.0);
        glTranslatef(1,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glQuadrado();
    glPopMatrix();

     glFlush();
}

void anima()
{
    switch (opcao) {
        case 1:
            if(vel < velMax){ vel+=0.5;}
            angX+=vel;
            break;
        case 2:
            if(vel > 0){ vel-=1;}
            angX+=vel;
            break;
        case 4:
            angX+=vel;
            break;
        case 3:
            angX+=vel;
            break;
        default:
            break;
    }
    glutTimerFunc(10,anima, 1);
    glutPostRedisplay();
}

void rotacoes(int key, int x, int y){
     //glutIdleFunc(anima);
     switch (key){
        case GLUT_KEY_LEFT :
           vel -= 1;
           opcao = 3;
           break ;
        case GLUT_KEY_RIGHT :
           vel+=1;
           opcao = 4;
           break ;
        default:
           break;
     }
}
void animacoes (int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
            vel=0.0;
            opcao=1;
          }
          break;
       case GLUT_RIGHT_BUTTON:
          if(estado == GLUT_DOWN){

             opcao=2;
          }
          break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Aula 7 _  Ex 01");
     glutDisplayFunc(display);
     glutSpecialFunc(rotacoes);
     glutTimerFunc(10,anima,1);
     glutMouseFunc(animacoes);

     //glutIdleFunc(anima);
     init();
     glutMainLoop();
}
