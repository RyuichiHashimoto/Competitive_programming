#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

typedef long long ll;
#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


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


bool used[1000000];

namespace SCCS {

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
    δΈγγγγζεΉγ°γ©γγεΎ©ζ°γ?εΌ·ι£η΅ζεγ«εθ§£γγγ
    εΈ°γε€ [vector<int>, vector<int>, ..., vector<int>]
    εvector<int>γ«γ―γεγζι£η΅ζεγ«ε±γγγγΌγηͺε·γδ»£ε₯γγγ¦γγγ
    */
    vector<vector<int>> SCC(Graph &graph) {
        Graph inverse_graph(graph.n_vetrics);

        //γ’γ«γ΄γͺγΊγ γ«εΌ·ι£η΅ζεγεΏθ¦γͺγ?γ§γδΊεγ«δ½ζ
        __create_Edge_inverse_graph(graph, inverse_graph);

        vector<bool> used(graph.n_vetrics + 1);
        fill(used.begin(), used.end(), false);

        //εΈ°γγγι γ«δΈ¦γ³ζΏγγ¦γγΌγηͺε·γε₯γγγ
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
        εΈ°γγγι γ§εγγΌγγ«ηͺε·γγ€γγγ
        εΌζ°γ?post_order(vector<int>) γ«εΈ°γγγγ?ι ηͺγ§γγΌγηͺε·γε₯γγ¦γγγ
        γ€γΎγγpost_order = [(εΈ°γγγι γ§δΈηͺη?γ?γγΌγ), (εΈ°γγγι γ§2ηͺη?γ?γγΌγ), ..., (εΈ°γγγι γ§nηͺη?γ?γγΌγ)]

        target_point: γγΌγηͺε·γ[1, graph.n_vetrics]γ?η―ε²γ§ζε?
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

};  // namespace SCCS

int counter = 0;

void dfs(Graph &g, map<int, int> &used, int from) {

    for (auto e : g.G[from]) {
        if (used[e.to] == 0) {
            used[e.from] = 1;
            counter++;
            dfs(g, used, e.to);
        }
    }
}

void _dfs(Graph &g, map<int, int> &used, int from) {

    counter++;
    for (auto e : g.G[from]) {
        if (used[e.to] == 0 && g.G[e.to].size() == 2) {
            used[e.from] = 1;
            _dfs(g, used, e.to);
        }
    }
}


int main() {

    int n, m;

    cin >> n >> m;

    if (n != m) {
        cout << "0" << endl;
        return 0;
    }


    Graph graph(n);
    rep(i, 1, n) {
        int a, b;
        cin >> a >> b;
        Edge e(a, b, 0, 0, 0);
        Edge inv_e(b, a, 0, 0, 0);
        graph.add_Edge(e);
        graph.add_Edge(inv_e);
    }

    vector<vector<int>> s = SCCS::SCC(graph);

    ll ret = 1;
    ll mod = 998244353;
    for (auto b : s) {


        if (b.size() == 1 or b.size() == 2) {
            cout << "0";
            return 0;
        } else {
            counter = 0;

            int edge = 0;

            for (auto i : b) {
                edge += graph.G[i].size();
            }

            if (edge / 2 != b.size()) {
                cout << "0";
                return 0;
            }

            ret = (2 * ret) % mod;
        }
    }

    cout << ret << endl;
    return 0;
}