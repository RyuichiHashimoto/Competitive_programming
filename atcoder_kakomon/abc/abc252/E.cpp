#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

class Edge {
  public:
    ll from;  // start of anEdge.
    ll to;    // end of anEdge.
    ll cap;   // the capacity for pass through
    ll cost;  // the cost to pass through (for finding the minimum cost flow)
    ll rev;   // the index of the inverseEdge.

    Edge(ll _from, ll _to, ll _cap, ll _cost, ll _rev) {
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
    int n_vetrics;

    Graph(int n_of_vetrics) {
        G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
    }

    void add_Edge(Edge &x) {
        G[x.from].push_back(x);
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


    void add_Edge(Graph &g, ll from, ll to, ll cost, ll id) {
        Edge e(from, to, 0, cost, id);
        Edge inv_e(to, from, 0, cost, id);
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


    Graph Kruskal(Graph &g) {
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

        rep(i, 0, edge_lists.size() - 1) {
            Edge e = edge_lists[i];
            if (!uft.same(e.from, e.to)) {
                add_Edge(ret_g, e.from, e.to, e.cost, e.rev);
                uft.unite(e.from, e.to);
            }
        }
        return ret_g;
    }

}  // namespace Kruskal

typedef pair<ll, int> P;
namespace Prim {

    // Graph class形式のデータを与えて、その最小全域木を返す。
    // 無向グラフを想定しており、有効グラフは想定していない。
    //
    // [使用方法]
    // Kruskal::add_Edge(g, a, b, c);
    // Graph min_tree = Kruskal::Kruskal(g);


    void add_Edge(Graph &g, int from, int to, int cost, int id) {
        Edge e(from, to, 0, cost, id);
        Edge inv_e(to, from, 0, cost, id);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }


    bool edge_cost_comparator(const Edge &x, const Edge &y) {
        // return x.cost > y.cost;
        if (x.cost != y.cost) {
            return x.cost > y.cost;
        } else if (x.from != y.from) {
            return x.from > y.from;
        } else if (x.to != y.to) {
            return x.to > y.to;
        } else {
            return true;
        }
    }

    Graph Prim(Graph &g) {
        Graph ret_g(g.n_vetrics);

        // edge_cost_comparator();
        auto compareFunc = [](const Edge &x, const Edge &y) { return edge_cost_comparator(x, y); };
        typedef priority_queue<Edge, vector<Edge>, decltype(compareFunc)> pq;
        pq que(compareFunc);


        int initial_target_node = 1;

        for (Edge &e : g.G[initial_target_node]) {
            que.push(e);
        }
        // cout << que.top().cost << endl;
        // que.pop();
        // cout << que.top().cost << endl;


        vector<bool> used(g.n_vetrics + 1);
        used[initial_target_node] = true;

        int connection = 0;
        while (!que.empty()) {
            const Edge e = que.top();
            que.pop();

            if (used[e.to]) {
                continue;
            }

            add_Edge(ret_g, e.from, e.to, e.cost, e.rev);
            used[e.to] = true;


            for (Edge next_e : g.G[e.to]) {
                if (!used[next_e.to]) {
                    que.push(next_e);
                }
            }

            connection++;
            if (g.n_vetrics == connection) {
                break;
            }
        }


        return ret_g;
    }

}  // namespace Prim


namespace Dykstra {

    void add_Edge(Graph &graph, ll from, ll to, ll cost, ll id) {
        Edge e(from, to, 0, cost, id);
        graph.add_Edge(e);
    }

    vector<ll> Dykstra(Graph &graph, int s) {
        /*
        s:  start idx;
        */

        ll INF = 0x7FFFFFFFFFFFFF;

        // if (s < graph.minimum_node_idx || s > graph.maximum_node_idx) {
        // cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl << "not " << s;
        // exit(1);
        // }

        vector<ll> ret_distance(graph.n_vetrics + 1);
        fill(ret_distance.begin(), ret_distance.end(), INF);
        vector<ll> ret_bef(graph.n_vetrics + 1);
        fill(ret_bef.begin(), ret_bef.end(), INF);

        // P: Pair<int, int>
        //    first int: metrics(e.g., cost, distance)
        //    second int: index of the node;
        priority_queue<P, vector<P>, greater<P>> que;

        ret_distance[s] = 0;
        vector<bool> used(graph.n_vetrics);

        ret_bef[s] = -1;
        que.push(P(0, s));


        while (!que.empty()) {
            P p = que.top();
            que.pop();

            int v = p.second;
            if (ret_distance[v] != p.first) {
                continue;
            }


            for (Edge &e : graph.G[v]) {
                if (ret_distance[e.to] > ret_distance[e.from] + e.cost) {

                    ret_distance[e.to] = ret_distance[e.from] + e.cost;
                    que.push(P(ret_distance[e.to], e.to));
                    ret_bef[e.to] = e.rev;
                }
            }
        }

        return ret_bef;
    }


}  // namespace Dykstra

int main() {
    int N, M;

    cin >> N >> M;

    Graph G(N);

    rep(i, 1, M) {
        int from, to, cost;
        cin >> from >> to >> cost;

        Dykstra::add_Edge(G, from, to, cost, i);
        Dykstra::add_Edge(G, to, from, cost, i);
    }


    vector<ll> g = Dykstra::Dykstra(G, 1);
    rep(i, 2, N) {
        cout << g[i] << " ";
    }
}