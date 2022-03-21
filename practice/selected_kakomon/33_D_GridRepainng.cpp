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

    int H, W;

    cin >> H >> W;

    int maze[52][52];
    int used[52][52];


    fill(used[0], used[52], -1);
    fill(maze[0], maze[52], -1);

    char tmp;
    int counter = 0;
    rep(i, 1, H) {
        rep(j, 1, W) {
            cin >> tmp;
            maze[i][j] = tmp == '#' ? 1 : 0;
            // cout << maze[i][j] << " ";
            if (maze[i][j] == 1) {
                counter++;
            }
        }
        // cout << endl;
    }

    queue<P> que;

    que.push(P{1, 1});
    used[1][1] = 1;

    bool find_flag = false;
    while (!que.empty() && !find_flag) {
        P p = que.front();
        que.pop();

        int x = p.first;
        int y = p.second;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};


        rep(i, 1, 4) {
            int next_x = x + dx[i - 1];
            int next_y = y + dy[i - 1];

            if ((maze[next_x][next_y] == 0) && (used[next_x][next_y] == -1)) {
                used[next_x][next_y] = used[x][y] + 1;
                que.push(P{next_x, next_y});
            }
            if ((next_x == H) && (next_y == W)) {

                find_flag = true;
                break;
            }
        }
    }
    if (find_flag) {
        cout << H * W - counter - used[H][W] << endl;
    } else {
        cout << "-1" << endl;
    }
}
