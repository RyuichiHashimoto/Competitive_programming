#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    
    vector<ll> xs_list(N), ys_list(N);
    rep(i, N)
    {
        cin >> xs_list[i] >> ys_list[i];
    }

    sort(xs_list.begin(), xs_list.end());
    sort(ys_list.begin(), ys_list.end());

    ll centor_x = xs_list[(int)N / 2];
    ll centor_y = ys_list[(int)N / 2];
    
    ll x = 0, y = 0;
    rep(i, N)
    {
        x += abs(centor_x - xs_list[i]);
        y += abs(centor_y - ys_list[i]);
    }
    cout << x + y;
}