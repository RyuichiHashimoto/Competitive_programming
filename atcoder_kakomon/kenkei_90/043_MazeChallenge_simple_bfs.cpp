/*
    thins function does not pass the at coder

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

ll amari = 1E9 + 7;

const int INT_INF = 0x7FFFFFFF;
int cost[1001][1001];

typedef pair<int, int> P;

int main(void)
{
    int H, W;
    cin >> H >> W;

    int from_x, from_y, to_x, to_y;
    cin >> from_x >> from_y >> to_x >> to_y;
    from_x--;
    from_y--;
    to_x--;
    to_y--;

    vector<string> maze(H);
    rep(i,H){
        cin >> maze[i];
    }

    fill(cost[0], cost[1001], INT_INF);

    cost[from_x][from_y] = 0;
    
    queue<P> que;
    que.push(P(from_x, from_y));
    bool find_flag = false;

    while (!(que.empty())){
        P current_point = que.front();
        que.pop();
    
        for (int i = current_point.first + 1; i < H;i++){

            if ( maze[i][current_point.second] == '#'){
                break;
            }
            
            if (cost[i][current_point.second] > cost[current_point.first][current_point.second] + 1)
            {
                cost[i][current_point.second] = cost[current_point.first][current_point.second] + 1;
                que.push(P(i, current_point.second));
                if (i == to_x and current_point.second == to_y){
                    find_flag = true;
                }
            }
        }
        if (find_flag){
            break;
        }

        for (int i = current_point.first - 1; i >= 0; i--)
        {
            if (maze[i][current_point.second] == '#')
            {
                break;
            }
            if (cost[i][current_point.second] > cost[current_point.first][current_point.second] + 1)
            {
                cost[i][current_point.second] = cost[current_point.first][current_point.second] + 1;
                que.push(P(i, current_point.second));
                if (i == to_x and current_point.second == to_y)
                {
                    find_flag = true;
                    break;
                }
            }            
        }
        if (find_flag)
        {
            break;
        }

        for (int i = current_point.second + 1; i < W; i++)
        {

            if (maze[current_point.first][i] == '#')
            {
                break;
            }
            if (cost[current_point.first][i] > cost[current_point.first][current_point.second] + 1)
            {
                cost[current_point.first][i] = cost[current_point.first][current_point.second] + 1;
                que.push(P(current_point.first, i));
                if (current_point.first == to_x and i == to_y)
                {
                    find_flag = true;
                    break;
                }
            }
        }
        if (find_flag){
            break;
        }

        for (int i = current_point.second - 1; i >= 0; i--)
        {

            if (maze[current_point.first][i] == '#')
            {
                break;
            }
            if (cost[current_point.first][i] > cost[current_point.first][current_point.second] + 1)
            {
                cost[current_point.first][i] = cost[current_point.first][current_point.second] + 1;
                que.push(P(current_point.first, i));
            }

            if (current_point.first == to_x and i == to_y)
            {
                break;
            }
        }
        if (find_flag)
        {
            cout << "g";
            break;
        }
    }
    
    cout << cost[to_x][to_y] - 1<<endl;
}