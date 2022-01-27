#include <iostream>
using namespace std;
#include <limits.h>
#include <queue>

typedef long long ll;

int main(void)
{
    int n = 5;
    int a[] = {2, 3, 3, 5, 6};

    int k = 3;

    int lb = -1, ub = n;

    
    while (ub - lb >= 1)
    {
        int mid = ( ub - lb) / 2;        
        if (k >= a[mid])
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }
    cout << ub;
}