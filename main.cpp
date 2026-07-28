#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#define HEIGHT 25
#define WIDTH 100

#define RENDER_SPEED 250 // in milisecond per frame

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
void clear_screen();

int main()
{
    std::vector<Point> object_points = {
        {0, 0},
        {0, 20},
        {14, 20},
        {14, 0},
    };

    Object A = object_points;

    Point T = {1, 2};

    for(int i = 1; i <= 15; i++)
    {
        clear_screen();

        render(A);

        for(auto &[x, y] : A.points)
        {
            x += T.x;
            y += T.y;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(RENDER_SPEED));
    }

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

        j = i;
    }

    return inside;
}

void clear_screen() {
    // \033[H  - Moves the cursor to the top-left corner (row 1, column 1)
    // \033[2J - Clears the entire visible screen
    std::cout << "\033[H\033[2J" << std::flush;
}
