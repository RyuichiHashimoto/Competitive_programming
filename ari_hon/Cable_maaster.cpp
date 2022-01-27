#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

bool check(double a,int K,double* length, int n){
    int num = 0;

    for (int i = 0; i < n;i++){
        num += (int) (length[i] / a);
    }
    return num >= K;
}



int main(){
    int N = 4;
    int K = 11;
    double L[] = {8.02, 7.43, 4.57, 5.39};

    double INF = 1.0E4+1;

    double lb = 0, ub = INF;

    while ( fabs(lb - ub) >= 1.0E-5){        
        double mid_length = (ub + lb) / 2;


        if (check(mid_length, K, L, N)) {
            lb = mid_length;
        } else {
            ub = mid_length;
        }        
    }
    cout <<  floor(ub*100)/100.0 << endl;
}
