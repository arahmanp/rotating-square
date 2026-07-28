#include <iostream>
#include <vector>

struct Point
{
    double x;
    double y;

    Point(double coord_x, double coord_y) : x(coord_x), y(coord_y) {};
};

struct Object
{
    std::vector<Point> points;

    Object(const std::vector<Point> &object_points) : points(object_points) {};
};

int main()
{
    Point A = {0, 4.5};

    std::cout << "coordinate of point A = (" << A.x << ", " << A.y << ")\n"; 

    return 0;
}