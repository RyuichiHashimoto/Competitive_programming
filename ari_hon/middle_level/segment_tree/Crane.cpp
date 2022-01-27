#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <time.h>
#include <limits.h>
#include"../../../library/graph/segment_tree.hpp"
using namespace std;

const int ST_SIZE = (1 << 16) - 1;
const int MAX_N = 10000, MAX_C = 10000;

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

void init(int k, int l, int r){

    if ( r - l  == 1){
        vy[k] = L[l];
    }
    else {
        int chl = k * 2 + 1, chr = k * 2 + 2;

        init(chl, 1, (1 + r) / 2);
        init(chl, (1 + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];        
    }
}


int main()
{
    N = 2, C = 1;

    L[0] = 10;
    L[1] = 5;

    S[0] = 1;
    A[0] = 90;

    init(0, 0, N);
}
