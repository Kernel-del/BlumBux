#include <iostream>
#include "src/geometric_2D_constants/import_lib.hpp"

int main() {
    Segment a(0, 1, 2, 0);
    Segment b(0, 0, 1, 2);
    Point c(func::getIntersectionPoint(a, b));

    std::cout << "Позиция пересечений отрезков a и b на кооринатах (" << c.getX() << ", " << c.getY() << ")\n";
    return 0;
}