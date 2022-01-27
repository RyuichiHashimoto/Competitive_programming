#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

int extgcd(int a, int b, int& x, int &y){

    int d = a;

    if (b!=0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
}

int main(){

    int a = 4, b = 11;

    extgcd(4, 11,)
}
