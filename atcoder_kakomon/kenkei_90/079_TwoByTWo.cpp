#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAX_N = 1E5;

const int MAX_H = 100, MAX_W = 100;

ll A[MAX_H][MAX_W];
ll B[MAX_H][MAX_W];

int main(void)
{
    int H, W;

    cin >> H >> W;

    rep(i,H){
        rep(j, W){
            cin >> A[i][j];
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            cin >> B[i][j];
        }
    }

    bool break_flag = false;
    ll sum  = 0;

    rep(i,H-1){
        rep(j, W - 1)
        {
            ll tmp = -A[i][j] + B[i][j];

            A[i][j] += tmp;
            A[i][j+1] += tmp;
            A[i+1][j] += tmp;
            A[i+1][j+1] += tmp;
            sum += abs(tmp);

        }
        

        if (A[i][W-1] != B[i][W-1]){
            break_flag = true;
            break;
        }
    }


    rep(i,W){
        if (A[H-1][i] != B[H-1][i]){
            break_flag = true;
            break;
        }
    }

    if (break_flag){
        cout << "No";
    } else {
        cout << "Yes" << endl;
        cout << sum;
    }
}
     