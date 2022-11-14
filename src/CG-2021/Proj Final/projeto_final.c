#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <glut.h>

GLfloat light0_pos[] = {0.0f, 1.0f, 5.0f, 1.0f};
GLfloat white[] = {1.0f, 0.75f, 0.65f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat kd = 1.0f;
GLfloat ks = 0.5f;

double phi = 0.0;
double theta = 0.0;
int n = 150;

double rx = 0.9;
double ry = 0.5;
double rz = 0.5;

double s1 = 1.5;
double s2 = 2.5;

float angX = 0;
float angY = 0;
float angZ = 0;

GLfloat camX = 0.0f;
GLfloat camY = 0.0f;
GLfloat camZ = 0.0f;

void lightning(){
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
    glLightfv(GL_LIGHT0,GL_SPECULAR,black);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(camX, camY, camZ,   //posição da câmera
              0.0, 0.0, 0.0,   //para onde a câmera aponta
              0.0, 1.0, 0.0);  //vetor view-up

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    gluPerspective(90.0, 1.0, 2.0, 8.0); //define uma projeção perspectiva
    glViewport(0, 0, 500, 500);
    lightning();
    glPushMatrix();

}


/* Returns the sign of x */
double sgnf ( double x ) {
   if ( x < 0 )
       return -1.0;
   if ( x > 0 )
       return 1.0;
   return 0;
}

void cube(){
   GLfloat shininess;   //Coeficiente de reflexão da luz ambiente k_a
    GLfloat diffuse[4];  //Coeficiente de reflexão difusa k_d
    GLfloat specular[4]; //Coeficiente de reflexão especular k_s

    shininess = 4.0;
    diffuse[0] = kd;
    diffuse[1] = kd;
    diffuse[2] = kd;
    diffuse[3] = 1;
    specular[0] = ks;
    specular[1] = ks;
    specular[2] = ks;
    specular[3] = 1;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT,GL_SHININESS,shininess);

    glBegin(GL_POLYGON);
        glNormal3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);

        glNormal3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);

        glNormal3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);

        glNormal3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();

    /*diffuse[0] = 0.0;
    diffuse[1] = 0.65;
    diffuse[2] = 0.0;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;*/


    glBegin(GL_POLYGON);
        glNormal3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glNormal3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glNormal3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glNormal3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
    glEnd();

    /*diffuse[0] = 0.0;
    diffuse[1] = 0.0;
    diffuse[2] = 0.65;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;*/


    glBegin(GL_POLYGON);
        glNormal3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glNormal3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glNormal3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glNormal3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();

    /*diffuse[0] = 0.65;
    diffuse[1] = 0.65;
    diffuse[2] = 0.0;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;*/


    glBegin(GL_POLYGON);
        glNormal3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
        glNormal3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glNormal3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glNormal3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();

    /*diffuse[0] = 0.0;
    diffuse[1] = 0.65;
    diffuse[2] = 0.65;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;*/


    glBegin(GL_POLYGON);
        glNormal3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glNormal3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glNormal3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glNormal3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();

    /*diffuse[0] = 0.65;
    diffuse[1] = 0.65;
    diffuse[2] = 0.65;
    diffuse[3] = 1.0;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;*/


    glBegin(GL_POLYGON);
        glNormal3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glNormal3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glNormal3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glNormal3f(-0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
}


void sweep01(){
    GLfloat shininess;   //Coeficiente de reflexão da luz ambiente k_a
    GLfloat diffuse[4];  //Coeficiente de reflexão difusa k_d
    GLfloat specular[4]; //Coeficiente de reflexão especular k_s

    shininess = 4.0;
    diffuse[0] = kd;
    diffuse[1] = kd;
    diffuse[2] = kd;
    diffuse[3] = 1;
    specular[0] = ks;
    specular[1] = ks;
    specular[2] = ks;
    specular[3] = 1;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT,GL_SHININESS,shininess);

    double ty = 0.0;
    double ty1 = 0.05;

    int i;
    for(i=0;i<170;i++){
        glBegin(GL_QUADS);
            //glNormal3f(-0.5,-0.5+ty,-0.5);
            //glVertex3f(-0.5,-0.5+ty,-0.5);

            glNormal3f(-1,-0.5-ty,0);
            glVertex3f(-1,-0.5-ty,0);

            glNormal3f(0,-0.5-ty,0);
            glVertex3f(0,-0.5-ty,0);

            glNormal3f(0.5,-0.5-ty,1);
            glVertex3f(0.5,-0.5-ty,1);

            glNormal3f(0,-0.5-ty,2);
            glVertex3f(0,-0.5-ty,2);

            glNormal3f(-1,-0.5-ty,2);
            glVertex3f(-1,-0.5-ty,2);

            glNormal3f(-1.5,-0.5-ty,1);
            glVertex3f(-1.5,-0.5-ty,1);

        glEnd();
        ty+=0.01;
        ty1+=0.05;
    }
}


void sweep02(){
    GLfloat shininess;   //Coeficiente de reflexão da luz ambiente k_a
    GLfloat diffuse[4];  //Coeficiente de reflexão difusa k_d
    GLfloat specular[4]; //Coeficiente de reflexão especular k_s

    shininess = 0.6;
    diffuse[0] = kd-0.8f;
    diffuse[1] = kd-0.8f;
    diffuse[2] = kd-0.8f;
    diffuse[3] = 0.1;
    specular[0] = ks-0.5f;
    specular[1] = ks-0.5f;
    specular[2] = ks-0.5f;
    specular[3] = 0.1;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT,GL_SHININESS,shininess);

    double theta = 0.0;
    double step;
    int n = 6;

    step = 0;
    int i,j;
    for(j=0;j<455;j++){
        glBegin(GL_LINE_LOOP);
        for(i=0;i<n;i++){
            glNormal3f(0.5*cos(theta),0.5*sin(theta),step);
            glVertex3f(0.5*cos(theta),0.5*sin(theta),step);
            theta = theta+(2*M_PI)/n;
        }
        glEnd();
        step+=0.01;
    }
}

void superquadrics(){
    int val=0;
    int i,j;
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat shininess;   //Coeficiente de reflexão da luz ambiente k_a
    GLfloat diffuse[4];  //Coeficiente de reflexão difusa k_d
    GLfloat specular[4]; //Coeficiente de reflexão especular k_s

    shininess = 65.0;
    diffuse[0] = kd;
    diffuse[1] = kd;
    diffuse[2] = kd;
    diffuse[3] = 1.0f;
    specular[0] = 1.0;
    specular[1] = 1.0;
    specular[2] = 1.0;
    specular[3] = 1.0;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT,GL_SHININESS,shininess);

    for(i=0;i<n;i++){
        glBegin(GL_POINTS);
            for(j=0;j<n;j++){
                glVertex3f(val+rx*sgnf(cos(phi))*pow(fabs(cos(phi)),s1+val)*(sgnf(cos(theta))*pow(fabs(cos(theta)),s2+val)),val+ry*sgnf(cos(phi))*pow(fabs(cos(phi)),s1+val)*(sgnf(sin(theta))*pow(fabs(sin(theta)),s2+val)),val+rz*sgnf(sin(phi))*pow(fabs(sin(phi)),s1));
                glNormal3f(val+rx*sgnf(cos(phi))*pow(fabs(cos(phi)),s1+val)*(sgnf(cos(theta))*pow(fabs(cos(theta)),s2+val)),val+ry*sgnf(cos(phi))*pow(fabs(cos(phi)),s1+val)*(sgnf(sin(theta))*pow(fabs(sin(theta)),s2+val)),val+rz*sgnf(sin(phi))*pow(fabs(sin(phi)),s1));
                phi = phi + (2*M_PI)/n;
            }
        glEnd();
        phi = 0.0;
        theta = theta+(2*M_PI)/n;
    }
}

void dedos(){
 float grossura_dedo=0.35;
    /*dedos*/
        /*mindinho*/
        glPushMatrix();
            glTranslatef(0.75,1.5,-1.0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.75,2,-0.75);
            glRotatef(45,1,0,0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();

        /*Indicador*/
        glPushMatrix();
            glTranslatef(-0.75,1.5,-1.0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.75,2,-0.75);
            glRotatef(45,1,0,0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();

        /*Anelar*/
        glPushMatrix();
            glTranslatef(0.25,1.5,-1.0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.25,2,-0.75);
            glRotatef(45,1,0,0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();

        /*Central*/
        glPushMatrix();
            glTranslatef(-0.25,1.5,-1.0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.25,2,-0.75);
            glRotatef(45,1,0,0);
            glScalef(grossura_dedo,1,0.5);
            cube();
        glPopMatrix();
}

void displayFunc() {
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(camX+4.0,camY,camZ,
              camX,camY,camZ,
              0.0, 0.0, 1.0); //vetor view-up (V)  //vetor view-up
    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção

    glLoadIdentity(); //carrega a matrix de identidade
    gluPerspective(90.0, 1.0, 0.5, 45.0); //define uma projeção perspectiva


    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat ns;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a de modelo
    diffuse[0] = kd;
    diffuse[1] = 0;
    diffuse[2] = kd;
    diffuse[3] = 1.0f;
    specular[0] = ks;
    specular[1] = ks;
    specular[2] = ks;
    specular[3] = 1.0f;
    ns = 50.0f;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);


        glRotatef(angX,1.0,0.0,0.0);
        glRotatef(angY,0.0,1.0,0.0);
        glRotatef(angZ,0.0,0.0,1.0);

    /* Energia */
    glPushMatrix();
        glTranslatef(0.0,0.0,1.0);
        superquadrics();
    glPopMatrix();

    /* Palma da mão */
    glPushMatrix();
        glTranslatef(0.5,1.3,-2.0);
        glRotatef(-45,0,1,0);
        glScalef(-1.5,1,1);
        sweep01();
    glPopMatrix();

    /* dedos */
    glPushMatrix();
    glTranslatef(0,-0.5,-1);
    glRotatef(45,1,0,0);
    dedos();
    glPopMatrix();

    /*polegar*/
    glPushMatrix();
        glTranslatef(-1,-0.5,-0.75);
        glRotatef(45,1,0,0);
        glScalef(0.5,1,0.5);
        cube();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1,0,0);
        glRotatef(-15,0,0,1);
        glRotatef(45,1,0,0);
        glScalef(0.5,1,0.5);
        cube();
    glPopMatrix();

    /* Antebraço */
    glPushMatrix();
        glTranslatef(0,-3.5,-4.5);
        //glRotatef(-15,0,0,1);
        glRotatef(-45,1,0,0);
        glScalef(2,2,1);
        sweep02();
    glPopMatrix();

lightning();
        glFlush(); //força o desenho das primitivas
        //glutSwapBuffers();
        //glutSwapBuffers();
}


void keyboardSpecial(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
             angY+=15;
             break ;
        case GLUT_KEY_DOWN :
             angY-=15;
             break ;
        case GLUT_KEY_LEFT:
             angZ-=15;
             break ;
         case GLUT_KEY_RIGHT:
                angZ+=15;
            break ;
        default:
             break;
     }
     glutPostRedisplay() ;
}

void keyboard(unsigned char key, int x, int y){
     switch (key){
        case 'x' :
             angX+=15;
             break ;
        case 'y' :
             angY+=15;
             break ;
         case 'z' :
             angZ+=15;
             break ;
         case 's' :
            camX+=1;
            break ;
         case 'w' :
            camX-=1;
            break ;
         case 'd' :
            camY+=1;
            break ;
         case 'a' :
            camY-=1;
            break ;
        default:
             break;
     }
     glutPostRedisplay() ;
}

void anima()
{
	if(s1>0.0){
         s1-=0.3;
	}else{
        s1 = 1.5;
	}

	if(s2>0.0){
	     s2-=0.3;
	}else{
	    s2=2.5;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
	glutCreateWindow("Viewing 3D - Projecao Perspectiva");
	glutDisplayFunc(displayFunc);
	glutSpecialFunc(keyboardSpecial);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(anima);
    init();
	glutMainLoop();
	return 0;
}
