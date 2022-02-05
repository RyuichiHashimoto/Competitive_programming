#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;

const int max_E = 3001;
typedef long long ll;

ll dp[3001][3001];

int main(void)
{
    int N;
    cin >> N;

    vector<ll> array(N+1);

    rep(i,1,N){
        cin >> array[i];
    }

    fill(dp[0],dp[3001],0x7FFFFFFF);



    rep(end,1,N){
        for(int start = end; start >= 1;start--){
            if (start == end){
                dp[start][end] = array[start];
            } else {
                ll l = max(array[start] - dp[start+1][end], array[end] - dp[start][end -1] );
                dp[start][end] =  l;
            }
        }
    }

    cout << dp[1][N]<<endl;






    // for(int i=1;i<)




}
     
    
    
    




