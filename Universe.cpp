#include <cstring>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Universe.h"

Universe::Universe() {
    Universe(600, 600);
}

Universe::Universe(unsigned int width, unsigned int height) {
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

    minAxisX = minAxisY = 0;
    maxAxisX = maxAxisY = 0;
    minAxisZ = -.1, maxAxisZ = .1;
}

void Universe::DrawAxis() {
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

void Universe::UpdateDraw() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawAxis();

    glFlush();
    glutSwapBuffers();
}

void Universe::DrawLoop() {
    while(1) {
        UpdateDraw();
    }
}
