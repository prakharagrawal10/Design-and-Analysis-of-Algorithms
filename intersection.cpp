#include <iostream>
using namespace std;

// Point structure to represent points in 2D space
struct Point {
    int x, y;
};

// Function to find the direction of three points (p, q, r)
int direction(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}


// Function to check if point q lies on segment pr
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// Function to check if two line segments intersect
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int d1 = direction(p1, q1, p2);
    int d2 = direction(p1, q1, q2);
    int d3 = direction(p2, q2, p1);
    int d4 = direction(p2, q2, q1);

    // General case
    if (d1 != d2 && d3 != d4) return true;

    // Special cases (collinear segments)
    if (d1 == 0 && onSegment(p1, p2, q1)) return true;
    if (d2 == 0 && onSegment(p1, q2, q1)) return true;
    if (d3 == 0 && onSegment(p2, p1, q2)) return true;
    if (d4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}



// Main function
int main() {
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};

    if (doIntersect(p1, q1, p2, q2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}