#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef unsigned long long ll;

const int MAX_N = 1e5+1;

bool dp[101][MAX_N];


bool dfs(int idx,int amount,vector<char> &answer, vector<int> &A,vector<int> &B){

    if (idx == 0){
        return amount == 0;
    }

    if ( amount - A[idx] >=0 && dp[idx - 1 ][amount - A[idx]]){
        answer[idx] = 'A';
        bool result = dfs(idx -1,amount - A[idx],answer,A,B);
        if (result){
            return true;
        }
    }

    if ( amount - B[idx] >= 0 && dp[idx - 1 ][amount - B[idx]]){
        answer[idx] = 'B';
        bool result =dfs(idx -1,amount - B[idx],answer,A,B);

        if (result){
            return true;
        }

    }
    
    return false;
}



int main(void)
{
    int N,S;
    cin >> N >> S;

    vector<int> A(N+1),B(N+1);

    rep(i,1,N){
        cin >> A[i] >> B[i];
    }

    fill(dp[0],dp[101],false);

    dp[0][0] =true;

    rep(i,1,N){
        rep(j,1,S){
            bool a_flag=false,b_flag = false;
                        
            if (j - A[i] >= 0){
                a_flag = dp[i-1][j-A[i]];
            }

            if (j - B[i] >= 0){
                b_flag = dp[i-1][j - B[i]];
            }            
            dp[i][j] = a_flag or b_flag;
        }
    }

    if (dp[N][S]){
        vector<char> answer(N+1);
        dfs(N,S,answer,A,B);

        rep(i,1,N){
            cout << answer[i];
        }
    } else {
        cout << "Impossible";
    }


}