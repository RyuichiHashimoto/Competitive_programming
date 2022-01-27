#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void)
{
    int N, L, K;

    cin >> N >> L;
    cin >> K;
    int *A_list = new int[N+2];

    A_list[0] = 0;
    A_list[N+1] = L;

    rep(i, N)
        cin >> A_list[i + 1];
}