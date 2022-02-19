#include <bits/stdc++.h>

#include <iostream>

using namespace std;

typedef long long ll;


namespace tree {
    struct node {
        int id;
        int parent;
        vector<int> childlen;
    };

    template <typename T>
    class tree {
      public:
        vector<node> nodes;
        vector<T> values;
        int root_node = -1;
        int n_nodes;

        tree(int _n_nodes) {
            n_nodes = _n_nodes;
            nodes.resize(n_nodes + 1);
            values.resize(n_nodes + 1);
        }

        void set_value(int idx, T value) { values[idx] = value; }

        T get_value(int idx) { return values[idx]; }
    };


    template <typename T>
    void __dfs__for_connect_node(tree<T> &tree, int target_node, vector<vector<int>> &relations, vector<bool> &used) {

        used[target_node] = true;


        for (int idx : relations[target_node]) {
            if (used[idx]) { continue; }

            tree.nodes[target_node].childlen.push_back(idx);
            tree.nodes[idx].parent = target_node;
            __dfs__for_connect_node(tree, idx, relations, used);
        }
    }

    template <typename T>
    vector<int> get_leaf_nodes(tree<T> &tree) {
        vector<int> ret;

        for (node &n : tree.nodes) {
            if ((int)n.childlen.size() == 0) { ret.push_back(n.id); }
        }
        return ret;
    }

    template <typename T>
    void connect_nodes(tree<T> &tree, int root_node_id, vector<vector<int>> &relations) {
        tree.root_node = root_node_id;

        tree.nodes[root_node_id].parent = -1;
        vector<bool> used(tree.n_nodes + 1);
        fill(used.begin(), used.end(), false);

        __dfs__for_connect_node(tree, root_node_id, relations, used);
    }

};  // namespace tree

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
            if (rank[x] == rank[y]) { rank[x]++; }
        }
    }

    bool same(int x, int y) { return root(x) == root(y); }
};

namespace segment_tree {

    typedef long long ll;

    class range_max {
      private:
        vector<ll> dat;    // segment tree本体
        vector<ll> cache;  // キャッシュ

        int n_leafs;  //最終ノードの数
                      //(完全２部木のため、n_leafsは2の累乗個作成し)
        int n_data;   // データ数
        const ll WORST_VALUE = 0x8000000000000000;

        ll compare(ll a, ll b) { return max(a, b); }

        /*
                キャッシュの情報をk番目のノードに代入する。
                キャッシュの情報をsegment treeに
            */
        void push(int k) {
            // 葉以外のノードを指定した場合、
            if (k < n_leafs) {
                cache[2 * k + 1] = compare(cache[k], cache[k * 2 + 1]);
                cache[2 * k + 2] = compare(cache[k], cache[k * 2 + 2]);
            }
            dat[k] = compare(cache[k], dat[k]);
            cache[k] = 0;
        }

        /*
                [left, right)の範囲を値xで塗り替える。

            */
        void __update(int left, int right, ll x, int k, int l, int r) {
            push(k);

            //更新範囲にかすってもいない場合、何もしない。
            if (r <= left || right <= l) { return; }

            //現在見ている範囲[l, r]が更新範囲を完全に覆っている場合
            if (left <= l && r <= right) {
                cache[k] = x;
                push(k);
                return;
            }

            __update(left, right, x, 2 * k + 1, l, (l + r) >> 1);
            __update(left, right, x, 2 * k + 2, (l + r) >> 1, r);
            dat[k] = compare(dat[k * 2 + 1], dat[2 * k + 2]);
        }

        /*
            完全2部木のルートノードから順に見て、[left,
           right)の範囲で最良値を求める。

            k：節点の番号
            [l , r): その節点を見ている範囲
        */
        ll __query(int left, int right, int k, int l, int r) {
            push(k);
            if (left >= r || right <= l) { return WORST_VALUE; }
            if (left <= l && r <= right) {
                return dat[k];
            } else {
                ll vl = __query(left, right, k * 2 + 1, l, (l + r) >> 1);
                ll vr = __query(left, right, k * 2 + 2, (l + r) >> 1, r);
                return compare(vl, vr);
            }
        }

      public:
        void init(int N) {
            n_leafs = 1;
            n_data = N;

            while (n_leafs < n_data) { n_leafs *= 2; }
            dat.resize(2 * n_leafs);
            cache.resize(2 * n_leafs);
        }

        segment_tree_for_maximum() {
            dat.clear();
            cache.clear();
        }

        /*
                [left,right)の最良値を返す。
            */
        ll query(int left, int right) { return __query(left, right, 0, 0, n_leafs); }

        /*
                [left,right)の最良値を返す。
            */
        ll query(int left, int right) { return __query(left, right, 0, 0, n_leafs); }
        /*
                [left,right)の要素をxにする。
            */
        void update(int left, int right, ll x) { return __update(left, right, x, 0, 0, n_leafs); }
    };
}  // namespace segment_tree