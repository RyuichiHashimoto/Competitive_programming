#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int A, B;

    cin >> A >> B;

    if ( 0 <A && B==0){
        cout << "Gold";
    } else if ( A==0 && 0 <B){
        cout << "Silver";
    } else if (0 <A && 0 < B) {
        cout << "Alloy";
    }
}