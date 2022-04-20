#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

class Edge {
  public:
    int from;  // start of anEdge.
    int to;    // end of anEdge.
    int cap;   // the capacity for pass through
    ll cost;   // the cost to pass through (for finding the minimum cost flow)
    int rev;   // the index of the inverseEdge.

    Edge(int _from, int _to, int _cap, ll _cost, int _rev) {
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

    void add_Edge(Graph &graph, int from, int to, ll cost) {
        Edge e(from, to, 0, cost, 0);
        graph.add_Edge(e);
    }

    vector<ll> Dykstra(Graph &graph, int s) {
        /*
        s:  start idx;
        */

        ll INF = 0x7FFFFFFFFFFFFFFF;

        // if (s < graph.minimum_node_idx || s > graph.maximum_node_idx) {
        // cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl << "not " << s;
        // exit(1);
        // }

        vector<ll> ret_distance(graph.n_vetrics + 1);
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

int main() {
    int N, M;

    cin >> N >> M;

    vector<ll> H(N + 1);

    rep(i, N) {
        cin >> H[i + 1];
    }
    ll pot = 1E9 + 1;

    Graph graph(N);

    rep(i, M) {

        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        if (H[tmp1] < H[tmp2]) {
            Dykstra::add_Edge(graph, tmp1, tmp2, -1 * (H[tmp2] - H[tmp1]) + 2 * H[tmp1]);
            Dykstra::add_Edge(graph, tmp2, tmp1, -1 * (H[tmp1] - H[tmp2]) + 2 * H[tmp2]);
        } else if (H[tmp1] > H[tmp2]) {
            Dykstra::add_Edge(graph, tmp1, tmp2, -2 * (H[tmp2] - H[tmp1]) + 2 * H[tmp1]);
            Dykstra::add_Edge(graph, tmp2, tmp1, -1 * (H[tmp1] - H[tmp2]) + 2 * H[tmp2]);
        } else {
            Dykstra::add_Edge(graph, tmp1, tmp2, (0));
            Dykstra::add_Edge(graph, tmp2, tmp1, (0));
        }
    }
    vector<ll> s = Dykstra::Dykstra(graph, 1);


    for (int i = 1; i <= 4; i++) {
        cout << s[i] + 2 * H[i] - 2 * H[1] << " ";
    }


    //  cout << (*max_element(s.begin(), s.end()));
}