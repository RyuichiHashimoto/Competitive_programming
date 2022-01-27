#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

const int INF = 0x7FFFFFFF;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_V 5000

using namespace std;

struct edge {
    int to; // 宛先ノードの番号
    int cap; // 該当辺の残余量
    int rev; // 
};


struct flow_graph{    
    vector<edge> G[MAX_V];
    bool used[MAX_V];
};

void add_edge(flow_graph &graph,int from, int to, int cap){
    graph.G[from].push_back(edge{to,cap, (int) graph.G[to].size()});
    graph.G[to].push_back(edge{from,0, (int)graph.G[from].size()-1});
}

int dfs(flow_graph &graph,int v, int t, int f)
{
    /*
        v: from node idx
        t: to node idx
        f: flow

    */
    if (v==t) return f;

    graph.used[v] = true;

    for( int i=0; i<graph.G[v].size(); i++){
        edge &e = graph.G[v][i];
        cout << i << endl;

        if (!graph.used[e.to] && e.cap > 0){
            int d = dfs(graph,e.to, t,min(f,e.cap));

            if (d > 0){
                e.cap -= d;
                graph.G[e.to][e.rev].cap += d;
                return d;
            }            
        }        
    }
    return 0;
}

int max_flow(flow_graph &graph,int s, int t){

    int flow = 0;
    for(;;){
        memset(graph.used,0,sizeof(MAX_V));
        int f = dfs(graph,s,t,INF);

        if (f == 0)
            return flow;

        flow += f;
    }

}

int main()
{
    int n_of_edge, n_of_vetrix;

    cin >> n_of_vetrix >> n_of_edge;

    flow_graph graph;
    rep(i,n_of_edge){
        int from,to,capa;
        cin >> from >> to >> capa;
        add_edge(graph,from,to,capa);
    }


    cout << max_flow(graph,0,4);



    

    

}