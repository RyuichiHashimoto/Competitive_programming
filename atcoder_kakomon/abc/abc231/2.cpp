#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<map>
using namespace std;

int ctoi(char a){
    return a - '0';
}

int main()
{
    string name;
    int N;

    map<string,int> map_info;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> name;        
        if (map_info.count(name)){
            map_info[name] = map_info[name] + 1;
        } else {
            map_info[name] = 1;
        }
    }
    string max_name ="";
    int max_val = -1;

    for(auto iter = map_info.begin();iter != map_info.end();iter++){
        if (max_val < iter->second){
            max_val = iter->second;
            max_name = iter->first;
        }
    }
    cout << max_name;    
}