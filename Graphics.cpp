#include <cstring>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Graphics.h"

void Graphics::Init(unsigned int width, unsigned int height) {
    // Argumentos específicos de OPENGL.
    char *argv[1];
    int argc = 1;

    argv[0] = strdup("Graph");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);

    glutCreateWindow("newton-simulator");

    glMatrixMode(GL_PROJECTION);
    glClearColor(1, 1, 1, .0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.);
}

void Graphics::DrawAxis() {
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(1);

    glBegin(GL_LINES);
	
    // Eje X.
    glVertex2f(-1., .0);
    glVertex2f(1., .0);

    // Eje Y.
    glVertex2f(.0, -1.);
    glVertex2f(.0, 1.);

    // Linea eje X negativo.
    glVertex2f(-0.95, .05);
    glVertex2f(-0.95, -.05);

    // Linea eje X positivo.
    glVertex2f(.95, .05);
    glVertex2f(.95, -.05);

    // Linea eje Y negativo.
    glVertex2f(.05, -.95);
    glVertex2f(-.05, -.95);

    // Linea eje Y positivo.
    glVertex2f(.05, .95);
    glVertex2f(-.05, .95);
	
    glEnd();
}

void Graphics::Update() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawAxis();

    glFlush();
    glutSwapBuffers();
}
