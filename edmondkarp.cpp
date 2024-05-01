#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define V 6 // Number of vertices in graph

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    int u, v;

    vector<vector<int>> rGraph = graph;
    vector<int> parent(V, -1);

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    vector<vector<int>> graph = { {0, 16, 13, 0, 0, 0},
                                  {0, 0, 10, 12, 0, 0},
                                  {0, 4, 0, 0, 14, 0},
                                  {0, 0, 9, 0, 0, 20},
                                  {0, 0, 0, 7, 0, 4},
                                  {0, 0, 0, 0, 0, 0} };

    cout << "The maximum possible flow is " << edmondsKarp(graph, 0, 5) << endl;

    return 0;
}