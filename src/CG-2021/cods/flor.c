#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float theta = 0.0;


void miolo(){
    //glClear(GL_COLOR_BUFFER_BIT);

    int i;
    float angulo=0;
    glBegin(GL_POLYGON);
        for(i=0; i<=15; i++){
            angulo=2*3.1415*i /10.0;
            glVertex2f(0.35*cos(angulo), 0.35*sin(angulo));
        }
    glEnd();
    //glFlush();

}

void petalas(){
    //glClear(GL_COLOR_BUFFER_BIT);

    int i;
    float angulo=0;
    glBegin(GL_POLYGON);
        for(i=0; i<=15; i++){
            angulo=2*3.1415*i /10.0;
            glVertex2f(0.25*cos(angulo), 0.25*sin(angulo));
        }
    glEnd();
    //glFlush();

}
void petalasSombra(){
    //glClear(GL_COLOR_BUFFER_BIT);

    int i;
    float angulo=0;
    glBegin(GL_POLYGON);
        for(i=0; i<=15; i++){
            angulo=2*3.1415*i /10.0;
            glVertex2f(0.2*cos(angulo), 0.2*sin(angulo));
        }
    glEnd();
    //glFlush();

}

void gira(){
    //para não girar infinito, defini um limite de 5 giradinhas
    int i;

    theta-=0.005;
    glutPostRedisplay();
    glutTimerFunc(1000, gira,0);
    //utilizando a função glutTimerFunc(temp em ms, função a chamar, valor) por motivos de: a função sleep() não estava funcionando no projeto opengl, pelo codeblocks, por algum motivo que eu não consegui definir (mesmo com a importação das devidas bibliotecas)

}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int  i;
    for(i=0; i<360; i=i+36){
        glPushMatrix();

        glRotatef(theta+i,0.0,0.0,1.0);
        glTranslatef(0.3,0.0,0.0);
        glColor3f(1.0,1.0,0.0);
        petalas();
        glColor3f(0.6,0.6,0.0);
        petalasSombra();

        glPopMatrix();
    }

    glColor3f(0.5,0.35,0.35);
    miolo();
    gira();
    glFlush();
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
    glutCreateWindow("Exercícios 2 - flor");
    init();
    glutDisplayFunc(desenha);
    glutMainLoop ();
    return 0;
}
