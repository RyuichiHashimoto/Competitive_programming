
#include <bits/stdc++.h>

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

typedef pair<ll, ll> P;


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

namespace Dykstra {

    void add_Edge(Graph &graph, int from, int to, int cost) {
        Edge e(from, to, 0, cost, 0);
        graph.add_Edge(e);
    }

    vector<int> Dykstra(Graph &graph, int s) {
        /*
        s:  start idx;
        */

        int INF = 0x7FFFFFFF;

        if (s < graph.minimum_node_idx || s > graph.maximum_node_idx) {
            cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl << "not " << s;
            exit(1);
        }

        vector<int> ret_distance(graph.n_vetrics + 1);
        fill(ret_distance.begin(), ret_distance.end(), INF);

        // P: Pair<int, int>
        //    first int: metrics(e.g., cost, distance)
        //    second int: index of the node;
        priority_queue<P, vector<P>, greater<P>> que;

        ret_distance[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            int v = p.second;

            for (Edge &e : graph.G[v]) {
                if (ret_distance[e.to] > ret_distance[e.from] + e.cost) {

                    ret_distance[e.to] = ret_distance[e.from] + e.cost;
                    que.push(P(ret_distance[e.to], e.to));
                }
            }
        }

        return ret_distance;
    }
}  // namespace Dykstra

int main(void) {


    int v, e, r;

    cin >> v >> e >> r;
    Graph g(v);

    if (e == 0) {
        rep(i, 0, v - 1) {
            if (i == r) {
                cout << "0" << endl;
            } else {
                cout << "INF" << endl;
            }
        }
        return 0;
    }

    int a, b, c;
    rep(i, 1, e) {
        cin >> a >> b >> c;
        Dykstra::add_Edge(g, a + 1, b + 1, c);
    }

    vector<int> ret = Dykstra::Dykstra(g, r + 1);

    rep(i, 1, v) {
        int a = ret[i];
        if (a == 0x7FFFFFFF) {
            cout << "INF" << endl;
        } else {
            cout << a << endl;
        }
    }
}
