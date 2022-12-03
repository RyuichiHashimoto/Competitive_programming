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
        vector<int> depth;
        vector<int> child_n_nodes;
        int root_node = -1;
        int n_nodes;

        tree(int _n_nodes) {
            n_nodes = _n_nodes;
            nodes.resize(n_nodes + 1);
            values.resize(n_nodes + 1);
            child_n_nodes.resize(n_nodes + 1);
            depth.resize(n_nodes + 1);


            for (int i = 0; i < n_nodes + 1; i++) {
                nodes[i].id = i;
            }

            fill(child_n_nodes.begin(), child_n_nodes.end(), -1);
            fill(depth.begin(), depth.end(), -1);
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
            tree.depth[idx] = tree.depth[target_node] + 1;
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
        tree.depth[root_node_id] = 0;
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


    /*
        指定したノードから、他の全ノードへの距離をBFSで探索して返す関数

        計算量：
            O(E), *Eはエッジ数

        @param:
            tree: 木構造(親子関係：指定済)

            target_node: 始点ノード

        使用例：
            tree::calc_child_size(tree, root_node_id);
    */
    template <typename T>
    vector<ll> calc_distance(tree<T> &tree, int target_node) {
        vector<ll> ret(tree.n_nodes + 1, 0);
        vector<bool> used(tree.n_nodes + 1, 0);

        used[target_node] = true;
        ret[target_node] = 0;

        queue<int> que;
        que.push(target_node);


        while (!que.empty()) {
            int node_id = que.front();
            que.pop();
            int parent_id = tree.nodes[node_id].parent;

            if (!(parent_id == -1) and !used[parent_id]) {
                que.push(parent_id);
                ret[parent_id] = ret[node_id] + 1;
                used[parent_id] = true;
            }

            for (auto c : tree.nodes[node_id].childlen) {
                if (!used[c]) {
                    ret[c] = ret[node_id] + 1;
                    used[c] = true;
                    que.push(c);
                }
            }
        }
        return ret;
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


namespace segtree {

    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

    template <class S, S (*op)(S, S), S (*e)()>
    struct segtree {
      private:
        int _n, size, log;
        std::vector<S> d;
        void update(int k) {
            d[k] = op(d[2 * k], d[2 * k + 1]);
        }

      public:
        segtree() : segtree(0) {
        }
        explicit segtree(int n) : segtree(std::vector<S>(n, e())){};
        explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
            log = ceil_pow2(_n);
            size = 1 << log;

            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }

        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }

        // [l, r)
        S prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;

            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        S all_prod() const {
            return d[1];
        }
    };

}  // namespace segtree


namespace lazySegmentTree {


    // 区間加算の区間和セグメントツリー
    class sum_add_tree {

      private:
        int n_leafs;
        int n_data;
        int n_nodes;
        vector<ll> nodes;
        vector<ll> lazys;
        ll inf = -1;


      public:
        // 1-indexed
        // array: {-1, a1, a2, a3, a4, .., an};
        sum_tree(vector<ll> &array, ll worst_val) {

            n_data = array.size();
            inf = worst_val;

            // 完全２部木のため、葉は2のべき乗数
            n_leafs = 1;
            while (n_data > n_leafs) {
                n_leafs *= 2;
            }


            n_nodes = n_leafs * 2 - 1;

            nodes.resize(n_nodes + 1);
            lazys.resize(n_nodes + 1, 0);
            fill(nodes.begin(), nodes.end(), inf);

            for (int i = 1; i < n_data; i++) {
                nodes[n_leafs + i - 1] = array[i];
            }
            for (int i = n_leafs - 1; i >= 1; i--) {
                nodes[i] = comparator(nodes[2 * i + 1], nodes[2 * i]);
            }
        }


        void __add(int from, int to, ll val, int idx, int l, int r) {
            // cout << "start: " << from << " " << to << " " << val << " " << idx << " " << l << " " << r << endl;

            // 遅延情報を更新する。
            eval(idx);

            // 全く重なっていない場合、何もしない。
            if (from > r || to < l) {
                return;
            }


            // 完全に覆いかぶさっている場合
            if ((from <= l) && (r <= to)) {
                lazys[idx] += (r - l + 1) * val;

                eval(idx);  // このタイミングで遅延情報がnodeに保存される。
            } else {
                __add(from, to, val, 2 * idx, l, (l + r) / 2);
                __add(from, to, val, 2 * idx + 1, (r + l) / 2 + 1, r);
                nodes[idx] = nodes[2 * idx] + nodes[2 * idx + 1];
            }
        }

        // [from, to]のノードに対して値valを代入する。
        void add(int from, int to, ll val) {
            __add(from, to, val, 1, 1, n_leafs);
        }


        // k番目のノードに関して、遅延評価を行う。
        void eval(int k) {

            if (lazys[k] != 0) {
                nodes[k] += lazys[k];

                if (!__is_leaf_node(k)) {
                    lazys[2 * k + 1] += lazys[k] / 2;
                    lazys[2 * k] += lazys[k] / 2;
                }
                lazys[k] = 0;
            }
        }

        // 引数で指定した番号のノードが葉であるか否か
        //
        // arg:
        //    int k: ノード番号
        //  return:
        //      True: 葉ノード
        //      False: 　葉ノードでない。
        bool __is_leaf_node(int k) {
            return (n_leafs <= k) && (2 * n_leafs - 1 >= k);
        }

        //
        ll comparator(ll one, ll two) {
            return one + two;
        }

        // [from, to]間で最適のものを抽出する。
        ll query(int from, int to) {
            return __query(from, to, 1, 1, n_leafs);
        }


        ll __query(int from, int to, int idx, int a, int b) {
            // 全く重なっていない場合
            if (from > b || to < a) {
                return inf;
            }
            eval(idx);

            // 完全に覆いかぶさっている場合
            if ((from < a) && (b < to)) {
                return nodes[idx];
            }

            if (a == b) {
                return nodes[idx];
            }

            ll vl = __query(from, to, idx * 2, a, (a + b) / 2);
            ll vr = __query(from, to, idx * 2 + 1, (a + b) / 2 + 1, b);
            return comparator(vl, vr);
        }

        void display_nodes() {
            for (auto s : nodes) {
                cout << s << " ";
            }
            cout << endl;
        }
        void display_lazys() {
            for (auto s : lazys) {
                cout << s << " ";
            }
            cout << endl;
        }
    };


    template <typename T>
    class min_update_tree {

      private:
        int n_leafs;
        int n_data;
        int n_nodes;
        T inf = 0x7FFFFFFFFFFFFFFF;
        vector<T> nodes;
        vector<T> lazys;
        vector<bool> lazys_flag;

        //
        T comparator(T one, T two) {
            return min(one, two);
        }


      public:
        // 1-indexed
        // array: {-1, a1, a2, a3, a4, .., an};
        LazySegmentTree(vector<T> &array, T worst_val) {

            n_data = array.size();
            inf = worst_val;

            // 完全２部木のため、葉は2のべき乗数
            n_leafs = 1;
            while (n_data > n_leafs) {
                n_leafs *= 2;
            }

            n_nodes = n_leafs * 2 - 1;

            nodes.resize(n_nodes + 1, inf);
            lazys.resize(n_nodes + 1, inf);
            lazys_flag.resize(n_nodes + 1);

            for (int i = 1; i < n_data; i++) {
                nodes[n_leafs + i - 1] = array[i];
            }
            for (int i = n_leafs - 1; i >= 1; i--) {
                nodes[i] = comparator(nodes[2 * i], nodes[2 * i + 1]);
            }
        }


        void __update(int from, int to, T val, int idx, int l, int r) {
            // cout << "start: " << from << " " << to << " " << val << " " << idx << " " << l << " " << r << endl;

            // 遅延情報を更新する。
            eval(idx);

            // 全く重なっていない場合、何もしない。
            if (from > r || to < l) {
                return;
            }

            // 完全に覆いかぶさっている場合
            if ((from <= l) && (r <= to)) {
                lazys[idx] = val;
                lazys_flag[idx] = true;
                eval(idx);  // このタイミングで遅延情報がnodeに保存される。
            } else {
                __update(from, to, val, 2 * idx, l, (l + r) / 2);
                __update(from, to, val, 2 * idx + 1, (r + l) / 2 + 1, r);
                nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
            }
        }

        // [from, to]のノードに対して値valを追加するする。
        void update(int from, int to, T val) {
            __update(from, to, val, 1, 1, n_leafs);
        }

        // k番目のノードに関して、遅延評価を行う。
        void eval(int k) {

            if (!lazys_flag[k]) return;

            if (!__is_leaf_node(k)) {
                if (lazys_flag[k]) {
                    lazys[2 * k] = lazys[2 * k + 1] = lazys[k];
                    lazys_flag[2 * k] = lazys_flag[2 * k + 1] = true;
                }
            }
            nodes[k] = lazys[k];
            lazys[k] = inf;
            lazys_flag[k] = false;
        }

        // 引数で指定した番号のノードが葉であるか否か
        //
        // arg:
        //    int k: ノード番号
        //  return:
        //      True: 葉ノード
        //      False: 　葉ノードでない。
        bool __is_leaf_node(int k) {
            return (n_leafs <= k) && (2 * n_leafs - 1 >= k);
        }

        // [from, to]間で最適のものを抽出する。
        T query(int from, int to) {
            return __query(from, to, 1, 1, n_leafs);
        }


        T __query(int from, int to, int idx, int a, int b) {
            // 全く重なっていない場合
            if (from > b || to < a) {
                return inf;
            }
            eval(idx);

            // 完全に覆いかぶさっている場合
            if ((from < a) && (b < to)) {
                return nodes[idx];
            }

            if (a == b) {
                return nodes[idx];
            }

            ll vl = __query(from, to, idx * 2, a, (a + b) / 2);
            ll vr = __query(from, to, idx * 2 + 1, (a + b) / 2 + 1, b);
            return comparator(vl, vr);
        }

        void display_nodes() {
            for (auto s : nodes) {
                cout << s << " ";
            }
            cout << endl;
        }
        void display_lazys() {
            for (auto s : lazys) {
                cout << s << " ";
            }
            cout << endl;
        }
    };
}  // namespace lazySegmentTree


// binary indexed tree
// 1-indexed
namespace fenwicktree {


    template <class T>
    class fenwicktree {
      private:
        int n_data;
        std::vector<T> array;

        T _internal_sum(int r) {
            T s = 0;
            while (r > 0) {
                s += array[r];
                r -= r & -r;
            }
            return s;
        }


      public:
        fenwicktree(int n) : n_data(n), array(n + 1){};

        // 0-indexed
        void add(int p, T x) {
            assert(1 <= p && p <= n_data);
            while (p <= n_data) {
                array[p] += x;
                p += p & -p;
            }
        }

        // [l, r]のsum
        T sum(int l, int r) {
            assert(1 <= l && l <= r && r <= n_data);
            return _internal_sum(r) - _internal_sum(l - 1);
        }
    };
};  // namespace fenwicktree