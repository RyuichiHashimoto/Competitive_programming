#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

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



/*xから到達可能な中で最長位置*/
int max_distance(int start_point,Graph &graph, vector<int>& dp,vector<bool> &used){
    
    if (used[start_point]){
        return dp[start_point];
    } else {

        // int max_distance_ = 0;
        int max_distance_ = 0;
        used[start_point] = true;

        for(edge e: graph.G[start_point]){
            // cout << e.from <<" " << e.to<<endl;
            max_distance_ = max(max_distance(e.to,graph,dp,used)+1,max_distance_);
        }
        // cout << max_distance<<endl;
        dp[start_point] = max_distance_;
     
        return max_distance_;
    }
}


int main(void)
{
    int N,M;
    cin >> N >> M;

    vector<int> dp(N+1);
    vector<bool> used(N+1);

    fill(used.begin(),used.end(),false);

    Graph graph(N);

    rep(i,1,M){
        int x,y;
        cin >> x >> y;

        edge e = edge(x,y,0,0,0);
        graph.add_edge(e);
    }
    int max_val = -1;
    rep(i,1,N){        
        max_val = max(max_val,max_distance(i,graph,dp,used));
    }
    rep(i,1,N){
        // cout << dp[i]<<endl;
    }
    
    
    cout << max_val<<endl;
}