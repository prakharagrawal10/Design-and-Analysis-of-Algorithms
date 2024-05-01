#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

Point p0; // Global variable to store the reference point

// Utility function to find the orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to get the element at the top of the stack without popping it
Point nextToTop(stack<Point>& s) {
    Point top = s.top();
    s.pop();
    Point nextTop = s.top();
    s.push(top);
    return nextTop;
}

// Comparator function for sorting points based on polar angle
bool compare(Point p1, Point p2) {
    // Find orientation of triplet (p, p1, p2)
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (p1.x*p1.x + p1.y*p1.y >= p2.x*p2.x + p2.y*p2.y);
    return (o == 2); // if counterclockwise, push it into the stack
}

// Function to find the point with the lowest y-coordinate
// Used as the reference point for sorting and polar angle calculation
Point findLowestPoint(vector<Point>& points) {
    Point lowest = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < lowest.y || (points[i].y == lowest.y && points[i].x < lowest.x)) {
            lowest = points[i];
        }
    }
    return lowest;
}

// Function to implement Graham Scan algorithm
vector<Point> grahamScan(vector<Point>& points) {
    // Find the point with the lowest y-coordinate
    p0 = findLowestPoint(points);

    // Sort points based on polar angle with respect to lowest point
    sort(points.begin(), points.end(), compare);

    // Initialize stack
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    
    // Process remaining points
    for (int i = 2; i < points.size(); i++) {
        while (s.size() > 1 && orientation(s.top(), points[i], nextToTop(s)) != 2) {
            s.pop();
        }
        s.push(points[i]);
    }

    // Copy the convex hull points from stack to a vector
    vector<Point> convexHull;
    while (!s.empty()) {
        convexHull.push_back(s.top());
        s.pop();
    }

    return convexHull;
}

// Driver function
int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> convexHull = grahamScan(points);

    cout << "Convex Hull:\n";
    for (auto point : convexHull) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
