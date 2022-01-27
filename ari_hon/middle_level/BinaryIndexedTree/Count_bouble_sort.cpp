#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void bi_dump_int(int num)
{
    int int_bytes = sizeof(int);

    int len = 8 * int_bytes;
    int bit[8 * int_bytes];
    int x;

    for (int i = 0; i < len; i++)
    {
        x = 1 << i;
        x = num & x;
        bit[len - i - 1] = x >> i;
    }
    printf("0b");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", bit[i]);
    }
}


const int MAX_N = 10000;

struct BinaryIndexTree
{
    int n;
    int value[MAX_N+1];
};


int sum(BinaryIndexTree &tree, int i)
{
    /*
        sum between value[0, i);            
    */   
    int ret = 0;
    while (i > 0)
    {
        /*
        cout << tree.value[i] << " ";
        bi_dump_int(i);
        cout << endl;
        */

        ret += tree.value[i];
        i -= (i & -i);        
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

BinaryIndexTree init_BinaryIndexTree(int *value, int n)
{
    BinaryIndexTree tree = BinaryIndexTree();
    tree.n = n;
    fill(tree.value, tree.value + MAX_N, 0);

    for (int j = 0; j < n; j++)
    {
        add(tree, j+1, value[j]);        
    }
    return tree;
}

int main(void)
{
    int n = 4;
    int a[4] = {3, 1, 4, 2};

    BinaryIndexTree tree = init_BinaryIndexTree(a,n);
    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += j - sum(tree, a[j]);
        add(tree, a[j], 1);
    }
    cout << ans << endl;
}