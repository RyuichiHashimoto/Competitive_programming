#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void)
{
    int H, W;

    cin >> H >> W;

    int MAX_H = 8;
    int MAX_W = 10000;

    int grids[MAX_H+1][MAX_W+1]; 

    rep(i,H){
        rep(j,W){
            cin >> grids[i][j];
        }
    }
    int max_value = 1;
    rep(i, 1 << H)
    {
        if (i ==0)
            continue;

        vector<int> bits;

        rep(j, H)
        {
            if ( i & (1 << j)){
                bits.push_back(j);
            }
        }

        map<int, int> apperance;

        for (int wid = 0; wid < W;wid++){
            int first_number = grids[bits[0]][wid];
            bool same_flag = true;
            for (auto b : bits)
            {
                if (first_number != grids[b][wid]){
                    same_flag = false;
                    break;
                }
            }
            if (same_flag){
                apperance[first_number]++;
                max_value = max(max_value, apperance[first_number] * (int)bits.size());
            }
        }
    }
    cout << max_value;
}