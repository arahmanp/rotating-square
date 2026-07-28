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
    std::vector<Point> object_points = {
        {0, 0},
        {0, 5}
    };

    Object A = object_points;

    for(auto [x, y] : A.points) {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}