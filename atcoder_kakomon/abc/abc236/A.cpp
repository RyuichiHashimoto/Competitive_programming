#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int x){
   return x * x + 2 * x + 3;
}

int main()
{

   string name;

   cin >> name;
   int a, b;
   cin >> a >> b;
   a--;
   b--;

   char tmp = name[a];

   name[a] = name[b];
   name[b] = tmp;
   cout << name;
}