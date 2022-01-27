#include <iostream>
#include <algorithm>
#include"segment_tree.hpp"
using namespace std;


namespace BinaryIndexedTree{

    const int MAX_N = 10000;

    struct BinaryIndexTree{
        int n;
        int value[MAX_N];
    };

    int sum(BinaryIndexTree &tree, int i)
    {
        /*
            sum between value[0, i);            
        */       
        int ret = 0;
        while (i > 0)
        {
            ret += tree.value[i];
            i -= i & -i;
        }
        return ret;
    }
    
    void add(BinaryIndexTree &tree, int i, int x)
    {
        /*
            add the i th leaf node. 
        */
                
        while (i <= tree.n)
        {
            tree.value[i] += x;
            i += i & -i;
        }
    }
};
