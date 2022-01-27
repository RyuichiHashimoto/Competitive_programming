#include <iostream>
#include <algorithm>
#include"segment_tree.hpp"
#include"../bit_utility.hpp"
using namespace std;
using namespace BinaryIndexedTree;

namespace BinaryIndexedTree
{

    const int MAX_N = 10000,n;

    int bit[MAX_N];

    int sum(int i){
        int ret = 0;
        while (i >0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret; 
    }

    void add(int i, int x){
        while (i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }

}

int main(void)
{
    
}