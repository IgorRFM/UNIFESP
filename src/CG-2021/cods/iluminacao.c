#include <windows.h>
#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double centro=500.0/2;

GLfloat angle = 0.0f;
GLfloat step = 0.05f;
GLfloat mouseX = 0.0;
GLfloat mouseY = 0.0;
GLfloat light0_pos[]={2.0,2.0,2.0,1.0};
GLfloat white[]={1.0,1.0,1.0,1.0};
GLfloat black[]={0.0,0.0,0.0,0.0};
#define PI 3.14159265
float val = PI/360;


void lightning(){
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,black);
    glLightfv(GL_LIGHT0,GL_SPECULAR,black);

    GLfloat light1_pos[] = {mouseX, mouseY, 6.0f, 1.0f};         //posição do holofote
    glLightfv(GL_LIGHT1,GL_POSITION,light1_pos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1,GL_SPECULAR, white);

    GLfloat direction[] = {0.0f, 0.0f, -1.0f};
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,direction);       //vetor direção
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,15.0f);               //espalhamento angular
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,1.0f);              //atenuação angular

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void init(){
     glClearColor(0.0,0.0,0.0,0.0);             //cor do fundo
     glEnable(GL_DEPTH_TEST);                   //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);                //matriz model view
     glLoadIdentity();
         gluLookAt(0.0, 0.0, 1.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
     glMatrixMode(GL_PROJECTION);               //matriz model view
     glLoadIdentity();
     glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);  //proj ortogonal
     glViewport(0,0,500,500);                   //viewport

     glPushMatrix();
}

void displayFunc(){
    GLfloat diffuse[4];                                 //declarando a diffuse
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpar buffer

    glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(0.0, 0.0, 1.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);



    glPushMatrix();
        // x' = x*cos(theta) - y*sen(theta)
        // y' = x*sen(theta) + y*cos(theta)
        glTranslatef(-1.5*cos(angle)-0.0*sin(angle),-1.5*sin(angle)+0.0*cos(angle),0);
        diffuse[0] = 0.0;
        diffuse[1] = 0.75;
        diffuse[2] = 0.0;
        diffuse[3] = 0.0;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glutSolidSphere(0.25,40,40);  //desenha uma esfera
    glPopMatrix();

    glPushMatrix();
         // x' = x*cos(theta) - y*sen(theta)
        // y' = x*sen(theta) + y*cos(theta)
        glTranslatef(1.5*cos(angle)-0.0*sin(angle),1.5*sin(angle)+0.0*cos(angle),0);
        diffuse[0] = 0.75;
        diffuse[1] = 0.0;
        diffuse[2] = 0.0;
        diffuse[3] = 0.0;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glutSolidSphere(0.25,40,40);  //desenha uma esfera
    glPopMatrix();

    glPushMatrix();
        // x' = x*cos(theta) - y*sen(theta)
        // y' = x*sen(theta) + y*cos(theta)
        glTranslatef(0*cos(angle)+1.5*sin(angle),0*sin(angle)-1.5*cos(angle),0);
        diffuse[0] = 0.0;
        diffuse[1] = 0.0;
        diffuse[2] = 0.75;
        diffuse[3] = 0.0;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glutSolidSphere(0.25,40,40);  //desenha uma esfera
    glPopMatrix();

    glPushMatrix();
// x' = x*cos(theta) - y*sen(theta)
        // y' = x*sen(theta) + y*cos(theta)
        glTranslatef(0*cos(angle)-1.5*sin(angle),0*sin(angle)+1.5*cos(angle),0);
        diffuse[0] = 0.75;
        diffuse[1] = 0.0;
        diffuse[2] = 0.75;
        diffuse[3] = 0.0;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glutSolidSphere(0.25,40,40);  //desenha uma esfera
    glPopMatrix();
    lightning();

    glFlush();
    //glutSwapBuffers();

}

void mouseFunc(int b, int est, int x, int y){
    switch(b){
        case GLUT_LEFT_BUTTON:
            if(est==GLUT_DOWN){
                //mouseX=(((float)x/((float)500/2))-1)*2;
                //mouseY=(((float)y/((float)500/2))-1)*2;
                mouseX=(x-centro) / centro;
                mouseY = (y-centro) / -centro;

            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void timerFunc(int value)
{
	angle += step;
	glutPostRedisplay();
	glutTimerFunc(30,timerFunc, 1);
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Iluminacao");
    glutDisplayFunc(displayFunc);
    glutMouseFunc(mouseFunc);
	glutTimerFunc(60,timerFunc,1);
    init();
    glutMainLoop();
    return 0;
}
