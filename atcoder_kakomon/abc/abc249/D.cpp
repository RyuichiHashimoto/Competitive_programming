#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

vector<ll> divisor(ll number) {
    /*
        数字 numberの約数を小さい順に列挙
        計算量: sqrt(number);

    */
    vector<ll> res;

    for (ll i = 1; i * i <= number; i++) {

        if (number % i == 0) {
            res.push_back(i);
            if (i * i != number) {
                res.push_back(number / i);
            }
        }
    }
    return res;
}

const int MAX_N = 2E5 + 1;
ll used[MAX_N];

int main(void) {

    int N;

    cin >> N;
    vector<ll> s(N);
    fill(used, used + MAX_N, 0);

    rep(i, 0, N - 1) {
        cin >> s[i];
        used[s[i]]++;
    }

    if (N < 3) {
        cout << "0";
        return 0;
    }

    ll ret = 0;
    for (int i = 0; i < N; i++) {
        vector<ll> yakusu_list = divisor(s[i]);


        for (auto yakusu : yakusu_list) {
            ll pair = s[i] / yakusu;
            ret += (used[yakusu]) * used[pair];
        }
    }
    cout << ret << endl;
}