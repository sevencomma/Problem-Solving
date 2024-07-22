#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    double x;
    double y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

bool compare(const Point& a, const Point& b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

void move(char ch, Point& point)
{
    if (ch == 'U') {
        if (point.y < 5.0)
            point.y++;
    }
    else if (ch == 'D') {
        if (point.y > -5.0)
            point.y--;
    }
    else if (ch == 'L') {
        if (point.x > -5.0)
            point.x--;
    }
    else if (ch == 'R') {
        if (point.x < 5.0)
            point.x++;
    }
}

int solution(string dirs) {
    Point point = { 0.0, 0.0};
    vector<Point> save_point;

    for (int i = 0; i < dirs.length(); i++) {
        double x = point.x;
        double y = point.y;
        move(dirs[i], point);
        if (x == point.x && y == point.y)
            continue;
        save_point.push_back({ (x + point.x) / 2, (y + point.y) / 2 });
    }

    sort(save_point.begin(), save_point.end(), compare);
    save_point.erase(unique(save_point.begin(), save_point.end()), save_point.end()); 
    int answer = save_point.size();

    return answer;
}