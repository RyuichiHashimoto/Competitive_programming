#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<map>
using namespace std;

int ctoi(char a){
    return a - '0';
}

int main()
{
    string S;
    cin >> S;

    if (S.size()==1) {
        cout <<"Yes";
    }
    else if (S.size()==2){
        if (S[0] == S[1] and S[0]=='o'){
            cout <<"No";
        } else {
            cout <<"Yes";
        }        
    } else {
        int b =0;
        if (S[0] == 'x' and S[1] == 'x'){
            S = "o" + S;
            b = 2;
        } else if (S[0]== 'x'){
            S = "ox"+S;
            b =1; 
        }
        string base = "oxx";

        bool flag = true; 
        for(int i=b;i<S.size();i++){
            if (base[i%3] != S[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout <<"Yes";
        } else {
            cout <<"No";
        }

    }
}