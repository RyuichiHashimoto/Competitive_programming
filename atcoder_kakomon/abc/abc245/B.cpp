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
    cin >> N;

    bool used[2001];
    fill(used, used + 2001, false);

    int a;
    rep(i, 1, N) {
        cin >> a;
        used[a] = true;
    }

    rep(i, 0, N) {
        if (!used[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;


    return 0;
}
