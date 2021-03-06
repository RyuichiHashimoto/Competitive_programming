
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

    ll a, b;

    cin >> a >> b;

    cout << mod_pow(a, b, 1000000007) << endl;
}
