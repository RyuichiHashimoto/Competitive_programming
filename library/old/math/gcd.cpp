#include <iostream>
using namespace std;
#include <limits.h>
#include <queue>

int gcd(int a, int b){
    if (b == 0){
        return a;
    }        
    return gcd(b, a % b);
}

int main(void){

    int a = 15;
    int b = 10;
                
    cout << gcd(a, b);
}