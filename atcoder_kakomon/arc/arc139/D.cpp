
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

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
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

// すべてのノードのコストが1 or 0であればTrue
// True: 全ノードのコストが1のみ or 0のみ
bool validate_noCost_Edge(Graph &g) {
    bool zero_weight_found = false;
    bool one_weight_found = false;

    for (int i = 0; i <= g.n_vetrics; i++) {
        for (auto e : g.G[i]) {
            if (e.cost == 0) {
                zero_weight_found = true;
            } else if (e.cost == 1) {
                one_weight_found = true;
            } else {
                return false;
            }
        }
    }
    return zero_weight_found ^ one_weight_found;
}

vector<int> find_shortest_path(Graph &g, int start_point, int end_point) {
    if (!validate_noCost_Edge(g)) {
        exit(-1);
    }

    vector<bool> used(g.n_vetrics + 1);
    vector<int> before(g.n_vetrics + 1, false);


    queue<int> que;

    que.push(start_point);
    used[start_point] = true;
    bool find_flag = false;

    while (!que.empty()) {
        int id = que.front();
        que.pop();
        for (auto e : g.G[id]) {
            if (used[e.to]) continue;

            used[e.to] = true;
            before[e.to] = e.from;
            que.push(e.to);

            if (e.to == end_point) {
                find_flag = true;
                break;
            }
        }
    }
    if (!find_flag) return vector<int>(0);


    vector<int> shortest_path;
    int id = end_point;
    shortest_path.push_back(id);
    while (id != start_point) {
        id = before[id];
        shortest_path.push_back(id);
    }

    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
}

int max_e = 200000;
int route_ids[1001][1001];
int dp[1001][200000 + 1];
int mod = 998244353;
int main(void) {

    int N, M, K;

    cin >> N >> M >> K;


    vector<int> A(M);

    rep(i, 1, M) {
        cin >> A[i - 1];
    }

    fill(route_ids[0], route_ids[1001], 0);
    vector<vector<int>> relations(N, vector<int>(2, -1));
    Graph g(N);

    rep(i, 1, N - 1) {
        int from, to;
        cin >> from >> to;
        route_ids[from][to] = i;
        route_ids[to][from] = i;
        Edge e(from, to, 0, 0, 0);
        Edge inv_e(to, from, 0, 0, 0);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }

    // return 1;
    vector<int> route_counter(N, 0);
    rep(i, 1, M - 1) {
        vector<int> spath = find_shortest_path(g, A[i - 1], A[i]);
        if (A[i - 1] == A[i]) {
            continue;
        }
        for (int j = 0; j < spath.size() - 1; j++) {

            int from = spath[j];
            int to = spath[j + 1];
            route_counter[route_ids[from][to]]++;
        }
    }
    int sum = 0;
    for (auto s : route_counter) {
        sum += s;
    }

    fill(dp[0], dp[1001], -1);
    dp[0][0] = 1;

    if (sum + K < 0) {
        cout << "0";
        return 0;
    }
    if (!((sum + K) % 2 == 0)) {
        cout << 0 << endl;
        return 0;
    }

    rep(idx, 0, N - 2) {

        rep(j, 0, 200000) {
            if (dp[idx][j] != -1) {
                if (dp[idx + 1][j + route_counter[idx + 1]] == -1) {
                    dp[idx + 1][j + route_counter[idx + 1]] = 0;
                }
                ll one = (ll)dp[idx + 1][j + route_counter[1 + idx]];
                ll two = (ll)dp[idx][j];

                dp[idx + 1][j + route_counter[1 + idx]] = (one + two) % mod;
            }
            if (dp[idx][j] != -1) {
                if (dp[idx + 1][j] == -1) {
                    dp[idx + 1][j] = 0;
                }
                ll one = (ll)dp[idx + 1][j];
                ll two = (ll)dp[idx][j];

                dp[idx + 1][j] = (one + two) % mod;
            }
        }
    }

    if (dp[N - 1][(sum + K) / 2] == -1) {
        cout << 0;
    } else {
        cout << dp[N - 1][(sum + K) / 2] << endl;
    }


    return 0;
}
