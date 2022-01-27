#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

const int INF = 0x000FFFFFF;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;



mat mul(mat &A, mat &B){
    mat ret_mat(A.size(), vec(B[0].size()));
    for(int i=0;i < A.size();i++){
        for(int k=0;k<B.size(); k++){
            for(int j=0;j<B[0].size();j++){
                
                ret_mat[i][j]  = (ret_mat[i][j] + A[i][k]*B[k][j] );
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
    int N = 2;

    mat A(3,vec(3));

    A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
    A[1][0] = 2; A[1][1] = 2; A[2][2] = 2;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;

    A = pow(A,N);
    pow(A,1);
    cout << A[0][0]<<endl;
    






    
}