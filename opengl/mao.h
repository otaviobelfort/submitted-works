#ifndef MAO_H
#define MAO_H
#include <GL/freeglut.h>

namespace Mao {
    int window;
    int ang = 0;


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
        glPushMatrix(); //palma da mao
        glRotatef(ang, 0.0, 1.0, 0.0);
        glScalef(1.0, 1.0, 0.2);
        glutWireCube(1.0);
        glPushMatrix(); //dedo-central
        glTranslatef(0.0, 0.75, 0.0);
        glScalef(0.4, 1.0, 1.0);
        glutWireCube(0.5);
        glPopMatrix();
        glPushMatrix(); //dedo-esquerda
        glTranslatef(-0.4, 0.75, 0.0);
        glScalef(0.4, 1.0, 1.0);
        glutWireCube(0.5);
        glPopMatrix();
        glPushMatrix(); //dedo-direita
        glTranslatef(0.4, 0.75, 0.0);
        glScalef(0.4, 1.0, 1.0);
        glutWireCube(0.5);
        glPopMatrix();
        glPushMatrix(); //polegar
        glRotatef(-90.0, 0.0, 0.0, 1.0);
        glTranslatef(0.4, 0.75, 0.0);
        glScalef(0.4, 1.0, 1.0);
        glutWireCube(0.5);
        glPopMatrix();
        glPopMatrix();
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
            case 'm':
                ang = (ang + 5) % 360;
                glutPostRedisplay();
                break;
            case 'M':
                ang = (ang - 5) % 360;
                glutPostRedisplay();
                break;
            case 27:
                printf("Finalizando MAO.");
                glutDestroyWindow(Mao::window);
                break;
        }
    }
    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        Mao::window = glutCreateWindow("Mão");
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);

    }
    
}

void mao() {
    Mao::init();
    glutMainLoop();
}
#endif /* MAO_H */

