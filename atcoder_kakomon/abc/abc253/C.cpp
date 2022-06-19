#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


const int MAX_E = 3001;


typedef pair<int, int> P;
int pow(int x, int n) {


    int ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}

int main() {

    int Q;

    cin >> Q;

    multiset<int> s;
    map<int, int> store;
    // s.erase(1);
    // int store[]

    rep(i, 1, Q) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (store[x] == 0) {
                store[x]++;
                s.insert(x);
            } else {
                store[x]++;
            }
        } else if (a == 2) {
            int x, a;
            cin >> x >> a;

            store[x] = store[x] - min(store[x], a);
            if (store[x] == 0) {
                s.erase(x);
            }
        } else if (a == 3) {
            cout << (*s.rbegin()) - *(s.begin()) << endl;
        }
    }
}