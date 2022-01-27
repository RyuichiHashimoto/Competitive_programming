#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

int main(void)
{
    ll a, b, c;

    cin >> a >> b >> c;

    ll sum = 1;
    rep(i,b){
        sum = sum * c;
    }

    if (a < sum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}