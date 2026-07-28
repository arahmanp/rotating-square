#include <iostream>
#include <vector>

struct Point
{
    double x;
    double y;

    Point(double coord_x, double coord_y) : x(coord_x), y(coord_y) {};
};

struct Square
{
    std::vector<Point> points;

    Square(const std::vector<Point> &square_points) : points(square_points) {};
};

int main()
{
    std::cout << "Hello, world!\n";

    return 0;
}