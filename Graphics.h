#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics {
    private:
        Graphics() {}
    
    public:
        static void Init(unsigned int width, unsigned int height);
        static void DrawAxis();
        static void Update();
};

#endif
