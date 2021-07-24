
#ifndef SUPERFICIEBEZIER_H
#define SUPERFICIEBEZIER_H

#include <stdlib.h>
#include <GL/freeglut.h>

namespace supbez {
    int window;
    GLfloat ctrlpoints[4][4][3] = { 
        //4 curvas, definidas por 4 pts, pts 3D
        { //curva 0
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.3},
            {0.0, 0.0, 0.7},
            {0.0, 0.0, 1.0},
        },
        { //curva 1
            {0.3, 0.5, 0.0},
            {0.3, 0.5, 0.3},
            {0.3, 0.5, 0.7},
            {0.3, 0.5, 1.0},
        },
        {//curva 2
            {0.7, 0.5, 0.0},
            {0.7, 0.5, 0.3},
            {0.7, 0.5, 0.7},
            {0.7, 0.5, 1.0},
        },
        { //curva 3
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.3},
            {1.0, 0.0, 0.7},
            {1.0, 0.0, 1.0},
        }
    };
    

    void display(void) {
        int i, j;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glRotatef(85.0, 1.0, 1.0, 1.0);
        glScalef(3.0,3.0,3.0);
        for (j = 0; j <= 8; j++) {
            glBegin(GL_LINE_STRIP);
            for (i = 0; i <= 30; i++) // i e j estarão entre 0 (início) e 1 (fim) da curva
                glEvalCoord2f((GLfloat) i / 30.0, (GLfloat) j / 8.0);
            glEnd();
            glBegin(GL_LINE_STRIP);
            for (i = 0; i <= 30; i++)
                glEvalCoord2f((GLfloat) j / 8.0, (GLfloat) i / 30.0);
            glEnd();
        }
        glPopMatrix();
        glFlush();
    }

    void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if (w <= h)
            glOrtho(-5.0, 5.0, -5.0 * (GLfloat) h / (GLfloat) w,
                5.0 * (GLfloat) h / (GLfloat) w, -5.0, 5.0);
        else
            glOrtho(-5.0 * (GLfloat) w / (GLfloat) h,
                5.0 * (GLfloat) w / (GLfloat) h, -5.0, 5.0, -5.0, 5.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27: printf("Finalizando SUPERFÍCIE DE BEZIER - GRID.");
                glutDestroyWindow(window);
                break;
        }
    }    

    void init(void) {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("Superficie de Bezier");

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,0, 1, 12, 4, &ctrlpoints[0][0][0]);
        glEnable(GL_MAP2_VERTEX_3);
        glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_FLAT);
        
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);
    }
}

void superficieBezierGrid() {
    supbez::init();
    glutMainLoop();
}

#endif /* SUPERFICIEBEZIER_H */

