#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;

int used[1501][1501][4];
int val[1501][1501];

int main(void) {

    int N;

    cin >> N;
    int from_x, from_y, to_x, to_y;

    cin >> from_x >> from_y >> to_x >> to_y;
    from_x--;
    from_y--;
    to_x--;
    to_y--;

    vector<string> map(N);

    rep(i, 0, N - 1) {
        cin >> map[i];
    }

    queue<P> que;

    que.push(P{from_x, from_y});


    fill(used[0][0], used[1501][0], -1);
    fill(val[0], val[1501], -1);

    used[from_x][from_y][0] = 1;
    used[from_x][from_y][1] = 1;
    used[from_x][from_y][2] = 1;
    used[from_x][from_y][3] = 1;
    val[from_x][from_y] = 0;


    while (!que.empty()) {
        P p = que.front();
        que.pop();
        int dx[4] = {1, -1, -1, 1};
        int dy[4] = {1, 1, -1, -1};

        rep(i, 0, 3) {
            int d = 1;
            while (true) {
                int next_x = dx[i] * d + p.first;
                int next_y = dy[i] * d + p.second;
                if (next_x == -1 or next_x == N) {
                    break;
                }
                if (next_y == -1 or next_y == N) {
                    break;
                }

                if (map[next_x][next_y] == '#') {
                    break;
                }
                if (used[next_x][next_y][i] == 1 or used[next_x][next_y][(i + 2) % 4] == 1) {
                    break;
                }
                used[next_x][next_y][i] = 1;
                used[next_x][next_y][(i + 2) % 4] = 1;

                if (val[next_x][next_y] == -1) {
                    val[next_x][next_y] = val[p.first][p.second] + 1;
                    que.push(P{next_x, next_y});
                }
                if (next_x == to_x && next_y == to_y) {
                    cout << val[next_x][next_y] << endl;
                    return 0;
                }
                d++;
            }
        }
    }
    cout << -1 << endl;
}
