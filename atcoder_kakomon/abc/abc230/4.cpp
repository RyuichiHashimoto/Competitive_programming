#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

int main()
{        
    ll N,D;

    cin >> N >> D;

    ll target = -1;
    ll counter = 0;

    vector<P> tobira(N);
    for(ll i =0;i<N;i++){
        ll left,right;
        cin >> left>>right;
        tobira[i] = P{right,left};
    }

    sort(tobira.begin(),tobira.end());
    for(ll i =0;i<N;i++){
        // cout << tobira[i].second <<" " <<tobira[i].first<<endl;
    }
    // cout << endl;

    for(ll i =0; i < N;i++){
        ll left,right;
        left = tobira[i].second;
        right = tobira[i].first;
        
        if (counter == 0){
            counter++;
            target = right + D - 1;
            // cout << 1<<" "<<target<< " " << left <<" " << right<<endl;
        } else if (target >= left) {
            // cout << 2<<" "<<target<< " " << left <<" " << right<<endl;
            continue;
        } else {
            target = right + D -1;
            counter++;
            // cout << 3<<" "<<target<< " " << left <<" " << right<<endl;
        }
    }

    cout << counter;




}