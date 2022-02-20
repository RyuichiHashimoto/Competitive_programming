#include <bits/stdc++.h>

#include <iostream>

using namespace std;

typedef long long ll;


// 木構造を取り扱うクラス（各ノードには一つ値が代入可能）
//
//   使用例　初期生成：
// 　　 tree::tree<vector<ll>> tree(N);
//　　　vector<vector<int>> relations(N + 1);
//      int a, b;　
//      (前提：ノード番号aとbが結合している)
//
//      rep(i, 1, N) {
//          cin >> a >> b;
//          relations[a].push_back(b);
//          relations[b].push_back(a);
//      }
//      tree::tree<vector<ll>> tree(N);
//      tree::connect_nodes(tree, 1, relations);
//
// 　使用例：id番目の子ノードへのアクセス
//      tree.nodes[id].childlen[ch_i]
//
// 　使用例：id番目の親ノードへのアクセス
// 　   tree.nodes[id].childlen[ch_i]
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
        vector<int> child_n_nodes;
        int root_node = -1;
        int n_nodes;

        tree(int _n_nodes) {
            n_nodes = _n_nodes;
            nodes.resize(n_nodes + 1);
            values.resize(n_nodes + 1);
            child_n_nodes.resize(n_nodes + 1);


            for (int i = 0; i < n_nodes + 1; i++) {
                nodes[i].id = i;
            }

            fill(child_n_nodes.begin(), child_n_nodes.end(), -1);
        }

        void set_value(int idx, T value) {
            values[idx] = value;
        }

        T get_value(int idx) {
            return values[idx];
        }
    };


    template <typename T>
    void __dfs__for_connect_node(tree<T> &tree, int target_node, vector<vector<int>> &relations, vector<bool> &used) {

        used[target_node] = true;


        for (int idx : relations[target_node]) {
            if (used[idx]) {
                continue;
            }

            tree.nodes[target_node].childlen.push_back(idx);
            tree.nodes[idx].parent = target_node;
            __dfs__for_connect_node(tree, idx, relations, used);
        }
    }


    /*
        与えられた木構造の葉ノードの番号を取得

        計算量：
            O(E): Eはエッジ数

        @param:
            tree 木構造

        使用例：
            vector<int> leafs = tree::get_leaf_nodes(tree);
    */
    template <typename T>
    vector<int> get_leaf_nodes(tree<T> &tree) {
        vector<int> ret;

        for (int i = 1; i <= tree.n_nodes; i++) {
            if ((int)tree.nodes[i].childlen.size() == 0) {
                ret.push_back(tree.nodes[i].id);
            }
        }
        return ret;
    }

    /*
        与えられた隣接行列に基づき、木構造の親子関係を決定していく（node.children, node.parentなどを埋めていく）

        計算量：
            O(E), *Eはエッジ数

        @param:
            tree: 木構造

            root_node_id: 木構造の根ノードの番号

            adjacency_matrix: 隣接リスト
                            　内部グラフを持たないことは前提条件（チェックしていない）

        使用例：
            int a, b;
            vector<vector<int>> relations(N + 1);

            rep(i, 0, N - 2) {
                cin >> a >> b;
                relations[a].push_back(b);
                relations[b].push_back(a);
            }
            tree::tree<vector<ll>> tree(N);
            tree::connect_nodes(tree, 1, relations);
    */
    template <typename T>
    void connect_nodes(tree<T> &tree, int root_node_id, vector<vector<int>> &adjacency_matrix) {
        tree.root_node = root_node_id;
        tree.nodes[root_node_id].parent = -1;
        vector<bool> used(tree.n_nodes + 1);
        fill(used.begin(), used.end(), false);

        __dfs__for_connect_node(tree, root_node_id, adjacency_matrix, used);
    }

    /*
        指定したノードの子孫ノードの総数を求める関数（自身のノードはカウントに含めない）
        深さ優先探索で実装。キャッシュ機能あり。
        結果は、treeクラス内部のchild_n_nodesオブジェクトで保管

        計算量：
            O(E), *Eはエッジ数

        @param:
            tree: 木構造(親子関係：指定済)

            target_node: 子孫ノードが知りたい親ノード

        使用例：
            tree::calc_child_size(tree, root_node_id);





    */
    template <typename T>
    void calc_child_size(tree<T> &tree, int target_node) {
        if (tree.child_n_nodes[target_node] != -1) {
            return;
        }

        int sum = 0;
        for (int id : tree.nodes[target_node].childlen) {
            calc_child_size(tree, id);
            sum += tree.child_n_nodes[id] + 1;
        }
        tree.child_n_nodes[target_node] = sum;
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
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
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

        ll compare(ll a, ll b) {
            return max(a, b);
        }

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
            if (r <= left || right <= l) {
                return;
            }

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
            if (left >= r || right <= l) {
                return WORST_VALUE;
            }
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

            while (n_leafs < n_data) {
                n_leafs *= 2;
            }
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
        ll query(int left, int right) {
            return __query(left, right, 0, 0, n_leafs);
        }

        /*
                [left,right)の最良値を返す。
            */
        ll query(int left, int right) {
            return __query(left, right, 0, 0, n_leafs);
        }
        /*
                [left,right)の要素をxにする。
            */
        void update(int left, int right, ll x) {
            return __update(left, right, x, 0, 0, n_leafs);
        }
    };
}  // namespace segment_tree