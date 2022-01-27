#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


typedef pair<int, int> P;

class edge{    
    public:
        int from;
        int to;
        int cost;    

        edge(int _from, int _to, int _cost){
            from = _from;
            to = _to;
            cost = _cost;
        }
};

class Graph{
    public:
        vector<vector<edge>> G;
        int minimum_node_idx;
        int maximum_node_idx;
        int n_vetrics;

        Graph(int n_of_vetrics){
            G.resize(n_of_vetrics+1);
            n_vetrics = n_of_vetrics;
            minimum_node_idx = 0x7FFFFFFF;
            maximum_node_idx = 0x80000000;
            
        }

        void add_edge(edge &x){            
            G[x.from].push_back(x);
            minimum_node_idx = min(minimum_node_idx, x.from);
            minimum_node_idx = min(minimum_node_idx, x.to);
            maximum_node_idx = max(maximum_node_idx, x.from);
            maximum_node_idx = max(maximum_node_idx, x.to);
        }

        int get_rank(int idx){
            return G[idx].size();
        }
};

vector<int> Dykstra(Graph &graph,int s){
    /*  
        s:  start idx;
    */

    int INF = 0x7FFFFFFF;

    if (s < graph.minimum_node_idx || s > graph.maximum_node_idx)
    {
        cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl<<"not " << s;
        exit(1);
    }

    vector<int> ret_distance(graph.n_vetrics);
    fill(ret_distance.begin(), ret_distance.end(), INF);

    // P: Pair<int, int>
    //    first int: metrics(e.g., cost, distance)
    //    second int: index of the node;
    priority_queue<P, vector<P>, greater<P>> que;

    ret_distance[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top();
        que.pop();

        int v = p.second;

        rep(i, graph.G[v].size()){
            edge &e = graph.G[v][i];

            if (ret_distance[e.to] > ret_distance[e.from]+e.cost){
                ret_distance[e.to] = ret_distance[e.from] + e.cost;
                que.push(P(ret_distance[e.to], e.to));
            }
        }
    }
    return ret_distance;
}

vector<int> get_dist(Graph &graph, int start)
{
    vector<int> ret(graph.n_vetrics);
    queue<int> que;
    int INF_ = 0x7FFFFFFF;
    fill(ret.begin(), ret.end(), INF_);

    que.push(start);
    ret[start] = 0;

    while(!(que.empty())){
        int index = que.front();
        que.pop();

        for (int i = 0; i < graph.G[index].size();i++){
            int t = graph.G[index][i].to;
            if (ret[t] == INF_)
            {
                ret[t] = ret[index] + 1;
                que.push(t);
            }
        }
    }
    return ret;
}

int main(void){

    int n;
    int from, to;
    
    cin >> n;    
    Graph graph(n);

    rep(i,n-1){
        cin >> from >>  to;
        from--;
        to--;
        edge e(from, to, 1);
        edge inverse(to, from, 1);
        
        graph.add_edge(e);
        graph.add_edge(inverse);
    }

    vector<int> distance = Dykstra(graph, 0);

    int max_ = 0x80000000;
    int idx = -1;
    rep(i, n)
    {
        if (max_ < distance[i])
        {
            max_ = distance[i];
            idx = i;
        }
    }

    distance = Dykstra(graph, idx);
    max_ = 0x80000000;
    idx = -1;
    rep(i, n)
    {
        if (max_ < distance[i])
        {
            max_ = distance[i];
            idx = i;
        }
    }

    cout << max_ + 1;
}