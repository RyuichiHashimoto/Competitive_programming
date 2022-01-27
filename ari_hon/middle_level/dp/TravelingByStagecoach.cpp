#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

const int INF = 0x000FFFFFF;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int solve(int s, int v,int **dp, int **matrix, int n_of_city)
{
    if (dp[s][v] >= 0){
        return dp[s][v];
    }

    if ( s == (1 << n_of_city) -1 && v == 0 ){
        return dp[s][v] = 0;
    }

    int res = INF;
    rep(u,n_of_city){
        if (!(s >> u & 1)){
            res = min(res, matrix[v][u]+ solve(s | 1<<u,u, dp,matrix,n_of_city));
        }
    }
    return dp[s][v] = res;    
}

int main()
{
    int n,m,a,b;
    int INF = 0x7FFFFFFF;
    cin >> n>>m>>a>>b;    


    double **matrix = new double*[m];
    int *ticket = new int[n];

    rep(i,n) cin>>ticket[i];
    rep(i,m) matrix[i] = new double[m];
    rep(i,m) fill(matrix[i],matrix[i]+m,-1);

    rep(i,m) {
        int from,to;
        double cost;
        cin >> from >> to >> cost;
        matrix[from-1][to-1] = cost;
        matrix[to-1][from-1] = cost;
    }

    double **dp = new double*[ 1 << n];
    rep(i, 1<<n ) dp[i] = new double[m];
    rep(i, 1<<n ) fill(dp[i],dp[i]+m,INF);

    dp[ 1<<n - 1 ][a-1] = 0;    
    double res = 0xFFFFFFFF;
        
    for(int s = (1<<n) -1 ;  s >= 0;s--){                                                
        res = min(res, dp[s][b-1]);

        for(int v=0;v<m;v++){
            
            for(int i=0;i<n;i++){

                if (s>>i && 1){
                    //チケットiがまだ使用していない場合
                    for(int u=0;u < m;u++){                                                
                        if (matrix[v][u] >=0){
                            // vからuへの道があれば、チケットiを用いて移動する。                            
                            dp[ s & ~(1<<i)][u] = min(dp[ s & ~(1<<i)][u], dp[s][v] + (double)matrix[v][u]/ticket[i]);                                                        
                        }
                        
                    }                    
                }

            }
        }
    }    

    cout << res<<endl;




    rep(i, 1<<n ) delete dp[i];        
    delete dp;
    rep(i,m) delete matrix[i];
    delete matrix;



}