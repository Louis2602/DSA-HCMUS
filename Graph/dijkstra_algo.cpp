#include <iostream>
#include <limits.h>

using namespace std;

#define V 9
int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int parent[], int src)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;

    int dest = 7;
    cout << "Path from Source: " << src << " to " << dest << " : ";
    cout << dest << " <- ";
    while (src != dest)
    {
        cout << parent[dest] << " <- ";
        dest = parent[dest];
    }
}

void dijkstra(int graph[V][V], int src)
{
    int len[V];
    bool vertexSet[V];
    int parent[V] = {0};
    for (int i = 0; i < V; i++)
        len[i] = INT_MAX, vertexSet[i] = false;
    len[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(len, vertexSet);
        vertexSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!vertexSet[v] && graph[u][v] && len[u] != INT_MAX && len[u] + graph[u][v] < len[v])
            {
                len[v] = len[u] + graph[u][v];
                parent[v] = u;
            }
    }
    printSolution(len, parent, src);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 2);
    return 0;
}
