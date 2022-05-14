#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;


int main() {
    ll N, M;
    cin >> N;

    vector<int> A(N + 1);
    vector<int> B(N + 1);
    set<int> A_set;
    set<int> B_set;
    map<int, map<int, int>> ans;

    rep(i, 1, N) {
        cin >> A[i];
    }
    rep(i, 1, N) {
        cin >> B[i];
    }

    int a = 1, b = 1;
    map<int, int> A_used;
    map<int, int> B_used;

    A_used[A[a]] = 1;
    B_used[B[b]] = 1;


    while (true) {
        // cout << a << " " << b << endl;
        A_set.insert(A[a]);
        B_set.insert(B[b]);
        A_used[A[a]] = 1;
        B_used[B[b]] = 1;

        if (A[a] == B[b]) {

            ans[a][b] = 1;
            if (A_used[A[a + 1]]) {
                if (a < N) {
                    a++;
                    continue;
                }
            } else if (B_used[B[b + 1]]) {
                if (b < N) {
                    b++;
                    continue;
                }
            } else if (a < N) {
                a++;
                continue;
            } else if (b < N) {
                b++;
                continue;
            } else {
                break;
            }


        } else if (A_set.size() < B_set.size()) {
            if (a < N) {
                a++;
                continue;
            } else if (b < N) {
                b++;
                continue;
            }

        } else {
            if (b < N) {
                b++;
                continue;
            } else if (a < N) {
                a++;
                continue;
            }
        }
        if ((a == N) && (b == N)) {
            break;
        }
    }
    int Q;
    cin >> Q;
    rep(i, 1, Q) {
        int a, b;
        cin >> a >> b;
        if (ans[a][b] == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}