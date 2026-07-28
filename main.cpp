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
bool is_point_inside_object(const Point &point, const Object &object);

int main()
{
    std::vector<Point> object_points = {
        {0, 0},
        {0, 20},
        {20, 14}
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
            if(is_point_inside_object({(double)i, (double)j}, object))
            {
                std::cout << '#';
            }
            else
            {
                std::cout << '.';
            }
        }

        std::cout << '\n';
    }
}

bool is_point_inside_object(const Point &point, const Object &object)
{
    auto [a, b] = point;
    int n = object.points.size();
    bool inside = false;

    int j = n - 1;
    for(int i = 0; i < n; i++)
    {
        auto [xi, yi] = object.points[i];
        auto [xj, yj] = object.points[j];

        if(((yi > b) != (yj > b)) && (a < (xj - xi) * (b - yi) / (yj - yi + 1e-9) + xi))
        {
            inside = !inside;
        }
    }

    return inside;
}
