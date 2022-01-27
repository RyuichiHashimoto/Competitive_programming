#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

const int INF = 0x000FFFFFF;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)





int main()
{
   int n, m;

   double **zahyo;

   cin >> n >> m;
   zahyo = new double*[n];
   rep(i,n) zahyo[i] = new double[m];   
         
   rep(i,n){
       rep(j,m){
           char tmp;
           cin >> tmp;

           if (tmp == 'x'){
               zahyo[i][j] = 1;
           } else if (tmp == '.') {
               zahyo[i][j] = 0;
           } else {
               cerr << "unexpected error has occured";
           }        
       }       
    }
    int dp** = new int[2];
    rep(i,2) dp[i] = new int[1 << m];    

    int *crt = dp[0],*next = dp[1];

    crt[0] = 0;

    for(int i = n -1; i >= 0;i--){
        for(int j=m-1;j>= 0;j--){
            for(int u = 0;u < 1 <<m;u++){
                if( ( (used >> j) &1) || zahyo[i][j]){
                    next[used] = crt[used &~(1<<j)];
                                    
                }





            }


        }


    }

    
    
    bool **used = new bool[n]
    rep(i,n) used[i] = new bool[m];       
    rep(i,n) delete used[i];
    delete used;
    rep(i,n) delete zahyo[i];
    delete zahyo;
    rep(i,2) delete dp[i];
    delete dp;




}