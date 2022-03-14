#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;


int dfs(vector<vector<int>> &map, int x, int y, int n, int m, vector<vector<bool>> &used) {

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int ret = 0;
    rep(i, 0, 3) {
        if (x + dx[i] >= n or x + dx[i] < 0) {
            continue;
        }
        if (y + dy[i] >= m or y + dy[i] < 0) {
            continue;
        }
        if (!used[x + dx[i]][y + dy[i]] && map[x + dx[i]][y + dy[i]] == 1) {
            used[x + dx[i]][y + dy[i]] = true;
            ret = max(ret, dfs(map, x + dx[i], y + dy[i], n, m, used) + 1);
            used[x + dx[i]][y + dy[i]] = false;
        }
    }
    return ret;
}


int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> ret(N);
    vector<vector<bool>> used(N);
    rep(i, 1, N) {
        ret[i - 1].resize(M);
        used[i - 1].resize(M);
        fill(used[i - 1].begin(), used[i - 1].end(), false);

        rep(j, 1, M) {
            cin >> ret[i - 1][j - 1];
        }
    }

    int max_ = 1;
    rep(i, 0, N - 1) {
        rep(j, 0, M - 1) {
            // cout << i << " " << j << " " << dfs(ret, i, j, N, M, used) << endl;
            max_ = max(max_, dfs(ret, i, j, N, M, used));
        }
    }
    cout << max_ << endl;
}