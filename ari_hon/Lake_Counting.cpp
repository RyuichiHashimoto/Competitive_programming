#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

void dfs(int x, int y, vector<string> &lake, int N, int M){
    lake[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            int pos_x = dx + x;
            int pos_y = dy + y;

            
            
            // 検索対象範囲内か
            if ( (pos_x < N and pos_x >= 0) && (pos_y < M and pos_y >= 0) )  {
                if (lake[pos_x][pos_y] == 'W'){
                    dfs(pos_x, pos_y, lake, N, M);
                }
            }
        }
    }
}


int main(){
    
    clock_t start  = clock();
    int N = -1,M=-1;
    cin >> N >> M;

    vector<string> lake(N);

    for (int i=0;i<N;i++){
        cin >> lake[i];
    }

    
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            if (lake[i][j] == 'W'){
                dfs(i, j, lake,N, M );
                counter = counter + 1;
            }
        }
    }
    cout << counter << endl;
}