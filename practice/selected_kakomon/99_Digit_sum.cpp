
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
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;


int main(void) {


    int dp[3][100001];
    fill(dp[0], dp[3], 0);


    int red = 0, blue = 0, green = 0;

    int n;
    cin >> n;
    int tmp;
    ll ret = 1;
    ll mod = 1000000007;
    rep(i, 1, n) {
        cin >> tmp;
        bool flag = true;
        int s = 0;
        if (tmp == red) {
            s++;
            if (flag) {
                red++;
                flag = false;
            }
        }
        if (tmp == blue) {
            s++;
            if (flag) {
                blue++;
                flag = false;
            }
        }
        if (tmp == green) {
            s++;
            if (flag) {
                green++;
                flag = false;
            }
        }
        ret = (ret * s) % mod;
    }
    cout << ret << endl;
}
