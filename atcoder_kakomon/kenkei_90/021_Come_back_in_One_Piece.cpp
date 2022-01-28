#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair<ll, ll> P;

class edge
{
public:
    int from; // start of an edge.
    int to;   // end of an edge.
    int cap;  // the capacity for pass through
    int cost; // the cost to pass through (for finding the minimum cost flow)
    int rev;  // the index of the inverse edge.

    edge(int _from, int _to, int _cap, int _cost, int _rev)
    {
        
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }
};

class Graph
{
public:
    vector<vector<edge>> G;
    int minimum_node_idx;
    int maximum_node_idx;
    int n_vetrics;

    Graph(int n_of_vetrics)
    {
        G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
        minimum_node_idx = 0x7FFFFFFF;
        maximum_node_idx = 0x80000000;
    }

    void add_edge(edge &x)
    {
        G[x.from].push_back(x);
        minimum_node_idx = min(minimum_node_idx, x.from);
        minimum_node_idx = min(minimum_node_idx, x.to);
        maximum_node_idx = max(maximum_node_idx, x.from);
        maximum_node_idx = max(maximum_node_idx, x.to);
    }

    int get_rank(int idx)
    {
        return G[idx].size();
    }
};

namespace SCC {

}

int main(void)
{
    int N,M;
    cin >> N >> M;

    Graph graph(N+1);
    rep(i, M)
    {
        int a,b,c;
        cin >> a >> b >> c;
        Dykstra::add_edge(graph, a, b, c);
        Dykstra::add_edge(graph, b, a, c);
    }
    vector<ll> fromA = Dykstra::Dykstra(graph, 1);
    vector<ll> fromB = Dykstra::Dykstra(graph, N);
    cout << fromA[N]<<endl;
    rep(i, N - 2)
    {
        cout << fromA[i + 2] + fromB[i+2]<<endl;
    }
    cout << fromA[N]<<endl;
}
     