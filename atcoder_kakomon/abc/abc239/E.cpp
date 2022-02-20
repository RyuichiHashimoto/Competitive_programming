#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1E5;


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

    template <typename T>
    void connect_nodes(tree<T> &tree, int root_node_id, vector<vector<int>> &relations) {
        tree.root_node = root_node_id;

        tree.nodes[root_node_id].parent = -1;
        vector<bool> used(tree.n_nodes + 1);
        fill(used.begin(), used.end(), false);

        __dfs__for_connect_node(tree, root_node_id, relations, used);
    }

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

    template <typename T>
    void __dfs__for_child_size(tree<T> &tree, int target_node) {
    }


};  // namespace tree


int main(void) {
    int N, Q;
    vector<vector<int>> target_list;

    cin >> N >> Q;
    vector<int> X(N + 1);

    rep(i, 1, N) {
        cin >> X[i];
    }

    int a, b;
    vector<vector<int>> relations(N + 1);

    rep(i, 0, N - 2) {
        cin >> a >> b;
        relations[a].push_back(b);
        relations[b].push_back(a);
    }
    tree::tree<vector<ll>> tree(N);

    tree::connect_nodes(tree, 1, relations);

    tree::calc_child_size(tree, 1);
    vector<int> leafs = tree::get_leaf_nodes(tree);


    vector<int> current_idx(N + 1);
    vector<int> find_time(N + 1);

    target_list.resize(N + 1);

    rep(i, 1, N) {
        find_time[i] = 0;
        current_idx[i] = 0;
        target_list[i].resize(21);
    }


    queue<int> que;

    for (int a : leafs) {
        que.push(a);
    }


    while (!que.empty()) {
        int id = que.front();
        que.pop();


        vector<int> idx_child(tree.nodes[id].childlen.size());
        fill(idx_child.begin(), idx_child.end(), 0);

        bool current_node_used_flag = false;
        int current_node_val = X[id];


        rep(i, 0, 19) {
            int idx_child_max = -1;
            int max_val = -1;

            for (int ch_i = 0; ch_i < idx_child.size(); ch_i++) {
                int child_num = tree.nodes[id].childlen[ch_i];

                if (idx_child[ch_i] == target_list[child_num].size()) {
                    continue;
                }

                if (max_val < target_list[child_num][idx_child[ch_i]]) {
                    max_val = target_list[child_num][idx_child[ch_i]];
                    idx_child_max = ch_i;
                }
            }

            if (!current_node_used_flag && max_val < current_node_val) {
                current_node_used_flag = true;
                max_val = current_node_val;
                idx_child_max = 0;
            } else {
                if (idx_child_max != -1) {
                    idx_child[idx_child_max]++;
                }
            }
            if (idx_child_max == -1) {
                break;
            }

            target_list[id][i] = max_val;
        }


        int parent_id = tree.nodes[id].parent;

        if (parent_id == -1) {
            continue;
        }
        find_time[parent_id]++;


        if (find_time[parent_id] == (int)tree.nodes[parent_id].childlen.size()) {

            que.push(parent_id);
        }
    }

    rep(i, 1, Q) {
        int a, b;
        cin >> a >> b;
        cout << target_list[a][b - 1] << endl;
    }
}