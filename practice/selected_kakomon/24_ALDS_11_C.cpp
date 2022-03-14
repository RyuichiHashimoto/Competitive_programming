#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;


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
int counter = 1;
vector<int> timestamp;
vector<int> fin_time;
vector<bool> used;
void dfs(Graph &graph, int idx) {

    used[idx] = true;
    timestamp[idx] = counter++;
    for (auto e : graph.G[idx]) {
        if (!used[e.to]) {
            dfs(graph, e.to);
        }
    }
    fin_time[idx] = counter++;
}

int main(void) {

    int N;

    cin >> N;
    Graph G(N);
    timestamp.resize(N + 1);
    fin_time.resize(N + 1);
    used.resize(N + 1);

    rep(i, 1, N) {
        int idx, K, tmp;
        cin >> idx >> K;
        rep(j, 1, K) {
            cin >> tmp;
            Edge a(idx, tmp);
            Edge inv_a(tmp, idx);
            G.add_Edge(a);
            // G.add_Edge(inv_a);
        }
    }

    fill(used.begin(), used.end(), false);
    fill(timestamp.begin(), timestamp.end(), -1);
    fill(fin_time.begin(), fin_time.end(), -1);


    rep(i, 1, N) {
        if (!used[i]) {
            dfs(G, i);
        }
    }


    rep(i, 1, N) {
        cout << i << " " << timestamp[i] << " " << fin_time[i] << endl;
    }
}