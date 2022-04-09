#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;


ll pow(ll x, ll n) {


    ll ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}

double calc(double P, double x) {
    return x + P / pow(2, x / 1.5);
}


int main(void) {

    int N = 2;

    double P;
    cin >> P;

    double upper = 100;
    double lower = 0;


    while ((upper - lower) >= 1E-8) {
        // cout << upper << " " << lower << endl;
        double distance = upper - lower;

        double c1 = lower + distance / 3;
        double c2 = lower + distance * 2 / 3;

        double ca_c1 = calc(P, c1);
        double ca_c2 = calc(P, c2);
        // cout << calc(c1) << " " << calc(c2) << endl;
        if (ca_c1 < ca_c2) {
            upper = c2;
        } else {
            lower = c1;
        }
    }
    // cout << calc(2, 1.5);
    // cout << calc()
    cout << setprecision(10) << calc(P, lower) << endl;
}