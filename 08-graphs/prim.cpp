// prims algorithm

#include <iostream>
using namespace std;

void prims(int **graph, int n)
{
    int *key = new int[n];
    int *parent = new int[n];
    bool *mstSet = new bool[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, n);
}

int minKey(int *key, bool *mstSet, int n)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int *parent, int **graph, int n)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}


int  main()
{   
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    cout << "Enter the graph: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    prims(graph, n);
    return 0;
}