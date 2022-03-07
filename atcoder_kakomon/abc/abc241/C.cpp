#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E4;

bool dfs(int x, int y, vector<string> &maze, int S) {

    int counter = 0;
    if (y + 6 <= S) {

        rep(i, 0, 5) {
            if (maze[x][y + i] == '.') {
                counter++;
                if (counter == 3) {
                    break;
                }
            }
        }
        if (counter <= 2) {
            return true;
        }
    }
    counter = 0;
    if (x + 6 <= S) {

        rep(i, 0, 5) {
            if (maze[x + i][y] == '.') {
                counter++;
                if (counter == 3) {
                    break;
                }
            }
        }
        if (counter <= 2) {
            return true;
        }
    }
    counter = 0;
    if (x + 6 <= S && y + 6 <= S) {

        rep(i, 0, 5) {
            // cout << maze[x + i][y + i];
            if (maze[x + i][y + i] == '.') {
                counter++;
                if (counter == 3) {
                    break;
                }
            }
        }
        if (counter <= 2) {
            return true;
        }
    }
    counter = 0;
    if (x >= 5 && y + 6 <= S) {

        rep(i, 0, 5) {
            if (maze[x - i][y + i] == '.') {
                counter++;
                if (counter == 3) {
                    break;
                }
            }
        }
        if (counter <= 2) {
            return true;
        }
    }
    return false;
}


int main(void) {

    int S;

    cin >> S;

    vector<string> maze(S);

    rep(i, 0, S - 1) {
        cin >> maze[i];
    }
    // cout << dfs(4, 4, maze, S) << endl;
    rep(i, 0, S - 1) {
        rep(j, 0, S - 1) {
            // cout << i << " " << j << endl;
            if (dfs(i, j, maze, S)) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}