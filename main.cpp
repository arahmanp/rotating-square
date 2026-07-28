#include <iostream>
#include <vector>

struct Point
{
    double x;
    double y;

    Point(double coord_x, double coord_y) : x(coord_x), y(coord_y) {};
};

// TODO: Try different representation of a square, such as an initial point, width, and length of the square.

struct Square
{
    std::vector<Point> points;

    Square(const std::vector<Point> &square_points) : points(square_points) {};
};

int main()
{
    Point A = {0, 4.5};

    std::cout << "coordinate of point A = (" << A.x << ", " << A.y << ")\n"; 

    return 0;
}