#include "unionFind.hpp"

union_find::~union_find()
{
    delete parent;
    delete rank;
}

union_find::union_find(int n)
{
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int union_find::find_root(int x){
    /*                        
        return the root node of a tree containng x.
        x: node number        
    */
    if (parent[x] == x)
    {
        return x;
   } else {
       return parent[x] = find_root(parent[x]);
   }
}

bool union_find::same(int x, int y)
{
    /*
        x, y: node number;
        return:
            true: x and y belong to a same tree.
            false: x and y belong to different trees.
    */
    return find_root(x) == find_root(y);
}

void union_find::unite(int x, int y)
{
    /*        
        merge two trees which each of the arguments belong to.
        
        x, y: node to merged with each other.
         
        x, y need not to be a root node.
        it dose not matter whether x  and y belong to a same  tree.
    */

    int root_x = find_root(x);
    int root_y = find_root(y);

    if (root_x == root_y)
    {
        return;
    }

    if (rank[x] < rank[y])
    {
        /*
            
        */
        parent[x] = y;
    }
    else
    {
        rank[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}
