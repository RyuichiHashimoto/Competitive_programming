#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

const int MAX_H = 17;
const int MAX_W = 17;

bool used[MAX_H][MAX_W];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x,int y,vector<string> &map,int N,int value){


    for (int i = 0; i < 4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= N || next_x < 0 || next_x >= N || next_y < 0){
            continue;
        }

        if (!used[next_x][next_y] && map[next_x][next_y] == '.'){
            used[next_x][next_y] = true;
            dfs(next_x,next_y,map,N,value+1)
            used[next_x][next_y] = false;
        }
    }
}

int main(void)
{
    int N;
    cin >> N;

    vector<string> map(N);

    rep(i,N){
        cin >> map[i];
    }
    int max_val = -1;
    rep(i, 16)
    {
        rep(j,16){
            fill(used[0], used[MAX_H], false);
            max_val = max(dfs(),max_val);
        }
    }
}