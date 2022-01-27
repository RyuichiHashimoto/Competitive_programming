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
int cost[1001][1001][4];

struct status{
    int x, y, direct;
};

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

    fill(cost[0][0], cost[1001][0], INT_INF);
    cost[from_x][from_y][0] = 0;
    cost[from_x][from_y][1] = 0;
    cost[from_x][from_y][2] = 0;
    cost[from_x][from_y][3] = 0;

    deque<status> que;
    que.push_front(status{from_x,from_y,0});
    que.push_front(status{from_x, from_y, 1});
    que.push_front(status{from_x, from_y, 2});
    que.push_front(status{from_x, from_y, 3});

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    while (!(que.empty())){
        status s = que.front();
        que.pop_front();
        // cout << s.x << " " << s.y << " " << s.direct << " " << cost[s.x][s.y][s.direct]<<endl;

        for (int i = 0; i < 4;i++){
            if (s.direct == i){
                int next_point_x = s.x + dx[i];
                int next_point_y = s.y + dy[i];

                if (next_point_x >= H or next_point_x < 0 or next_point_y >= W or next_point_y < 0){
                    continue;
                }

                if (maze[next_point_x][next_point_y] == '.' && cost[next_point_x][next_point_y][i] > cost[s.x][s.y][s.direct])
                {
                    cost[next_point_x][next_point_y][i] = cost[s.x][s.y][i];
                    que.push_front(status{next_point_x, next_point_y, i});
                }
            } else {
                if (cost[s.x][s.y][i] >  cost[s.x][s.y][s.direct]+1)
                {
                    cost[s.x][s.y][i] = cost[s.x][s.y][s.direct]+1;
                    que.push_back(status{s.x,s.y,i});
                }
            }                    
        }
    }
   int min_val = INT_INF;

   rep(i, 4)
   {
       min_val = min(min_val, cost[to_x][to_y][i]);
   }
   cout << min_val << endl;
}