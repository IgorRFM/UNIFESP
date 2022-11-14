#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float s=0,r=0,theta=0;


void carro01(){
    //glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,0.0);
        glVertex2f(-0.5,0.0);
    glEnd();
    //glFlush();

}

void roda(){
    //glClear(GL_COLOR_BUFFER_BIT);

    int i;
    float angulo=0;
    glBegin(GL_POLYGON);
        for(i=0; i<=7; i++){
            angulo=2*3.1415*i /7.0;
            glVertex2f(0.15*cos(angulo), 0.15*sin(angulo));
        }
    glEnd();
    //glFlush();

}
void carro02(){
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(-0.25,0.8);
        glVertex2f(0.25,0.8);
        glVertex2f(0.25,0.0);
        glVertex2f(-0.25,0.0);
    glEnd();
    //glFlush();

}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.4+s,0.4+s,1);
    glTranslatef(0.0+r,0.0,0.0);

    carro01();
    carro02();
    glPushMatrix();
        glTranslatef(-0.25,0.0,0.0);
        glRotatef(theta,0.0,0.0,1.0);
        roda();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.25,0.0,0.0);
        glRotatef(theta,0.0,0.0,1.0);
        roda();
    glPopMatrix();

    glFlush();
}
void key(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            theta-=3.0;
            r+=0.2;
            break;
        case GLUT_KEY_LEFT:
            theta+=3.0;
            r-=0.2;
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
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutInit(&argc, argv);
    glutCreateWindow("Exercícios 2 - carro");
    init();
    glutDisplayFunc(desenha);
    glutSpecialFunc(key);
    glutMainLoop ();
    return 0;
}
