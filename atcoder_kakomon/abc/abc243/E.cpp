#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

ll distance_[301][301];
int map_[301][301];
int prev_[301][301];


void printPath2(int start, int goal) {
    int stack[301], sp;
    sp = 0;
    for (int cur = goal; cur != start; cur = prev_[start][cur]) stack[sp++] = cur;
    stack[sp++] = start;

    while (sp--) printf("%d%c", stack[sp], " \n"[!sp]);
}


int main(void) {

    int N, M;
    cin >> N >> M;


    fill(distance_[0], distance_[301], -1);


    ll a, b, c;
    rep(i, 1, M) {
        cin >> a >> b >> c;
        distance_[a][b] = c;
        map_[a][b] = i;
    }

    rep(i, 1, N) {
        rep(j, 1, N) {
            prev_[i][j] = i;
        }
    }

    rep(i, 1, N) {
        rep(j, 1, N) {
            rep(k, 1, N) {
                if (distance_[i][k] + distance_[k][j] < distance_[i][j]) {
                    distance_[i][j] = distance_[i][k] + distance_[k][j];
                    prev_[i][j] = prev_[k][j];
                }
            }
        }
    }
    vector<bool> used(M + 1);
    fill(used.begin(), used.end(), false);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i <= N; j++) {
            int goal = j;
            int start = i;
            if (i == j) {
                continue;
            }
            for (int cur = goal; cur != start; cur = prev_[start][cur]) {
                cout << goal << " " << start << " " << cur << endl;
                used[map_[cur][prev_[start][cur]]] = true;
            }
        }
    }
}
