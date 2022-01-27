#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;

vector<int> V[10000];

int main()
{
   int X, Y;
   cin >> X >> Y;

   int res = Y - X;

   if (res > 0){
      if (res %10 == 0){
         cout << res / 10 ;
      } else {
         cout << res / 10 +1 << endl;
      }      
   } else {
      cout << "0";
   }
}