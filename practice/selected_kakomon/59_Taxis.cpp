#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


class Edge {
  public:
    int from;  // start of anEdge.
    int to;    // end of anEdge.
    int cost;  // the cost to pass through (for finding the minimum cost flow)

    Edge(int _from, int _to, int _cost) {
        from = _from;
        to = _to;
        cost = _cost;
    }
};

class Graph {
  public:
    vector<Edge> G[5001];
    // vector<vector<Edge>> G;
    int n_vetrics;

    Graph(int n_of_vetrics) {
        // G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
    }

    void add_Edge(Edge &x) {
        G[x.from].push_back(x);
    }

    int get_rank(int idx) {
        return G[idx].size();
    }
};

namespace Dykstra {

    void add_Edge(Graph &graph, int from, int to, int cost) {
        Edge e(from, to, cost);
        graph.add_Edge(e);
    }

    vector<int> Dykstra(Graph &graph, int s) {
        /*
        s:  start idx;
        */

        int INF = 0x7FFFFFFF;


        vector<int> ret_distance(graph.n_vetrics + 1);
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

    int N, K;

    cin >> N >> K;

    int a, b;

    int max_mitionri = -1;

    int A[5001], B[5001];

    rep(i, 1, N) {
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }

    Graph bfs_g(N);
    Graph g(N);
    rep(i, 1, K) {
        // cout << a << " " << b << endl;
        cin >> a >> b;
        Dykstra::add_Edge(bfs_g, a, b, 1);
        Dykstra::add_Edge(bfs_g, b, a, 1);
    }


    bool used[5001];
    rep(i, 1, N) {
        queue<P> que;
        que.push(P{i, 0});

        fill(used, used + 5001, false);


        used[i] = true;

        while (!que.empty()) {
            P p = que.front();
            que.pop();

            for (Edge e : bfs_g.G[p.first]) {
                if (!used[e.to]) {

                    Edge e_ = Edge(i, e.to, A[i]);
                    g.add_Edge(e_);
                    // Dykstra::add_Edge(g, i, e.to, A[i]);
                    used[e.to] = true;

                    if (p.second + 1 != B[i]) {
                        que.push(P{e.to, p.second + 1});
                    }
                }
            }
        }
    }


    // cout << "asd" << endl;


    vector<int> s = Dykstra::Dykstra(g, 1);


    cout << s[N] << endl;
}