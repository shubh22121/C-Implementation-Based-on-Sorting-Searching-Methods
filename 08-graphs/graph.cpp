#include <iostream>
using namespace std;

// Representing he adj matrix
class Graph{
    private:
    int **array;
    int vertx;
    public:

    Graph(int v){
        vertx = v;
        for(int i=0;i<v;i++){
            // this is an order n2 funtion so sad :-(
            // allocating memory for the rows
            array[i] = new int[v];
            for(int j=0;j<v;j++){
                array[i][j] = 0; // setting garbage values to 0
            }
        }
    }

    // multi graph
    void add_edges_multi(int i,int j){
        array[i][j] = array[i][j]+1;
    }

    // simple 
    void add_edges(int i,int j){
        array[i-1][j-1] = 1;
        array[j-1][i-1] = 1;
    }

    void remove_edge(int i,int j){
        array[i][j]=0;
        array[j][i]=0;
    }
    void display(){
        for (int i=0;i<vertx;i++){
            for (int j=0;j<vertx;j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(){
        int st[vertx][2];
        int s=0;
        bool visit[vertx];
        visit[0] = true;
        for (int i=1;i<vertx;i++){
            visit[i] = false;
        }
        int i=0;
        int count=0;

        int prev_count=0; // this is for j 
        while (count<vertx){
            for (int j=prev_count;j<vertx && count<vertx;j++){
                if (array[i][j] != 0){
                    cout << "("<<i <<','<<j<<")" << " ";
                    st[s][0]=i;
                    st[s++][1]=j;
                    remove_edge(i,j);
                    if (j == vertx){
                        i++;
                    }
                    if (visit[j]==true){
                        prev_count=j;
                    }else{
                        i=j;
                        prev_count=0;
                    }
                    
                    visit[i] = true;
                    
                    // unstack
                    count++;
                    break;
                }
            }
        }
    }
};

int main(){
    Graph g= Graph(4);
    g.add_edges(1,2);
    g.add_edges(3,4);
    g.add_edges(1,4);
    g.add_edges(3,2);
    g.display();
    g.DFS();
}