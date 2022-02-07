#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, from,to) for (int i = from; i <= (int)(to); i++)

typedef unsigned long long ll;

const int N_MAX = 100000;

ll importance[N_MAX+1];
ll used[N_MAX+1];


class edge
{
public:
    int from; // start of an edge.
    int to;   // end of an edge.
    int cap;  // the capacity for pass through
    int cost; // the cost to pass through (for finding the minimum cost flow)
    int rev;  // the index of the inverse edge.
    int idx;

    edge(int _from, int _to, int _cap, int _cost, int _rev)
    {
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }

    edge(int _from, int _to, int _idx)
    {
        from = _from;
        to = _to;
        idx = _idx;
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

int dfs(Graph &graph,edge &target_edge){
    ll sum =0;

    for(auto e: graph.G[target_edge.to]){
        if (e.idx == target_edge.idx){
            continue;
        } else if (used[e.idx]){
            sum += importance[e.idx];
        } else {
            sum += dfs(graph,e);
        }
    }
    sum++;
    used[target_edge.idx] = true;
    importance[target_edge.idx] = sum;
    // cout << sum;

    return sum;
}



int main(void)
{
    int N;
    cin >> N;

    fill(used,used+N+1,false);
    fill(importance,importance+N+1,0);


    Graph graph(N);

    rep(i,1,N-1){
        int a,b;
        cin >> a >> b;
        edge e(a,b,i);
        edge inv(b,a,i);
        
        graph.add_edge(e);
        graph.add_edge(inv);
    }

    for(auto e: graph.G[1]){
        // cout <<"asd"<<endl;
        dfs(graph,e);
    }

    ll sum = 0;

    rep(i,1,N-1){
        sum += (importance[i]) *(N - importance[i]);
    }
    cout << sum;

}