#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;


int main(void) {

    int N;
    cin >> N;
    vector<int> A(N);

    rep(i, 1, N) {
        cin >> A[i - 1];
    }

    int counter = 0;
    int M;
    cin >> M;
    rep(i, 1, M) {
        int tmp;
        cin >> tmp;

        vector<int>::iterator s = lower_bound(A.begin(), A.end(), tmp);
        if (tmp == *s) {
            counter++;
        }
    }
    cout << counter << endl;
}