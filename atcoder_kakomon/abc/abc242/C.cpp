#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)


typedef long long ll;

ll amari = 998244353;
int main(void) {

    ll N;

    cin >> N;


    vector<ll> A(10);

    rep(i, 1, 9) {
        A[i] = 1;
    }
    vector<ll> B(10);

    for (ll i = 1; i < N; i++) {


        for (ll j = 2; j < 9; j++) {
            B[j] = (A[j - 1] + A[j]) % amari;

            B[j] = (B[j] + A[j + 1]) % amari;
        }
        B[1] = (A[1] + A[2]) % amari;
        B[9] = (A[9] + A[8]) % amari;

        rep(i, 1, 9) {
            A[i] = B[i];
        }
    }

    ll sum = 0;
    rep(i, 1, 9) {
        sum = (sum + A[i]) % amari;
    }
    cout << sum << endl;
}