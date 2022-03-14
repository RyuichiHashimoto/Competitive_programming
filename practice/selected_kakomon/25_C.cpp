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

void dfs(vector<vector<int>> &map, int x, int y, vector<vector<bool>> &used) {

    used[x][y] = 1;

    if (x + 1 < map.size() && !used[x + 1][y] && map[x + 1][y] == 1) {
        dfs(map, x + 1, y, used);
    }

    if (x - 1 >= 0 && !used[x - 1][y] && map[x - 1][y] == 1) {
        dfs(map, x - 1, y, used);
    }

    if (y + 1 < map[0].size() && !used[x][y + 1] && map[x][y + 1] == 1) {
        dfs(map, x, y + 1, used);
    }

    if (y - 1 >= 0 && !used[x][y - 1] && map[x][y - 1] == 1) {
        dfs(map, x, y - 1, used);
    }

    if (x + 1 < map.size() && y + 1 < map[0].size() && !used[x + 1][y + 1] && map[x + 1][y + 1] == 1) {
        dfs(map, x + 1, y + 1, used);
    }
    if (x + 1 < map.size() && y - 1 >= 0 && !used[x + 1][y - 1] && map[x + 1][y - 1] == 1) {
        dfs(map, x + 1, y - 1, used);
    }

    if (x - 1 >= 0 && y + 1 < map[0].size() && !used[x - 1][y + 1] && map[x - 1][y + 1] == 1) {
        dfs(map, x - 1, y + 1, used);
    }

    if (x - 1 >= 0 && y - 1 >= 0 && !used[x - 1][y - 1] && map[x - 1][y - 1] == 1) {
        dfs(map, x - 1, y - 1, used);
    }
}


int main(void) {

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == b && a == 0) {
            break;
        }
        vector<vector<int>> map(b);
        vector<vector<bool>> used(b);
        rep(i, 1, b) {
            map[i - 1].resize(a);
            used[i - 1].resize(a);
            rep(j, 1, a) {
                cin >> map[i - 1][j - 1];
            }
        }


        int counter = 0;
        rep(i, 1, b) {
            rep(j, 1, a) {
                if (!used[i - 1][j - 1] && (map[i - 1][j - 1] == 1)) {
                    counter++;
                    dfs(map, i - 1, j - 1, used);
                }
            }
        }
        cout << counter << endl;
    }
}