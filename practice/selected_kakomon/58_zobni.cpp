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

        ll INF = 0x7FFFFFFFFFFFFFFF;

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
int used[200001];
bool danger[200001];
bool zonbi_town_list[200001];

void dfs(Graph &g, ll from, ll counter, ll limit) {

    if (counter == limit) {
        return;
    }

    for (Edge e : g.G[from]) {
        if (used[e.to] > counter) {
            used[e.to] = counter + 1;
            danger[e.to] = true;
            dfs(g, e.to, counter + 1, limit);
        }
    }
    return;
}

int main(void) {

    ll N, M, K, S;

    cin >> N >> M >> K >> S;

    ll low_p, high_p;
    cin >> low_p >> high_p;

    fill(danger, danger + 200001, false);
    fill(zonbi_town_list, zonbi_town_list + 200001, false);

    vector<ll> zonbi_town(K + 1);

    rep(i, 1, K) {
        cin >> zonbi_town[i];
        zonbi_town_list[zonbi_town[i]] = true;
    }

    Graph dfs_g(N + 1);
    vector<ll> A(M), B(M);

    rep(i, 1, M) {
        cin >> A[i - 1] >> B[i - 1];
    }


    rep(i, 0, M - 1) {
        Edge e(A[i], B[i], 0, 0, 0);
        Edge inv_e(B[i], A[i], 0, 0, 0);
        dfs_g.add_Edge(e);
        dfs_g.add_Edge(inv_e);
    }

    rep(i, 1, K) {
        fill(used, used + 200001, 0x7FFFFFFF);
        dfs(dfs_g, zonbi_town[i], 0, S);
    }

    Graph dyk_g(N + 1);

    rep(i, 0, M - 1) {
        if (!zonbi_town_list[A[i]] && !zonbi_town_list[B[i]]) {
            if (danger[A[i]]) {
                Dykstra::add_Edge(dyk_g, B[i], A[i], high_p);
            } else {
                Dykstra::add_Edge(dyk_g, B[i], A[i], low_p);
            }

            if (danger[B[i]]) {
                Dykstra::add_Edge(dyk_g, A[i], B[i], high_p);
            } else {
                Dykstra::add_Edge(dyk_g, A[i], B[i], low_p);
            }
            // cout << A[i] << " " << B[i] << endl;
        }
    }

    vector<ll> s = Dykstra::Dykstra(dyk_g, 1);


    if (!danger[N]) {
        cout << s[N] - low_p << endl;
    } else {
        cout << s[N] - high_p << endl;
    }


    return 0;
}