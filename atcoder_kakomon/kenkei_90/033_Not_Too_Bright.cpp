    #include <iostream>
    #include <bits/stdc++.h>
    #include<map>
    using namespace std;

    #define rep(i, n) for (int i = 0; i < (int)(n); i++)

    typedef long long ll;

    typedef pair<ll, ll> P;

    int main(void)
    {
        int a, b;

        cin >> a >> b;

        if (a == 1 or b == 1){
            cout << a * b;
        }
        else
        {
            cout << ((a + 1) / 2) *((b+1)/2);
        }
    }