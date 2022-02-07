#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef pair<int, int> P;

typedef long long ll;

int main(){

   int T;

   cin >> T;

   rep(i,T){
      ll a,s;

      cin >> a >> s;
      
      ll amari = s - a*2;
      if (amari < 0){
         cout <<"No"<<endl;
      } else if ( (amari & a) == 0){
         cout <<"Yes"<<endl;
      } else {
         cout << "No"<<endl;
      }
            
   }   
}