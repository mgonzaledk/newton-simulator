#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstring>
#include <functional>
#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>

class Graphics {
    public:
        struct Point {
            double s;
            double x, y, z;
            double r, g, b;

            Point(double s, double x, double y, double z, double r, double g, double b) :
                s(s), x(x), y(y), z(z), r(r), g(g), b(b) {}
            
            Point() :
                s(.1), x(.0), y(.0), z(.0), r(.0), g(.0), b(.0) {}
        };

    private:
        Graphics() {}

        static void Reshape(int x, int y);
        static void Keyboard(unsigned char key, int x, int y);
        static void RightMouseButton(int x, int y);
        static void Mouse(int button, int state, int x, int y);
    
    public:
        static std::vector<Point> points;

        template<typename T>
        static std::function<T> loop;

        template<typename T>
        static void Init(unsigned int width, unsigned int height,
            std::function<T> loop);

        static void AddPoint(const Point &point);
        static void Clear();

        static void DrawAxis();
        static void DrawPoint(double s, double x, double y, double z, double r, double g, double b);
        static void DrawPoint(const Point &point);

        template<typename T>
        static void Update();
        
        static void Timer(int);
};

template<typename T>
std::function<T> Graphics::loop;

template<typename T>
void Graphics::Init(unsigned int width, unsigned int height,
    std::function<T> loop
) {
    Graphics::loop<T> = loop;

    // Argumentos específicos de OPENGL.
    int argc = 0;
    
    glutInit(&argc, nullptr);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("newton-simulator");
    glutDisplayFunc(Graphics::Update<T>);
    glutReshapeFunc(Graphics::Reshape);
    glutKeyboardFunc(Graphics::Keyboard);
    glutMouseFunc(Graphics::Mouse);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(.0, .0, .0, .0);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -1000.0);

    glutTimerFunc(0, Graphics::Timer, 0);
    glutMainLoop();
}

template<typename T>
void Graphics::Update() {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    loop<T>();

    for(const Point &point : points) {
        DrawPoint(point);
    }
 
    glFlush();
    glutSwapBuffers();
}

#endif
