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
    int n,k,m;
            
    cin >> n >> k>>m;

    mat A(n, vec(n));

    rep(i,n)
        rep(j,n)
            cin >> A[i][j];

    
    mat B(2*n, vec(2*n));

    rep(i,n){
        rep(j,n){
            B[i][j] = A[i][j];
        }
        B[i+n][i] = B[i+n][i+n] = 1;
    }
    
    mat C = pow(B,k+1);
    
    
    rep(i,n){
        rep(j,n)
            cout << C[i][j] % M <<" ";
        cout << endl;
        
    }




}  