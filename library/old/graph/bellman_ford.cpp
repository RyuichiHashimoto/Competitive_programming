#include<iostream>
using namespace std;
#include <limits.h>
#include<queue>

struct edge {
    int from;
    int to;
    int cost;
};

int V=10, E=10;
edge es[10000];
int d[10000];
int INF = 0x6FFFFFFF;

void shorted_path(int s){
    for (int i = 0; i < V; i++)
    {
        d[i] = INF;        
    }
    d[s] = 0;
    while (true)
    {
        bool update = false;
        for (int i = 0; i < E; i++){
            edge e = es[i];

            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost ){
                /*eがはじめの視点または、d[e.to]はもともとある到達点へのへのコスト。*/
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (update != true){
            break;
        }
    }
    cout << d[0];
}


int main(void){

    int max_e = 10000;
    
    
    
    shorted_path(4);
}