
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<ll, ll> P;

ll mod_pow(ll x, ll expo, ll mod) {
    /*
        return (x  ** expor ) % mod
    */

    ll res = 1;

    while (expo > 0) {
        if (expo & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;

        expo = expo >> 1;
    }
    return res;
}


int main(void) {

    ll N, Q;

    cin >> N >> Q;
    vector<ll> A(N + 1);
    vector<int> B(Q + 2);
    ll distance[120002];
    fill(distance, distance + 120001, 0);


    rep(i, 1, N) {
        cin >> A[i];
        if (i != 1) {
            distance[i - 1] = mod_pow(A[i - 1], A[i], 1000000007) + distance[i - 2];
        }
        // cout << distance[i - 1] << " ";
    }
    // cout << endl;


    ll ret = 0;
    B[0] = 1;
    B[Q + 1] = 1;
    rep(i, 1, Q) {
        cin >> B[i];
    }

    rep(i, 1, Q + 1) {
        int big = max(B[i], B[i - 1]);
        int small = min(B[i], B[i - 1]);
        // cout << big << " " << small << endl;
        // cout << distance[big - 1] << " " << distance[small - 1] << endl;

        ll s = distance[big - 1] - distance[small - 1];
        if (s < 0) {
            s += 1000000007;
        }

        ret = (ret + s) % 1000000007;
    }


    cout << ret << endl;
}
