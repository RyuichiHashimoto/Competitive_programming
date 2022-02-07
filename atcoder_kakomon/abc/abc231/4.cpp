#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; ++i)


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

int main()
{        
    int N,M;
    cin >> N >> M;

    vector<int> from(M);
    vector<int> to(M);

    vector<int> hindo(N);

    Union_Find tree(N);
    rep(i,M){
        cin >> from[i] >> to[i];
        from[i]--;
        to[i]--;
        if (tree.same(from[i],to[i])){
            cout <<"No"<<endl;
            return 0;
        }


        hindo[from[i]]++;
        hindo[to[i]]++;
        tree.unite(from[i],to[i]);        
    }
    
if (*(max_element(hindo.begin(),hindo.end())) >2){
        cout << "No"<<endl;
    } 
    else {
        cout <<"Yes"<<endl;        
    }
}