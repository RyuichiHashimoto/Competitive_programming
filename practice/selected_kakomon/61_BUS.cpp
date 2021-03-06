
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


namespace warshall_floyd {

    void add_Edge(Graph &g, int from, int to, int cost) {
        Edge e = Edge(from, to, 0, cost, 0);
        g.add_Edge(e);
    }


    vector<vector<ll>> warshall_floyd(Graph &g) {
        ll LL_MAX_ = 0x7FFFFFFFFFFFFFF;
        vector<vector<ll>> ret(g.n_vetrics + 1, vector<ll>(g.n_vetrics + 1, LL_MAX_));

        rep(i, 1, g.n_vetrics) {
            ret[i][i] = 0;
        }

        rep(i, 1, g.n_vetrics) {
            for (Edge e : g.G[i]) {
                ret[e.from][e.to] = e.cost;
            }
        }


        rep(k, 1, g.n_vetrics) {
            rep(i, 1, g.n_vetrics) {
                rep(j, 1, g.n_vetrics) {
                    if ((ret[i][k] != LL_MAX_) and (ret[k][j] != LL_MAX_)) {
                        ret[i][j] = min(ret[i][j], ret[i][k] + ret[k][j]);
                    }
                }
            }
        }
        return ret;
    }

    bool has_close_circle(vector<vector<ll>> &distance) {
        rep(i, 1, distance.size() - 1) {
            if (distance[i][i] < 0) {
                return true;
            }
        }
        return false;
    }


};  // namespace warshall_floyd


int main(void) {

    int n, m;

    cin >> n >> m;

    Graph g(n);


    int a, b, c;
    rep(i, 1, m) {
        cin >> a >> b >> c;
        // a++;
        // b++;
        warshall_floyd::add_Edge(g, a, b, c);
        warshall_floyd::add_Edge(g, b, a, c);
    }


    vector<vector<ll>> ret = warshall_floyd::warshall_floyd(g);
    ll min_ = 0x7FFFFFFFFFFFFFF;
    ll max_ = -1;

    rep(i, 1, n) {
        rep(j, 1, n) {
            min_ = min(min_, *max_element(ret[i].begin() + 1, ret[i].end()));
        }
    }
    cout << min_ << endl;


}  // namespace )
