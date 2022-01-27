#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

int dp[100 + 1][100 + 1];
int n, m;
char s[200][200];

int main()
{
    int n = 3;
    int w[] = {3, 4, 2};
    int p[] = {4, 5, 3};
    int W = 7;

    for (int i = 0; i < n;i++){
        for (int j = 0; j <= W; j++){
            if ( j < w[i]){
                /* 一つもアイテムを入れることができない場合。*/
                dp[i + 1][j] = dp[i][j];
            }  else {
                /*  */
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + p[i]);
            }
        }
    }
    cout << dp[n][W];
}
