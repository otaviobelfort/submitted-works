
#ifndef SUPERFICIEBEZIERMESH_H
#define SUPERFICIEBEZIERMESH_H

#include <stdlib.h>
#include <GL/freeglut.h>

namespace supmesh {
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
            {0.3, 0.5, -0.7},
            {0.3, 0.5, 1.0},
        },
        {//curva 2
            {0.7, 0.5, 0.0},
            {0.7, 0.5, 0.3},
            {0.7, 0.5, -0.7},
            {0.7, 0.5, 1.0},
        },
        { //curva 3
            {1.0, 0.0, 0.0},
            {1.0, 0.0, 0.3},
            {1.0, 0.0, 0.7},
            {1.0, 0.0, 1.0},
        }
    };

    void initlights(void) {
        GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
        GLfloat mat_diffuse[] = {1.0, 0.8, 0.8, 1.0};
        GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
        GLfloat mat_shininess[] = {70.0};

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_POSITION, position);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glScalef(3.0,3.0,3.0);
        glRotatef(85.0, 1.0, 1.0, 1.0);
        glEvalMesh2(GL_FILL, 0, 20, 0, 20);
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
            case 27: printf("Finalizando SUPERFÍCIE DE BEZIER - MESH.");
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
        glEnable(GL_DEPTH_TEST);
        glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
        glEnable(GL_MAP2_VERTEX_3);
        glEnable(GL_AUTO_NORMAL);
        glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
        initlights();

        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);
    }
}

void superficieBezierMesh() {
    supmesh::init();
    glutMainLoop();
}

#endif /* SUPERFICIEBEZIERMESH_H */

