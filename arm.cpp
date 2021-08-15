//*********************************************************************
//  Minicurso: Computacao Grafica usando OpenGL
//  Autor: Prof. Laurindo de Sousa Britto Neto
//*********************************************************************

/* Inclui os headers do OpenGL, GLU, e GLUT */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

#define ESC 27

static int ombro = 0, cotovelo = 0, indicador = 0, medio = 0, polegar = 0, pan = 0;

void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);

int main(int argc, char** argv){
    /* inicia o GLUT */
    glutInit(&argc,argv);

    /* inicia o display usando RGB e double-buffering */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700,512);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Braco Robotico");

    /* Funcao com alguns comandos para a inicializacao do OpenGL; */
    init ();

    /* define as func�es de callback */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

  return 0;
}

/* Funcao com alguns comandos para a inicializacao do OpenGL; */
void init(void){
  glClearColor (1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
  glEnable(GL_DEPTH_TEST); // Habilita o algoritmo Z-Buffer
}

void reshape (int w, int h){
    /* muda para o modo GL_PROJECTION e reinicia a projec��o */
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    /* define a zona da janela onde se vai desenhar */
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    /* Define a forma do "viewing volume" para termos               *
     * uma projec��o de perspectiva (3D).                           *
     * gluPerpective(angulo,aspecto,ponto_proximo, ponto distante); */
    gluPerspective(60, (float)w/(float)h, 1.0, 20.0);
    gluLookAt(0.0,0.0,5.0, 	// posi��o da c�mera (olho) 
			  0.0,0.0,0.0, 	// centro da cena
			  0.0,1.0,0.0); // dire��o de cima 
    /* muda para o modo GL_MODELVIEW (n�o pretendemos alterar a projec��o
     * quando estivermos a desenhar a tela) */
    glMatrixMode (GL_MODELVIEW);
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
    case 'y': // sentido anti-horário
			pan = (pan + 5) % 360;
			glutPostRedisplay();
		break;
		case 'Y': // sentido horário
			pan = (pan - 5) % 360;
			glutPostRedisplay();
    break;
		case 'o': // sentido anti-horário
			ombro = (ombro + 5) % 360;
			glutPostRedisplay();
		break;
		case 'O': // sentido horário
			ombro = (ombro - 5) % 360;
			glutPostRedisplay();
		break;
		case 'c': // sentido anti-horário
			cotovelo = (cotovelo + 5) % 360;
			glutPostRedisplay();
		break;
		case 'C': // sentido horário
			cotovelo = (cotovelo - 5) % 360;
			glutPostRedisplay();
		break;
    case 'i': // sentido anti-horário
			indicador = (indicador + 5) % 360;
			glutPostRedisplay();
		break;
		case 'I': // sentido horário
			indicador = (indicador - 5) % 360;
			glutPostRedisplay();
		break;
    case 'm': // sentido anti-horário
			medio = (medio + 5) % 360;
			glutPostRedisplay();
		break;
		case 'M': // sentido horário
			medio = (medio - 5) % 360;
			glutPostRedisplay();
		break;
    case 'p': // sentido anti-horário
			polegar = (polegar + 5) % 360;
			glutPostRedisplay();
		break;
		case 'P': // sentido horário
			polegar = (polegar - 5) % 360;
			glutPostRedisplay();
		break;
		case ESC:
			exit(0);
		break;
		default:
		break;
	}
}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa o Buffer de Cores
    glLoadIdentity();

    glPushMatrix();
      glRotatef ((GLfloat) pan, 0.0, 1.0, 0.0);

      // braço
      glTranslatef (-1.0, 0.0, 0.0);
      glRotatef ((GLfloat) ombro, 0.0, 0.0, 1.0);
      glTranslatef(1, 0, 0);

      glPushMatrix();
        glColor3f(1, 0, 0);
        glScalef(2, 0.5, 0.5);
        glutSolidCube(1);
      glPopMatrix();
      
      // fim do braço

      // antebraço
      glTranslatef (1.0, 0.0, 0.0);
      glRotatef ((GLfloat) cotovelo, 0.0, 0.0, 1.0);
      glTranslatef (1.0, 0.0, 0.0);

      glPushMatrix();
        glColor3f(0, 1, 0);
        glScalef(2, 0.5, 0.5);
        glutSolidCube(1);
      glPopMatrix();

      // fim do antebraço

      glPushMatrix();
        glTranslatef (1.0, 0.2, -0.2);
        glRotatef ((GLfloat) indicador, 0.0, 0.0, 1.0);
        glTranslatef(0.15, 0, 0);
        glScalef(0.3, 0.1, 0.1);
        glColor3f(0, 0, 1);
        glutSolidCube(1);
      glPopMatrix();

      glPushMatrix();
        glTranslatef (1.0, 0.2, 0.2);
        glRotatef ((GLfloat) medio, 0.0, 0.0, 1.0);
        glTranslatef(0.15, 0.0, 0.0);
        glScalef(0.3, 0.1, 0.1);
        glColor3f(0, 1, 1);
        glutSolidCube(1);
      glPopMatrix();

      glPushMatrix();
        glTranslatef (1.0, -0.2, 0.0);
        glRotatef ((GLfloat) polegar, 0.0, 0.0, 1.0);
        glTranslatef(0.15, 0.0, 0.0);
        glScalef(0.3, 0.1, 0.1);
        glColor3f(1, 1, 0);
        glutSolidCube(1);
      glPopMatrix();

    glPopMatrix();

    /* Troca os buffers, mostrando o que acabou de ser desenhado */
    glutSwapBuffers();
}

