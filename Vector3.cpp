#include "Exceptions.h"

#include "Vector3.h"

Vector3::Vector3() :
    x(0), y(0), z(0) {}

Vector3::Vector3(double x, double y, double z) :
    x(x), y(y), z(z) {}

double Vector3::Module() const {
    #define POW2(x) ((x) * (x))

    return POW2(x) + POW2(y) + POW2(z);

    #undef POW
}

double &Vector3::operator[](int coord) {
    if(
        coord > 2 &&
        coord != 120 && coord != 121 && coord != 122 &&
        coord != 88 && coord != 89 && coord != 90
    ) {
        throw BadArgumentException;
    }

    switch(coord) {
        case 0: case 88: case 120: return x;
        case 1: case 89: case 121: return y;
    }

    return z;
}

#define VECTOR3_OPERATOR_VECTOR3(op) \
    Vector3 Vector3::operator op(const Vector3 &vector) { \
        return Vector3(x op vector.x, y op vector.y, z op vector.z); \
    }

#define VECTOR3_OPERATOR_CONSTANT(op) \
    Vector3 Vector3::operator op(double constant) { \
        return Vector3(x op constant, y op constant, z op constant); \
    }

VECTOR3_OPERATOR_VECTOR3(+)
VECTOR3_OPERATOR_VECTOR3(-)
VECTOR3_OPERATOR_CONSTANT(*)
VECTOR3_OPERATOR_CONSTANT(/)

#undef VECTOR3_OPERATOR
#undef VECTOR3_OPERATOR_CONSTANT

#define VECTOR3_OPERATOR_VASSIGN(op) \
    void Vector3::operator op##=(const Vector3 &vector) { \
        *this = Vector3(x op vector.x, y op vector.y, z op vector.z); \
    }

#define VECTOR3_OPERATOR_CASSIGN(op) \
    void Vector3::operator op##=(double constant) { \
        *this = Vector3(x op constant, y op constant, z op constant); \
    }

VECTOR3_OPERATOR_VASSIGN(+)
VECTOR3_OPERATOR_VASSIGN(-)
VECTOR3_OPERATOR_CASSIGN(*)
VECTOR3_OPERATOR_CASSIGN(/)

#undef VECTOR3_OPERATOR_VASSIGN
#undef VECTOR3_OPERATOR_CASSIGN
    
Vector3::~Vector3() {}
