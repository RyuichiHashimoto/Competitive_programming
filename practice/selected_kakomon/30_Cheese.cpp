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

struct info {
    int x, y, count;
};

int main(void) {

    int H, W, N;

    cin >> H >> W >> N;

    vector<string> map(H);
    rep(i, 1, H) {
        cin >> map[i - 1];
    }

    bool used[1001][1001];

    int position[10][2];


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] - '0' >= 0 && map[i][j] - '0' <= N) {
                position[map[i][j] - '0'][0] = i;
                position[map[i][j] - '0'][1] = j;
            } else if (map[i][j] == 'S') {
                position[0][0] = i;
                position[0][1] = j;
            }
        }
    }


    int sum = 0;
    for (int i = 1; i < N + 1; i++) {
        fill(used[0], used[1001], false);

        int sx = position[i - 1][0];
        int sy = position[i - 1][1];
        int gx = position[i][0];
        int gy = position[i][1];
        // cout << sx << " " << sy << " " << gx << " " << gy << endl;

        queue<info> que;

        que.push(info{sx, sy, 0});

        int ret = 0;
        info in;
        while (!que.empty()) {
            in = que.front();
            que.pop();
            // cout << in.x << " " << in.y << endl;

            if (in.x == gx && in.y == gy) {
                ret = in.count;
                break;
            }

            if (in.x + 1 < H && (!used[in.x + 1][in.y]) && (map[in.x + 1][in.y] != 'X')) {
                used[in.x + 1][in.y] = true;
                que.push(info{in.x + 1, in.y, in.count + 1});
            }

            if (in.x - 1 >= 0 && !used[in.x - 1][in.y] && (map[in.x - 1][in.y] != 'X')) {
                used[in.x - 1][in.y] = true;
                que.push(info{in.x - 1, in.y, in.count + 1});
            }

            if (in.y + 1 < W && !used[in.x][in.y + 1] && (map[in.x][in.y + 1] != 'X')) {
                used[in.x][in.y + 1] = true;
                que.push(info{in.x, in.y + 1, in.count + 1});
            }

            if (in.y - 1 >= 0 && !used[in.x][in.y - 1] && (map[in.x][in.y - 1] != 'X')) {
                used[in.x][in.y - 1] = true;
                que.push(info{in.x, in.y - 1, in.count + 1});
            }
        }

        // cout << ret << endl;
        sum += ret;
    }
    cout << sum << endl;
}