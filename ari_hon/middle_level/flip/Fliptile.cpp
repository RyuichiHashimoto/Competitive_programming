#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;
const int MAX_N = 10000;

int offset = 1;

const int dx[5] = {-1, 0,0,0,1};
const int dy[5] = {0, 1, 0, -1, 0};


void cpy(int **src,int **dst,int n,int m){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

int get_color(int** initial_tile,int **flip,int x,int y,int n,int m){

    int reverse_times = 0;
    for (int i = 0; i < 5; i++)
    {
        int x_pos = x + dx[i];
        int y_pos = y + dy[i];

        if ((x_pos >=0 && x_pos<n) && ( y_pos >= 0 && y_pos<m)){
            reverse_times = reverse_times + flip[x_pos][y_pos];
        }        
    }
    return (reverse_times + initial_tile[x][y]) % 2;
}

int check(int **initial_tile,int **flip, int n, int m)
{

    for (int i = 1; i < n;i++){
        for (int j = 0; j < m; j++)
        {
            if (get_color(initial_tile,flip,i-1,j,n,m) == 1){
                flip[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < m; j++){

        if (get_color(initial_tile, flip, n-1, j, n, m) == 1){
            return -1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m; j++)
        {
            sum += flip[i][j];
        }
    }
    return sum;
}

int main(){
    int n, m;

    cin >> n >> m;

    int **initial_tile, **working_tile, **opt_tile,**empty_tile;

    initial_tile = new int *[n];
    working_tile = new int *[n];
    opt_tile = new int *[n];
    empty_tile = new int *[n];

    for (int i = 0; i < n; i++)
    {
        initial_tile[i] = new int[m];
        working_tile[i] = new int[m];
        opt_tile[i] = new int[m];
        empty_tile[i] = new int[m];

        for (int j = 0; j < m; j++)
        {
            cin >> initial_tile[i][j];
            empty_tile[i][j] = 0;
        }
    }

    int minimum_n_operator = 0x7FFFFFFF;
    for (int i = 0; i < (1 << n); i++)
    {
        // memset(working_tile, sizeof(working_tile), 0);
        cpy(working_tile, opt_tile, n, m);

        for (int j = 0; j < m;j++){
            working_tile[0][j] = (i >> j) & 1;
        }

        int chekc_result = check(initial_tile,working_tile, n, m);

        if ((chekc_result != -1) && chekc_result < minimum_n_operator)
        {                        
            cpy(working_tile, opt_tile, n, m);
            minimum_n_operator = chekc_result;            
        }
    }
    if (minimum_n_operator == -1){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << opt_tile[i][j] + " ";
            }
            cout << endl;
        }
    }
}
