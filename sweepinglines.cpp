#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point start, end;
};

// Function to check if two line segments intersect
bool doIntersect(const Segment& s1, const Segment& s2) {
    auto orientation = [](const Point& p, const Point& q, const Point& r) -> int {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0; // Collinear
        return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
    };

    int o1 = orientation(s1.start, s1.end, s2.start);
    int o2 = orientation(s1.start, s1.end, s2.end);
    int o3 = orientation(s2.start, s2.end, s1.start);
    int o4 = orientation(s2.start, s2.end, s1.end);

    // General case: segments intersect if orientations are different
    if (o1 != o2 && o3 != o4)
        return true;

    // Special cases: segments are collinear and overlap
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
        // Check if segments overlap
        if (max(s1.start.x, s1.end.x) < min(s2.start.x, s2.end.x) ||
            max(s2.start.x, s2.end.x) < min(s1.start.x, s1.end.x) ||
            max(s1.start.y, s1.end.y) < min(s2.start.y, s2.end.y) ||
            max(s2.start.y, s2.end.y) < min(s1.start.y, s1.end.y))
            return false;
        return true;
    }

    return false;
}

// Function to find intersecting line segments using line sweep algorithm
vector<pair<int, int>> findIntersectingLines(const vector<Segment>& segments) {
    vector<pair<int, int>> intersections;

    for (size_t i = 0; i < segments.size(); ++i) {
        for (size_t j = i + 1; j < segments.size(); ++j) {
            if (doIntersect(segments[i], segments[j])) {
                intersections.push_back({i, j});
            }
        }
    }

    return intersections;
}

int main() {
    // Example usage
    vector<Segment> segments = {
        {{1, 1}, {4, 4}},
        {{2, 3}, {5, 1}},
        {{3, 2}, {6, 5}}
    };

    vector<pair<int, int>> intersectingPairs = findIntersectingLines(segments);

    cout << "Intersecting segments:\n";
    for (const auto& pair : intersectingPairs) {
        cout << "Segments " << pair.first << " and " << pair.second << endl;
    }

    return 0;
}