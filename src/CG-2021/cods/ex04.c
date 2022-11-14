#include <windows.h>
#include <gl/glut.h>

int qtd=0;
double posx[50], posy[50];
double posxx[50], posyy[50];

double tam=400.0;
double centro=400.0/2;
int aux=0;

GLfloat cor[3] = {0,0,1.0};

void desenha(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(cor);

    int i;

    glBegin(GL_LINES);
        for(i=0; i<qtd; i++){
            glVertex2f(posx[i], posy[i]);
            glVertex2f(posxx[i], posyy[i]);
        }

    glEnd();

    glFlush();
}

void clique(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado==GLUT_DOWN){
                if(aux==0){
                    posx[qtd] = (x-centro) / centro;
                    posy[qtd] = (y-centro) / -centro;
                    aux=1;
                }else{
                    posxx[qtd] = (x-centro) / centro;
                    posyy[qtd] = (y-centro) / -centro;
                    aux=0;
                    qtd++;
                }
            }
            break;
        default:
            break;
    }
    if(aux==0){
        glutPostRedisplay();
    }

}

void teclado(unsigned char tecla, int x, int y){
    switch(tecla){
        case '1':
            printf("Mudando de cor...\n");
            cor[0] = 1.0;
            cor[1] = 0.0;
            cor[2] = 0.0;
            break;
        case '2':
            printf("Mudando de cor...\n");
            cor[0] = 1.0;
            cor[1] = 0.0;
            cor[2] = 1.0;
            break;
        case '3':
            printf("Mudando de cor...\n");
            cor[0] = 1.0;
            cor[1] = 1.0;
            cor[2] = 0.0;
            break;
        case '4':
            printf("Mudando de cor...\n");
            cor[0] = 1.0;
            cor[1] = 1.0;
            cor[2] = 1.0;
            break;
        case '5':
            printf("Mudando de cor...\n");
            cor[0] = 0.2;
            cor[1] = 1.0;
            cor[2] = 0.5;
            break;
        case '6':
            printf("Mudando de cor...\n");
            cor[0] = 0.0;
            cor[1] = 0.0;
            cor[2] = 1.0;
            break;
        case '7':
            printf("Mudando de cor...\n");
            cor[0] = 0.0;
            cor[1] = 1.0;
            cor[2] = 0.0;
            break;
        case '8':
            printf("Mudando de cor...\n");
            cor[0] = 0.0;
            cor[1] = 1.0;
            cor[2] = 1.0;
            break;
        case '9':
            printf("Mudando de cor...\n");
            cor[0] = 0.6;
            cor[1] = 0.6;
            cor[2] = 0.6;
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

    glutCreateWindow ("Exercício 04");

    glutDisplayFunc (desenha);
    glutMouseFunc(clique);
    glutKeyboardFunc(teclado);


    glutMainLoop ();

    return 0;
}
