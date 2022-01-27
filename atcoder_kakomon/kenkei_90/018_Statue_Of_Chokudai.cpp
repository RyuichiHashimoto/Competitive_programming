#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(void)
{
    int T,L,X,Y,Q;

    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;

    
    vector<int> Time_list(Q);
    rep(i,Q){
        cin >> Time_list[i];
    }

    double centor_x = 0,centor_y = 0, centor_z = L / 2.0;
    static const double pi = 3.141592653589793;

    int time = 0;

    double x,y,z;
    

    rep(i,Q){
        int time = Time_list[i];
        x = 0;
        y = cos(pi * 2*( (double) (T - time) / T) + pi*3.0 / 2.0) * L/2 + centor_y;
        z = sin(pi * 2* ( (double) (T - time ) / T) + pi*3.0 / 2.0) * L/2 + centor_z;

        double distance = sqrt((x - X) * (x - X) + (y - Y) * (y - Y) + (z-0)*(z-0));
        double angle = asin(z / distance);
        cout << std::setprecision(16) << angle * 180 / pi << endl;
    }
}