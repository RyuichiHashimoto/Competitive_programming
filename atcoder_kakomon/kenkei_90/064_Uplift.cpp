#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void)
{
    int N, Q;
    cin >> N >> Q;
    rep(i,N){
        cin >> height[i];
    }

    ll original_huben = 0;
    rep(i, N-1)    
    {
        diff[i] = height[i + 1] - height[i];
        original_huben += abs(diff[i]);
    }
    int l, r, v;
    ll current_huben = original_huben;
    // cout << "-------------------";
    // cout << original_huben<<endl<<endl;    

    rep(i, Q)
    {
        cin >> l >> r >> v;
        l--;
        r--;

                                

        if (l  != 0)
        {            
            ll before = abs(diff[l - 1]);
            diff[l - 1] = diff[l - 1] + v;
            current_huben += abs(diff[l-1]) - before;          
        }
        
        if (r != N-1){            
            // cout << v << endl;
            // cout << diff[r] << endl;
            ll before = abs(diff[r]);            
            diff[r] = diff[r] - v;
            current_huben += abs(diff[r]) - before;
        }
        cout << current_huben << endl;
        
    }
}