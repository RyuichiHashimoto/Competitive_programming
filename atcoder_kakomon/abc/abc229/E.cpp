#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
class Union_Find {
  private:
    int *par;
    int *rank;
    int n_merges;

  public:
    Union_Find(int size) {
        par = new int[size];
        rank = new int[size];
        n_merges = 0;


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


        n_merges++;

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

    int group() {
        return n_merges;
    }
};

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> check(N + 1);
    rep(i, 1, M) {
        int a, b;
        cin >> a >> b;

        int s = min(a, b);
        int d = max(a, b);

        check[s].push_back(d);
    }

    Union_Find tree(N + 1);
    vector<int> ret_list;
    ret_list.push_back(0);
    for (int i = N; i >= 2; i--) {


        for (auto s : check[i]) {
            // cout << "merge:" << i << " " << s << endl;
            tree.unite(s, i);
        }
        ret_list.push_back(N - i + 1 - tree.group());
    }

    reverse(ret_list.begin(), ret_list.end());
    for (auto s : ret_list) {
        cout << s << endl;
    }
}