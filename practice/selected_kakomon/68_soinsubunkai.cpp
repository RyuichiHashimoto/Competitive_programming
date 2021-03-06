
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

vector<P> prime_factor_as_vect(ll number) {
    // 素因数分解


    vector<P> ret;
    for (ll i = 2; i * i <= number; i++) {
        ll count = 0;
        while (number % i == 0) {
            count++;
            number = number / i;
        }
        if (count != 0) ret.push_back(P(i, count));
    }
    if (number != 1) ret.push_back(P(number, 1));

    return ret;
}
int main(void) {

    int N;

    cin >> N;

    vector<P> result = prime_factor_as_vect(N);

    cout << N << ":";
    for (auto s : result) {
        rep(i, 1, s.second) {
            cout << " " << s.first;
        }
    }

    cout << endl;
}
