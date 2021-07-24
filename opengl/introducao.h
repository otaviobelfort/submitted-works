#ifndef INTRODUCAO_H
#define INTRODUCAO_H

#include <GL/freeglut.h>
void introducao();

namespace intro {
    int window;
    
    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(40, 200);
        glVertex2i(200, 10);
        glEnd();
        glFlush();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27: printf("Finalizando INTRODUÇÃO.");
                glutDestroyWindow(intro::window);
                break;
        }
    }

    void init(void) {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(256, 256);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("Desenhando uma linha");
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glOrtho(0, 256, 0, 256, -1, 1);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
    }
}

void introducao() {
    intro::init();
    glutMainLoop();

}




#endif /* INTRODUCAO_H */

