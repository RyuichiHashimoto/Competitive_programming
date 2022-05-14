#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;

/*
      N以下の素数を列挙する。
   */
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
int main() {

    ll N;
    cin >> N;
    int max_ = 1E6;

    vector<int> prime_list = Eratosthenes(max_);
    sort(prime_list.begin(), prime_list.end());


    ll ret = 0;

    for (auto _b : prime_list) {
        ll b = _b;

        if (b == 2ll) continue;

        ll triple = b * b * b;

        if (triple > N) {
            break;
        }


        ll amari = N / triple + 1;

        auto f_p = lower_bound(prime_list.begin(), prime_list.end(), _b);
        auto s_p = lower_bound(prime_list.begin(), prime_list.end(), amari);

        ll first_pos = (f_p - prime_list.begin());
        ll second_p = (s_p - prime_list.begin());

        ll added = min(first_pos, second_p);

        if (added == -1) {
            added = 0;
        }
        ret += added;
    }
    cout << ret << endl;
}