#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

const int INF = 0x000FFFFFF;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int s, int v,int **dp, int **matrix, int n_of_city)
{
    if (dp[s][v] >= 0){
        return dp[s][v];
    }

    if ( s == (1 << n_of_city) -1 && v == 0 ){
        return dp[s][v] = 0;
    }

    int res = INF;
    rep(u,n_of_city){
        if (!(s >> u & 1)){
            res = min(res, matrix[v][u]+ solve(s | 1<<u,u, dp,matrix,n_of_city));
        }
    }
    return dp[s][v] = res;    
}

int main()
{
    
    int n = 5;
    int m = 9;
    cin >> n >> m;
    int **matrix = new int *[n];
    int **dp = new int *[1<<n];

    
    
    rep(i, n) matrix[i] = new int[n];
    rep(i, n) fill(matrix[i], matrix[i] + n, 0x000FFFFFF);
    rep(i, 1<<n) dp[i] = new int[n];    
    rep(i, 1<<n) fill(dp[i], dp[i] + n, -1);

    rep(i, m)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        matrix[from][to] = cost;
    }

    cout << solve(0,0,dp,matrix,n);
    
       
    rep(i, n) delete matrix[i];
    delete matrix;
    rep(i, 1<<n) delete dp[i];
    delete dp;
}