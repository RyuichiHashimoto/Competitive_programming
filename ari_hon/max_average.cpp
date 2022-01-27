#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

bool can_update_max(double x,int n_total_items, int n_select_items, int *profit, int *weight){
    
    double *y = new double[n_total_items];
    for (int i = 0; i < n_total_items; i++){
        y[i] = profit[i] - x * weight[i];
    }
    sort(y, y + n_total_items, greater<double>());

    double ret = 0;
    for (int i = 0; i < n_select_items;i++){
        ret += y[i];
    }
    
    delete y;
    if (ret > 0){
        return true;
    } else {
        return false;
    }    
}

int main(){

    int n= 3;
    int k = 2;
    int w[] = {2, 5, 2};
    int v[] = {2, 3, 1};

    

    double lb = 0, ub = 0x7FFFFFFF;

    
    while (  fabs(ub - lb) >1.0E-14){
        double mid = (lb + ub) / 2;
        
        if(can_update_max(mid,n, k, v,w)){
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << ub << endl;
}
