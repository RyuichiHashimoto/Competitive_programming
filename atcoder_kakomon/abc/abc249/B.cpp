
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


int main(void) {

    string S;
    cin >> S;

    int large_counter = 0;
    int small_counter = 0;
    int answer = 1;

    map<char, int> large;
    map<char, int> small;


    for (int i = 0; i < S.size(); i++) {
        if ((S[i] >= 'A') && (S[i] <= 'Z')) {
            large_counter = 1;
            if (large[S[i]] == 1) {
                answer = -1;
            } else {
                large[S[i]] = 1;
            }
        }

        else if ((S[i] >= 'a') && (S[i] <= 'z')) {
            small_counter = 1;
            if (small[S[i]] == 1) {
                answer = -1;
            } else {
                small[S[i]] = 1;
            }
        }
    }

    // cout << large_counter << " " << small_counter << " " << answer;
    if (large_counter == 1) {
        if (small_counter == 1) {
            if (answer == 1) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
