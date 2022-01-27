#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>
#include"/root/library/graph/maximized_flow.hpp"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

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