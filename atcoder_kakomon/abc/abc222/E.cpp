#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
typedef pair<ll, ll> P;


class Union_Find {
  private:
    int *par;
    int *rank;

  public:
    Union_Find(int size) {
        par = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    ~Union_Find() {
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


bool check_lines(ll _x, ll _y, ll A, ll B, ll C) {
    ll x = _x;
    ll y = _y;

    int no_flag = 0;
    ll rest = x;

    if (A <= rest * y) {
        ll height = (A + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }

    if (B <= rest * y) {
        ll height = (B + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }

    if (C <= rest * y) {
        ll height = (C + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }


    return no_flag == 0;
}

bool check_two(ll _x, ll _y, ll A, ll B, ll C) {
    ll x = _x;
    ll y = _y;

    int no_flag = 0;
    ll rest = x;

    if (A <= rest * y) {
        ll height = (A + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }

    swap(rest, y);

    if (B <= rest * y) {
        ll height = (B + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }

    if (C <= rest * y) {
        ll height = (C + y - 1) / y;
        rest -= height;
    } else {
        no_flag = 1;
    }
    return no_flag == 0;
}

int main() {
    ll x, y, A, B, C;

    cin >> x >> y >> A >> B >> C;

    if (x > y) {
        swap(x, y);
    }


    if (check_lines(x, y, A, B, C)) {
        cout << "Yes" << endl;
        return 0;
    }
    // return 1;

    if (check_lines(y, x, A, B, C)) {
        cout << "Yes" << endl;
        return 0;
    }


    if (check_two(x, y, A, B, C)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(x, y, A, C, B)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (check_two(x, y, B, A, C)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(x, y, B, C, A)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (check_two(x, y, C, A, B)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(x, y, C, B, A)) {
        cout << "Yes" << endl;
        return 0;
    }


    if (check_two(y, x, A, B, C)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(y, x, A, C, B)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (check_two(y, x, B, A, C)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(y, x, B, C, A)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (check_two(y, x, C, A, B)) {
        cout << "Yes" << endl;
        return 0;
    }
    if (check_two(y, x, C, B, A)) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}