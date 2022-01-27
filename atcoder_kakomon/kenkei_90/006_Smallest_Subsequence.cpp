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




int main(void)
{
    int N, K;
    string massag;

    cin >> N >> K;
    cin >> massag;

    const int s = massag.size();
    int nex[massag.size()+1][26];
    
    rep(i, 26) nex[massag.size()][i] = massag.size();

    for (int i = massag.size() - 1; i >= 0; i--)
    {
        rep(j,26){
            if (massag[i] - 'a' == j){
                nex[i][j] = i;
            } else {
                nex[i][j] = nex[i+1][j];
            }
        }                        
    }

    int CurrentPos = 0;
    string Answer = "";
    rep(_, K)
    {
        int i = _ + 1;

        rep(j,26){
            int NexPos = nex[CurrentPos][j];
            int MaxPossibleLength = (int)(massag.size() - NexPos - 1) + i;
            if (MaxPossibleLength >= K){
                Answer += (char)('a' + j);
                CurrentPos = NexPos + 1;
                break;
            }
        }
    }
    cout << Answer;
}