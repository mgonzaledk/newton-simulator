#include "Graphics.h"

std::vector<Graphics::Point> Graphics::points;

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

void Graphics::DrawPoint(double x, double y, double z, double r, double g, double b) {
    glColor3f(r, g, b);
    
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}

void Graphics::DrawPoint(const Point &point) {
    DrawPoint(point.x, point.y, point.z, point.r, point.g, point.b);
}

void Graphics::Timer(int iter) {
    glutPostRedisplay();
    
    // 1000ms / 6ms = 166 fps
    glutTimerFunc(6, Graphics::Timer, iter + 1);
}
