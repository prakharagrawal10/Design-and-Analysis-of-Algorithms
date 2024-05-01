#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int, int> find_top_and_least_scores(const vector<int>& scores, int start, int end) {
    if (start == end) {
        return make_pair(scores[start], scores[start]);
    }

    int mid = start + (end - start) / 2;
    pair<int, int> left = find_top_and_least_scores(scores, start, mid);
    pair<int, int> right = find_top_and_least_scores(scores, mid + 1, end);

    int top = max(left.first, right.first);
    int least = min(left.second, right.second);

    return make_pair(top, least);
}

int main() {
    vector<int> scores = {85, 72, 90, 65, 92, 78, 60, 95};

    pair<int, int> result = find_top_and_least_scores(scores, 0, scores.size() - 1);

    cout << "Top score: " << result.first << endl;
    cout << "Least score: " << result.second << endl;

    return 0;
}
