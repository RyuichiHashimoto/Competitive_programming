#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void) {

    int N;

    cin >> N;
    vector<int> A(N), B(N);

    rep(i, 1, N) {
        cin >> A[i - 1];
    }

    rep(i, 1, N) {
        cin >> B[i - 1];
    }
    int first = 0;
    map<int, int> find_map;
    rep(i, 1, N) {
        if (A[i - 1] == B[i - 1]) {
            find_map[A[i - 1]] = 1;
            first++;
        }
    }

    int second = 0;
    rep(i, 0, N - 1) {
        int val = A[i];

        auto s = find(B.begin(), B.end(), val);
        if (!(s == B.end()) && find_map[*s] != 1) {
            second++;
        }
    }
    cout << first << endl << second << endl;
}