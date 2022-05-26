#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
typedef pair<int, int> P;

int main() {

    int N, K;
    int a;
    cin >> N >> K;
    set<int> max_set;
    int max_a = -1;
    rep(i, 1, N) {
        cin >> a;
        if (max_a < a) {
            max_set.clear();
            max_set.insert(i);
            max_a = a;
        } else if (max_a == a) {
            max_set.insert(i);
        }
    }


    rep(i, 1, K) {
        cin >> a;
        if (max_set.find(a) != max_set.end()) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}