#include <iostream>
using namespace std;
#include <queue>

#define MAX_V 100000
#define INF 0x6FFFFFFF

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;


int prim() {

    fill(mincost, mincost + V, INF);
    fill(used, used + V, false);
    mincost[0] = 0;
    int res = 0;

    while (true){
        int v = -1;

        for (int u = 0; u < V;u++){
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]) ){
                v = u;
            }
        }    
    }
}
