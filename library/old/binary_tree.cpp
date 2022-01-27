#include<iostream>
using namespace std;
#include <limits.h>
#include<queue>

// int heap[100000], sz = 0;
struct node {
    int val;
    node *lch, *rch;
};

node * insert(node *p, int x){
    if (p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    } else {
        
        if (x < p->val){
            p->lch = insert(p->lch,x);
        } else {
            p->rch = insert(p->rch, x);
        }
        return p;
    }
}

bool find(node *p, int x){

    if (p ==NULL){
        return false;        
    } else if (p->val == x){
        return true;
    } else {
        return find(p->lch, x) or find(p->rch, x);
    }
}


node *remove(node *p, int x){

    if (p == NULL)
    {
        return NULL;
    } 
    else if (x < p->val){
        p->lch = remove(p->lch, x);
    }
    else if (x > p->val){
        p->rch = remove(p->rch, x);
    } else if (p->lch == NULL){
        node *q = p->rch;
        delete p;
        return q;
    } else if ( p->lch->rch == NULL){
        node *q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    } else {
        node *q;

        for (q = p->lch; q->rch->rch == NULL; q= q->rch);

        node *r = q->rch;

        
        q->rch = q->rch->lch;

        r->lch = p->lch;
        r->rch = p->rch;

        delete p;
        return r;
    }
    return p;
}
#include<set>

int main(void){

    set<int> s;

    s.insert(1);
    s.insert(6);
    s.insert(5);
    s.insert(3);
    s.insert(56);

    set<int>::iterator ite;

    ite = s.find(5125);

    cout << *s.end();
}