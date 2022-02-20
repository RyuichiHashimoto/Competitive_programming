
int main(void) {
    int N, Q;

    cin >> N >> Q;
    vector<int> X(N + 1);

    rep(i, 1, N) { cin >> X[i]; }

    int a, b;
    Graph graph(N);
    rep(i, 0, N - 2) {
        cin >> a >> b;
        edge e(a, b, i);
        edge rev_e(b, a, i);

        graph.add_edge(e);
        graph.add_edge(rev_e);
    }

    queue<int> que;
    bool used[MAX_N + 1];
    fill(used, used + MAX_N, false);

    rep(i, 2, N) {
        if (graph.get_rank(i) == 1) {
            used[i] = true;
            que.push(i);
        }
        // cout << i<<" " << graph.get_rank(i)<<endl;
    }

    fill(used, used + MAX_N, false);
    vector<int> leafs = find_leaf_nodes::find_leaf_nodes(graph, 1);
    vector<int> parents = find_parents::find_parents(graph, 1);

    for (auto i : leafs) { cout << i << endl; }


    int find_time[MAX_N + 1];

    fill(used, used + MAX_N, false);
    fill(find_time, find_time + MAX_N, 0);

    while (!que.empty()) {
        int id = que.front();
        que.pop();
        target_list[id].push_back(X[id]);


        if (id != 1) {
            int paremt = parents[id];
            // target_list[paremt].insert(target_list[paremt].end(),target_list[id].begin(),target_list[id].end());
            find_time[paremt]++;

            if ((paremt != 1) && (find_time[paremt] == graph.G[paremt].size() - 1)) {
                que.push(paremt);
            } else if ((paremt == 1) && (find_time[paremt] == graph.G[paremt].size())) {
                que.push(paremt);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        // sort(target_list[i].begin(),target_list[i].end(),greater<int>());
    }

    rep(i, 1, Q) {
        int a, b;
        cin >> a >> b;
        // cout << a << b<<endl;
        cout << target_list[i][b - 1] << endl;
    }
}