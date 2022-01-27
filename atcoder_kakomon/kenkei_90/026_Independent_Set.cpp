#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

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

    int get_vetrics()
    {
        /*
            vetrics数を返す関数
        */

        return n_vetrics;
    }
};

namespace color_assign{
    /*
        ノードの色分けを行う。

    */

    void add_edge(Graph &graph,int from, int to){
        edge e(from, to, 0, 0, 0);
        edge rev_e(to, from, 0, 0, 0);

        graph.add_edge(e);
        graph.add_edge(rev_e);
    }

    void _dfs_2_colors(Graph &graph, vector<int> &color_ids, int vetric_id, int assigned_color, int n_colors)
    {
        color_ids[vetric_id] = assigned_color;

        for (edge &e : graph.G[vetric_id])
        {
            int to_vetric_id = e.to;            
            if (color_ids[to_vetric_id] == -1)
            {
                _dfs_2_colors(graph, color_ids, to_vetric_id, (assigned_color + 1) % n_colors, n_colors);
            } 
        }
    }

    vector<int> coloring(Graph &G,int n_colors){
        /*
            グラフGの頂点をn_color色で塗り分ける関数            
        */
        if (n_colors !=  2){
            cerr << "this this function is implemented only 2 color version";
            exit(1);
        }

        vector<int> color_ids(G.n_vetrics+1);
        fill(color_ids.begin(),color_ids.end(),-1);

        if (n_colors == 2)
        {
            _dfs_2_colors(G, color_ids, 1, 0, n_colors);
        }
        return color_ids;
    }
};

int main(void)
{
    int N;

    cin >> N;

    Graph G(N);

    rep(i,N-1){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        color_assign::add_edge(G, tmp1, tmp2);
    }

    vector<int> id_lists = color_assign::coloring(G, 2);

    vector<int> color_1;
    vector<int> color_2;

    rep(i,id_lists.size()){
        if (id_lists[i+1] == 0){
            color_1.push_back(i+1);
        } else {
            color_2.push_back(i + 1);
        }
    }
    vector<int> target_color_id = color_1;
    if (color_1.size() < color_2.size()){
        target_color_id = color_2;
    }

    rep(i, N/2){
        cout << target_color_id[i]<< " ";
    }
}