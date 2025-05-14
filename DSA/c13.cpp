/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify the 
prominent land marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 100; // maximum number of nodes

int adj_matrix[MAXN][MAXN]; // adjacency matrix
int adj_list[MAXN][MAXN]; // adjacency list
int dist[MAXN]; // distance array for BFS
bool visited[MAXN]; // visited array for DFS

// DFS function
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < MAXN; i++) {
        if (adj_matrix[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

// BFS function
void bfs(int node) {
    memset(dist, -1, sizeof(dist));
    dist[node] = 0;

    int q[MAXN];
    int front = 0, rear = 0;
    q[rear++] = node;

    while (front != rear) {
        int u = q[front++];
        cout << u << " ";

        for (int i = 0; i < MAXN; i++) {
            if (adj_list[u][i] && dist[i] == -1) {
                dist[i] = dist[u] + 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    int n, m; // number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // initialize adjacency matrix and adjacency list
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            adj_matrix[i][j] = 0;
            adj_list[i][j] = 0;
        }
    }

    // add edges to the adjacency matrix and adjacency list
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter edge " << i+1 << " (u v w): ";
        cin >> u >> v >> w;
        adj_matrix[u][v] = adj_matrix[v][u] = w;
        adj_list[u][v] = adj_list[v][u] = 1;
    }

    // perform DFS and BFS on the graph
    int start_node;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> start_node;

    cout << "DFS: ";
    dfs(start_node);
    cout << endl;

    cout << "BFS: ";
    bfs(start_node);
    cout << endl;

    return 0;
}
