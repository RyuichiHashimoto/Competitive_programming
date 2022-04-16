#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)


int main(void) {

    ll N, K, X;
    cin >> N >> K >> X;

    vector<ll> A(N);

    rep(i, 0, N - 1) {
        cin >> A[i];
    }

    priority_queue<ll> que;

    rep(i, 0, N - 1) {
        que.push(A[i]);
    }


    while (!que.empty()) {
        ll amount = que.top();
        que.pop();

        if (amount == 0) {
            return 1;
        } else if (amount <= X) {
            // cout << "1_" << amount << endl;
            K--;
        } else {
            // cout << "2_" << amount << endl;
            ll kupon = min(K, amount / X);
            amount = amount - kupon * X;
            que.push(amount);
            K = K - kupon;
        }

        if (K == 0) {
            break;
        }
    }

    ll ret = 0;
    while (!que.empty()) {
        ret += que.top();
        que.pop();
    }
    cout << ret << endl;
}
