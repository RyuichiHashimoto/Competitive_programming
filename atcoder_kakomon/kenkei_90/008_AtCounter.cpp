#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string answer = "atcoder";

/*
int dfs(string &name, int idx,int counter,int N){

    if (counter==7){
        return 1;
    }

    int tmp = idx;
    int sum = 0;
    while (true)
    {
        if (idx == N+1){
            break;
        }

        int val = name.find(answer[counter],idx);
        if (val != string::npos)
        {
            sum += dfs(name, val, counter + 1, N);
        }
        else
        {
            break;
        }
        idx = val+1;
    }
    return sum;
}

int main(void){
    
    int N;
    string name;
    cin >> N;
    cin >> name;

    cout << dfs(name, 0, 0, N);
}

*/

void dp(vector<vector<int>> &dp_list, int pos, int ){



}



int main(void)
{
    

    int N;
    string name;
    cin >> N;
    cin >> name;

    vector<vector<int>> dp_list(N);
    rep(i,N){
        dp_list[i].resize(7);
        fill(dp_list[i].begin(), dp_list[i].end(), 0);
    }
    


    rep(i,7){
        if(i==0){
            rep(j,N){
                if ( name[j] == 'a'){
                    dp_list[i][j] = 1;
                }
            }
            dp_lis
        }

    }

    for (int i = 0; i < 7;i++){
        if (i == 0){

        }
        for (int j = 0; j < N; j++)
        {
            
        }
    }
        

        cout << dfs(name, 0, 0, N);
}