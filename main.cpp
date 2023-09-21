/*
На бесконечной координатной сетке находится муравей.
Муравей может перемещаться на 1 клетку вверх (x,y+1), вниз (x,y-1), влево (x-1,y), вправо (x+1,y), по одной клетке за шаг.

Клетки, в которых сумма цифр в координате X плюс сумма цифр в координате Y больше, чем 25 недоступны муравью.
Например, клетка с координатами (59, 79) недоступна, т.к. 5+9+7+9=30, что больше 25.

Сколько клеток может посетить муравей если его начальная позиция (1000,1000), (включая начальную клетку).
Прислать ответ в виде числа клеток и решение на языке C++
 */

/*
В итоге у нас есть точка (x,y)
Точка может быть досутeпна или нет в зависимости от суммы цифр в обоих числовых индексах x и y.
В задаче указано, что сетка бесконечная. Доступен отрицательный диапазон.
В задаче указаны возможные направления: только вверх,вниз, влево, вправо. Те есть 4 направления = 4 смежных точки.
 */

// Результат https://github.com/Boring-Mind/Ant-assignment
// 148847
// без учета начально точки
// https://github.com/Boring-Mind/Ant-assignment/issues/1

#include <iostream>
#include <sstream>
#include <stack>
#include <set>

using namespace std;

using Point = std::pair<int64_t, int64_t>;
std::set<Point> processed_point;
std::stack<Point> points_to_process;

static bool point_unavailable(const Point &point)
{
    static const int Max_digit_summ = 25;
    std::stringstream sstream;
    sstream << point.first << point.second;
    auto summ = 0;
    while(const char ch = sstream.get())
    {
        if(ch < '0')
            break;

        summ += ch - '0';
    }

    return summ > Max_digit_summ;
}

void process_next_point(const Point& point)
{
    // точка уже была обработана, а соседние были добавлены на обработку.
    if(processed_point.find(point) != processed_point.end())
    {
        return;
    }

    // точка недоступна.
    if(point_unavailable(point))
    {
        return;
    }

    // добавить соседние 4 точки для обработки.
    points_to_process.push({point.first, point.second - 1});
    points_to_process.push({point.first, point.second + 1});
    points_to_process.push({point.first - 1, point.second});
    points_to_process.push({point.first + 1, point.second});

    // текущая точка обработана
    processed_point.insert(point);
}

int64_t calculate_available_points(const Point& point)
{
    process_next_point(point);
    while(!points_to_process.empty())
    {
        const auto point = points_to_process.top();
        points_to_process.pop();
        process_next_point(point);

    }

    return processed_point.size();
}

int main()
{
    std::cout << "Max point count: " << calculate_available_points({1000, 1000}) << std::endl;
    return 0;
}
