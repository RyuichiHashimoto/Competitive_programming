#include<iostream>
using namespace std;

class union_find{
    
private:
    int *parent;
    int *rank;
    int n;
    const int INF = 0x6FFFFFFF;

public:
    ~union_find();
    union_find(int n);

    int find_root(int x);
    void unite(int x, int y);
    bool same(int x, int y);
    void init_union_find(int n);
};





