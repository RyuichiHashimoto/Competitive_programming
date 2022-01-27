#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef pair<int, int> Point;

void solv1(){
    int n = 3;
    int a[] = {3, 5, 8};
    int m[] = {3, 2, 2};
    int k = 17;

    int MAX_N = 100;
    int MAX_K = 17;

    bool dp[MAX_N + 1][MAX_K + 1];

    dp[0][0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int k = 0; k < m[i] && k * a[i] <= j; k++)
            {
                dp[i + 1][j] = dp[i][j] - k * a[i];
            }
        }
    }

    if (dp[n][k])
    {
        cout << "Yes\n";
    }
}

int main(){

    int n = 4;
    int m = 3;
    int M = 10000;

    

}