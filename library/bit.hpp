#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void display(ll x){

    int bit[64];
    fill(bit,bit+64,0);

    int counter = 0;
    while(x != 0){
        bit[counter++] = (int)(x & 1);
        x = x >> 1;
    }
    reverse(bit,bit+64);
    for(int i=0;i<64;i++){
        cout << bit[i];
    }
    cout << endl;
}