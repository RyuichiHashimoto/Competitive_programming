#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;

vector<int> V[10000];

int main()
{
   string S,T;

   cin >> S;
   cin >> T;

    bool flag = true;
    for(int i=0;i<(int) S.size();i++){
        int a = (S[i] - S[0]);
        if (a < 0) a += 26;


        int b = (T[i] - T[0]);
        if (b < 0) b += 26;
                
        if ( a != b){
            flag = false;
            break;
        }                         
    }

    if (flag){
        cout << "Yes";
    } else {
        cout << "No";
    }


}