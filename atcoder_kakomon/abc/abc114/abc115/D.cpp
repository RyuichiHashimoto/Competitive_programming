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
ll Pcounts[51];
ll sou[51];


ll max_(ll target_val, int sou_count) {

    if (sou_count == 1) {
        if (target_val == 1) {
            return 0;
        } else if (target_val == 5) {
            return 3;
        } else {
            return target_val - 1;
        }
    }
    if (target_val == 1) {
        return 0;
    }

    if (sou[sou_count] == target_val) {
        return Pcounts[sou_count];
    } else if (sou[sou_count] / 2 + 1 == target_val) {
        return Pcounts[sou_count - 1] + 1ll;
    } else if (sou[sou_count] / 2 + 1 > target_val) {

        return max_(target_val - 1, sou_count - 1);
    } else if (sou[sou_count] / 2 + 1 < target_val) {
        ll s = target_val - sou[sou_count] / 2 - 1;
        return Pcounts[sou_count - 1] + 1ll + max_(s, sou_count - 1);
    }
    exit(1);
}


int main(void) {

    int N;
    ll X;

    cin >> N >> X;


    ll patie;


    Pcounts[0] = 1;
    sou[0] = 1;

    rep(i, 1, 51) {
        Pcounts[i] = 2 * Pcounts[i - 1] + 1;
        sou[i] = 2 * sou[i - 1] + 3;
    }


    cout << max_(X, N) << endl;
    return 0;
}
