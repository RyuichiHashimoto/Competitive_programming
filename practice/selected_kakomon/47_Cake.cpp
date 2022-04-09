
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)
typedef tuple<int, int, ll, bool> tp;

ll dp[2001][2001];
ll A[2001];

ll dfs(int from, int to) {
}


int main(void) {

    int N;

    cin >> N;

    fill(A, A + 2001, 0);
    rep(i, 1, N) {
        cin >> A[i - 1];
    }
    fill(dp[0], dp[4001], -1);


    dfs(0, n - 1);
}
