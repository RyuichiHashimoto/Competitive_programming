#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
typedef long long ll;
using namespace std;

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

int used[1000000];
int coun[1000000];

ll dfs(Graph &g, ll current_num, ll trial, ll max_trial, ll Query_num) {
    if (trial == max_trial) {
        return current_num;
    }

    ll ret = current_num;

    for (auto c : g.G[current_num]) {
        if (used[c.to] == Query_num) {
            if (coun[c.to] < trial) {
                ret = dfs(g, c.to, trial + 1, max_trial, Query_num);
            }
        } else if (used[c.to] != Query_num) {
            used[c.to] = Query_num;
            coun[c.to] = trial;
            ret += dfs(g, c.to, trial + 1, max_trial, Query_num);
        }
    }
    return ret;
}

typedef pair<int, int> P;

int main() {

    int N, M;
    cin >> N >> M;

    Graph graph(N + 1);
    fill(used, used + 1000000, -1);
    fill(coun, coun + 1000000, 1000);

    rep(i, 1, M) {
        int a, b;
        cin >> a >> b;
        Edge e(a, b, 0, 0, 0);
        Edge inv_e(b, a, 0, 0, 0);
        graph.add_Edge(e);
        graph.add_Edge(inv_e);
    }

    int Q;
    cin >> Q;
    ll ret = 0;
    rep(i, 1, Q) {
        int x, k;
        cin >> x >> k;
        used[x] = i;
        queue<P> que;
        P p{x, 0};

        que.push(p);

        int ret = 0;
        int Query_num = i;
        while (!que.empty()) {
            P p = que.front();
            que.pop();

            int current_num = p.first;
            ret += current_num;

            if (p.second >= k) {
                continue;
            }


            for (auto c : graph.G[current_num]) {
                if (used[c.to] != Query_num) {
                    used[c.to] = Query_num;
                    if (p.second < k) {
                        P next_p(c.to, p.second + 1);
                        que.push(next_p);
                    }
                }
            }
        }
        cout << ret << endl;
    }
}