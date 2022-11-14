#include <windows.h>
#include <GL/glut.h>

GLUquadricObj *obj;

int objId = 1;
float angX = 0;
float angY = 0;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7,7,-7,7,-7,7);
     glPushMatrix();
     obj = gluNewQuadric();
     gluQuadricDrawStyle(obj,GLU_LINE);
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
     glColor3f(0.6,0.6,0.6);

     glPopMatrix();
     glPushMatrix();

     glRotatef(angX,1,0,0);
     glRotatef(angY,0,1,0);

     //rosto
     glColor3f(0.6,0.6,0.6);
     glutWireSphere(3,50,50);

     //nariz
     glColor3f(0.9, 0.1, 0.1);
     glPushMatrix();
        glTranslatef(3,0.0,0.0);
        glutWireSphere(1,20,20);
     glPopMatrix();

     //olho dir
     glColor3f(1, 1, 1);
     glPushMatrix();
        glTranslatef(2.5,1.5,1.5);
        glutWireCube(1);
     glPopMatrix();

    //olho dir
     glColor3f(1, 1, 1);
     glPushMatrix();
        glTranslatef(2.5,1.5,-1.5);
        glutWireCube(1);
     glPopMatrix();

     //lábios
     glColor3f(1, 1, 1);
     glPushMatrix();
        glTranslatef(2.5,-1.5,0);
        glRotatef(90,0,1,0);
        glutWireTorus(0.25,1,20,20);
     glPopMatrix();


     glFlush();
}

void transformacoes(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
           angX+=20;
           break ;
        case GLUT_KEY_DOWN :
           angX-=20;
           break ;
        case GLUT_KEY_LEFT :
           angY-=20;
           break ;
        case GLUT_KEY_RIGHT :
           angY+=20;
           break ;
        default:
           break;
     }
     glutPostRedisplay() ;
}

int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Aula 7 _  Ex 01");
     glutDisplayFunc(display);
     glutSpecialFunc(transformacoes);
     init();
     glutMainLoop();
}
