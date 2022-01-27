#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i,from, to) for (int i = from; i < (int)to; i++)

using namespace std;
const int INT_INF = 0x7FFFFFFF;

typedef pair<int, int> P;

struct edge_with_cost
{
    int to, cap, cost, rev;
};

class minimum_cost_flow{

    private:
        vector<vector<edge_with_cost>> graph;
        int *h;
        int *dist;
        int *prev_v;
        int *prev_e;
        
        int n_edges;
        int n_vetrics;

    public:
        minimum_cost_flow(int _n_edges, int _n_vetrics){
            n_edges = _n_edges;
            n_vetrics = _n_vetrics;

            graph.resize(_n_edges);
            dist = new int[n_vetrics];
            prev_v = new int[n_vetrics];
            prev_e = new int[n_edges];
            h = new int[n_vetrics];
        }

        ~minimum_cost_flow(){
            delete dist;
            delete prev_v;
            delete prev_e;
            delete h;
        }

        void add_edge(int from, int to, int cap, int cost){
            graph[from].push_back((edge_with_cost){to, cap, cost, G[to].size()});
            graph[to].push_back((edge_with_cost){from, 0, -cost, G[from].size() - 1});
        };        

        int  find_min_cost_flow( int s, int t, int f){
            /*
                find a flow (the size is f) with the minimum cost. 
                
                s: start node index
                t: end node index
                f: flow size            
            */
            int res = 0;
            
            // initialize 
            fill(h, h + n_vetrics, 0);

            while(f>0){

                // conduct the dicstra method
                priority_queue<P, vector<P>, greater<P>> pque;
                fill(dist, dist + n_vetrics, INT_INF);
                dist[s] = 0;
                pque.push(P(0, s));

                while (!pque.empty()){
                    P p = pque.top();
                    pque.pop();

                    int v = p.second;

                    if ( dist[v] < p.first){
                        continue;
                    }

                    for (int i = 0; i < graph[v].size();i++){
                        edge_with_cost &e = graph[v][i];

                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            pque.push(P(dist[e.to], e.to));
                        }
                    }
                }
            }

            if (dist[t] == INT_INF){
                return -1;
            }

            rep(v, 0, n_vetrics){
                h[v] += dist[v];
            }

            int d = f;            
            for (int v = t; v != s; v = prev_v[v]){
                d = min(d, graph[prev_v[v]][prev_e[v]].cap);
            }

            f -= d;
            res += d * h[t];

            for (int v = t; v != s; v = prev_v[v]){
                edge_with_cost &e = graph[prev_v[v]][prev_e[v]];
                e.cap -= d;
                graph[v][e.rev].cap += d;
            }

            return res;
        }
};





int main()
{

    int V, E;
    cin >> V >> E;


    

}