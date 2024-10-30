/**
 * @file
 * @brief Check whether two line segments intersect each other.
 */
#include <algorithm>
#include <iostream>

/**
 * Define a Point.
 */
struct Point {
    int x;  /// x-coordinate of the point
    int y;  /// y-coordinate of the point
};

/**
 * SegmentIntersection class to check intersection of two segments.
 */
class SegmentIntersection {
public:
    /**
     * Check if two line segments intersect.
     */
    bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
        int d1 = direction(p3, p4, p1);
        int d2 = direction(p3, p4, p2);
        int d3 = direction(p1, p2, p3);
        int d4 = direction(p1, p2, p4);

        // General case
        if ((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0) &&
            (d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)) {
            return true;
        }

        // Special cases
        if (d1 == 0 && on_segment(p3, p4, p1)) return true;
        if (d2 == 0 && on_segment(p3, p4, p2)) return true;
        if (d3 == 0 && on_segment(p1, p2, p3)) return true;
        if (d4 == 0 && on_segment(p1, p2, p4)) return true;

        return false;
    }

private:
    /**
     * Determine the orientation of the ordered triplet (p, q, r).
     * @return 0 if collinear, positive if clockwise, negative if counter-clockwise.
     */
    int direction(const Point& p, const Point& q, const Point& r) const {
        return (r.y - p.y) * (q.x - p.x) - (r.x - p.x) * (q.y - p.y);
    }

    /**
     * Check if point r lies on line segment 'pq'.
     */
    bool on_segment(const Point& p, const Point& q, const Point& r) const {
        return std::min(p.x, q.x) <= r.x && r.x <= std::max(p.x, q.x) &&
               std::min(p.y, q.y) <= r.y && r.y <= std::max(p.y, q.y);
    }
};

/**
 * Main function to test the algorithm.
 */
int main() {
    SegmentIntersection segment;
    Point p1, p2, p3, p4;

    std::cout << "Enter coordinates of first segment (x1 y1 x2 y2): ";
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    
    std::cout << "Enter coordinates of second segment (x3 y3 x4 y4): ";
    std::cin >> p3.x >> p3.y >> p4.x >> p4.y;

    std::cout << (segment.intersect(p1, p2, p3, p4) ? "Intersect" : "Do not intersect") << std::endl;

    return 0;
}
