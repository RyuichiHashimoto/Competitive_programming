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

    int a, b, c;

    cin >> a >> b >> c;

    if (a >= b && b >= c) {
        cout << "Yes";
    } else if (a <= b && b <= c) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    // cout << char(a) << endl;
}