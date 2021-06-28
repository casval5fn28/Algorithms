#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph{
    public:
        int V;
        list< pair<int, int> > *adj;
        Graph(int V);
        void addEdge(int u, int v, int w);
        int dijkstraSP(int src,int tg);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
}


int Graph::dijkstraSP(int src,int tgt){
    long long mst_wt =0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    mst_wt = dist[tgt];
    return mst_wt;

}


int main(){
    int V,E,src,tgt,x,y,weight;
    int mst_wt;
    cin>>V>>E;
    cin>>src>>tgt;
    Graph g(V);
    for(int i=0;i<E;i++){

        cin>>x>>y>>weight;
        g.addEdge(x,y,weight);
    }

    mst_wt = g.dijkstraSP(src,tgt);
    cout<<"Cost of shortest path : "<< mst_wt;
    return 0;
}



