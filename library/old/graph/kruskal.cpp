#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100000
#define MAX_E 100000

struct edge {
    int u, v, cost;
};


int E, V;
edge es[MAX_E];

int kruskal() {

    sort(es, es + E, comp);
    init_union_find(E);

    int res = 0;
    for (int i = 0; i < E; i++)
    {
        edge e = es[i];
        if (!same(e.u,e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

/*
    クラスカルの実装にunion foundを用いるため。
*/

#define uf_MAX_N 100000

int uf_par[uf_MAX_N];  // parent node number
int uf_rank[uf_MAX_N]; // A tree height the (idx) contains

void init_union_find(int n)
{
    
    /*
        n: the number of candidate.        
        initialize for union find serarch.
    */        
    for (int i = 0; i < n; i++)
    {
        uf_par[i] = i; 
        uf_rank[i] = 0;
    }
}

int find(int x)
{
    if (uf_par[x] == x)
    {
        return x;
    }
    else
    {
        return uf_par[x] = find(uf_par[x]);
    }
}

void unite(int x, int y)
{
    /*        
        merge two trees which each of the arguments belong to.
        
        x, y: node to merged with each other.
         
        x, y need not to be a root node.
        it dose not matter whether x  and y belong to a same  tree.
    */

    int root_x = find(x);
    int root_y = find(y);

    
    if (root_x == root_y){        
        return;
    }

    if (uf_rank[x] < uf_rank[y])
    {
        /*
            
        */        
        uf_par[x] = y;
    }
    else
    {
        uf_par[y] = x;
        if (uf_rank[x] == uf_rank[y])
            uf_rank[x]++;
    }
}

bool same(int x, int y)
{
    /*
        x, y: node number;
        return:
            true: x and y belong to a same tree.
            false: x and y belong to different trees.
    */
    return find(x) == find(y);
}


int main(void)
{



}