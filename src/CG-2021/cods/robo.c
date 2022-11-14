#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float theta=0;
int aux=0;

void quadrado(){
    //glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
    glEnd();
    //glFlush();

}


void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glTranslatef(0.0,0.5,0.0);
        glRotatef(theta, 0.0,0.0,1.0);
        glTranslatef(0.0,-0.5,0.0);
        glScalef(0.2,0.6,1);
        glColor3f(0.5,0.5,0.5);
        quadrado();                     //braço traseiro
    glPopMatrix();

    glPushMatrix();
        //glTranslatef(0.0,-0.5,0.0);
        //glTranslatef(0.0,0.5,0.0);
        glRotatef(-theta, 0.0,0.0,1.0);
        glTranslatef(0.0,-0.5,0.0);
        glScalef(0.2,0.6,1);
        glColor3f(0.5,0.5,0.5);
        quadrado();                  //perna traseira
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6,0.6,0.6);
        glTranslatef(0.0,0.4,0.0);
        glScalef(0.3,0.3,1.0);

        quadrado(); //cabeça
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6,0.6,0.6);
        glScalef(0.4,0.6,1);
        quadrado();                 //torso
    glPopMatrix();

    glPushMatrix();
        //glTranslatef(0.0,-0.5,0.0);
        //glTranslatef(0.0,0.5,0.0);
        glRotatef(theta, 0.0,0.0,1.0);
        glTranslatef(0.0,-0.5,0.0);
        glScalef(0.2,0.6,1);
        glColor3f(0.7,0.7,0.7);
        quadrado();                  //perna frontal
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,0.5,0.0);
        glRotatef(-theta, 0.0,0.0,1.0);
        glTranslatef(0.0,-0.5,0.0);
        glScalef(0.2,0.6,1);
        glColor3f(0.7,0.7,0.7);
        quadrado();                  //braço frontal
    glPopMatrix();

    glFlush();
}
void key(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            if(aux==0){
                theta-=3.0;
            }else{
                theta+=3.0;
            }

            if(theta==30){
                aux=0;
            }else if(theta==-30){
                aux=1;
            }
            printf("%d %f", aux, theta);

            break;
        case GLUT_KEY_LEFT:
            if(aux==0){
                theta+=3.0;
            }else{
                theta-=3.0;
            }

            if(theta==30){
                aux=1;
            }else if(theta==-30){
                aux=0;
            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0,1.0,1.0);
}

int main(int argc, char **argv)
{
    printf("teste");
    #warning "C Preprocessor got here!"

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Exercícios 2 - robo (use as setas para andar)");
    init();
    glutDisplayFunc(desenha);
    glutSpecialFunc(key);
    glutMainLoop ();
    return 0;
}
