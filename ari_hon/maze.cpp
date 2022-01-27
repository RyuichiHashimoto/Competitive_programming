#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef pair<int, int> Point;

int main(){

    const int INF = 10000;
    int N = -1, M = -1;
    cin >> N >> M;

    vector<string> maze(N);
    vector<vector<int> > distance_from_gole(N);
    for (int i = 0; i < N;i++){
        distance_from_gole[i] = vector<int>(M);
        for (int j = 0; j < M;j++){            
            distance_from_gole[i][j] = INF;            
        }
    }

    for (int i = 0; i < N; i++){
            cin >> maze[i];
    }

    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int S_X = -1, S_Y = -1;
    int G_X = -1, G_Y = -1;
    queue<Point> que;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M;j++){
            if (maze[i][j] == 'S'){
                S_X = i;
                S_Y = j;
                distance_from_gole[i][j] = 0;
                que.push(Point(i, j));
            }
            if (maze[i][j] == 'G'){
                G_X = i;
                G_Y = j;
            }
        }
    }

    bool find_flag = false;
    while (que.size())
    {
        Point point = que.front();que.pop();

        if (point.first == G_X && point.second == G_Y)
        {
            break;
        }
                
        for (int i = 0; i < 4; i++){
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && distance_from_gole[nx][ny] == INF)
            {

                que.push(Point(nx, ny));
                distance_from_gole[nx][ny] = distance_from_gole[point.first][point.second] + 1;
            }
        }
    }
    cout << distance_from_gole[G_X][G_Y];
}