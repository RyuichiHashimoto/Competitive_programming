
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;


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
    ll minimum_node_idx;
    ll maximum_node_idx;
    ll n_vetrics;

    Graph(ll n_of_vetrics) {
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

    ll get_rank(ll idx) {
        return G[idx].size();
    }
};

namespace Dykstra {

    void add_Edge(Graph &graph, ll from, ll to, ll cost) {
        Edge e(from, to, 0, cost, 0);
        graph.add_Edge(e);
    }

    vector<ll> Dykstra(Graph &graph, ll s) {
        /*
        s:  start idx;
        */

        ll INF = 0x7FFFFFFF;

        vector<ll> ret_distance(graph.n_vetrics + 1);
        fill(ret_distance.begin(), ret_distance.end(), INF);

        // P: Pair<ll, ll>
        //    first ll: metrics(e.g., cost, distance)
        //    second ll: index of the node;
        priority_queue<P, vector<P>, greater<P>> que;

        ret_distance[s] = 0;
        que.push(P(0, s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            ll v = p.second;

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


    ll n, k;

    cin >> n >> k;

    ll a, b, c, d;
    Graph g(n + 1);


    rep(i, 1, k) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            Dykstra::add_Edge(g, b, c, d);
            Dykstra::add_Edge(g, c, b, d);
        } else {
            cin >> b >> c;

            vector<ll> s = Dykstra::Dykstra(g, b);


            if (s[c] == INT_MAX) {

                cout << "-1" << endl;
            } else {
                cout << s[c] << endl;
            }
        }
    }
    return 0;
}
