#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int ctoi(char a){
    return a - '0';
}

int main()
{
    string masg = "";
    cin >> masg;

    if (masg[0] == masg[1] && masg[2] == masg[3] && masg[0] == masg[3])
    {
        cout << "Weak";
    } else {
        bool sequence_flag = true;
        for (int i = 0; i < 3; i++)
        {
            if ( (ctoi(masg[i + 1]) - ctoi(masg[i]) != 1) and (ctoi(masg[i + 1]) - ctoi(masg[i]) != -9))
            {
                sequence_flag = false;        
            }
        }

        if (sequence_flag)
        {
            cout << "Weak";
        }
        else
        {
            cout << "Strong";
        }
    }
    
}