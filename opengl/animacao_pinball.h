#ifndef ANIMACAO_PINBALL_H
#define ANIMACAO_PINBALL_H

#include <GL/freeglut.h>
#include <stdlib.h>


namespace anip {
    GLint movebola = 0;
    GLint direcao = 1;
    int window, fim = 0;

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        // glPolygonMode(GL_BACK, GL_LINE);
        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(15.0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(2, 2);
        glVertex2i(599, 2);
        glVertex2i(599, 399);
        glVertex2i(2, 399);
        glEnd();

        glBegin(GL_LINES);
        glVertex2i(100, 190);
        glVertex2i(100, 240);
        glVertex2i(500, 190);
        glVertex2i(500, 240);
        glEnd();

        glPointSize(15.0);
        glBegin(GL_POINTS);
        glVertex2i(movebola + 200, 210);
        glEnd();

        //  glFlush();
        glutSwapBuffers();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27: printf("Finalizando ANIMAÇÃO PINBALL.");
                fim = 1;
                glutDestroyWindow(window);
                break;
        }
    }

    void bola(int passo) {
        if (direcao == 1) {
            movebola += passo;
            if (movebola == 290)
                direcao = 0;
        } else {
            movebola -= passo;
            if (movebola == -90)
                direcao = 1;
        }
        if (!fim)glutPostRedisplay();
        glutTimerFunc(10, bola, 1);
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(600, 400);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("PINBALL");
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glOrtho(0, 600, 0, 400, -1, 1);
        glutDisplayFunc(anip::display);
        glutTimerFunc(10, anip::bola, 1);
        glutKeyboardFunc(anip::keyboard);
    }

}

void animacao_pinball() {
    anip::init();
    glutMainLoop();
}


#endif /* ANIMACAO_PINBALL_H */

