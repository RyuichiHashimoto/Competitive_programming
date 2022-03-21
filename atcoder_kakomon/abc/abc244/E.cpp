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

    Edge(int _from, int _to) {
        from = _from;
        to = _to;
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

ll mod = 998244353;

int _N, _M, _K, _S, _T, _X;

ll dfs(Graph &graph, int k, int from_val, int target_count, int target_val) {

    cout << k << endl;
    if (k == _K) {

        bool one = target_count / 2 == 0;
        bool second = (_T == from_val);

        if (one && second) {
            return 1;
        } else {
            return 0;
        }
    }

    ll sum = 0;
    for (Edge e : graph.G[from_val]) {

        if (e.to == target_val) {
            sum = (sum + dfs(graph, k + 1, e.to, target_count + 1, target_val)) % mod;
        } else {
            sum = (sum + dfs(graph, k + 1, e.to, target_count, target_val)) % mod;
        }
    }
    return sum % mod;
}

int main(void) {

    cin >> _N >> _M >> _K >> _S >> _T >> _X;

    Graph g(_N);

    bool map[2001][2001];
    fill(map[0], map[2001], false);

    rep(i, 1, _M) {
        int a, b;
        cin >> a >> b;
        Edge e(a, b), inv_e(b, a);

        g.add_Edge(e);
        g.add_Edge(inv_e);

        map[a][b] = true;
        map[b][a] = true;
    }

    int dp[2001][2001][2];
    fill(dp[0][0], dp[2001][0], 0);

    // int dp[30][30][2];
    // fill(dp[0][0], dp[30][0], 0);


    dp[0][_S][0] = 1;

    rep(i, 1, _K) {
        rep(j, 1, _N) {
            for (Edge e : g.G[j]) {
                if (e.to == _X) {
                    dp[i][e.to][0] = (dp[i - 1][e.from][1] + dp[i][e.to][0]) % mod;
                    dp[i][e.to][1] = (dp[i - 1][e.from][0] + dp[i][e.to][1]) % mod;
                } else {
                    dp[i][e.to][0] = (dp[i - 1][e.from][0] + dp[i][e.to][0]) % mod;
                    dp[i][e.to][1] = (dp[i - 1][e.from][1] + dp[i][e.to][1]) % mod;
                }
            }
        }
    }
    cout << dp[_K][_T][0];
}
