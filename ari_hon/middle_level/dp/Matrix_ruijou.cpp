#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 10000;

mat mul(mat &A, mat &B){
    mat ret_mat(A.size(), vec(B[0].size()));

    for(int i=0;i < A.size();i++){
        for(int k=0;k<B.size(); k++){
            for(int j=0;j<B[0].size();j++){
                ret_mat[i][j]  = (ret_mat[i][j] + A[i][k]*B[k][j] )  % M;
            }
        }
    }    
    return ret_mat;    
}

mat pow(mat A, ll n){

    mat B(A.size(), vec(A.size()));
    
    rep(i, A.size()) B[i][i] = 1;

    while (n > 0){
        if (n &1)
            B = mul(B,A);
        A = mul(A,A);
        n = n >> 1;
    }
    
    return B;
}

int main()
{
    int n = 10;

    mat A(2,vec(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;

    A = pow(A,n);
    cout << A[1][0]<<endl;    
}