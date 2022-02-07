#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int N;


    cin >> N;

    if (N>=42){
        N++;
    }
    if (N < 10){
        cout <<"AGC00"<<N; 
    } else {
        cout <<"AGC0"<<N; 
    }


}