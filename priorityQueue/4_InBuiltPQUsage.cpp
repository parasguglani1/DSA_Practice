#include <bits/stdc++.h>
using namespace std;

/**
 *  Default priority queue usage present in queue.h
 */
int main(){
    // max priority queue
    priority_queue<int> pq;
    // min priority queue
    priority_queue<int, vector<int>, greater<int> > min_pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);    
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}