#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>

using namespace std;
typedef long long ll;



int main(){

    int MAX_N = 40;
    int n = 4;
    double weight[] = {2, 1, 3, 2};
    double profit[] = {3, 2, 4, 2};
    pair<ll, ll> ps[1 << (n / 2)];


    ll W = 5;
    int n2 = n / 2;

    
    for (int i = 0; i < (1 << n2);i++){
        ll sw = 0, sv = 0;
        
        for (int j = 0; j < n2;j++){
            if ( (i>>j)&1){
                sw += weight[j];
                sv += profit[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }

    sort(ps, ps + (1 << n2));

    int m = 1;

    for (int i = 0; i < (1 << n2);i++){
        if  (ps[m - 1].second < ps[i].second){
            ps[m++] = ps[i];
        }        
    }

    ll INF = 0xFFFFFFFFFF;
    ll res = 0;

    for (int i = 0; i < (1 << (n - n2)); i++){
        ll sw = 0, sv = 0;

        for (int j = 0; j < n - n2;j++){
            if ((i >> j) & 1){
                sv += weight[j];
                sw += profit[j];
            }
        }

        /*キャパを超えていない場合、*/
        if (sw < W){
            ll tv = (lower_bound(ps, ps + m,make_pair(W-sv,INF)) - 1 )  -> second;
            res = max(res, sv + tv);
        }
    }
    cout << res << endl;
}
