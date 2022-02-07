#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

class edge
{
public:
   int from; // start of an edge.
   int to;   // end of an edge.
   ll cap;  // the capacity for pass through
   ll cost; // the cost to pass through (for finding the minimum cost flow)
   ll rev;  // the index of the inverse edge.

   edge(int _from, int _to, ll _cap, ll _cost, ll _rev)
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
   ll n_vetrics;

   Graph(ll n_of_vetrics)
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

   int get_rank(ll idx)
   {
      return G[idx].size();
   }
};


namespace Dykstra
{

   typedef pair<int, ll> P;

   void add_edge(Graph &graph, int from, int to, ll cost)
   {
      edge e(from, to, 0, cost, 0);
      graph.add_edge(e);
   }

   vector<ll> Dykstra(Graph &graph, int s)
   {
      /*  
        s:  start idx;
      */

      ll INF = 0x7FFFFFFFFFFFFFFF;

      if (s < graph.minimum_node_idx || s > graph.maximum_node_idx)
      {
         cerr << "There is no such a index: minimum is " << graph.minimum_node_idx << " and maximum is " << graph.maximum_node_idx << endl
              << "not " << s;
         exit(1);
      }

      vector<ll> ret_distance(graph.n_vetrics);
      fill(ret_distance.begin(), ret_distance.end(), INF);

      // P: Pair<int, int>
      //    first ll: metrics(e.g., cost, distance)
      //    second int: index of the node;
      priority_queue<P, vector<P>, greater<P>> que;

      ret_distance[s] = 0;
      que.push(P(0ll, s));

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
}
int main()
{
   int N,M;

   cin >> N >> M;

   vector<ll> H(N+1);

   rep(i,N){
      cin >> H[i+1];
   }
   Graph graph(N + 1);

   rep(i, M)
   {
     
      int tmp1, tmp2;
      cin >> tmp1 >> tmp2;

      if (H[tmp1] < H[tmp2]){
         Dykstra::add_edge(graph, tmp1, tmp2, -1 * (H[tmp2] - H[tmp1]));
         Dykstra::add_edge(graph, tmp2, tmp1, -2*(H[tmp1] - H[tmp2]));
      }
      else if (H[tmp1] > H[tmp2]){
         Dykstra::add_edge(graph, tmp1, tmp2, -2 * (H[tmp1] - H[tmp2]));
         Dykstra::add_edge(graph, tmp2, tmp1, -1 * (H[tmp2] - H[tmp1]));
      } else {
         Dykstra::add_edge(graph, tmp1, tmp2, (0));
         Dykstra::add_edge(graph, tmp2, tmp1, (0));
      }
   }
   /*
   vector<ll> s = Dykstra::Dykstra(graph,1);

   cout << (*max_element(s.begin(),s.end())) * -1;
   */
}