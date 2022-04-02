
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int main(void) {

    int n, m;

    cin >> n >> m;


    vector<vector<int>> triangle(n + 3, vector<int>(n + 3, 0));
    vector<vector<int>> minus_triangle(n + 3, vector<int>(n + 3, 0));
    vector<int> A(m + 1), B(m + 1), C(m + 1);

    rep(i, 1, m) {
        cin >> A[i] >> B[i] >> C[i];
    }
    rep(i, 1, m) {
        triangle[A[i]][B[i]]++;
        triangle[A[i] + C[i] + 1][B[i] + C[i] + 1]--;
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            triangle[i][j] += triangle[i - 1][j - 1];
        }
    }

    rep(i, 1, m) {
        minus_triangle[A[i] + C[i] + 1][B[i]]--;
        minus_triangle[A[i] + C[i] + 1][B[i] + C[i] + 1]++;
    }


    rep(i, 1, n) {
        rep(j, 1, n) {
            minus_triangle[i][j] += minus_triangle[i][j - 1];
        }
    }

    int a = 0;
    rep(i, 1, n) {
        rep(j, 1, i) {
            triangle[i][j] += triangle[i - 1][j] + minus_triangle[i][j];
            if (triangle[i][j] != 0) {
                a++;
            }
        }
    }
    cout << a << endl;
}
