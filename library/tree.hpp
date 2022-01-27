#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
