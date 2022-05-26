
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

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

ll dp[1 << 17][18];
typedef pair<int, int> P;

int main(void) {

    int N, M;
    cin >> N >> M;

    Graph g(N);
    rep(i, 1, M) {
        int from, to;
        cin >> from >> to;
        Edge e(from, to, 0, 0, 0);
        Edge inv_e(to, from, 0, 0, 0);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }

    queue<P> que;
    fill(dp[0], dp[1 << 17], LL_MAX);

    rep(i, 1, N) {
        dp[1 << (i - 1)][i] = 1;
        que.push(P{1 << (i - 1), i});
    }
    // cout << dp[1][1];


    while (!que.empty()) {
        P p = que.front();
        que.pop();

        for (auto e : g.G[p.second]) {
            int next_status = p.first;
            next_status ^= (1 << (e.to - 1));
            int next_pos = e.to;
            // cout << next_status << " " << p.first << " " << next_pos << endl;

            if (dp[next_status][next_pos] == LL_MAX) {
                // cout << next_status << " " << next_pos << endl;
                dp[next_status][next_pos] = dp[p.first][p.second] + 1;
                que.push(P{next_status, next_pos});
            }
        }
    }


    ll ret = 0;
    brep(i, N) {
        // cout << i << endl;
        if (i == 0) {
            continue;
        }
        ll min_value = (1ll << 61);
        rep(j, 1, N) {
            min_value = min(min_value, dp[i][j]);
        }
        // cout << min_value << " " << i << endl;
        ret += min_value;
    }
    cout << ret << endl;

    return 0;
}
