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
    vector<int> S(N + 1);


    map<int, int> store;


    rep(a, 1, 150) {
        rep(b, 1, 150) {
            int s = 4 * a * b + 3 * (a + b);
            store[s] = 1;
        }
    }
    int counter = 0;
    rep(i, 1, N) {
        int tmp;
        cin >> tmp;
        if (store[tmp] != 1) {
            counter++;
        }
    }
    cout << counter << endl;
}