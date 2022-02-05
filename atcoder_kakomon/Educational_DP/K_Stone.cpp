#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;

const int max_E = 1e5+3;

int dp[max_E][3];

int None = 0;
int First = 1;
int Second = 2;


int main(void)
{
    int N,K;
    cin >> N >> K;
    vector<int> array(N);

    rep(i,0,N-1){
        cin >> array[i];
    }
    sort(array.begin(),array.end());

    fill(dp[0],dp[max_E],None);

    //1: first win, 2: second win
    //手がない場合
    dp[0][1] = Second;
    dp[0][2] = First;

    
    rep(i, 1,K){
        //先手探索
        for (int a: array){
            if  (i - a <0){
                break;
            } else if (dp[i-a][2]==First){
                dp[i][1] = First;
            }        
           
        }
        if (dp[i][1]==None){
            dp[i][1] = Second;
        }
        //先手探索
        for (int a: array){
            if  (i - a <0){
                break;
            } else if (dp[i-a][1]==Second){                
                dp[i][2] = Second;
            }            
        }
        if (dp[i][2]==None){
            dp[i][2] = First;
        }
    }


    if (dp[K][1]==First){
        cout << "First";
    } else if (dp[K][1] == Second){
        cout << "Second"<< endl;
    } else {
        return 1;
    }





}
     
    
    
    




