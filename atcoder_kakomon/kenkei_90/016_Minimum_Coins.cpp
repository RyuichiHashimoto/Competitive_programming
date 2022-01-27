#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void)
{
    int N, A, B, C;
    cin >> N;
    int coin[3];
    cin >> coin[0] >> coin[1] >> coin[2];
    sort(coin, coin + 3,greater<int>());
    A =  coin[0];
    B =  coin[1];
    C =  coin[2];

    int min_val = 0x7FFFFFFF;

    for (int i = 0; i <= N / A;i++){
        int rest = N - A * i;

        for (int j = 0; j <= rest/B;j++){
            int rest_2 = rest - B *j;

            if (rest_2 % C == 0){
                min_val = min(min_val, i + j + rest_2 / C);
            }
        }
    }
    cout << min_val << endl;
}