#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
    private:
        double x, y, z;
    
    public:
        Vector3();
        Vector3(double x, double y, double z);

        double Module() const;

        double &operator[](int coord);
        Vector3 operator+(const Vector3 &vector);
        Vector3 operator-(const Vector3 &vector);
        Vector3 operator*(double constant);
        Vector3 operator/(double constant);
        void operator+=(const Vector3 &vector);
        void operator-=(const Vector3 &vector);
        void operator*=(double constant);
        void operator/=(double constant);

        virtual ~Vector3();
};

#endif
