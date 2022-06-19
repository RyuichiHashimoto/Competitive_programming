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

    int N;
    cin >> N;

    int val = N % 100;


    if (val < 10) {
        cout << "0" << val << endl;

    } else {
        cout << val << endl;
    }
}