#include "RGB.h"

RGB::RGB() : r(0), g(0), b(0) {}

RGB::RGB(int red, int green, int blue) : r(red), g(green), b(blue) {}

int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }

void RGB::setR(int red)   { r = red; }
void RGB::setG(int green) { g = green; }
void RGB::setB(int blue)  { b = blue; }

bool RGB::isEqual(const RGB &c1, const RGB &c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}
