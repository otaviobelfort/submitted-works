#ifndef ANIMACAO_BRACO_H
#define ANIMACAO_BRACO_H
#include <GL/freeglut.h>

namespace anib {
    static int ombro = 0, cotovelo = 0;
    static int contOmbro = 0, contCotovelo = 0;
    int window,fim=0;



    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 0.0, 0.0); // cria eixo virtual estático
        glBegin(GL_LINES);
        glVertex2i(-250, 0);
        glVertex2i(250, 0); // eixo X
        glVertex2i(0, -250);
        glVertex2i(0, 250); // eixo Y
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0); // origem posicionada no ombro
        glRotatef((GLfloat) ombro, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(1.0, 0.0, 0.0); // origem posicionada no cotovelo 
        glRotatef((GLfloat) cotovelo, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
        glPopMatrix();
        glPopMatrix(); // origem volta para o sistema de coordenadas original 
        glutSwapBuffers();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -10.0);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 'o': contOmbro = -1;
                break;
            case 'O': contOmbro = 1;
                break;
            case 'c': contCotovelo = -1;
                break;
            case 'C': contCotovelo = 1;
                break;
            case 'p':
            case 'P':contOmbro = 0;
                contCotovelo = 0;
                break;
            case 27:printf("Finalizando ANIMAÇÃO BRAÇO.");
                fim=1;
                glutDestroyWindow(anib::window);
                break;
        }
    }

    void animacao(int passo) {
        ombro = (ombro + contOmbro) % 360;
        cotovelo = (cotovelo - contCotovelo) % 360;
        if(!fim)
            glutPostRedisplay();
        glutTimerFunc(10, animacao, 1);
    }
    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        anib::window = glutCreateWindow("Animação braço");
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutTimerFunc(10, animacao, 1);
    }    

}

void animacao_braco() {
    anib::init();
    glutMainLoop();
}

#endif /* ANIMACAO_BRACO_H */

