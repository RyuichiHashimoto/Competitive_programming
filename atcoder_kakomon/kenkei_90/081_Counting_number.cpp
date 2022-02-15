#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 5000;
int zahyo[MAX_N+1][MAX_N+1];

int main(void)
{
    fill(zahyo[0],zahyo[MAX_N+1],0);
    
    int N,K;
    cin >> N >> K;

    
    rep(i,1,N){
        int A,B;
        cin >> A >> B;
        zahyo[A][B]++;
    }

    rep(i,1,MAX_N){
        rep(j,1,MAX_N){
            zahyo[i][j]  += zahyo[i][j-1];
        }
    }

    rep(i,1,MAX_N){
        rep(j,1,MAX_N){
            zahyo[i][j]  += zahyo[i-1][j];
        }
    }

    int max_n = -1;
    rep(i,1,MAX_N - K){
        rep(j,1,MAX_N - K){
            int right_i = i + K;
            int right_j = j + K;
            max_n = max(max_n, zahyo[right_i][right_j] - zahyo[i-1][right_j] - zahyo[right_i][j-1] + zahyo[i-1][j-1]);
        }   
    }
    cout << max_n<<endl;
    
    
    
    
}
     