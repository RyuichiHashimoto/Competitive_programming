#include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
typedef long long ll;

void shift_3(vector<int> &A, int s) {
    int tmp = A[s];
    A[s] = A[s - 1];
    A[s - 1] = A[s - 2];
    A[s - 2] = tmp;
}


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

    bool not_found = false;
    rep(i, 0, N - 3) {
        int minimum = *min_element(A.begin() + i, A.end());
        auto iter = std::find(A.begin() + i, A.end(), minimum);
        int n = iter - A.begin();
        while ((n - i) >= 2) {
            shift_3(A, n);
            n -= 2;
        }
        if ((n - i) == 1) {
            shift_3(A, n + 1);
            shift_3(A, n + 1);
        }
    }

    int last_minimum = -1;
    bool s = false;

    rep(i, 0, N - 3) {
        int minimum = *min_element(B.begin() + i, B.end());
        if (last_minimum == minimum) {
            s = true;
        }
        auto iter = std::find(B.begin() + i, B.end(), minimum);
        int n = iter - B.begin();
        while ((n - i) >= 2) {
            shift_3(B, n);
            n -= 2;
        }
        if ((n - i) == 1) {
            shift_3(B, n + 1);
            shift_3(B, n + 1);
        }
        last_minimum = minimum;
    }
    rep(i, 0, N - 3) {
        if (A[i] != B[i]) {
            cout << "No" << endl;
            return 0;
        }
    }


    if (s || ((A[N - 2] == B[N - 2]) && (A[N - 1] == B[N - 1]))) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}