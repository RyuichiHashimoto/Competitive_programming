#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(string moji,int left_counter,int right_counter, int n){    
    if ( (left_counter + right_counter) ==n){
        cout << moji << endl;
        return;
    }

    if (left_counter == 0){
        dfs(moji + "(", left_counter + 1,right_counter,n);
    } else if (left_counter == right_counter){
        dfs(moji + "(", left_counter + 1, right_counter, n);
    } else if ((2*left_counter) == n) {        
        dfs(moji + ")", left_counter, right_counter + 1, n);
    }  else {
        dfs(moji + "(", left_counter + 1,right_counter,n);
        dfs(moji + ")", left_counter , right_counter+1,n);
    }
}


int main(void)
{
    int N;
    cin >> N;

    if (N%2 == 0){
        dfs("", 0,0,  N);
    }
    
}