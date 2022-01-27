#include<iostream>
using namespace std;
#include <limits.h>

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

void bi_dump_long_long(long long num)
{
    int int_bytes = sizeof(long long);

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
        cout << bit[i];
    }
}
