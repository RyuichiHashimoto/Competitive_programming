#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int ctoi(char a){
    return a - '0';
}

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;


int main()
{
    int N,Q;
    cin >> N >>Q;

    vector<int> Array(N);
    vector<int> Query(Q);

    rep(i,N){
        cin >> Array[i];
    }
    rep(i,Q){
        cin >> Query[i];
    }

    sort(Array.begin(),Array .end());

    for(int i=0;i<Q;i++){
        if ( Query[i] > Array[N-1]){
            cout << 0<<endl;
        } else {
            auto s = lower_bound(Array.begin(),Array.end(),Query[i]);    
            cout << N - (s - Array.begin())<<endl;
        }
    }
    cout << (Array.end() -  Array.begin())<<endl;
}