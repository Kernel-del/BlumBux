#include <iostream>
#include "rules_two_dimensional.hpp"

int main() {
    Segment a(0, 0, 0, 1);
    std::cout << "Длина отрезка = " << a.getLen() << " ед.\n";
    std::cout << "Отрезок, относительно первой точки, смотрит по " << a.getAngleP1() << " радиану\n";

    return 0;
}