    #include <iostream>
    #include <bits/stdc++.h>
    #include<map>
    using namespace std;

    #define rep(i, n) for (int i = 0; i < (int)(n); i++)

    typedef long long ll;


    int main(void)
    {
        int Q;
        cin >> Q;

        deque<int> que;
        rep(i, Q)
        {
            int t1, t2;
            cin >> t1 >> t2;
            if (t1 == 1)
                que.push_front(t2);
            if (t1 == 2)
                que.push_back(t2);
            if (t1 == 3)
                cout << que[t2-1]<<endl;
        }
    }