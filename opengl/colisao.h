#ifndef COLISAO_H
#define COLISAO_H
#include <stdlib.h>
#include <GL/freeglut.h>

namespace coli {

#define SIM 1
#define NAO 0
#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define PRETO    0.0, 0.0, 0.0
#define MARRON   0.4, 0.3, 0.0

    int pegou = NAO, window, fim = 0;
    static int pneu = 0,
            eixoy = 0,
            eixox = 0,
            ang = 0;

    static GLfloat xc = -200.0, yc = 0.0, /*carro*/
            xq = 0.0, yq = 0.0; /*quadrado*/

    static GLdouble zoom = 220.0;
    void idle(void);

    void display(void) {
        /*  glClear(GL_COLOR_BUFFER_BIT);*/
        glPushMatrix();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gluLookAt(0, 0, zoom, 0, 0, 0, 0, 1, 0);

        glTranslatef(0.0, 0.0, 0.0);
        glRotatef((GLfloat) eixox, 1.0, 0.0, 0.0);
        glRotatef((GLfloat) eixoy, 0.0, 1.0, 0.0);
        /*
           glPushMatrix();
           glPopMatrix();
         */

        glPushMatrix();
        /*origem posicionada no fundo do carro */
        glTranslatef(xc - 10.0, 0.0, 0.0);
        glPushMatrix();
        glRotatef((GLfloat) ang, 0.0, 0.0, 1.0);
        glTranslatef(10.0, 0.0, 0.0);
        glColor3f(AZUL);
        glScalef(20.0, 5.0, 15.0);
        glutSolidCube(1.0);
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        /*origem posicionada no centro do fundo do carro */
        glTranslatef(xc, -2.5, 0.0);
        glColor3f(CINZA);
        glScalef(20.0, 1.0, 1.0);
        glutSolidCube(1.0);
        glPopMatrix();


        glPushMatrix();
        /*origem posicionada na "roda1" do carro */
        glColor3f(PRETO);
        glTranslatef(xc - 5.0, -5.0, 5.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glScalef(5.0, 5.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /*origem posicionada na "roda2" do carro */
        glTranslatef(xc - 5.0, -5.0, -5.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glScalef(5.0, 5.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /* origem posicionada na "roda3" do carro */
        glTranslatef(xc + 10.0, -5.0, 5.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glScalef(5.0, 5.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /*origem posicionada na "roda4" do carro */
        glTranslatef(xc + 10.0, -5.0, -5.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glScalef(5.0, 5.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();


        glPushMatrix();
        /*origem eixo das rodas traseiras */
        glTranslatef(xc - 5.0, -5.0, 0.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glColor3f(CINZA);
        glScalef(1.0, 1.0, 10.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /*origem eixo das rodas dianteiras */
        glTranslatef(xc + 10.0, -5.0, 0.0);
        glRotatef((GLfloat) pneu, 0.0, 0.0, 1.0);
        glColor3f(CINZA);
        glScalef(1.0, 1.0, 10.0);
        glutSolidCube(1.0);
        glPopMatrix();


        glPushMatrix();
        /*origem posicionada na cabine do carro */
        glTranslatef(xc + 15.0, 2.5, 0.0);
        glScalef(10.0, 10.0, 15.0);
        glColor3f(AZUL);
        glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /*origem posicionada na frente do carro */
        glTranslatef(xc + 20.5, 0.0, 0.0);
        glScalef(1.0, 15.0, 15.0);
        glColor3f(CINZA);
        glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
        /*origem posicionada no início do braço do carro */
        glTranslatef(xc + 26.0, yc - 7.0, 0.0);
        glScalef(10.0, 1.0, 15.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(xq, yq, 0.0);
        /*origem posicionada no início do quadrado */
        glColor3f(MARRON);
        glScalef(10.0, 10.0, 10.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPopMatrix();

        glutSwapBuffers();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 120.0, 280.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27: printf("Finalizando COLISÃO.");
                fim = 1;
                glutDestroyWindow(window);
                break;
        }
    }

    void idle(void) {
        pneu = (pneu - 5) % 360;
        if (xq - 35.0 - xc <= 0.0) {
            if ((yc > 2.0)&&(yc < 12.0)) {
                xc += 1.0;
                xq += 1.0;
            } else {
                xc += 1.0;
                if (xq - 25.0 - xc <= 0.0) {
                    xq += 1.0;
                    if (yc <= 2.0)pegou = SIM;
                }
            }

        } else xc += 1.0;

        if (pegou == SIM) {
            if (ang <= 45)ang += 1;
            if (yc < 15.0) {
                yc = (yc + 0.2);
                if (pegou == SIM)yq += 0.2;
            }
        }
        if (xc >= 200) {
            xc = -200.0, yc = 0.0, /*carro*/
                    xq = 0.0, yq = 0.0; /*quadrado*/
            ang = 0;
            eixoy = rand() % 360;
            eixox = rand() % 90;
            pegou = NAO;
        }

        if (!fim)glutPostRedisplay();
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1016, 714);
        glutInitWindowPosition(0, 0);
        window = glutCreateWindow("Colisões");
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glutIdleFunc(idle);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
    }
}

void colisao() {
    coli::init();
    glutMainLoop();
}





#endif /* COLISAO_H */

