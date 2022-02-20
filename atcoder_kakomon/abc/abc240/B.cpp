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

    map<int, int> st;
    cin >> N;
    int counter = 0;

    rep(i, 1, N) {
        int tmp;
        cin >> tmp;

        if (st[tmp] == 0) {
            counter++;
            st[tmp] = 1;
        }
    }
    cout << counter << endl;
}