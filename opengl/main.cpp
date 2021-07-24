#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

#include "introducao.h"
#include "preenchimento.h"
#include "transformacoes.h"
#include "animacao_braco.h"
#include "animacao_pinball.h"
#include "mao.h"
#include "iluminacao.h"
#include "colisao.h"
#include "fontes.h"
#include "textura.h"
#include "curva.h"
#include "superficie_bezier_grid.h"
#include "superficie_bezier_mesh.h"
#include "malha.h"
#include "blending.h"
#include "transparencia.h"
#include "fog.h"

namespace principal {
#define sair 0
    int window;

    void desenhaTextoBmp(int x, int y, void *fonte, string texto) {
        glRasterPos2f(x, y);
        for(int i=0;i<texto.length();i++)
            glutBitmapCharacter(fonte, texto.at(i));
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        desenhaTextoBmp(10, 240, GLUT_BITMAP_TIMES_ROMAN_24, "1-Introducao.");
        desenhaTextoBmp(120, 240, GLUT_BITMAP_TIMES_ROMAN_24, "2-Preenchimento.");
        desenhaTextoBmp(10, 220, GLUT_BITMAP_TIMES_ROMAN_24, "3-Transformacoes geometricas.");
        desenhaTextoBmp(120, 220, GLUT_BITMAP_TIMES_ROMAN_24, "4-Animacao braco.");
        desenhaTextoBmp(10, 200, GLUT_BITMAP_TIMES_ROMAN_24, "5-Animacao pinball.");
        desenhaTextoBmp(120, 200, GLUT_BITMAP_TIMES_ROMAN_24, "6-Mao.");
        desenhaTextoBmp(10, 180, GLUT_BITMAP_TIMES_ROMAN_24, "7-Iluminacao.");
        desenhaTextoBmp(120, 180, GLUT_BITMAP_TIMES_ROMAN_24, "8-Colisao.");
        desenhaTextoBmp(10, 160, GLUT_BITMAP_TIMES_ROMAN_24, "9-Fonte.");
        desenhaTextoBmp(120, 160, GLUT_BITMAP_TIMES_ROMAN_24, "a-Textura.");
        desenhaTextoBmp(10, 140, GLUT_BITMAP_TIMES_ROMAN_24, "b-Curva.");
        desenhaTextoBmp(120, 140, GLUT_BITMAP_TIMES_ROMAN_24, "c-Superfície Bezier Grid.");
        desenhaTextoBmp(10, 120, GLUT_BITMAP_TIMES_ROMAN_24, "d-Superfície Bezier Mesh.");
        desenhaTextoBmp(120, 120, GLUT_BITMAP_TIMES_ROMAN_24, "e-Malha de poligonos-MUITO INTERESSANTE.");
        desenhaTextoBmp(10, 100, GLUT_BITMAP_TIMES_ROMAN_24, "f-Blending.");
        desenhaTextoBmp(120, 100, GLUT_BITMAP_TIMES_ROMAN_24, "g-Transparencia.");
        desenhaTextoBmp(10, 80, GLUT_BITMAP_TIMES_ROMAN_24, "h-Neblina.");
        desenhaTextoBmp(120, 80, GLUT_BITMAP_TIMES_ROMAN_24, "ESC-Finalizar.");
        glFlush();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case '1': introducao();
                break;
            case '2': preenchimento();
                break;
            case '3': transformacoes();
                break;
            case '4': animacao_braco();
                break;
            case '5': animacao_pinball();
                break;
            case '6': mao();
                break;
            case '7': iluminacao();
                break;
            case '8': colisao();
                break;
            case '9': fontes();
                break;
            case 'a':case 'A': textura();
                break;
            case 'b':case 'B': curva();
                break;
            case 'c':case 'C': superficieBezierGrid();
                break;
            case 'd':case 'D': superficieBezierMesh();
                break;
            case 'e':case 'E': malha();
                break;
            case 'f':case 'F': blending();
                break;
            case 'g':case 'G': transparencia();
                break;
            case 'h':case 'H': neblina();
                break;

            case 27:printf("Finalizando PROGRAMA.");
                exit(0);
                break;
        }
    }

    void init(void) {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1024, 768);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("Menu principal");
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glOrtho(0, 256, 0, 256, -1, 1);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    principal::init();
    glutMainLoop();
    return (0);
}