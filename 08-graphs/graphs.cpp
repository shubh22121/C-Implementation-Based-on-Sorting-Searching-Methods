// graph representation

#include <iostream>
using namespace std;

class Graph {
    private:
     int V;
        int **adj;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printGraph();
};  

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1;
    adj[w][v] = 1;
}

void Graph::printGraph() {
    for (int v = 0; v < V; v++) {
        for (int w = 0; w < V; w++) {
            cout << adj[v][w] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();

    return 0;
}

