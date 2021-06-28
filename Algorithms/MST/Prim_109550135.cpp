#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

// Allocates memory for adjacency list
Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


void Graph::primMST(){

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    int src = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    long long mst_wt = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
          if(inMST[u] == true){
            continue;
        }
        inMST[u] = true;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print  MST weight using key array
    for (int i = 1; i < V; ++i){
        mst_wt += key[i];
    }
    cout<<"Cost of shortest path : "<< mst_wt;
}
int main(){
    int V, E, x, y,weight;
    cin >> V >> E;
    Graph g(V);
    for(int i=0;i<E;i++){
        cin>>x>>y>>weight;
        g.addEdge(x,y,weight);
    }
    g.primMST();
    return 0;
}
