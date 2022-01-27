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
   int N, K;

   cin >> N >> K;

   vector<double> Perm(N);

   priority_queue<double,vector<double>,greater<double>> pque;

   rep(i,N){
      cin >> Perm[i];
   }

   rep(i,K){
      pque.push(Perm[i]);
   }
   
   for (int i = K; i < N;i++){
      cout << pque.top() << endl;
      pque.push(Perm[i]);
      pque.pop();
   }
   cout << pque.top() << endl;
}