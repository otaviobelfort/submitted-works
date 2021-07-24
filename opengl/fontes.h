#ifndef FONTES_H
#define FONTES_H
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <string>
using namespace std;

namespace fonte {
    int window;

    void desenhaTextoBmp(int x, int y, void *fonte, string texto) {
        glRasterPos2f(x, y);
        for(int i=0;i<texto.length();i++)
            glutBitmapCharacter(fonte, texto.at(i));
    }

    void desenhaTextoStroke(GLfloat x, GLfloat y, void *fonte, string texto) {
        glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(0.005, 0.005, 0.005);
        for(int i=0;i<texto.length();i++)
            glutStrokeCharacter(fonte, texto.at(i));
        glPopMatrix();
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 0, 0);
        desenhaTextoBmp(40, 35, GLUT_BITMAP_TIMES_ROMAN_24, "Texto BMP com TIMES_ROMAN_24.");
        desenhaTextoBmp(30, 210, GLUT_BITMAP_9_BY_15, "Texto com GLUT_BITMAP_9_BY_15.");
        desenhaTextoBmp(70, 240, GLUT_BITMAP_HELVETICA_18, "Texto com GLUT_BITMAP_HELVETICA_18.");
        glColor3f(0, 0, 0);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluPerspective(40.0, 1.0, 0.1, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        gluLookAt(0.0, 0.0, 4.0, // eye is at (0,0,30) 
                0.0, 0.0, 0.0, // center is at (0,0,0) 
                0.0, 1.0, 0.); // up is in postivie Y direction
        glPushMatrix();
        glTranslatef(0, 0, -4);
        glRotatef(50, 0, 1, 0);

        desenhaTextoStroke(-2.5, 1.1, GLUT_STROKE_ROMAN, "  Texto escrito com");
        desenhaTextoStroke(-2.5, 0, GLUT_STROKE_ROMAN, " GLUT_STROKE_ROMAN.");
        glLineWidth(1);
        desenhaTextoStroke(-3.5, -1.1, GLUT_STROKE_MONO_ROMAN, "GLUT_STROKE_MONO_ROMAN.");
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
        glScalef(1, -1, 1);
        glTranslatef(0, -h, 0);
        glMatrixMode(GL_MODELVIEW);
    }
    
    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27: printf("Finalizando FONTES.");
                glutDestroyWindow(window);
                break;
        }
    }

    void init() {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 250);
        window=glutCreateWindow("Exemplo de fontes GLUT bitmap e stroke");
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glColor3f(0, 0, 0);
        glLineWidth(3.0);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);

    }
}

void fontes() {
    fonte::init();
    glutMainLoop();
}

#endif /* FONTES_H */

