#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef unsigned long long ll;

ll sum_array(vector<ll> &array, ll s){
    ll ret = 0;
    int counter = 0;
    while(s > 0){
        if ( (s & 1) == 1 ){
            ret += array[counter];
        }
        s = s >> 1;
        counter++;
    }

    return ret;
}

int main(void)
{
    ll N,K,P;
    cin >> N >> K >> P;
    vector<ll> array(N);
    rep(i,0,N-1){
        cin >> array[i];
    }


    int mid = N/2;

    vector<ll> before[100];
    vector<ll> after[100];
    rep(i,0,99){
        before[i].clear();
        after[i].clear();
    }

    
    rep(i,0, (1 <<mid)-1){        
        before[__builtin_popcount(i)].push_back(sum_array(array,i));
    }
    rep(i, 0, (1 <<(N-mid))-1){                   
        after[__builtin_popcount(i)].push_back(sum_array(array,(ll)i<<mid));
    }

    rep(i,0,20){
        sort(before[i].begin(),before[i].end());
        sort(after[i].begin(),after[i].end());
    }
    
    ll ret =0;
    rep(i,0,K){
        int before_id = i;
        int after_id = K - i;
        if (after_id<0){
            continue;
        }

        for(auto s: before[before_id]){
            ll rest = P - s; 
            if (P <s)
                continue;
            auto genkai = lower_bound(after[after_id].begin(),after[after_id].end(),rest+1);

            ret += (ll)(genkai - after[after_id].begin());
        }
    }
    cout << ret<<endl;


}