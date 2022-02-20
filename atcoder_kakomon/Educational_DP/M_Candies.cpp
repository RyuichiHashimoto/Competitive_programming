#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;

const int CONST_N = 401;

ll dp[CONST_N][CONST_N];

ll cul[CONST_N];


// [left, right]
ll dfs(vector<ll> array,int left, int right){
    if (dp[left][right]!=-1){
        return dp[left][right];
    }
    
    if(right == left){
        return 0;
    } else if (right - left == 1){
        return dp[left][right] = (array[left] + array[right]);
    } else {
        // cout << left <<" " << right<<endl;
        ll min_val = 0x7FFFFFFFFFFFFFFF;
        rep(mid,left,right-1){
            // cout << left <<" " <<mid <<" " << right<<endl;
            min_val = min(min_val, dfs(array,left,mid) + dfs(array,mid+1,right));
        }    
        return dp[left][right] = min_val + cul[right] - cul[left-1];
    }
}

int main(void)
{
    int N,K;
    cin >> N >> K;
    vector<int> val(N);
    rep(i,N){
        cin >> val[i];
    }

    ll mod = 1e9+7;

    











   
}
     
    
    
    




