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


    // 区間加算の区間和セグメントツリー
    template <typename T>
    class range_sum_query {

      private:
        int n_leafs;
        int n_data;
        int n_nodes;
        vector<T> nodes;
        T inf = -1;


      public:
        // 1-indexed
        // array: {0, a1, a2, a3, a4, .., an};
        range_sum_query(vector<ll> &array, T worst_val) {

            n_data = array.size();
            inf = worst_val;

            // 完全２部木のため、葉は2のべき乗数
            n_leafs = 1;


            do {
                n_leafs *= 2;
            } while (n_data > n_leafs);


            n_nodes = n_leafs * 2 - 1;

            nodes.resize(n_nodes + 1);
            fill(nodes.begin(), nodes.end(), inf);

            for (int i = 1; i < n_data; i++) {
                nodes[n_leafs + i - 1] = array[i];
            }
            for (int i = n_leafs - 1; i >= 1; i--) {
                nodes[i] = comparator(nodes[2 * i + 1], nodes[2 * i]);
            }
        }

        void update(int idx, T value) {
            idx += n_leafs - 1;
            nodes[idx] = value;

            while (idx > 1) {
                idx /= 2;
                nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
            }
        }

        void add(int idx, T value) {
            idx += n_leafs - 1;
            nodes[idx] += value;

            while (idx > 1) {
                idx /= 2;
                nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
            }
        }

        T comparator(T one, T two) {
            return min(one, two);
            // return min(one, two);
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

            // 完全に覆いかぶさっている場合
            if ((from < a) && (b < to)) {
                return nodes[idx];
            }

            if (a == b) {
                return nodes[idx];
            }


            T vl = __query(from, to, idx * 2, a, (a + b) / 2);
            T vr = __query(from, to, idx * 2 + 1, (a + b) / 2 + 1, b);
            return comparator(vl, vr);
        }

        void display_nodes() {
            for (auto s : nodes) {
                cout << s << " ";
            }
            cout << endl;
        }
    };


    template <typename T>
    class range_min_query {

      private:
        int n_leafs;
        int n_data;
        int n_nodes;
        vector<T> nodes;
        T inf = -1;


      public:
        // 1-indexed
        // array: {0, a1, a2, a3, a4, .., an};
        range_min_query(vector<ll> &array, T worst_val) {

            n_data = array.size();
            inf = worst_val;

            // 完全２部木のため、葉は2のべき乗数
            n_leafs = 1;


            do {
                n_leafs *= 2;
            } while (n_data > n_leafs);


            n_nodes = n_leafs * 2 - 1;

            nodes.resize(n_nodes + 1);
            fill(nodes.begin(), nodes.end(), inf);

            for (int i = 1; i < n_data; i++) {
                nodes[n_leafs + i - 1] = array[i];
            }
            for (int i = n_leafs - 1; i >= 1; i--) {
                nodes[i] = comparator(nodes[2 * i + 1], nodes[2 * i]);
            }
        }

        void update(int idx, T value) {
            idx += n_leafs - 1;

            nodes[idx] = value;

            while (idx > 1) {
                idx /= 2;
                nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
            }
        }

        void add(int idx, T value) {
            idx += n_leafs - 1;
            nodes[idx] += value;

            while (idx > 1) {
                idx /= 2;
                nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
            }
        }

        T comparator(T one, T two) {
            return one + two;
            // return min(one, two);
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

            // 完全に覆いかぶさっている場合
            if ((from < a) && (b < to)) {
                return nodes[idx];
            }

            if (a == b) {
                return nodes[idx];
            }


            T vl = __query(from, to, idx * 2, a, (a + b) / 2);
            T vr = __query(from, to, idx * 2 + 1, (a + b) / 2 + 1, b);
            return comparator(vl, vr);
        }

        void display_nodes() {
            for (auto s : nodes) {
                cout << s << " ";
            }
            cout << endl;
        }
    };

}  // namespace segment_tree


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
namespace BIT {

    typedef long long ll;


    class BIT {
      private:
        int n_leafs;
        int n_data;
        vector<ll> array;

      public:
        BIT(int n) {
            n_leafs = 1;
            n_data = n;
            while (n_leafs < n_data) {
                n_leafs *= 2;
            }
            array.resize(n_leafs);
            fill(array.begin(), array.end(), 0);
        }

        // 1-indexed
        // a[0] + a[1] + ... + a[i]を返す
        ll __sum_sub(int i) {
            if (i == 0) return 0;
            ll s = 0;
            for (int k = i; k > 0; k -= (k & -k)) {
                s += array[k];
            }
            return s;
        }

        // 1-indexed
        // a[from] + a[1] + ... + a[to]を返す
        ll sum(int from, int to) {
            return __sum_sub(to) - __sum_sub(from - 1);
        }

        // 1-indexed
        void add(int i, ll x) {
            if (i == 0) return;

            for (int k = i; k <= n_leafs; k += (k & -k)) {
                array[k] += x;
            }
        }
    };


};  // namespace BIT
