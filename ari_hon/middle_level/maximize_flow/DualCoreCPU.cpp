#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair<int, int> P;

class edge
{
public:
    int from; // start of an edge.
    int to;   // end of an edge.    
    int cap;  // the capacity for pass through
    int cost; // the cost to pass through (for finding the minimum cost flow)
    int rev;  // the index of the inverse edge.

    edge(int _from, int _to, int _cap, int _cost, int _rev)
    {
        from = _from; 
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }
};

class Graph
{
public:
    vector<vector<edge>> G;
    int minimum_node_idx;
    int maximum_node_idx;
    int n_vetrics;

    Graph(int n_of_vetrics)
    {
        G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
        minimum_node_idx = 0x7FFFFFFF;
        maximum_node_idx = 0x80000000;
    }

    void add_edge(edge &x)
    {
        G[x.from].push_back(x);
        minimum_node_idx = min(minimum_node_idx, x.from);
        minimum_node_idx = min(minimum_node_idx, x.to);
        maximum_node_idx = max(maximum_node_idx, x.from);
        maximum_node_idx = max(maximum_node_idx, x.to);
    }

    int get_rank(int idx)
    {
        return G[idx].size();
    }
};

vector<int> Dykstra(Graph &graph, int s)
{
    /*  
        s:  start idx;
    */

    int INF = 0x7FFFFFFF;

    if (s < graph.minimum_node_idx || s > graph.maximum_node_idx)
    {
        cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl
             << "not " << s;
        exit(1);
    }

    vector<int> ret_distance(graph.n_vetrics);
    fill(ret_distance.begin(), ret_distance.end(), INF);

    // P: Pair<int, int>
    //    first int: metrics(e.g., cost, distance)
    //    second int: index of the node;
    priority_queue<P, vector<P>, greater<P>> que;

    ret_distance[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();

        int v = p.second;

        rep(i, graph.G[v].size())
        {
            edge &e = graph.G[v][i];

            if (ret_distance[e.to] > ret_distance[e.from] + e.cost)
            {
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

    while (!(que.empty()))
    {
        int index = que.front();
        que.pop();

        for (int i = 0; i < graph.G[index].size(); i++)
        {
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

namespace bipartite_maching{

    void add_edge(Graph &graph,int from, int to){
        edge e(from, to, 0, 0, 0);
        edge e_inverse(to, from, 0, 0, 0);

        graph.add_edge(e);
        graph.add_edge(e_inverse);        
    }

    bool has_increased_flow(Graph &graph,vector<bool> &used, vector<int> &match,int v){
        used[v] = true;

        rep(i,graph.G[v].size()){
            int u = graph.G[v][i].to;
            int w = match[u];

            if ( w<0 || !used[w] &&  has_increased_flow(graph,used,match,w)){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching(Graph &graph){
        int res = 0;
        int V = graph.n_vetrics;
        vector<int> match(V);
        vector<bool> used(V);
        fill(match.begin(), match.end(), -1);
        
        for (int v = 0; v < V;v++){
            if ( match[v] < 0){
                fill(used.begin(), used.end(), false);
                
                if( has_increased_flow(graph,used,match,v)){
                    res++;
                }
            }
            
            
        }
        return res;
    }
}


namespace maximum_flow{
    
    void add_edge(Graph &graph ,int from, int to, int cap){
        /*通常の辺と残余ネットワーク用の辺を追加する。*/
                
        edge t(from,to,cap,0,graph.G[to].size());        
        edge t_inverse(to, from, 0, 0, graph.G[from].size() - 1);

        graph.add_edge(t);
        graph.add_edge(t_inverse);        
    }

    int obtain_increased_flow(Graph &graph, vector<bool>  &used, int v, int t, int f){
        if (v == t){
            return f;
        }
        used[v] = true;

        for (int i = 0; i < graph.G[v].size();i++){
            edge &e = graph.G[v][i];
            
            
            if (!used[e.to] && e.cap>0){
                int d = obtain_increased_flow(graph, used, e.to, t, min(f, e.cap));

                if (d > 0){
                    e.cap -= d;
                    graph.G[e.to][e.rev].cap += d;
                    return d;
                }
            }            
        }
        return 0;
    }

    int max_flow(Graph &graph,int s, int t){
        int flow = 0;
        int INT_MAX_ = 0x7FFFFFFF;
        vector<bool> used(graph.n_vetrics);

        for (;;)
        {
            fill(used.begin(), used.end(), false);
            int f = obtain_increased_flow(graph, used, s, t, INT_MAX_);
            if (f == 0){
                return flow;
            }
            flow += f;
        }
    }
}

int main(){

    int N, F, D;

    cin >> N >> F >> D;

    Graph graph(N+2*F+2*D+2);

    int tmp;
    int counter = 0;

    int read_mode = 0; // 0 for food.  1 for drink

    rep(i,F){
        maximum_flow::add_edge(graph, 0, i+1, 1);
    }
    rep(i, D)
    {
        maximum_flow::add_edge(graph, N+F+i+1 , N+F+D+1, 500);
    }

    do{
        cin >> tmp;
        if (tmp == -1){
            counter++;
            if (counter>=4){
                read_mode = 1;
            }
            continue;
        } else if (tmp == -2){
            break;
        } else {
            cin >> tmp;
            int cow_idx = counter % N;

            if (read_mode == 0){
                maximum_flow::add_edge(graph, tmp,F+cow_idx,1);                
            } else if(read_mode == 1){
                maximum_flow::add_edge(graph, F + cow_idx, F+N+tmp, 1);
            } else {
                cerr << "unexpected error has occurred";
                exit(-1);
            }
        }
    } while (1);

    cout << maximum_flow::max_flow(graph,0,N+F+D+1)<<endl;
}
