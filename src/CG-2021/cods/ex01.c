#include <windows.h>
#include <gl/glut.h>

double posx=0.0, posy=0.0;
double tam=400.0;
double centro=400.0/2;

void desenha(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2f(posx, posy);
    glEnd();

    glFlush();
}

void clique(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado==GLUT_DOWN)
                posx = (x-centro) / centro;
                posy = (y-centro) / -centro;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition (50 ,100);

    glutInitWindowSize (tam ,tam);

    glutCreateWindow ("Exercício 01");

    glutDisplayFunc (desenha);
    glutMouseFunc(clique);
    glutMainLoop ();

    return 0;
}
