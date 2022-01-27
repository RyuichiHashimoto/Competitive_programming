#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>
#include<tuple>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

int main()
{
   int N, Q;

   cin >> N >> Q;

   vector<int> perm(N+1);
   
   perm[0] = -1;
   
   
   map<int, int> count;
   map<P, int> query_ret;

   rep(i,N){
      int a;
      cin >> a;
      count[a] = count[a] + 1;

      P p(a, count[a]);
      query_ret[p] = i+1;
      
   }

   rep(i,Q){
      int a, b;
      cin >> a>>b;
      // cout << a << b << endl;

      int ret = query_ret[P(a,b)];

      if (ret == 0){
         cout << "-1"<<endl;
      } else {
         cout << ret << endl;
      }
   }
}