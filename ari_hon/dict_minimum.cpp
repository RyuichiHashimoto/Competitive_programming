#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef pair<int, int> Point;

int main(){

    const int INF = 10000;
    int N = 6;
    string S = "ACDBCB";


    // a: 探索文字列の左端、b = 探索範囲の右端
    int a = 0, b = N - 1;
    int counter = 0;
    int left, right;

    while (a <= b){
        for (int i = 0; i < N - counter; i++)
        {
            // 
            if  (S[a + i] < S[b - i ]){
                left = true;
                break;
            }
            else if (S[a + i] < S[b - i]) {
                left = false;
                break;
            }                        
        }

        if (left)
            putchar(S[a++]);
        else
            putchar(S[b--]);
    }
    
}