
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
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

int dp[1 << 15 + 1][15];
int tsp[1 << 16 + 1][16];

int main(void) {
    int V, E;
    cin >> V >> E;
    fill(dp[0], dp[1 << 15 + 1], INT_MAX / 100);
    fill(tsp[0], tsp[16], -1);

    rep(i, 1, E) {
        int a, b, c;
        cin >> a >> b >> c;
        tsp[a][b] = c;
    }

    dp[0][0] = 0;

    rep(S, 1, 1 << 15) {
        rep(to, 0, V) {
            rep(from, 0, V) {
                if (tsp[from][to] != -1 && ((S >> to) & 1 == 1)) {
                    dp[S][to] = min(dp[S][to], dp[S ^ (1 << to)][from] + tsp[from][to]);
                }
            }
        }
    }
    if (INT_MAX / 100 == dp[(1 << V) - 1][0]) {
        cout << "-1" << endl;
    } else {
        cout << dp[(1 << V) - 1][0] << endl;
    }
}
