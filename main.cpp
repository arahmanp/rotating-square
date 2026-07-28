#include <iostream>

struct Point
{
    double x;
    double y;

    Point(double coord_x, double coord_y) : x(coord_x), y(coord_y) {};
};

int main()
{
    std::cout << "Hello, world!\n";

    return 0;
}