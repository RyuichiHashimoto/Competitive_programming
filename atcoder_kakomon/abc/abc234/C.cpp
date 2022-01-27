#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

int main()
{
   ll x = -1;

   cin >> x;

   string name = "";
   while (x != 0)
   {

      if (x % 2 == 1){
         name = "2" + name;
      } else {
         name = "0" + name;      
      }
      x = x / 2;
   }
   cout << name;
}