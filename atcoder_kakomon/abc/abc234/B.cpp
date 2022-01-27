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
   int N = 0;

   cin >> N;

   vector<vector<double>> points(N);

   rep(i,N){
      points[i].resize(2);
      cin >> points[i][0] >> points[i][1];
   }

   double max_distance = -1;
   rep(i, N)
   {
      rep(j, N)
      {
         double distance = sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));

         max_distance = max(max_distance, distance);
      }
   }

   cout << std::setprecision(15)<< max_distance;
}