#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <queue>
using namespace std;

typedef unsigned long long ll;


#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

const int MAX_N = 1E5;

template <typename T>
vector<T> compress(vector<T> &X) {

    vector<T> vals = X;

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < (int)vals.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

template <typename T>
struct pair_greater {
    bool f_greater = false;
    bool s_greater = false;
    bool f_priority = true;

    constexpr bool operator()(const T &x, const T &y) const {
        if (f_priority) {
            if (x.first != y.first) {
                return (f_greater) == (x.first > y.first);
            } else {
                return (s_greater) == (x.second > y.second);
            }
        } else {
            if (x.second != y.second) {
                return (s_greater) == (x.second > y.second);
            } else {
                return (f_greater) == (x.first > y.first);
            }
        }
    };
};


class Edge {
  public:
    int from;  // start of anEdge.
    int to;    // end of anEdge.
    int cap;   // the capacity for pass through
    int cost;  // the cost to pass through (for finding the minimum cost flow)
    int rev;   // the index of the inverseEdge.

    Edge(int _from, int _to) {
        from = _from;
        to = _to;
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

typedef pair<int, int> P;


int main(void) {


    int H, W, N;
    int start_x, start_y, goal_x, goal_y;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int tmp1, tmp2;


    cin >> H >> W >> N;
    cin >> start_x >> start_y >> goal_x >> goal_y;

    vector<P> zahyo;
    map<P, int> id;
    map<int, map<int, int>> stone;
    map<int, map<int, int>> u;

    P start_p = P{start_x, start_y};
    P goal_p = P{goal_x, goal_y};
    zahyo.push_back(start_p);
    zahyo.push_back(goal_p);

    u[start_x][start_y] = 1;
    u[goal_x][goal_y] = 1;


    rep(i, 1, N) {
        cin >> tmp1 >> tmp2;
        stone[tmp1][tmp2] = 1;
        rep(k, 0, 3) {
            int x_cand = tmp1 + dx[k];
            int y_cand = tmp2 + dy[k];
            bool x_isin = (x_cand >= 1) && (x_cand <= H);
            bool y_isin = (y_cand >= 1) && (y_cand <= W);
            if (x_isin and y_isin) {
                if (u[x_cand][y_cand] == 0) {
                    zahyo.push_back(P{x_cand, y_cand});
                    u[x_cand][y_cand] = 1;
                }
            }
        }
    }


    rep(i, 0, (int)zahyo.size() - 1) {
        id[zahyo[i]] = i + 1;
    }

    int com_N = zahyo.size();
    vector<P> original_zahyo = zahyo;
    Graph graph(com_N);

    pair_greater<P> com;
    com.f_priority = true;
    com.f_greater = false;
    com.s_greater = false;

    sort(zahyo.begin(), zahyo.end(), com);
    rep(i, 0, com_N - 1) {
        // cout << zahyo[i].first << " " << zahyo[i].second << endl;
    }


    rep(i, 0, com_N - 1) {

        int j = 1;
        // cout << "target_" << zahyo[i].first << " " << zahyo[i].second << endl;
        bool find_stone_flag = false;
        while (!find_stone_flag && (i + j < zahyo.size()) && (zahyo[i].first == zahyo[i + j].first)) {

            int x = zahyo[i + j].first;
            int y = zahyo[i + j].second + 1;
            // cout << x << " " << y << endl;

            if (stone[x][y] == 1) {
                int from_id = id[zahyo[i]];
                int to_id = id[zahyo[i + j]];
                Edge e(from_id, to_id);
                Edge inv_e(to_id, from_id);
                graph.add_Edge(e);
                // graph.add_Edge(inv_e);


                find_stone_flag = true;
                // cout << "sss" << endl;
                // cout << zahyo[i].first << " " << zahyo[i].second << " " << zahyo[i + j].first << " " << zahyo[i + j].second << endl;
            }
            j++;
        }


        j = 1;
        // cout << "target_" << zahyo[i].first << " " << zahyo[i].second << endl;
        find_stone_flag = false;
        while (!find_stone_flag && (i - j >= 0) && zahyo[i].first == zahyo[i - j].first) {

            int x = zahyo[i - j].first;
            int y = zahyo[i - j].second - 1;
            // cout << x << " " << y << endl;

            if (stone[x][y] == 1) {
                int from_id = id[zahyo[i]];
                int to_id = id[zahyo[i - j]];
                Edge e(from_id, to_id);
                Edge inv_e(to_id, from_id);
                graph.add_Edge(e);
                // graph.add_Edge(inv_e);
                find_stone_flag = true;
            }
            j++;
        }
    }


    com.f_priority = false;
    com.f_greater = false;
    com.s_greater = false;
    sort(zahyo.begin(), zahyo.end(), com);

    rep(i, 0, com_N - 1) {

        int j = 1;
        // cout << "target_" << zahyo[i].first << " " << zahyo[i].second << endl;
        bool find_stone_flag = false;
        while (!find_stone_flag && (i + j < zahyo.size()) && (zahyo[i].second == zahyo[i + j].second)) {

            int x = zahyo[i + j].first + 1;
            int y = zahyo[i + j].second;
            // cout << x << " " << y << endl;

            if (stone[x][y] == 1) {
                int from_id = id[zahyo[i]];
                int to_id = id[zahyo[i + j]];
                Edge e(from_id, to_id);
                Edge inv_e(to_id, from_id);
                graph.add_Edge(e);
                // graph.add_Edge(inv_e);


                find_stone_flag = true;
            }
            j++;
        }


        j = 1;
        find_stone_flag = false;
        while (!find_stone_flag && (i - j >= 0) && (zahyo[i].second == zahyo[i - j].second)) {

            int x = zahyo[i - j].first - 1;
            int y = zahyo[i - j].second;
            // cout << x << " " << y << endl;

            if (stone[x][y] == 1) {
                int from_id = id[zahyo[i]];
                int to_id = id[zahyo[i - j]];
                Edge e(from_id, to_id);
                Edge inv_e(to_id, from_id);
                graph.add_Edge(e);
                // graph.add_Edge(inv_e);
                find_stone_flag = true;
            }
            j++;
        }
    }


    vector<bool> used(zahyo.size() + 1);
    vector<int> distance(zahyo.size() + 1);
    queue<int> que;
    fill(used.begin(), used.end(), false);
    fill(distance.begin(), distance.end(), -1);

    int n = zahyo.size();


    int start_id = id[start_p];
    int goal_id = id[goal_p];

    que.push(start_id);
    distance[start_id] = 0;
    used[start_id] = true;

    bool find_flag = false;

    while (!que.empty()) {
        int current_id = que.front();
        que.pop();
        // cout << "current: " << original_zahyo[current_id - 1].first << " " << original_zahyo[current_id - 1].second << endl;

        for (auto e : graph.G[current_id]) {
            int tmp = e.to;

            if (used[tmp] == false) {
                used[tmp] = true;
                distance[tmp] = distance[current_id] + 1;

                // que.push(tmp);
                // cout << "tmp";
                que.push(tmp);
                // cout << "            add: " << original_zahyo[tmp - 1].first << " " << original_zahyo[tmp - 1].second << endl;


                if (tmp == goal_id) {
                    queue<int>().swap(que);
                    break;
                }
            }
        }
    }
    if (distance[goal_id] == -1) {
        cout << "No" << endl;
    } else {
        cout << distance[goal_id] << endl;
    }
}