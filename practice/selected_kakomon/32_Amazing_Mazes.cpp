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


int main(void) {

    int right = 0;
    int up = 1;
    int left = 2;
    int down = 3;

    int W, H;


    int maze[32][32][4];
    int used[32][32];


    while (true) {
        cin >> W >> H;

        if (W == 0 and H == 0) {
            break;
        }
        fill(maze[0][0], maze[32][0], -1);
        fill(used[0], used[32], -1);

        rep(i, 1, 2 * H - 1) {

            int tmp = 0;
            if (i & 1) {

                rep(j, 1, W - 1) {

                    cin >> tmp;
                    maze[(i >> 1) + 1][j][right] = tmp;
                    maze[(i >> 1) + 1][j + 1][left] = tmp;
                }
            } else {

                rep(j, 1, W) {
                    cin >> tmp;
                    maze[(i >> 1)][j][down] = tmp;
                    maze[(i >> 1) + 1][j][up] = tmp;
                }
            }
        }
        rep(i, 1, H) {
            rep(j, 1, W) {
                // cout << maze[i][j][0] << " ";
            }
            // cout << endl;
        }

        queue<P> que;
        que.push(P{1, 1});
        used[1][1] = 1;

        // cout << "------------" << endl;
        bool find_falg = false;
        while (!que.empty()) {
            P p = que.front();
            que.pop();
            int x = p.first, y = p.second;

            // cout << x << " " << y << endl;


            for (int i = 0; i < 4; i++) {
                if (maze[x][y][i] == 0) {
                    int next_x, next_y;
                    if (i == right) {
                        next_x = x;
                        next_y = y + 1;
                    } else if (i == down) {
                        next_x = x + 1;
                        next_y = y;
                    } else if (i == left) {
                        next_x = x;
                        next_y = y - 1;
                    } else if (i == up) {
                        next_x = x - 1;
                        next_y = y;
                    }

                    if (used[next_x][next_y] == -1) {
                        used[next_x][next_y] = used[x][y] + 1;
                        que.push(P{next_x, next_y});
                    }

                    if ((next_x == H) && (next_y == W)) {
                        find_falg = true;
                        cout << used[next_x][next_y] << endl;
                        break;
                    }
                }
            }
            if (find_falg) {
                break;
            }
        }
        if (!find_falg) {
            cout << 0 << endl;
        }
    }
}
