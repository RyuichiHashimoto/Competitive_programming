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

    int R, C;

    cin >> R >> C;

    int a[2][2];

    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];


    cout << a[R - 1][C - 1] << endl;
}