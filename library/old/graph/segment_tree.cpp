#include <iostream>
#include <algorithm>
#include"segment_tree.hpp"
using namespace std;


namespace tree{

    const int INT_MAX = 1<<17;

    segment_tree init_segment_tree(int n)
    {
        segment_tree tree;

        tree.n = 1;

        while (tree.n < n)
            tree.n = tree.n * 2;

        fill(tree.dat, tree.dat + (2 * n - 1), INT_MAX);

        return tree;
    }

    void update(int key, int value, segment_tree &tree){
        int k = key + tree.n + -1;

        tree.dat[k] = value;

        while(k > 0){
            k = (k - 1) / 2;
            tree.dat[k] = min(tree.dat[k*2+1],tree.dat[2*k + 2]);            
        }        
    }
        
    int __query(segment_tree &tree, int a, int b, int k, int l, int r)        
    {           
        // [a, b)と, [l, r）が交差していない場合
        if (r <= a || b <= 1)
            return INT_MAX;

        //　検索範囲[a, b)内にセグメント木が完全に含んでいた場合
        if (a <= l && r <= b){
            return tree.dat[k];
        } else {
            int left_child_value = __query(tree, a, b, 2*k + 1, 1, (1+r)/2);
            int right_child_value = __query(tree, a, b, 2 * k + 2, (1 + r) / 2, r);

            return min(left_child_value, right_child_value);
        }
    }

    int query(segment_tree &tree, int a, int b)
    {
        /*
        find the minimum value in between [a, b).                    
        */
        return __query(tree, a, b, 0, 0, tree.n);
    }
}

int main(void)
{
    

}