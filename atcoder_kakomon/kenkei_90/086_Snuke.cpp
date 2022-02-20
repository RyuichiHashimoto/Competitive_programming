#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 12;
int bit[MAX_N][61];

ll A_CANDIATE[MAX_N+1];


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


struct query{
    int x,y,z;
    ll w;

};

int main(void)
{
    fill(bit[0],bit[MAX_N],0);
    fill(A_CANDIATE,A_CANDIATE + MAX_N, 0x7FFFFFFFFFFFFFFF);
    
    int N,Q;
    cin >> N >>Q;
    vector<query> que(Q);

    rep(i,1,Q){
        int x,y,z;
        ll w;
        que[i-1] = query{x,y,z,w};
        cin >> x >> y >>z >> w;        
        A_CANDIATE[x]  = A_CANDIATE[x] & w;        
        A_CANDIATE[y]  = A_CANDIATE[y] & w;
        A_CANDIATE[z]  = A_CANDIATE[z] & w;
    }

    for(query q:  que){
        
    }



    display( A_CANDIATE[1]);
    cout << __builtin_popcount(A_CANDIATE[1]);


    
    
    
    
    
    




    
}
     