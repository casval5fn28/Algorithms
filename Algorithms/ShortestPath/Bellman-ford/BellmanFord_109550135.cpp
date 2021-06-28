#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
# define INF 0x3f3f3f3f

struct Edge {
    int src, tgt, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void bellmanfordSP(struct Graph* graph, int src,int tgt){
    long long mst_wt =0;
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++){
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].tgt;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].tgt;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Negative loop detected!");
            return;
        }
    }
    mst_wt = dist[tgt];
    cout<<"Cost of shortest path : "<< mst_wt;
    return;
}

int main(){
    int V,E,src,tgt,x,y,weight;
    cin>>V>>E;
    cin>>src>>tgt;
    struct Graph* graph = createGraph(V, E);
    for(int i=0;i<E;i++){

        cin>>x>>y>>weight;
        graph->edge[i].src = x;
        graph->edge[i].tgt = y;
        graph->edge[i].weight = weight;
    }
    bellmanfordSP(graph,src,tgt);

    return 0;
}

