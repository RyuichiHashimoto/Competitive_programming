#include<iostream>
using namespace std;
#include <limits.h>
#include<queue>

int heap[100000], sz = 0;

void push(int x){

    int i = sz++;

    while ( i > 0){
        /*　親のID */
        int p = (i - 1) / 2;

        if (heap[p] <= x){
            break;
        }
        /**/
        heap[i] = heap[p];
       
        i = p;        
    }
    heap[i] = x;
}

int pop(){

    int ret = heap[0];

    int x = heap[--sz];

    int i = 0;

    
    while (i*2 + 1 < sz) {
        int left_idx = i * 2 + 1;
        int right_idx = i * 2 + 2;
        
        if ( right_idx < sz &&  heap[ right_idx] < heap[left_idx]) left_idx = right_idx;




    }

    return ret;
}

int main(void){

    priority_queue<int> pque;

    pque.push(3);
    pque.push(5);
    pque.push(1);

    int counter = 0;
    while (!pque.empty())
    {
        cout << pque.top() << endl;
        
        if (counter++ > 10)
        {
            break;
        }
    }
    
}