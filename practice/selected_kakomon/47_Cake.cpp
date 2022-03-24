
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

typedef pair<int, int> P;

int dp[2001][2001];
int A[2001];
void dfs(int a, int b, int s) {

    rep(i, 0, N - 1) {
        if (A[i] != -1) {
            if (A[(i - 1 + N) % N] == -1) dp[]
        }
    }
}

int main(void) {

    int N;

    cin >> N;

    fill(A, A + 2001, 0);
    rep(i, 1, N) {
        cin >> A[i - 1];
    }


    rep(i, 0, N - 1) {
        fill(dp[0], dp[2001], -1);
        dp[i][i] = A[i];
    }
}
