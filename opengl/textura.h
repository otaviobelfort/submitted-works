#ifndef TEXTURA_H
#define TEXTURA_H
#include <GL/freeglut.h>
#include <stdio.h>
#include <string>

//Para maiores informações, ver documentação
//http://docs.gl/gl3/
namespace tex {
    float angulo = 0.0f, rotX = 1.0, rotY = 0.0f, rotZ = 0.0f, velocidade = -1.00;
    int w, h, window, fim=0;

    GLuint texid1;
//Para maiores informações sobre a estrutura de um arquivo bmp, ver "http://easygrid.ic.uff.br/~aconci/curso/bmp.pdf"
    char *carrega_bmp(string name) {
        FILE *f = fopen(name.c_str(), "rb");
        if (f == NULL) {
            printf("Erro ao carregar o arquivo %s !", name.c_str()); 
            exit(1);
        }
        int of;
        fseek(f, 10, SEEK_SET);
        fread(&of, sizeof (int), 1, f);
        fseek(f, 4, SEEK_CUR);
        fread(&w, sizeof (int), 1, f);
        fread(&h, sizeof (int), 1, f);

        fseek(f, of, SEEK_SET);

        int by = ((w * 3 + 3) / 4) * 4 - (w * 3 % 4);
        char *tmp_m = (char *) malloc(sizeof (char) * by * h);
        char *m = (char *) malloc(sizeof (char) * w * h * 3);
        fread(tmp_m, sizeof (char) * by * h, 1, f);
        int x, y, i;
        for (y = 0; y < h; y++) {
            for (x = 0; x < w; x++) {
                for (i = 0; i < 3; i++) {
                    m[3 * (w * y + x) + i] = tmp_m[3 * (w * y + x) + (2 - i)];
                }
            }
        }
        free(tmp_m);
        return m;
    }

    GLuint carregaTextura(string path) {
        char *wa = carrega_bmp(path);
        GLuint texid;
        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
        free(wa);
        return texid;
    }

    void colocaImagem() {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texid1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    void display(void) {
        colocaImagem();
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        gluLookAt(0.0f, 0.0f, 10.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f);

        glRotatef(angulo, rotX, rotY, rotZ);
        glBegin(GL_QUADS);
        glTexCoord3f(-1, 1, 0);
        glVertex3f(-1, 1, 0);
        glTexCoord3f(1, 1, 0);
        glVertex3f(1, 1, 0);
        glTexCoord3f(1, -1, 0);
        glVertex3f(1, -1, 0);
        glTexCoord3f(-1, -1, 0);
        glVertex3f(-1, -1, 0);
        glEnd();
        angulo += velocidade;
        if(!fim)
            glutSwapBuffers();
    }

    void reshape(int w, int h) {
        // Função é chamada caso a tela tenha sido alterada
        if (h == 0)
            h = 1;
        float proporsao = w * 1.0 / h;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, w, h);
        gluPerspective(45.0f, proporsao, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                fim=1;
                printf("Finalizando TEXTURA.");
                glutDestroyWindow(tex::window);
                break;
            case ' ':
            {
                if (rotX == 1.0f) {
                    rotX = 0.0f;
                    rotY = 1.0f;
                    rotZ = 0.0f;
                } else if (rotY == 1.0f) {
                    rotX = 0.0f;
                    rotY = 0.0f;
                    rotZ = 1.0f;
                } else if (rotZ == 1.0f) {
                    rotX = 1.0f;
                    rotY = 0.0f;
                    rotZ = 0.0f;
                }
            }
        }
    }

    void special(int key, int x, int y) {
        if (key == GLUT_KEY_UP) {
            velocidade += 0.05;
            printf("Velocidade Rotação : %.2f\n", velocidade);
        }
        if (key == GLUT_KEY_DOWN) {
            velocidade -= 0.05;
            printf("Velocidade Rotação : %.2f\n", velocidade);
        }
        if (key == GLUT_KEY_LEFT)
            if (velocidade < 0)velocidade *= -1;
        if (key == GLUT_KEY_RIGHT)
            if (velocidade > 0)velocidade *= -1;
    }

    void mouse(int button, int state, int x, int y) {

        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN) {
                printf("Clicou com o botão esquerdo na Posição  X : %i Y : %i \n", x, y);
            } else if (state == GLUT_UP) {
                printf("Soltou Botão esquerdo\n");
            }
        } else if (button == GLUT_RIGHT_BUTTON) {
            if (state == GLUT_DOWN) {
                printf("Clicou com o botão direito na Posição  X : %i Y : %i \n", x, y);
            } else if (state == GLUT_UP) {
                printf("Soltou Botão direito\n");
            }
        } else if (button == GLUT_MIDDLE_BUTTON) {
            if (state == GLUT_DOWN) {
                printf("Clicou com o botão do meio na Posição  X : %i Y : %i \n", x, y);
            } else if (state == GLUT_UP) {
                printf("Soltou Botão do meio\n");
            }
        }
    }

    void MovimentoMouse(int x, int y) {
        printf("Mouse na Posição  X : %i Y : %i \n", x, y);
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(320, 240);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("Textura.");
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        texid1 = carregaTextura("Textura.bmp");
        glutDisplayFunc(display);
        glutIdleFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutPassiveMotionFunc(MovimentoMouse);
        glutKeyboardFunc(keyboard);
        glutSpecialFunc(special);

    }
}

void textura() {
    tex::init();
    glutMainLoop();
}


#endif /* TEXTURA_H */

