#include <iostream>
#include <algorithm>
using namespace std;

namespace tree{

    const int MAX_N = 1 << 17;
    

    struct segment_tree
    {
        int n;
        int dat[2 * MAX_N - 1];
    };

    tree::segment_tree init_segment_tree(int n);

    void update(int key, int value, segment_tree &tree);
    
    int __query(segment_tree & tree, int a, int b, int k, int l, int r);
    int query(segment_tree &tree, int a, int b);
}
