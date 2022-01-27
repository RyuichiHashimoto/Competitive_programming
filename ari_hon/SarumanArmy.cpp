#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;



int main(){

    int N = 6;
    int R = 10;
    int X[] = {1, 7, 15, 20, 30, 50};
    
    sort(X, X + N);
    int i = 0, ans = 0;

    
    while (i < N)
    {

        // カバーされていない領域の一番左端にある点の位置
        int s = X[i++];

        
        // i: 新たに追加するデータの候補
        while (i < N &&X[i] <= s + R) i++;

        int P = X[i - 1];

        
        while (i < N && X[i] <= P + R) i++;
        cout << P << endl;

        ans++;
    }

    cout << ans;
}
