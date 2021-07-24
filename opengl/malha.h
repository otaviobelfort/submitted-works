#ifndef MALHA_H
#define MALHA_H

#include <GL/freeglut.h>
#include <stdlib.h>
namespace Malha {
    // Variáveis para controles de navegação
    GLfloat angle, fAspect;
    GLfloat rotX, rotY, rotX_ini, rotY_ini;
    GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
    int x_ini, y_ini, bot, window;

    // Define um vértice

    typedef struct {
        float x, y, z; // posição no espaço
    } VERT;

    // Define uma face

    typedef struct {
        int total; // total de vértices
        int ind[4]; // índices para o vetor de vértices
    } FACE;

    // Define um objeto 3D

    typedef struct {
        VERT *vertices; // aponta para os vértices
        FACE *faces; // aponta para as faces
        int total_faces; // total de faces no objeto
    } OBJ;

    // Definição dos vértices
    VERT vertices[] = {
        { -1, 0, -1}, // 0 canto inf esquerdo tras.
        { 1, 0, -1}, // 1 canfo inf direito  tras.
        { 1, 0, 1}, // 2 canto inf direito  diant.
        { -1, 0, 1}, // 3 canto inf esquerdo diant.
        { 0, 2, 0}, // 4 topo
    };

    // Definição das faces
    FACE faces[] = {
        { 4,
            { 0, 1, 2, 3}}, // base
        { 3,
            { 0, 1, 4, -1}}, // lado traseiro
        { 3,
            { 0, 3, 4, -1}}, // lado esquerdo
        { 3,
            { 1, 2, 4, -1}}, // lado direito
        { 3,
            { 3, 2, 4, -1}} // lado dianteiro
    };

    // Finalmente, define o objeto pirâmide
    OBJ piramide = {
        vertices, faces, 5
    };

    // Desenha um objeto em wireframe

    void DesenhaObjetoWireframe(OBJ *objeto) {
        OBJ *obj = objeto;
        // Percorre todas as faces
        for (int f = 0; f < obj->total_faces; ++f) {
            glBegin(GL_LINE_LOOP);
            // Percorre todos os vértices da face
            for (int v = 0; v < obj->faces[f].total; ++v)
                glVertex3f(obj->vertices[faces[f].ind[v]].x,
                    obj->vertices[faces[f].ind[v]].y,
                    obj->vertices[faces[f].ind[v]].z);
        }
        glEnd();
    }

    // Função callback de redesenho da janela de visualização

    void Desenha(void) {
        // Limpa a janela de visualização com a cor  
        // de fundo definida previamente
        glClear(GL_COLOR_BUFFER_BIT);
        // Altera a cor do desenho para preto
        glColor3f(0.0f, 0.0f, 0.0f);
        // Desenha o objeto definido anteriormente: uma pirâmide
        DesenhaObjetoWireframe(&piramide);
        // Executa os comandos OpenGL
        glFlush();
    }

    // Função usada para especificar a posição do observador virtual

    void PosicionaObservador(void) {
        // Especifica sistema de coordenadas do modelo
        glMatrixMode(GL_MODELVIEW);
        // Inicializa sistema de coordenadas do modelo
        glLoadIdentity();
        // Posiciona e orienta o observador
        glTranslatef(-obsX, -obsY, -obsZ);
        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);
    }

    // Função usada para especificar o volume de visualização

    void EspecificaParametrosVisualizacao(void) {
        // Especifica sistema de coordenadas de projeção
        glMatrixMode(GL_PROJECTION);
        // Inicializa sistema de coordenadas de projeção
        glLoadIdentity();
        // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
        gluPerspective(angle, fAspect, 0.1, 1200);
        PosicionaObservador();
    }

    // Função callback chamada quando o tamanho da janela é alterado 

    void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
        // Para previnir uma divisão por zero
        if (h == 0) h = 1;

        // Especifica as dimensões da viewport
        glViewport(0, 0, w, h);

        // Calcula a correção de aspecto
        fAspect = (GLfloat) w / (GLfloat) h;

        EspecificaParametrosVisualizacao();
    }

    // Função callback chamada para gerenciar eventos de teclas normais (ESC)

    void Teclado(unsigned char tecla, int x, int y) {
        switch (tecla) {
            case 27: printf("Finalizando SUPERFÍCIE DE BEZIER - MESH.");
                glutDestroyWindow(window);
                break;
        }
    }


    // Função callback para tratar eventos de teclas especiais

    void TeclasEspeciais(int tecla, int x, int y) {
        switch (tecla) {
            case GLUT_KEY_HOME: if (angle >= 10) angle -= 5;
                break;
            case GLUT_KEY_END: if (angle <= 150) angle += 5;
                break;
        }
        EspecificaParametrosVisualizacao();
        glutPostRedisplay();
    }

    // Função callback para eventos de botões do mouse

    void GerenciaMouse(int button, int state, int x, int y) {
        if (state == GLUT_DOWN) {
            // Salva os parâmetros atuais
            x_ini = x;
            y_ini = y;
            obsX_ini = obsX;
            obsY_ini = obsY;
            obsZ_ini = obsZ;
            rotX_ini = rotX;
            rotY_ini = rotY;
            bot = button;
        } else bot = -1;
    }

    // Função callback para eventos de movimento do mouse   

    void GerenciaMovim(int x, int y) {
        const double SENS_ROT = 5.0;
        const double SENS_OBS = 15.0;
        const double SENS_TRANSL = 30.0;
        // Botão esquerdo ?
        if (bot == GLUT_LEFT_BUTTON) {
            // Calcula diferenças
            int deltax = x_ini - x;
            int deltay = y_ini - y;
            // E modifica ângulos
            rotY = rotY_ini - deltax / SENS_ROT;
            rotX = rotX_ini - deltay / SENS_ROT;
        }// Botão direito ?
        else if (bot == GLUT_RIGHT_BUTTON) {
            // Calcula diferença
            int deltaz = y_ini - y;
            // E modifica distância do observador
            obsZ = obsZ_ini + deltaz / SENS_OBS;
        }// Botão do meio ?
        else if (bot == GLUT_MIDDLE_BUTTON) {
            // Calcula diferenças
            int deltax = x_ini - x;
            int deltay = y_ini - y;
            // E modifica posições
            obsX = obsX_ini + deltax / SENS_TRANSL;
            obsY = obsY_ini - deltay / SENS_TRANSL;
        }
        PosicionaObservador();
        glutPostRedisplay();
    }

    // Função responsável por inicializar parâmetros e variáveis

    void Inicializa(void) {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define do modo de operação da GLUT
        glutInitWindowPosition(5, 5); // Especifica a posição inicial da janela GLUT
        glutInitWindowSize(450, 450); // Especifica o tamanho inicial em pixels da janela GLUT
        window = glutCreateWindow("Desenho do wireframe de uma pirâmide"); // Cria a janela passando como argumento o título da mesma
        glutDisplayFunc(Desenha); // Registra a função callback de redesenho da janela de visualização
        glutReshapeFunc(AlteraTamanhoJanela); // Registra a função callback de redimensionamento da janela de visualização
        glutMouseFunc(GerenciaMouse); // Registra a função callback para eventos de botões do mouse
        glutMotionFunc(GerenciaMovim); // Registra a função callback para eventos de movimento do mouse	
        glutKeyboardFunc(Teclado); // Registra a função callback para tratamento das teclas normais 
        glutSpecialFunc(TeclasEspeciais); // Registra a função callback para tratamento das teclas especiais


        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da janela de visualização como branca
        angle = 60; // Inicializa a variável que especifica o ângulo da projeção perspectiva
        // Inicializa as variáveis usadas para alterar a posição do observador virtual
        rotX = 0;
        rotY = 0;
        obsX = obsY = 0;
        obsZ = 5;
    }
}

// Programa Principal 

void malha() {
    Malha::Inicializa(); // Chama a função responsável por fazer as inicializações 
    glutMainLoop(); // Inicia o processamento e aguarda interações do usuário
}

#endif /* MALHA_H */