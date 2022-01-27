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
    
    ll sum_ = 1;
    ll waru = 1.0E9 + 7;
    rep(i, N)
    {
        ll tmp, each_sum=0;
        
        rep(j, 6)
        {
            cin >> tmp;
            each_sum += tmp;
        }
        // cout << each_sum << endl;
        sum_ = (sum_ * each_sum) % (waru);                
    }
    cout << sum_;
}