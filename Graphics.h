#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>

class Graphics {
    public:
        struct Point {
            double x, y, z;

            Point(double x, double y, double z) :
                x(x), y(y), z(z) {}
            
            Point() :
                x(.0), y(.0), z(.0) {}
        };

    private:
        Graphics() {}
    
    public:
        static std::vector<Point> points;

        static void Init(unsigned int width, unsigned int height);

        static void AddPoint(const Point &point);
        static void Clear();

        static void DrawAxis();
        static void DrawPoint(double x, double y, double z);
        static void DrawPoint(const Point &point);

        static void Update();
};

#endif
