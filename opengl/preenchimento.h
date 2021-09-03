#ifndef PREENCHIMENTO_H
#define PREENCHIMENTO_H
#include <GL/freeglut.h>
#include <stdlib.h>

GLfloat r, g, b;
GLubyte tux[] = {
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xfe, 0x0,
    0x0, 0xc4, 0x23, 0x0,
    0x1, 0x83, 0x21, 0x80,
    0x1, 0x7, 0xe0, 0x80,
    0x1, 0x7, 0xf0, 0x80,
    0x1, 0x8f, 0xf9, 0x80,
    0x0, 0xff, 0xff, 0x0,
    0x0, 0x4f, 0xf1, 0x0,
    0x0, 0x6f, 0xf1, 0x0,
    0x0, 0x2f, 0xf3, 0x0,
    0x0, 0x27, 0xe2, 0x0,
    0x0, 0x30, 0x66, 0x0,
    0x0, 0x1b, 0x1c, 0x0,
    0x0, 0xb, 0x88, 0x0,
    0x0, 0xb, 0x98, 0x0,
    0x0, 0x8, 0x18, 0x0,
    0x0, 0xa, 0x90, 0x0,
    0x0, 0x8, 0x10, 0x0,
    0x0, 0xc, 0x30, 0x0,
    0x0, 0x6, 0x60, 0x0,
    0x0, 0x3, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0
};

namespace preen {
    int window;
    int cont = 25;
    int POS_X1 = 30;
    int POS_X2 = 113;
    int POS_Y1 = 143;
    int POS_Y2 = 185;

    void display(void) {

  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();



  glPopMatrix();
  glutSwapBuffers();
}
    void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -10.0);
}
    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                printf("Finalizando PREENCHIMENTO DE REGIÕES.");
                glutDestroyWindow(preen::window);
                break;
        }
    }

    void mouse(int button, int state, int x, int y) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN) {
                    r = (GLfloat) rand() / (RAND_MAX + 1.0);
                    g = (GLfloat) rand() / (RAND_MAX + 1.0);
                    b = (GLfloat) rand() / (RAND_MAX + 1.0);
                    glutPostRedisplay();
                }
                break;
        }
    }
  

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        preen::window = glutCreateWindow("Preenchendo regiões");

        glClearColor(1.0, 1.0, 1.0, 1.0);
        glOrtho(0, 256, 0, 256, -1, 1);
        r = 0; g = 1; b = 0;
        
        glutDisplayFunc(display);
        //glutReshapeFunc(reshape);

        glutKeyboardFunc(keyboard);
        glutMouseFunc(mouse);
    }
}



void preenchimento() {
    preen::init();
    glutMainLoop();
   
}



#endif /* PREENCHIMENTO_H */
