#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main()
{

   int N, M;
   cin >> N >> M;

   vector<string> S(N);

   map<string, int> T;

   rep(i,N){
      cin >> S[i];
   }
   rep(i,M){
      string name;
      cin >> name;
      T[name] = 1;
   }

   rep(i,N){
      if (T[S[i]]== 1){
         cout << "Yes"<<endl;
      } else {
         cout << "No"<<endl;
      }
   }


}