#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


class Edge {
  public:
    int from;  // start of anEdge.
    int to;    // end of anEdge.
    int cap;   // the capacity for pass through
    int cost;  // the cost to pass through (for finding the minimum cost flow)
    int rev;   // the index of the inverseEdge.

    Edge(int _from, int _to, int _cap, int _cost, int _rev) {
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }
};

class Graph {
  public:
    vector<vector<Edge>> G;
    int minimum_node_idx;
    int maximum_node_idx;
    int n_vetrics;

    Graph(int n_of_vetrics) {
        G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
        minimum_node_idx = 0x7FFFFFFF;
        maximum_node_idx = 0x80000000;
    }

    void add_Edge(Edge &x) {
        G[x.from].push_back(x);
        minimum_node_idx = min(minimum_node_idx, x.from);
        minimum_node_idx = min(minimum_node_idx, x.to);
        maximum_node_idx = max(maximum_node_idx, x.from);
        maximum_node_idx = max(maximum_node_idx, x.to);
    }

    int get_rank(int idx) {
        return G[idx].size();
    }
};


namespace SCC {

    void add_Edge(Graph &, int, int);
    void __post_order_by_dfs(Graph &, vector<int> &, vector<bool> &, int);
    void __create_inverse_graph(Graph &, Graph &);

    void add_Edge(Graph &graph, int from, int to) {
        Edge e(from, to, 0, 0, 0);
        graph.add_Edge(e);
    }

    /*

    */
    void __create_Edge_inverse_graph(Graph &original, Graph &inverse) {
        inverse = Graph(original.n_vetrics);

        for (int i = 1; i <= original.n_vetrics; i++) {
            for (auto e : original.G[i]) {
                Edge inv_e(e.to, e.from, e.cap, e.cost, e.rev);
                inverse.add_Edge(inv_e);
            }
        }
    }

    /*
    与えられた有効グラフを復数の強連結成分に分解する。
    帰り値 [vector<int>, vector<int>, ..., vector<int>]
    各vector<int>には、同じ教連結成分に属するノード番号が代入されている。
    */
    vector<vector<int>> SCC(Graph &graph) {
        Graph inverse_graph(graph.n_vetrics);

        //アルゴリズムに強連結成分が必要なので、事前に作成
        __create_Edge_inverse_graph(graph, inverse_graph);

        vector<bool> used(graph.n_vetrics + 1);
        fill(used.begin(), used.end(), false);

        //帰りがけ順に並び替えてノード番号を入れる。
        vector<int> post_order;
        for (int i = 1; i <= graph.n_vetrics; i++) {
            if (!used[i]) __post_order_by_dfs(graph, post_order, used, i);
        }

        reverse(post_order.begin(), post_order.end());

        fill(used.begin(), used.end(), false);
        vector<vector<int>> ret;
        for (auto i : post_order) {
            if (!used[i]) {
                vector<int> inv_post_order;
                __post_order_by_dfs(inverse_graph, inv_post_order, used, i);
                ret.push_back(inv_post_order);
                for (auto s : inv_post_order) {
                    // cout << s << " ";
                }
                // cout << endl;
            }
        }
        return ret;
    }

    /*
        帰りがけ順で各ノードに番号をつける。
        引数のpost_order(vector<int>) に帰りがけの順番でノード番号を入れていく。
        つまり、post_order = [(帰りがけ順で一番目のノード), (帰りがけ順で2番目のノード), ..., (帰りがけ順でn番目のノード)]

        target_point: ノード番号、[1, graph.n_vetrics]の範囲で指定
    */
    void __post_order_by_dfs(Graph &graph, vector<int> &post_order, vector<bool> &used, int target_point) {
        used[target_point] = true;

        for (auto e : graph.G[target_point]) {
            if (!used[e.to]) {
                __post_order_by_dfs(graph, post_order, used, e.to);
            }
        }
        post_order.push_back(target_point);
    }

};  // namespace SCC

bool find_[200001];
bool heiro[200001];

int mod_counter = 0;

bool dfs(Graph &g, int from) {


    for (Edge e : g.G[from]) {
        if (!find_[e.to] && !heiro[e.to]) {
            dfs(g, e.to);
            mod_counter++;
            find_[e.to] = true;
        }
    }
    return false;
}

int main(void) {

    int N, M;

    cin >> N >> M;

    Graph g(N);
    Graph inv_g(N);

    rep(i, 1, M) {
        int a, b;

        cin >> a >> b;

        SCC::add_Edge(g, a, b);
        SCC::add_Edge(inv_g, b, a);
    }

    vector<vector<int>> a = SCC::SCC(g);


    map<int, int> heiro_map;
    fill(heiro, heiro + 200001, false);

    int counter = 0;
    for (auto s : a) {
        if (s.size() != 1) {
            counter += s.size();
            for (int v : s) {
                heiro[v] = true;
                heiro_map[v] = 1;
            }
        }
    }

    fill(find_, find_ + 200001, false);
    for (auto s : a) {
        if (s.size() != 1) {
            for (int v : s) {
                dfs(inv_g, v);
            }
        }
    }

    cout << counter + mod_counter << endl;
}