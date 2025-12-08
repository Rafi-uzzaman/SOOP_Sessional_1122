#include <iostream>
using namespace std;

int n = 4;  // number of vertices
int m = 3;  // number of colors allowed
int color[20];

// Predefined adjacency matrix of a graph
int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    return true;
}

bool graphColoring(int v) {
    if (v == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoring(v + 1))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    if (graphColoring(0)) {
        cout << "\nGraph Coloring Result:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    } 
    else {
        cout << "No coloring possible with " << m << " colors.\n";
    }
}
