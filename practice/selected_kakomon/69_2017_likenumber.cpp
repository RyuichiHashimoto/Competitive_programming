
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

vector<int> Eratosthenes(int N) {
    vector<int> prime_list;

    bool *is_prime = new bool[N + 1];
    fill(is_prime, is_prime + N, true);

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime_list.push_back(i);

            for (int j = 1; j * i <= N; j++) {
                is_prime[i * j] = false;
            }
        }
    }
    delete is_prime;
    return prime_list;
}
int main(void) {

    int Q;

    cin >> Q;

    vector<int> sosuu = Eratosthenes(100000);
    bool used[100000 + 1];
    int ruiseki[100000 + 1];
    fill(used, used + 100000 + 1, false);
    fill(ruiseki, ruiseki + 100000 + 1, 0);

    for (auto sosu : sosuu) {
        used[sosu] = true;
    }


    int min_ = 0;
    for (int i = 1; i <= 100000; i++) {
        // cout << used[i] << " asdfasdf";
        if ((used[i]) && (used[(i + 1) / 2])) {
            min_++;
        }
        ruiseki[i] = min_;
    }


    int l, r;
    rep(i, 1, Q) {
        cin >> l >> r;
        if (l == 1) {
            cout << ruiseki[r];
        } else {
            cout << ruiseki[r] - ruiseki[l - 2];
        }
        cout << endl;
    }
}
