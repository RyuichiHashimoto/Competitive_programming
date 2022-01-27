#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(void){

    int H, W;
    cin >> H >> W;

    vector<vector<int>> matrix(H);    

    rep(i,H){
        matrix[i].resize(W);

        rep(j, W)
            cin >> matrix[i][j];
    }

    vector<int> H_sum(H);
    vector<int> W_sum(W);

    rep(i,H){
        int sum = 0;

        rep(j,W){
            sum += matrix[i][j];
        }
        H_sum[i] = sum;
    }

    rep(j, W)
    {
        int sum = 0;

        rep(i, H)
        {
            sum += matrix[i][j];
        }
        W_sum[j] = sum;
    }
    rep(i,H){
        rep(j, W){
            cout << H_sum[i] + W_sum[j] - matrix[i][j] << " "; 
        }
        cout << endl;
    }
}