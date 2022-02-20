#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef unsigned long long ll;

vector<int> LIC(vector<int> &array){
    /* 
       1-indexed
       第i要素が最終になる単純増加数列
    */
    
    int N = array.size();
    int *dp = new int[N];

    vector<int> ret(N);  
    int INF = 0x7FFFFFFF;

    fill(dp,dp + N,INF);
    
    int cnt = 0;
    for(int i=0;i<=N ;i++){
        int s = lower_bound(dp, dp + cnt, array[i] ) - dp; 
        dp[s] = array[i];
        ret[i] = s + 1;
        if (ret[i] == cnt) cnt ++;
    }

    delete dp;
    return ret;
}


int main(void)
{
    int N;
    cin >> N;
    vector<int> rev_array(N+1);
    vector<int> normal_array(N+1);

    rep(i,1,N){
        int tmp;
        cin >> tmp;
        rev_array[i] = tmp;
        normal_array[i] = tmp;
    }
    reverse(rev_array.begin(),rev_array.end());

    vector<int> ret_from_left = LIC(normal_array);
    vector<int> ret_from_right = LIC(rev_array);

    int Answer = 0;
    rep(i,1,N){
        Answer = max(Answer, (int) ret_from_left[i] + (int)ret_from_right[i] - 1);
    }
    cout << Answer << endl;
	return 0;
}
	
    



    


    
    
    
    
    
    
    

