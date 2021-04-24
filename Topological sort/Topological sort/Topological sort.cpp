#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <stack>
#include <chrono>
using namespace std;

vector <vector<int> > graph;
stack<int> vertexGraph, Stack;
vector<int> vizited;
vector <bool> used;
int const WHITE = 0, GREY = 1, BLACK = 2;
int cycle_flag = -1;

// create random Graph
void randomGraph(int n, int& count) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int flag = rand() % 2;
            if (flag == 1) {
                row.push_back(j);
                vertexGraph.push(j);
                vertexGraph.push(i);
                count++;
            }
        }
        graph.push_back(row);
    }
}

//checking the graph for cyclicity
bool dfs(int v) {
    if (vizited[v] == BLACK) {
        return false;
    }
    else {
        vizited[v] = GREY;
        used[v] = true;
        for (size_t i = 0; i < graph[v].size(); i++) {
            int neighbour = graph[v][i]; 
            if (vizited[neighbour] == WHITE) {
                if (dfs(neighbour))
                    return true;
            }
            else if (vizited[neighbour] == GREY) {
                cycle_flag = neighbour;
                return true;
            }
        }
        vizited[v] = BLACK;
        Stack.push(v);
        return false;
    }
}

void topological_sort(int n) {
    for (int i = 0; i < n; i++) 
        used[i] = false;

    for (int i = 0; i < n; i++)
        if (!used[i]) 
            dfs(i);
}

int main() {
    int n, count = 0;
    cout << "\nnodes: ";
    cin >> n;
        
    vizited.resize(n, WHITE);
    used.resize(n);

    randomGraph(n, count);

    cout << " nvertex: " << count << endl;

    auto t1 = chrono::high_resolution_clock::now();

    topological_sort(n);

    if (cycle_flag != -1) {
        cout << "this graph has cycl" << endl;
        chrono::duration<double, milli> elapsed = chrono::high_resolution_clock::now() - t1;
        cout << "runtime = " << elapsed.count() << endl;
    }
    else {
        // cout << "\nFollowing is a Topological Sort of the given graph\n";
        chrono::duration<double, milli> elapsed = chrono::high_resolution_clock::now() - t1;
        cout << "runtime = " << elapsed.count() << endl;
    }
    return 0;
}
