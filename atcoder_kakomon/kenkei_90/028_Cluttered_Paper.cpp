#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main(void)
{
    int N;

    cin >> N;

    int mp[1002][1002];
    fill(mp[0],mp[1002],0);
    int W = 1000, H = 1000;

    rep(i,N){
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;

        mp[t1][t2] += 1;
        mp[t3][t2] += -1;
        mp[t1][t4] += -1;
        mp[t3][t4] += 1;
    }

    rep(w_i,W+1){
        rep(h_i,H+1){           
            mp[w_i][h_i + 1] += mp[w_i][h_i];
        }
    }
    rep(h_i, H + 1){
        rep(w_i, W + 1)
        {
            mp[w_i + 1][h_i] += mp[w_i][h_i];
        }
    }

    vector<int> answer(N);
    fill(answer.begin(), answer.end(), 0);

    rep(h_i,H+1){
        rep(w_i,W +1){
            answer[mp[w_i][h_i]]++;
        }
    }

    rep(i,N){
        cout << answer[i+1] << endl;
    }
}