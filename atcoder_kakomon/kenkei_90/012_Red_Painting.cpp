#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

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

int main(void)
{
    int H, W, Q;
    cin >> H >> W >> Q;

    int tmp1, tmp2, tmp3, tmp4;
    
    bool painted[2009][2009];
    fill(painted[0], painted[2009], false);
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    Union_Find uf(2009 * 2009);

    rep(i,Q){
        int t;
        cin >> t;
        if (t == 1){
            cin >> tmp1 >> tmp2;

            painted[tmp1][tmp2] = true;
            for (int d_i = 0; d_i < 4; d_i++)
            {
                int number = tmp1 * W + tmp2;

                int move_x = tmp1 + dx[d_i];
                int move_y = tmp2 + dy[d_i];

                // cout << move_x << " " << move_y << endl;

                if (painted[move_x][move_y])
                {
                    int move = move_x * W + move_y;
                    uf.unite(number, move);
                }
            }
        } else if (t == 2 ){
            cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;

            if (painted[tmp1][tmp2] && painted[tmp3][tmp4])
            {        
                int number_1 = tmp1 * W + tmp2;
                int number_2 = tmp3 * W + tmp4;
                if (uf.same(number_1, number_2))
                {
                    cout << "Yes"<<endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
     