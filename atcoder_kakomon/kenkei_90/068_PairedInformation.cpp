#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

vector<int> dp[MAX_N];



class Union_Find
{
private:
    int *par;
    int *rank;

public:
    Union_Find(int size)
    {
        par = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    ~Union_Find()
    {
        delete par;
        delete rank;
    }

    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            par[x] = root(par[x]);
            return par[x];
        }
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
            return;

        if (rank[x] < rank[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
};

struct query {
    int x,y,v;
}


int main(void)
{
        
    int N,Q;
    cin >> N >>Q;
    N = MAX_N;
    ll INF = 0x7FFFFFFFFFFFFFFF;

    Union_Find tree(N+1);

    
    vector<query> T0_reuqset;
    vector<query> T1_reuqset;

    vector<string> answer(Q+1);

    rep(i,1,Q){
        int t,x,y ,v;
        cin >> t >> x >> y >> v;
        
        if (t == 0){
            T0_reuqset.add(query(x,y,v));    
        } else {
            T1_reuqset.add(query(x,y,v));    
        }
    }

    for(query q: T0_reuqset) {
        
    }
}