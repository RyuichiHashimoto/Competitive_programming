#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1E5;


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
int ID_counter = 1;
template <typename T>
void dfs(tree::tree<T> &tree, int target_node, vector<vector<int>> &zahyo) {
    if (tree.child_n_nodes[target_node] == 0) {
        zahyo[target_node][0] = ID_counter;
        zahyo[target_node][1] = ID_counter;
        ID_counter++;
        // cout << target_node << " " << zahyo[target_node][1];
        return;
    }
    for (int id : tree.nodes[target_node].childlen) {
        // cout << id << endl;
        dfs(tree, id, zahyo);
    }

    bool initial_flag = true;
    int l, r;
    for (int id : tree.nodes[target_node].childlen) {

        if (initial_flag) {
            l = zahyo[id][0];
            r = zahyo[id][1];
            initial_flag = false;
        } else {
            l = min(zahyo[id][0], l);
            r = max(zahyo[id][1], r);
        }
    }
    zahyo[target_node][0] = l;
    zahyo[target_node][1] = r;
}


int main(void) {
    int N;
    cin >> N;

    tree::tree<vector<ll>> tree(N);
    vector<vector<int>> relations(N + 1);
    vector<vector<int>> zahyo(N + 1);

    int a, b;

    rep(i, 1, N) {
        zahyo[i].resize(2);
        cin >> a >> b;
        relations[a].push_back(b);
        relations[b].push_back(a);
    }
    tree::connect_nodes(tree, 1, relations);
    calc_child_size(tree, 1);
    dfs(tree, 1, zahyo);


    rep(i, 1, N) {
        cout << zahyo[i][0] << " " << zahyo[i][1] << endl;
    }
}