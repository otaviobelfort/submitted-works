#ifndef BLENDING_H
#define BLENDING_H

#include <stdio.h>
#include <GL/freeglut.h>

namespace blend {
    float xrot;
    float yrot;
    float zrot;
    float ratio;
    float AlfaVidro = 0.5f;
    int window, aberto;

    void reshape(int w, int h) {
        if (h == 0) h = 1;
        ratio = 1.0f * w / h;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, w, h);
        gluPerspective(50, ratio, 1, 200); // Define o ângulo de visão
        glMatrixMode(GL_MODELVIEW); // Define a posição do observador
        glLoadIdentity();
        gluLookAt(0, 0, 5, 0, 0, 0, 0.0f, 1.0f, 0.0f);
    }

    void DrawCube(GLfloat alfa) {
        glBegin(GL_QUADS);
        // frente
        glColor4f(0.7f, 0.7f, 0, alfa);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        // tras
        glColor4f(0, 0, 0.7f, alfa);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        // cima
        glColor4f(0.7f, 0, 0.7f, alfa);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        // baixo
        glColor4f(0.7f, 0.7f, 0.7f, alfa);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        // direita
        glColor4f(0, 0.5f, 0, alfa);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        // esquerda
        glColor4f(0.7f, 0, 0, alfa);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();
    }

    void DesenhaVidro(GLfloat alfa) {
        static float x = -2;
        static float delta = -0.002f;
        glPushMatrix();
        glTranslatef(x, 0, 0);
        if ((x > 2) || (x < -2))
            delta *= -1;
        x += delta;
        glColor4f(1, 1, 1, alfa);
        glBegin(GL_QUADS);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glEnd();
        glPopMatrix();

    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_BLEND); // Desabilita o BLEND para o primeiro objeto
        glPushMatrix();
        glTranslatef(0, 0, -1);
        glRotatef(xrot, 1.0, 0.0, 0.0);
        glRotatef(yrot, 0.0, 1.0, 0.0);
        glRotatef(zrot, 0.0, 0.0, 1.0);
        glEnable(GL_CULL_FACE); // habilita remoção de faces traseiras
        glCullFace(GL_BACK);
        DrawCube(0.5);
        glPopMatrix();

        // Habilita o BLEND para ao segundo objeto
        glEnable(GL_BLEND);
        // NovaCorNaTela = CorDoObjeto * AlfaDoObjeto + CorAntigaNaTele * (1-AlfaDoObjeto)
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR
                );
        glPushMatrix();
        glTranslatef(0, 0, 0);
        DesenhaVidro(AlfaVidro);
        glPopMatrix();
        xrot += 0.03f;
        yrot += 0.02f;
        zrot += 0.04f;
        if (aberto)
            glutSwapBuffers();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                aberto = 0;
                glutDestroyWindow(window);
                break;
        }
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(500, 500);
        window = glutCreateWindow("Blending");
        aberto = 1;

        //glShadeModel(GL_SMOOTH); // Enable Smooth Shading
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black Background
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_DEPTH_TEST); // habilita ZBuffer

        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutKeyboardFunc(keyboard);
        glutIdleFunc(display);
    }
}

void blending() {
    blend::init();
    glutMainLoop();
}

#endif /* BLENDING_H */

