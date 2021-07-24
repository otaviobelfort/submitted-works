#ifndef TRANSPARENCIA_H
#define TRANSPARENCIA_H

#include <stdio.h>
#include <GL/freeglut.h>

namespace transp {
    int window;
    bool ordem = true;
    bool disable = false;
    int aberto;

    void desenhaQuadrado() {
        const int t = 7;
        glBegin(GL_QUADS);
        glVertex2f(-t, -t);
        glVertex2f(-t, t);
        glVertex2f(t, t);
        glVertex2f(t, -t);
        glEnd();
    }

    void display(void) {
        if (disable)
            glDisable(GL_BLEND);
        else
            glEnable(GL_BLEND);

        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        if (ordem)
            glColor4f(1, 0, 0, 0.5);
        else
            glColor4f(0, 0, 1, 0.5);

        glTranslatef(-5, -5, 0);
        desenhaQuadrado();

        if (ordem)
            glColor4f(0, 0, 1, 0.5);
        else
            glColor4f(1, 0, 0, 0.5);
        glTranslatef(10, 10, 0);
        desenhaQuadrado();
        if (aberto)
            glutSwapBuffers();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                aberto = 0;
                glutDestroyWindow(window);
                break;
            case 't': case 'T': ordem = !ordem;
                glutPostRedisplay();
                break;
            case 'd': case 'D': disable = !disable;
                glutPostRedisplay();
                break;
        }
        //glutPostRedisplay();
    }

    // Função callback chamada quando o tamanho da janela é alterado 

    void reshape(GLsizei w, GLsizei h) {
        // Evita a divisao por zero
        if (h == 0) h = 1;

        // Especifica as dimensões da Viewport
        glViewport(0, 0, w, h);

        // Inicializa o sistema de coordenadas
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // Estabelece a janela de seleção (esquerda, direita, inferior, 
        // superior) mantendo a proporção com a janela de visualização
        if (w <= h)
            gluOrtho2D(-20, 20, -20 * h / w, 20 * h / w);
        else
            gluOrtho2D(-20 * w / h, 20 * w / h, -20, 20);

        glMatrixMode(GL_MODELVIEW);
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(500, 500);
        window = glutCreateWindow("Transparencia");
        aberto = 1;
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white Background
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutIdleFunc(display);
    }
}

void transparencia() {
    transp::init();
    glutMainLoop();
}

#endif /* TRANSPARENCIA_H */

