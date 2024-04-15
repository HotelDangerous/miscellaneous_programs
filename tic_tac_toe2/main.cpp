// Compute the sum of two given integers. If the two values are the same, return triple their sum

#include <iostream>
#include "Circle.h"

int main() {
    auto my_circle = Circle(5);
    auto my_rect = Rectangle(11, 2);

    std::cout << "The circle has diameter " << my_circle.diameter() << " and circumference " <<
                my_circle.circumference() << "!" << std::endl;

    std::cout << "The rectangle has area " << my_rect.area() << " and perimeter " << my_rect.perimeter() <<
                "!" << std::endl;
    return 0;
}
