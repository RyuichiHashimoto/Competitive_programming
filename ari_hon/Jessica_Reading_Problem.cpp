#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;




int main(){

    int P = 5;
    int a[] = {1, 8, 8, 8, 1};
    
    set<int> all;

    for (int i = 0; i < P;i++){
        all.insert(a[i]);        
    }

    int n = all.size();

    int s = 0; /*勉強開始位置*/ 
    int t = 0; /*勉強終了位置*/   
    int num = 0; /*見つけたユニークな内容の数*/
    map<int, int> count; //key: ページの内容, value: count ofthe page;
    int res = P;

    for (;;)
    {
        while (t < P && num < n){
            /*全種類が取得できる or 勉強終了位置が終わりに来るまで*/
            
            if (count[a[t]] == 0)
            {
                num++;
            }
            count[a[t]]++;
            t++;
            
        }

        if ( num < n)
            break;

        res = min(res, t - s);

        if(--count[a[s++]]==0){
            num--;
        }
    }
    cout << res;
}
