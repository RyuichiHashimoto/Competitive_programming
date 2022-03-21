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

    int N;
    string s;

    cin >> N >> s;


    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    int x = 0, y = 0;
    int idx = 0;
    rep(i, 0, N - 1) {

        if (s[i] == 'S') {
            x += dx[idx];
            y += dy[idx];
        } else {
            idx = (idx + 1) % 4;
        }
    }
    cout << x << " " << y << endl;
}
