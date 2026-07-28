#include <iostream>
#include <vector>

#define HEIGHT 25
#define WIDTH 100

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

void render(const Object &object);

int main()
{
    std::vector<Point> object_points = {
        {0, 0},
        {0, 5}
    };

    Object A = object_points;

    render(A);

    return 0;
}

void render(const Object &object)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            std::cout << '.';
        }

        std::cout << '\n';
    }
}
