#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;
const int MAX_N = 10000;

int calc(int K, vector<int> &dir,int N){

    vector<int> f(MAX_N);

    fill(f.begin(), f.end(), 0);
    int res = 0;  // 必要な回転回数
    int sum = 0;  // 

    for (int i = 0; i + K < N; i++)    
    {
        if ((dir[i] + sum) %2 != 0){
            res++;
            f[i] = 1;
        }
        
        sum += f[i];
        if (i -K + 1>= 0){
            sum -= f[i - K + 1];
        }        
    }

    
    for (int i = N - K + 1; i < N;i++){
        if ((dir[i] + sum ) %2 != 0){
            return -1;
        }

        if (i -K + 1 >= 0){
            sum -= f[i - K + 1];
        }
    }

    return res;
}

int main(){

    int N = 7;
    int MAX_N = 10000;
    string name = "BBFBFBB";    
    vector<int> dir(MAX_N);

    for (int i = 0; i < name.size();i++){
        if (name[i] == 'B')
        {
            dir[i] = 1;
        }
        else
        {
            dir[i] = 0;
        }
    }

    int K = 1, M = N;
    for (int k = 1; k < N;k++){
        int m = calc(k,dir,N);

        if (m>=0 && M>m){
            M = m;
            k = k;
        }
    }
    cout << K << " " << M << endl;
}
