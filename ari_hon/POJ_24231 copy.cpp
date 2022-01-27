#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

int main(){

    int N = 4;
    int P = 10;

    int A[] = {10, 14, 20, 21, 25};
    int B[] = {10, 5, 2, 4, 0};

    priority_queue<int> pque;

    int ans = 0, pos = 0, tank = P;
    
    
    for (int i = 0; i < N;i++){
        // if ()
        /* 現在位置から次のガソリンスタンドまでの距離*/
        int d = A[i] - pos;
        
        while (tank < d){
            if (pque.empty()){
                ans = -1;
                break;
            } else {
                tank = tank + pque.top();
                pque.pop();
                ans++;
            }
        }
        if (ans == -1)
            break;

        tank = tank - d;
        pos = A[i];
        pque.push(B[i]);
    }

    cout << ans << endl;
}