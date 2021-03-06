
#include <bits/stdc++.h>

#include <cassert>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

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


namespace Kruskal {

    // Graph class形式のデータを与えて、その最小全域木を返す。
    // 無向グラフを想定しており、有効グラフは想定していない。
    //
    // [使用方法]
    // Kruskal::add_Edge(g, a, b, c);
    // Graph min_tree = Kruskal::Kruskal(g);


    void add_Edge(Graph &g, int from, int to, int cost) {
        Edge e(from, to, 0, cost, 0);
        Edge inv_e(to, from, 0, cost, 0);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }


    class __Union_Find {
      private:
        int *par;
        int *rank;

      public:
        __Union_Find(int size) {
            par = new int[size];
            rank = new int[size];


            for (int i = 0; i < size; i++) {
                par[i] = i;
                rank[i] = 0;
            }
        }

        ~__Union_Find() {
            delete par;
            delete rank;
        }

        int root(int x) {
            if (par[x] == x) {
                return x;
            } else {
                par[x] = root(par[x]);
                return par[x];
            }
        }

        void unite(int x, int y) {
            x = root(x);
            y = root(y);

            if (x == y) return;

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else {
                par[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }

        bool same(int x, int y) {
            return root(x) == root(y);
        }

        int groups(int x, int y) {
            return root(x) == root(y);
        }
    };


    bool edge_cost_comparator(const Edge &x, const Edge &y) {
        if (x.cost != y.cost) {
            return x.cost < y.cost;
        } else if (x.from != y.from) {
            return x.from < y.from;
        } else if (x.to != y.to) {
            return x.to < y.to;
        } else {
            return true;
        }
    }


    Graph Kruskal(Graph &g, int k) {
        Graph ret_g(g.n_vetrics);
        __Union_Find uft(g.n_vetrics + 1);

        // used[min_edge.from] = true;

        vector<Edge> edge_lists;


        rep(i, 1, g.n_vetrics) {
            for (Edge e : g.G[i]) {
                edge_lists.push_back(e);
            }
        }

        sort(edge_lists.begin(), edge_lists.end(), edge_cost_comparator);
        int groups = g.n_vetrics;
        if (groups == k) {
            return ret_g;
        }

        rep(i, 0, edge_lists.size() - 1) {
            Edge e = edge_lists[i];
            if (!uft.same(e.from, e.to)) {
                add_Edge(ret_g, e.from, e.to, e.cost);
                uft.unite(e.from, e.to);
                groups--;
            }
            if (groups == k) {
                return ret_g;
            }
        }

        return ret_g;
    }

}  // namespace Kruskal

bool edge_cost_comparator(const Edge &x, const Edge &y) {
    if (x.cost != y.cost) {
        return x.cost > y.cost;
    } else if (x.from != y.from) {
        return x.from < y.from;
    } else if (x.to != y.to) {
        return x.to < y.to;
    } else {
        return true;
    }
}


int main(void) {

    int v, e, k;

    cin >> v >> e >> k;

    Graph g(v);

    int a, b, c;
    rep(i, 1, e) {
        cin >> a >> b >> c;
        Kruskal::add_Edge(g, a, b, c);
    }

    Graph min_tree = Kruskal::Kruskal(g, k);

    vector<Edge> edge_list;

    int sum = 0;
    rep(i, 1, v) {
        for (Edge e : min_tree.G[i]) {
            sum += e.cost;
        }
    }


    cout << (sum >> 1) << endl;
}
