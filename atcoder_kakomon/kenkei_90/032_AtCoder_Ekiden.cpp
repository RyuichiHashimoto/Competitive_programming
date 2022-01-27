#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;
const int MAX_N = 11;

bool used[MAX_N];
vector<vector<int>> time_(MAX_N);
vector<vector<int>> hunaka(MAX_N);

int main(void)
{
    int N;
    int M;    
    cin >> N;
    
    time_.resize(N);
    hunaka.resize(N);

    rep(i,N){
        time_[i].resize(N);
        hunaka[i].resize(N);

        rep(j,N){
            cin >> time_[i][j];
        }
    }

    cin >> M;
    int tmp1, tmp2;
    rep(i, M)
    {                
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        hunaka[tmp1][tmp2] = 1;
        hunaka[tmp2][tmp1] = 1;
    }
    vector<int> permutation(N);
    rep(i,N){
        permutation[i] = i;
    }
    
    int min_value = 0x7FFFFFFF;
    do
    {
        int sum = 0;
        bool break_flag = false;
        rep(i, N)
        {
            if ( !(i==N-1) && hunaka[permutation[i]][permutation[i + 1]] == 1)
            {
                break_flag = true;
                break;
            }

            sum += time_[permutation[i]][i];
        }

        if (!break_flag){
            min_value = min(min_value, sum);
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    if (min_value == 0x7FFFFFFF){
        cout << "-1";
    } else {
        cout << min_value;
    }
        
}