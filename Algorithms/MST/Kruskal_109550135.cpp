#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

typedef pair<int, int> iPair;


struct Graph{
    int V, E;
    vector< pair<int, iPair> > edges;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w){
        edges.push_back({w, {u, v}});
    }
    int kruskalMST();
};

struct DisjointSets{
    int *parent, *rnk;
    int n;

    DisjointSets(int n){
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for (int i = 0; i <= n; i++){
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u){
        if (u != parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y){
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
        }
        if (rnk[x] == rnk[y]){
            rnk[y]++;
        }
    }
};

int Graph::kruskalMST(){
    long long mst_wt = 0;
    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating a cycle or not
        if (set_u != set_v){
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main(){
    int V,E,x,y;
    long long weight;
    cin>>V>>E;
    Graph g(V, E);
    for(int i=0;i<E;i++){
        cin>>x>>y>>weight;
        g.addEdge(x,y,weight);;
    }
    long long mst_wt = g.kruskalMST();
    cout<<"Cost of shortest path : "<< mst_wt;

    return 0;
}



