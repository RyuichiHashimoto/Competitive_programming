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

    int W, H;
    cin >> W >> H;

    int map[102][102];
    bool used[102][102];
    fill(map[0], map[102], -1);
    fill(used[0], used[102], false);

    rep(i, 1, H) {
        rep(j, 1, W) {
            cin >> map[i][j];
        }
    }

    queue<P> que;
    int counter = 0;

    rep(i, 1, H) {
        if (map[i][1] == 0) {
            used[i][1] = true;
            que.push(P{i, 1});
        } else {
            if (i & 1) {
                counter += 1;
            } else {
                counter += 3;
            }
        }
        if (map[i][W] == 0) {
            used[i][W] = true;
            que.push(P{i, W});
        } else {
            if (i & 1) {
                counter += 3;
            } else {
                counter += 1;
            }
        }
    }
    // cout << counter << endl;

    rep(i, 1, W) {

        if (map[1][i] == 1) {
            counter += 2;
        }
        if (map[1][i] == 0 && !used[1][i]) {
            used[1][i] = true;
            que.push(P{1, i});
        }
        if (map[H][i] == 1) {
            counter += 2;
        }

        if (map[H][i] == 0 && !used[H][i]) {
            used[H][i] = true;
            que.push(P{H, i});
        }
    }
    if (map[W][1] == 1) {
        counter--;
    }
    if ((map[1][H] == 1) && ((H & 1) == 0)) {
        counter--;
    }
    if ((map[W][H] == 1) && ((H % 2) == 0)) {
        // counter--;
    }


    while (!que.empty()) {
        P p = que.front();
        que.pop();


        int kdx[] = {0, 1, 1, 0, -1, -1};
        int kdy[] = {1, 1, 0, -1, 0, 1};

        int gdx[] = {0, 1, 1, 0, -1, -1};
        int gdy[] = {1, 0, -1, -1, -1, 0};


        for (int j = 0; j <= 5; j++) {

            int x, y;

            if (p.first & 1) {
                x = kdx[j] + p.first;
                y = kdy[j] + p.second;
            } else {
                x = gdx[j] + p.first;
                y = gdy[j] + p.second;
            }


            if (map[x][y] == -1) {
                continue;
            } else if (map[x][y] == 0) {
                if (used[x][y]) {
                    continue;
                }
                used[x][y] = true;
                que.push(P{x, y});
            } else if (map[x][y] == 1) {
                counter++;
            } else {
                cout << "error";
            }
        }
    }
    cout << counter << endl;
}