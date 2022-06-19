#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
using namespace std;
typedef long long ll;
#include <numeric>

const int MAX_E = 3001;

ll kaijou(ll a, ll mod) {

    ll ret = 1;
    rep(i, 1, a) {
        ret = (ret * i);
    }
    return ret;
};


int divisor(ll number, ll upper_limit) {
    /*
        数字 numberの約数を小さい順に列挙
        計算量: sqrt(number);

    */
    int ret = 0;

    ll val = number / upper_limit;

    for (ll i = val; i <= upper_limit; i++) {
        if (i == 0) {
            continue;
        }

        if (number % i == 0) {
            if (i * i == number) {
                if (i <= upper_limit) {
                    ret++;
                }
            } else {
                if ((i <= upper_limit) && (number / i <= upper_limit)) {
                    ret = ret + 2;
                }
            }
        }
    }
    return ret;
}

int main() {

    vector<ll> val_list;

    ll counter = 1;
    ll N = 0;
    cin >> N;

    while (true) {
        ll tmp = counter * counter;
        if (tmp <= N * N) {
            val_list.push_back(tmp);
        } else {
            break;
        }
        counter++;
    }


    rep(i, 1, N) {
        auto c = lower_bound(val_list.begin(), val_list.end(), i);
        while (*c / i != 0) {
            c++;
        }
    }
}
