#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct edge
{
    int to, cap, cost, reg;
};

using namespace std;

int E, V;
const int INF = 0x7FFFFFFF;

const int MAX_V = 50000;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prev_v[MAX_V], prev_e[MAX_V];

void add_edge(int from, int to,int cap,int cost){
    G[from].push_back(edge{to, cap, cost, (int) (G[to].size())});
    G[to].push_back(edge{from, 0, -1*cost, (int )(G[to].size()-1)});
}

int min_cost_flow(int s, int t, int f){

    int res = 0;

    while (f>0){
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;

        while (update){
            update = false;
            rep(v,V){
                if (dist[v] == INF)
                    continue;

                rep(i,G[V].size()){
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v]+e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        prev_v[e.to] = v;
                        prev_e[e.to] = i;
                        update = true;
                    }
                }
            }                                                                    
        }

    }
}


int main()
{
    
    cin >> V >> E;

    int from, to, cap, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cap >> cost;
        add_edge(from,to,cap,cost);
    }


    

}