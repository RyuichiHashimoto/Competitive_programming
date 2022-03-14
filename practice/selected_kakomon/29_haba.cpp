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

typedef pair<int, int> q;
int main(void) {

    int N, M;

    int sy, sx, gy, gx;

    cin >> N >> M;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<string> map(N);

    rep(i, 1, N) {
        cin >> map[i - 1];
    }

    queue<P> que;
    que.push(P{sy, sx});
    vector<vector<int>> ret(N);
    int worst = 100000000;

    rep(i, 1, N) {
        ret[i - 1].resize(M);
        fill(ret[i - 1].begin(), ret[i - 1].end(), worst);
    }
    ret[sy][sx] = 0;


    while (!que.empty()) {
        P p = que.front();
        que.pop();

        int y = p.first;
        int x = p.second;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        rep(i, 0, 3) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;

            if (tx >= M || tx < 0) {
                continue;
            }
            if (ty >= N || ty < 0) {
                continue;
            }


            if (ret[ty][tx] == worst && map[ty][tx] == '.') {

                ret[ty][tx] = ret[y][x] + 1;
                que.push(P{ty, tx});
            }
            if (ty == gy and tx == gx) {
                break;
            }
        }
    }

    cout << ret[gy][gx] << endl;
}