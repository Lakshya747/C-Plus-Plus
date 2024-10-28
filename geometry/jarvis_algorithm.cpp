#include <vector>
#include <cassert>
#include <iostream>

struct Point { 
    int x, y; 
};

class ConvexHull {
    std::vector<Point> points;
public:
    explicit ConvexHull(const std::vector<Point> &pts) : points(pts) {}

    std::vector<Point> getHull() const {
        if (points.size() < 3) return {};

        std::vector<Point> hull;
        int leftmost = 0;
        for (int i = 1; i < points.size(); i++)
            if (points[i].x < points[leftmost].x)
                leftmost = i;

        int p = leftmost, q;
        do {
            hull.push_back(points[p]);
            q = (p + 1) % points.size();
            for (int i = 0; i < points.size(); i++)
                if (orientation(points[p], points[i], points[q]) == 2)
                    q = i;
            p = q;
        } while (p != leftmost);
        return hull;
    }

    static int orientation(const Point &p, const Point &q, const Point &r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        return (val == 0) ? 0 : (val > 0) ? 1 : 2;
    }
};

void test() {
    std::vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    ConvexHull hull(points);
    auto actual = hull.getHull();
    std::vector<Point> expected = {{0, 3}, {0, 0}, {3, 0}, {3, 3}};
    assert(actual == expected);
    std::cout << "Test passed!\n";
}

int main() {
    test();
    return 0;
}
