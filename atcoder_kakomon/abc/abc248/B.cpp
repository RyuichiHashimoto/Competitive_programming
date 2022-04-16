
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

int main(void) {

    ll A, B, K;

    cin >> A >> B >> K;

    if (A >= B) {
        cout << 0 << endl;
        return 0;
    }

    int counter = 0;
    while (true) {
        counter++;
        A = A * K;
        if (A >= B) {
            cout << counter << endl;
            return 0;
        }
    }


    return 0;
}
