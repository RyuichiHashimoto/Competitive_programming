#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;

ll amari = 1e9+7;

const int CONST_N = 22;

ll dp[CONST_N][CONST_N];
ll matching[CONST_N][1 << (CONST_N-1)+1];

int main(void)
{
    int N;
    cin >> N;

    fill(dp[0],dp[CONST_N],0);
    fill(matching[0],matching[CONST_N],0);

    rep(i,0,N-1){
        rep(j,0,N-1){
            cin >> matching[i][j];
        }
    }
    dp[0][0] = 1;

    rep(i,0,N){
        rep(S,0,1<<N){
            int bit_info = 1;
            int counter = 0;

            
        }
    }
}
     
    
    
    




