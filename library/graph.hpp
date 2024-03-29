#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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


namespace Dykstra {

    void add_Edge(Graph &graph, int from, int to, int cost) {
        Edge e(from, to, 0, cost, 0);
        graph.add_Edge(e);
    }

    vector<int> Dykstra(Graph &graph, int s) {
        /*
        s:  start idx;
        */

        int INF = 0x7FFFFFFF;

        // if (s < graph.minimum_node_idx || s > graph.maximum_node_idx) {
        // cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl << "not " << s;
        // exit(1);
        // }

        vector<int> ret_distance(graph.n_vetrics + 1);
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
            if (ret_distance[v] != p.first) {
                continue;
            }

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


vector<int> get_dist(Graph &graph, int start) {
    vector<int> ret(graph.n_vetrics + 1);
    queue<int> que;
    int INF_ = 0x7FFFFFFF;
    fill(ret.begin(), ret.end(), INF_);

    que.push(start);
    ret[start] = 0;

    while (!(que.empty())) {
        int index = que.front();
        que.pop();

        for (int i = 0; i < graph.G[index].size(); i++) {
            int t = graph.G[index][i].to;
            if (ret[t] == INF_) {
                ret[t] = ret[index] + 1;
                que.push(t);
            }
        }
    }
    return ret;
}

namespace bipartite_maching {

    void add_Edge(Graph &graph, int from, int to) {
        Edge e(from, to, 0, 0, 0);
        Edge e_inverse(to, from, 0, 0, 0);

        graph.add_Edge(e);
        graph.add_Edge(e_inverse);
    }

    bool has_increased_flow(Graph &graph, vector<bool> &used, vector<int> &match, int v) {
        used[v] = true;

        rep(i, graph.G[v].size()) {
            int u = graph.G[v][i].to;
            int w = match[u];

            if (w < 0 || !used[w] && has_increased_flow(graph, used, match, w)) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching(Graph &graph) {
        int res = 0;
        int V = graph.n_vetrics;
        vector<int> match(V);
        vector<bool> used(V);
        fill(match.begin(), match.end(), -1);

        for (int v = 0; v < V; v++) {
            if (match[v] < 0) {
                fill(used.begin(), used.end(), false);

                if (has_increased_flow(graph, used, match, v)) {
                    res++;
                }
            }
        }
        return res;
    }
}  // namespace bipartite_maching

namespace maximum_flow {

    void add_Edge(Graph &graph, int from, int to, int cap) {
        /*通常の辺と残余ネットワーク用の辺を追加する。*/

        Edge t(from, to, cap, 0, graph.G[to].size());
        Edge t_inverse(to, from, 0, 0, graph.G[from].size() - 1);

        graph.add_Edge(t);
        graph.add_Edge(t_inverse);
    }

    int obtain_increased_flow(Graph &graph, vector<bool> &used, int v, int t, int f) {
        if (v == t) {
            return f;
        }
        used[v] = true;

        for (int i = 0; i < graph.G[v].size(); i++) {
            Edge &e = graph.G[v][i];

            if (!used[e.to] && e.cap > 0) {
                int d = obtain_increased_flow(graph, used, e.to, t, min(f, e.cap));

                if (d > 0) {
                    e.cap -= d;
                    graph.G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(Graph &graph, int s, int t) {
        /*
            graph: graph.
            int s: start node.
            int t: end node.
        */

        int flow = 0;
        int INT_MAX_ = 0x7FFFFFFF;
        vector<bool> used(graph.n_vetrics);

        for (;;) {
            fill(used.begin(), used.end(), false);
            int f = obtain_increased_flow(graph, used, s, t, INT_MAX_);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }
}  // namespace maximum_flow

namespace minimize_cost {

    void add_Edge(Graph &graph, int from, int to, int cap, int cost) {
        /*通常の辺と残余ネットワーク用の辺を追加する。*/
        Edge t(from, to, cap, cost, graph.G[to].size());
        Edge t_inverse(to, from, 0, cost, graph.G[from].size() - 1);

        graph.add_Edge(t);
        graph.add_Edge(t_inverse);
    }
    typedef pair<int, int> P;

    int min_cost_flow(Graph &graph, int s, int t, int f) {
        /*
            graph: graph.
            int s: start node.
            int t: end node.
            int f: input flow size.
        */

        int res = 0;
        const int INT_INF = 0x7FFFFFFF;
        vector<int> h(graph.n_vetrics);
        vector<int> dist(graph.n_vetrics);
        vector<int> prev_v(graph.n_vetrics);
        vector<int> prev_e(graph.n_vetrics);
        fill(h.begin(), h.end(), 0);
        fill(h.begin(), h.end(), 0);
        fill(h.begin(), h.end(), 0);

        while (f > 0) {
            priority_queue<P, vector<P>, greater<P>> que;
            fill(dist.begin(), dist.end(), INT_INF);
            dist[s] = 0;
            que.push(P(0, s));

            while (!(que.empty())) {
                P p = que.top();
                que.pop();

                int v = p.second;

                if (dist[v] < p.first) {
                    continue;
                }

                rep(i, graph.G[v].size()) {
                    Edge &e = graph.G[v][i];

                    if ((e.cap > 0) && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prev_v[e.to] = v;
                        prev_e[e.to] = i;
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }

            if (dist[t] == INT_INF) {
                return -1;
            }

            int V = graph.n_vetrics;
            rep(v, V) h[v] += dist[v];

            int d = f;

            for (int v = t; v != s; v = prev_v[v]) {
                d = min(d, graph.G[prev_v[v]][prev_e[v]].cap);
            }

            f -= d;
            res += d * h[t];

            for (int v = t; v != s; v = prev_v[v]) {
                Edge &e = graph.G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                graph.G[v][e.rev].cap += d;
            }
        }

        return res;
    }

}  // namespace minimize_cost

namespace color_assign {
    /*
        ノードの色分けを行う。

    */

    void add_Edge(Graph &graph, int from, int to) {
        Edge e(from, to, 0, 0, 0);
        Edge rev_e(to, from, 0, 0, 0);

        graph.add_Edge(e);
        graph.add_Edge(rev_e);
    }

    void _dfs_2_colors(Graph &graph, vector<int> &color_ids, int vetric_id, int assigned_color, int n_colors) {
        color_ids[vetric_id] = assigned_color;

        for (Edge &e : graph.G[vetric_id]) {
            int to_vetric_id = e.to;
            if (color_ids[to_vetric_id] == -1) {
                _dfs_2_colors(graph, color_ids, to_vetric_id, (assigned_color + 1) % n_colors, n_colors);
            }
        }
    }

    vector<int> coloring(Graph &G, int n_colors) {
        /*
            グラフGの頂点をn_color色で塗り分ける関数
        */
        if (n_colors != 2) {
            cerr << "this this function is implemented only 2 color version";
            exit(1);
        }

        vector<int> color_ids(G.n_vetrics + 1);
        fill(color_ids.begin(), color_ids.end(), -1);

        if (n_colors == 2) {
            _dfs_2_colors(G, color_ids, 1, 0, n_colors);
        }
        return color_ids;
    }
};  // namespace color_assign

namespace SCC {

    void add_Edge(Graph &, int, int);
    void __post_order_by_dfs(Graph &, vector<int> &, vector<bool> &, int);
    void __create_inverse_graph(Graph &, Graph &);

    void add_Edge(Graph &graph, int from, int to) {
        Edge e(from, to, 0, 0, 0);
        graph.add_Edge(e);
    }

    /*

    */
    void __create_Edge_inverse_graph(Graph &original, Graph &inverse) {
        inverse = Graph(original.n_vetrics);

        for (int i = 1; i <= original.n_vetrics; i++) {
            for (auto e : original.G[i]) {
                Edge inv_e(e.to, e.from, e.cap, e.cost, e.rev);
                inverse.add_Edge(inv_e);
            }
        }
    }

    /*
    与えられた有効グラフを復数の強連結成分に分解する。
    帰り値 [vector<int>, vector<int>, ..., vector<int>]
    各vector<int>には、同じ教連結成分に属するノード番号が代入されている。
    */
    vector<vector<int>> SCC(Graph &graph) {
        Graph inverse_graph(graph.n_vetrics);

        //アルゴリズムに強連結成分が必要なので、事前に作成
        __create_Edge_inverse_graph(graph, inverse_graph);

        vector<bool> used(graph.n_vetrics + 1);
        fill(used.begin(), used.end(), false);

        //帰りがけ順に並び替えてノード番号を入れる。
        vector<int> post_order;
        for (int i = 1; i <= graph.n_vetrics; i++) {
            if (!used[i]) __post_order_by_dfs(graph, post_order, used, i);
        }

        reverse(post_order.begin(), post_order.end());

        fill(used.begin(), used.end(), false);
        vector<vector<int>> ret;
        for (auto i : post_order) {
            if (!used[i]) {
                vector<int> inv_post_order;
                __post_order_by_dfs(inverse_graph, inv_post_order, used, i);
                ret.push_back(inv_post_order);
                for (auto s : inv_post_order) {
                    // cout << s << " ";
                }
                // cout << endl;
            }
        }
        return ret;
    }

    /*
        帰りがけ順で各ノードに番号をつける。
        引数のpost_order(vector<int>) に帰りがけの順番でノード番号を入れていく。
        つまり、post_order = [(帰りがけ順で一番目のノード), (帰りがけ順で2番目のノード), ..., (帰りがけ順でn番目のノード)]

        target_point: ノード番号、[1, graph.n_vetrics]の範囲で指定
    */
    void __post_order_by_dfs(Graph &graph, vector<int> &post_order, vector<bool> &used, int target_point) {
        used[target_point] = true;

        for (auto e : graph.G[target_point]) {
            if (!used[e.to]) {
                __post_order_by_dfs(graph, post_order, used, e.to);
            }
        }
        post_order.push_back(target_point);
    }

};  // namespace SCC


namespace Kruskal {

    // Graph class形式のデータを与えて、その最小全域木を返す。
    // 無向グラフを想定しており、有効グラフは想定していない。
    //
    // [使用方法]
    // Kruskal::add_Edge(g, a, b, c);
    // Graph min_tree = Kruskal::Kruskal(g);


    void add_Edge(Graph &g, int from, int to, int cost) {
        Edge e(from, to, 0, cost, 0);
        Edge inv_e(to, from, 0, cost, 0);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }


    class __Union_Find {
      private:
        int *par;
        int *rank;

      public:
        __Union_Find(int size) {
            par = new int[size];
            rank = new int[size];

            for (int i = 0; i < size; i++) {
                par[i] = i;
                rank[i] = 0;
            }
        }

        ~__Union_Find() {
            delete par;
            delete rank;
        }

        int root(int x) {
            if (par[x] == x) {
                return x;
            } else {
                par[x] = root(par[x]);
                return par[x];
            }
        }

        void unite(int x, int y) {
            x = root(x);
            y = root(y);

            if (x == y) return;

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else {
                par[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }

        bool same(int x, int y) {
            return root(x) == root(y);
        }
    };


    bool edge_cost_comparator(const Edge &x, const Edge &y) {
        if (x.cost != y.cost) {
            return x.cost < y.cost;
        } else if (x.from != y.from) {
            return x.from < y.from;
        } else if (x.to != y.to) {
            return x.to < y.to;
        } else {
            return true;
        }
    }


    Graph Kruskal(Graph &g) {
        Graph ret_g(g.n_vetrics);
        __Union_Find uft(g.n_vetrics + 1);

        // used[min_edge.from] = true;

        vector<Edge> edge_lists;

        rep(i, 1, g.n_vetrics) {
            for (Edge e : g.G[i]) {
                edge_lists.push_back(e);
            }
        }

        sort(edge_lists.begin(), edge_lists.end(), edge_cost_comparator);

        rep(i, 0, edge_lists.size() - 1) {
            Edge e = edge_lists[i];
            if (!uft.same(e.from, e.to)) {
                add_Edge(ret_g, e.from, e.to, e.cost);
                uft.unite(e.from, e.to);
            }
        }
        return ret_g;
    }

}  // namespace Kruskal

namespace Prim {
    // Graph class形式のデータを与えて、その最小全域木を返す。
    // 無向グラフを想定しており、有効グラフは想定していない。
    //
    // [使用方法]
    // Kruskal::add_Edge(g, a, b, c);
    // Graph min_tree = Kruskal::Kruskal(g);


    void add_Edge(Graph &g, int from, int to, int cost) {
        Edge e(from, to, 0, cost, 0);
        Edge inv_e(to, from, 0, cost, 0);
        g.add_Edge(e);
        g.add_Edge(inv_e);
    }


    bool edge_cost_comparator(const Edge &x, const Edge &y) {
        // return x.cost > y.cost;
        if (x.cost != y.cost) {
            return x.cost > y.cost;
        } else if (x.from != y.from) {
            return x.from > y.from;
        } else if (x.to != y.to) {
            return x.to > y.to;
        } else {
            return true;
        }
    }

    Graph Prim(Graph &g) {
        Graph ret_g(g.n_vetrics);

        // edge_cost_comparator();
        auto compareFunc = [](const Edge &x, const Edge &y) { return edge_cost_comparator(x, y); };
        typedef priority_queue<Edge, vector<Edge>, decltype(compareFunc)> pq;
        pq que(compareFunc);


        int initial_target_node = 1;

        for (Edge &e : g.G[initial_target_node]) {
            que.push(e);
        }
        // cout << que.top().cost << endl;
        // que.pop();
        // cout << que.top().cost << endl;


        vector<bool> used(g.n_vetrics + 1);
        used[initial_target_node] = true;

        int connection = 0;
        while (!que.empty()) {
            const Edge e = que.top();
            que.pop();

            if (used[e.to]) {
                continue;
            }

            add_Edge(ret_g, e.from, e.to, e.cost);
            used[e.to] = true;


            for (Edge next_e : g.G[e.to]) {
                if (!used[next_e.to]) {
                    que.push(next_e);
                }
            }

            connection++;
            if (g.n_vetrics == connection) {
                break;
            }
        }


        return ret_g;
    }

}  // namespace Prim


namespace warshall_floyd {

    void add_Edge(Graph &g, int from, int to, int cost) {
        Edge e = Edge(from, to, 0, cost, 0);
        g.add_Edge(e);
    }


    vector<vector<ll>> warshall_floyd(Graph &g) {
        ll LL_MAX_ = 0x7FFFFFFFFFFFFFF;
        vector<vector<ll>> ret(g.n_vetrics + 1, vector<ll>(g.n_vetrics + 1, LL_MAX_));

        rep(i, 1, g.n_vetrics) {
            ret[i][i] = 0;
        }

        rep(i, 1, g.n_vetrics) {
            for (Edge e : g.G[i]) {
                ret[e.from][e.to] = e.cost;
            }
        }


        rep(k, 1, g.n_vetrics) {
            rep(i, 1, g.n_vetrics) {
                rep(j, 1, g.n_vetrics) {
                    if ((ret[i][k] != LL_MAX_) and (ret[k][j] != LL_MAX_)) {
                        ret[i][j] = min(ret[i][j], ret[i][k] + ret[k][j]);
                    }
                }
            }
        }
        return ret;
    }

    bool has_close_circle(vector<vector<ll>> &distance) {
        rep(i, 1, distance.size() - 1) {
            if (distance[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
};  // namespace warshall_floyd