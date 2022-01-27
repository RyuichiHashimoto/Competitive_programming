#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;

vector<int> G[10000];
int color[10000];  // 頂点iの色 (1 or -1 or others)

bool dfs(int v, int c){
    /* 頂点vがcで塗れるか
    
        判定方法： 
            隣接ノードが-cで塗れるか
            隣接ノードの隣接ノードがcで塗れるか

    */    
    color[v] = c;

    for (int i = 0; i < G[v].size();i++){
        
        if (color[G[v][i]] == c){
            return false;
        }

        if (color[G[v][i]] == 0 && ! dfs(G[v][i],-1*c)){
            return false;
        }
    }
    return true;
}

int main()
{
    int V, E;

    cin >> V >> E;

    int start, to;
    for (int i = 0; i < E; i++){
        cin >> start >> to;
        G[start].push_back(to);
        G[to].push_back(start);
    }

    memset(color, 10000, 0);
    bool flag = true;
    for (int i = 0; i < V; i++)
    {
        if ( color[i] == 0 ){
            if (!dfs(i,1)){
                cout << "No";
                flag = false;
            }
        }
                
    }
    if (flag){
        cout << "Yes";
    }
}