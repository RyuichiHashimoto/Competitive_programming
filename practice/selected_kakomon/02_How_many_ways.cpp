#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

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

int main(void) {

    int N;

    cin >> N;

    int counter = 0;
    for (int i = 1; i <= N; i += 2) {
        vector<ll> ret = divisor((ll)i);


        if (ret.size() == 8) {
            counter++;
        }
    }
    cout << counter << endl;
}