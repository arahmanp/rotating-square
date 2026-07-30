#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#define HEIGHT 25
#define WIDTH 100

#define RENDER_DELAY 100 // in milisecond per frame

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
void translate(Object &object, const Point &T, int duration /* in milisecond */);

int main()
{
    std::vector<Point> object_points = {
        {0, 0},
        {0, 10},
        {7, 10},
        {7, 0},
    };

    Object A = object_points;

    Point T1 = {10, 15};
    Point T2 = {-10, 15};
    Point T3 = {0, 50};
    Point T4 = {20, -20};

    translate(A, T1, 4000);
    translate(A, T2, 4000);
    translate(A, T3, 2000);
    translate(A, T4, 1000);

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

void translate(Object &object, const Point &T, int duration /* in milisecond */)
{
    int d_x = T.x;
    int d_y = T.y;

    int n_frame = duration / RENDER_DELAY;

    double v_x = (RENDER_DELAY * d_x) / (double)duration;
    double v_y = (RENDER_DELAY * d_y) / (double)duration;

    for(int frame = 1; frame <= n_frame; frame++)
    {
        clear_screen();

        render(object);

        for(auto &[x, y] : object.points)
        {
            x += v_x;
            y += v_y;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(RENDER_DELAY));
    }
}