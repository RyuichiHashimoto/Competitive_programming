
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

ll A[2000000];

map<ll, int> check;

ll func(int from, int to) {
    int counter = 0;
    ll ret = 0;
    for (int i = from; i < to; i++) {
        ret += A[i] << counter;
        counter++;
    }
    return ret;
}


bool dfs(int from, int to, bool minus) {
    if (from == to) {
        if (A[from] == 0 && !minus) {
            return true;
        } else if ((A[from] == 1) && minus) {
            return true;
        } else {
            return false;
        }
    }

    bool result_1, result_2;
    if (to - from < 62) {
        ll ret = func(from, to);
        if (minus) {
            ret = ~ret;
        }
        if (check[ret] == 1) {
            return true;
        } else if (check[ret] == -1) {
            return false;
        }
    }

    if (!minus && (A[from] == 1)) {
        result_1 = false;
    } else if (minus && (A[from] == 0)) {
        result_1 = false;
    } else {
        result_1 = dfs(from + 1, to, !minus);
        if (result_1 == true) {

            if (to - from < 62) {
                ll ret = func(from, to);
                if (minus) {
                    ret = ~ret;
                }
                check[ret] = 1;
            }

            return true;
        }
    }

    if (!minus && (A[to] == 0)) {
        result_2 = dfs(from, to - 1, minus);
    } else if (minus && (A[to] == 1)) {
        result_2 = dfs(from, to - 1, minus);
    } else {
        result_2 = false;
    }

    if (result_2) {
        if (to - from < 62) {
            ll ret = func(from, to);
            if (minus) {
                ret = ~ret;
            }
            check[ret] = 1;
        }
    } else {
        if (to - from < 62) {
            ll ret = func(from, to);
            if (minus) {
                ret = ~ret;
            }
            check[ret] = -1;
        }
    }

    return result_2;
}

int main(void) {

    int n;
    cin >> n;

    rep(i, 1, n) {
        cin >> A[i - 1];
    }

    int from = 0;
    bool minus = false;
    for (int to = n - 1; to >= from; to--) {
        if (A[to] == 0 && !minus) {
            continue;
        } else if (A[to] == 1 && minus) {
            continue;
        } else if ((A[from] == 0) && !minus) {
            from++;
            to++;
            minus = !minus;
        } else if ((A[from] == 1) && minus) {
            from++;
            to++;
            minus = !minus;
        } else {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
}