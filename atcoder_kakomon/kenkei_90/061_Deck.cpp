    #include <iostream>
    #include <bits/stdc++.h>
    #include<map>
    using namespace std;

    #define rep(i, n) for (int i = 0; i < (int)(n); i++)

    typedef long long ll;


    int main(void)
    {
        const int max_q = 1.0E5;
        vector<int> array(max_q * 2+2);

        int start = max_q;
        int end = max_q;
        int Q;
        cin >> Q;

        rep(i,Q){
            int t1, t2;
            cin >> t1 >> t2;

            if (t1 == 1){
                start--;
                array[start] = t2;
            } else if (t1 == 2){                
                array[end++] = t2;
            } else if (t1 == 3){
                cout << array[start + t2-1]<<endl;
            }
            // cout << "----------------------" << endl;
            
            for (int j = start; j < end; j++)
            {
                // cout << array[j] <<" ";
            }
            // cout << endl;
        }
    }