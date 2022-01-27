#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;


#define MAX_N 5000
#define MAX_R 100000
#define INF 0x6FFFFFFF

struct edge {
    int from, to, cost;
};

int N, R;

vector<edge> Neighbor[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];
typedef pair<int, int> P;


int main(){

    priority_queue<P, vector<P>, greater<P>> pque;
    fill(dist, dist + MAX_N, INF);
    fill(dist2, dist2 + MAX_N, INF);
    dist[0] = 0;
    pque.push(P(0, 0));

    while (!pque.empty()){
        P p = pque.top();
        pque.pop();
        int d = p.first;
        int v = p.second;
        
        if (dist2[v] < d)
            continue;

        for (int i  = 0; i < Neighbor[v].size();i++){
            edge &e = Neighbor[v][i];

            int d2 = d + e.cost;
            if (dist[e.to] > d2){
                swap(dist[e.to], d2);
                pque.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                pque.push(P(dist2[e.to], e.to));
            }            
        }
    }
    cout << dist2[N - 1];
}
