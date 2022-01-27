#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
#include<limits.h>
using namespace std;

int INF = INT_MAX;

int MAX_N = 100;
int MAX_V = 100;

int dp[100 + 1][10000 + 1];

int main()
{
    int N = 4;
    int w[] = {2, 1, 3, 2};
    int p[] = {3, 2, 4, 2};
    int capacity = 5;

    // initialize
    // fill(dp, dp[0] + MAX_N * MAX_V + 1, INF);
    cout << INF;
}
