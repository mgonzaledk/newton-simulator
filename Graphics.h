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
            double x, y, z;
            double r, g, b;

            Point(double x, double y, double z, double r, double g, double b) :
                x(x), y(y), z(z), r(r), g(g), b(b) {}
            
            Point() :
                x(.0), y(.0), z(.0), r(.0), g(.0), b(.0) {}
        };

    private:
        Graphics() {}
    
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
        static void DrawPoint(double x, double y, double z, double r, double g, double b);
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
    char *argv[1];
    int argc = 1;

    argv[0] = strdup("Graph");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);

    glutCreateWindow("newton-simulator");
    glutDisplayFunc(Graphics::Update<T>);

    glMatrixMode(GL_PROJECTION);
    glClearColor(1, 1, 1, .0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.);

    glutTimerFunc(0, Graphics::Timer, 0);
    glutMainLoop();
}

template<typename T>
void Graphics::Update() {
    glClear(GL_COLOR_BUFFER_BIT);

    loop<T>();
    DrawAxis();

    for(const Point &point : points) {
        DrawPoint(point);
    }

    glFlush();
    glutSwapBuffers();
}

#endif
