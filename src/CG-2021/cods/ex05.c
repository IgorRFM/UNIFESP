#include <windows.h>
#include <gl/glut.h>

double posx=0.0, posy=0.0;
double posxx=0.0, posyy=0.0;
double posxxx=0.0, posyyy=0.0;
double tam=400.0;
double centro=400.0/2;
int aux=0, aux2=0;

GLfloat cor[3] = {0,0,1.0};

void desenha(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(cor);

    if(aux2==0){        //desenha linha
        glBegin(GL_LINES);
            glVertex2f(posx, posy);
            glVertex2f(posxx, posyy);
        glEnd();
    }else{              //desenha triangulo
        glBegin(GL_TRIANGLES);
            glVertex2f(posx, posy);
            glVertex2f(posxx, posyy);
            glVertex2f(posxxx, posyyy);
        glEnd();
    }


    glFlush();
}

void clique(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado==GLUT_DOWN){
                if(aux2==0){            //se "r"
                    if(aux==0){             //primeiro ponto da linha
                        posx = (x-centro) / centro;
                        posy = (y-centro) / -centro;
                        aux=1;
                    }else{                  //segundo ponto da linha
                        posxx = (x-centro) / centro;
                        posyy = (y-centro) / -centro;
                        aux=0;
                    }
                }else{                  //se "t"
                    if(aux==0){             //primeiro ponto do triangulo
                        posx = (x-centro) / centro;
                        posy = (y-centro) / -centro;
                        aux=1;
                    }else if(aux==1){       //segundo ponto do triangulo
                        posxx = (x-centro) / centro;
                        posyy = (y-centro) / -centro;
                        aux=2;
                    }else{                  //terceiro ponto do triangulo
                        posxxx = (x-centro) / centro;
                        posyyy = (y-centro) / -centro;
                        aux=0;
                    }
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

void zerar(){
    posx=0; posxx=0; posxxx=0;
    posy=0; posyy=0; posyyy=0;
    aux=0;
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
        case 'r':
            aux2=0;
            zerar();
            break;
        case 'R':
            aux2=0;
            zerar();
            break;
        case 't':
            aux2=1;
            zerar();
            break;
        case 'T':
            aux2=1;
            zerar();
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

    glutCreateWindow ("Exercício 05");

    glutDisplayFunc (desenha);
    glutMouseFunc(clique);
    glutKeyboardFunc(teclado);
    //problema: se troocar de cor antes de finalizar a figura (depois de dar o primeiro clique, por exemplo)
    //          a figura vai ser completada no local em que o mouse estava, quando o botão foi apertado


    glutMainLoop ();

    return 0;
}
