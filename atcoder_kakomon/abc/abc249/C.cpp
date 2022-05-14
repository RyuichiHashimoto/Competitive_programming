
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

int shutugen[28][28];

int main(void) {

    int N, K;

    cin >> N >> K;


    fill(shutugen[0], shutugen[28], 0);

    string tmp;
    rep(i, 1, N) {
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            shutugen[i - 1][tmp[j] - 'a']++;
        }
    }

    vector<int> as;
    int ret = -1;
    brep(i, 15) {

        int tmp = i;
        vector<int> shutugen_kaisuu(28, 0);
        int counter = 0;
        while (tmp > 0) {
            if (tmp & (1)) {
                for (int i = 0; i < 27; i++) {
                    if (shutugen[counter][i] != 0) {
                        shutugen_kaisuu[i]++;
                    }
                }
            }
            tmp >>= 1;
            counter++;
        }
        int tmp_ret = 0;
        rep(j, 0, 26) {
            if (shutugen_kaisuu[j] == K) {
                tmp_ret++;
            }
        }
        ret = max(ret, tmp_ret);
    }
    cout << ret << endl;

    return 0;
}
