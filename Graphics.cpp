#include <cstring>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Graphics.h"

std::vector<Graphics::Point> Graphics::points;

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

void Graphics::AddPoint(const Point &point) {
    points.push_back(point);
}

void Graphics::Clear() {
    points.clear();
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

void Graphics::DrawPoint(double x, double y, double z) {
    glColor3f(.0, .0, .0);
    
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}

void Graphics::DrawPoint(const Point &point) {
    DrawPoint(point.x, point.y, point.z);
}

void Graphics::Update() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawAxis();

    for(const Point &point : points) {
        DrawPoint(point);
    }

    glFlush();
    glutSwapBuffers();
}
