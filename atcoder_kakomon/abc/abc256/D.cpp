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

    int N;
    cin >> N;

    vector<int> L(N), R(N);


    int max_val = 3E5 + 10;
    vector<int> imosu(max_val);

    int max_r = -1;
    rep(i, 1, N) {
        cin >> L[i - 1] >> R[i - 1];
        imosu[L[i - 1]]++;
        imosu[R[i - 1]]--;
        max_r = max(max_r, R[i - 1]);
    }

    rep(i, 1, max_val - 1) {
        imosu[i] += imosu[i - 1];
    }

    int counter = 0;
    int idx = 0;
    while (true) {


        int find_left = idx;
        while (imosu[find_left] <= 0) {
            find_left++;
            if (find_left > max_r) {
                break;
            }
        }
        if (find_left > max_r) {
            break;
        }
        int find_right = find_left + 1;
        while (imosu[find_right] > 0) {
            find_right++;
        }

        cout << find_left << " " << find_right << endl;
        // break;
        idx = find_right + 1;
    }


    // cout << counter;
}
