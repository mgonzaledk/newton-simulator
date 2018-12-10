#include "Graphics.h"

std::vector<Graphics::Point> Graphics::points;

void Graphics::Reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45., (GLdouble)width / (GLdouble)height, .5, 3000.);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height); 
}

void Graphics::Keyboard(unsigned char key, int x, int y) {
    (void)x, (void)y;

    if(key == 'w') {
        // ↑.
        glTranslatef(.0, -5., .0);
    } else if(key == 's') {
        // ↓.
        glTranslatef(.0, 5., .0);
    } else if(key == 'a') {
        // ←.
        glTranslatef(5., .0, .0);
    } else if(key == 'd') {
        // →.
        glTranslatef(-5., .0, .0);
    } else if(key == '+') {
        // Zoom +.
        glTranslatef(.0, .0, 5.);
    } else if(key == '-') {
        // Zoom -.
        glTranslatef(.0, .0, -5.);
    }
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

void Graphics::DrawPoint(double s, double x, double y, double z, double r, double g, double b) {
    glColor3f(r, g, b);

    glPushMatrix();
        glTranslatef(x, y, z);
        glutSolidSphere(s, 20, 40);
    glPopMatrix();
}

void Graphics::DrawPoint(const Point &point) {
    DrawPoint(point.s, point.x, point.y, point.z, point.r, point.g, point.b);
}

void Graphics::Timer(int iter) {
    glutPostRedisplay();
    
    // 1000ms / 6ms = 166 fps
    glutTimerFunc(6, Graphics::Timer, iter + 1);
}
