#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1E5;


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