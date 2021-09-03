/*
 * depth.c
 * 
 * Demonstra os diferentes modos de teste de profundidade
 * em OpenGL.
 *          Ting (21/09/08)
 */
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glDepthRange(0.0, 1.0);  /* The default z mapping */
   glDepthFunc(GL_LESS);
}

/* The three rectangles are drawn.  In selection mode, 
 * each rectangle is given the same name.  Note that 
 * each rectangle is drawn with a different z value.
 */
void drawRects()
{
   glBegin(GL_QUADS);
   glColor3f(1.0, 0.0, 1.0);  /* magenta */
   glVertex3i(0, 2, -2);
   glVertex3i(0, 7, -2);
   glVertex3i(5, 7, -2);
   glVertex3i(5, 2, -2);
   glEnd();
   glBegin(GL_QUADS);
   glColor3f(1.0, 1.0, 0.0); /* amarelo */
   glVertex3i(2, 0, 0);
   glVertex3i(2, 6, 0);
   glVertex3i(6, 6, 0);
   glVertex3i(6, 0, 0);
   glEnd();
   glBegin(GL_QUADS);
   glColor3f(0.0, 1.0, 1.0);  /* ciano */
   glVertex3i(3, 2, -1);
   glVertex3i(3, 8, -1);
   glVertex3i(8, 8, -1);
   glVertex3i(8, 2, -1);
   glEnd();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   drawRects();
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 8.0, 0.0, 8.0, -0.5, 2.5);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
	  case '1':
		  glClearDepth(-3.0);
		  glDepthFunc(GL_NEVER);
		  break;
	  case '2':
		  glClearDepth(-3.0);
		  glDepthFunc(GL_ALWAYS);
		  break;
	  case '3':
		  glClearDepth(3.0);
		  glDepthFunc(GL_LESS);
		  break;
	  case '4':
		  glClearDepth(3.0);
		  glDepthFunc(GL_LEQUAL);
		  break;
	  case '5':
		  glClearDepth(-2.0);
		  glDepthFunc(GL_EQUAL);
		  break;
	  case '6':
		  glClearDepth(-2.0);
		  glDepthFunc(GL_GEQUAL);
		  break;
	  case '7':
		  glClearDepth(-10.0);
		  glDepthFunc(GL_GREATER);
		  break;
	  case '8':
		  glDepthFunc(GL_NOTEQUAL);
		  break;
      case 27:
         exit(0);
         break;
   }
	glutPostRedisplay();
}

/*  Main Loop
 */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (200, 200);
   glutInitWindowPosition (100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0; 
}