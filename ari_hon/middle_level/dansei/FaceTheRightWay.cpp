#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;
const int MAX_N = 10000;

struct parameter{
    int N, H, R, T;
};

const double g = 10.0;

double calc(parameter &param)
{

    if (param.T<0){
        return param.H;
    } else {
        double t = sqrt(2*param.H/g);
 
        int k = (int)(param.T/t);
 
        if (k % 2 == 0)
        {
            return param.H - g * (param.T - k * t) * (param.T - k * t) / 2;
        }
        else
        {
            return param.H - g * (k * t + t - param.T) * (k * t + t - param.T) / 2;
        }
    }
}

int main(){

    
}
