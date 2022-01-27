    #include <iostream>
    #include <bits/stdc++.h>
    #include<map>
    using namespace std;

    #define rep(i, n) for (int i = 0; i < (int)(n); i++)

    typedef long long ll;


    int main(void)
    {
        int N, P, Q;
        cin >> N >> P >>  Q;
        vector<ll> array(N);

        ll counter = 0;
        rep(i1, N)
        {
            rep(i2, i1)
            {
                rep(i3, i2)
                {
                    rep(i4, i3)
                    {
                        rep(i5, i4)
                        {
                            if ( (i1+i2+i3+i4+i5) % P == Q){
                                counter++;
                            }
                        }
                    }
                }
            }
        }
        cout << counter << endl;
    }