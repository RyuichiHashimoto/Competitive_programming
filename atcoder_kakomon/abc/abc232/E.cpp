#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> V[10000];

typedef long long ll;

ll pow(ll x, ll n, ll mod){

   ll res = 1;
   
   while (n > 0){
      if (n &1)
         res = (res*x) %mod;
      x = (x*x) %mod;      
      n = n >> 1;
   }    
   return res;
}

int main()
{
   int H, W, K;
   int x1,y1,x2,y2;

   cin >> H>>W >> K;
   cin >> x1>>y2>>x2>>y2;

   

   

   
   cout << pow(H+W-2,K-2,998244353)*2;   
   
}