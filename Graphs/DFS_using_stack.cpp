#include <iostream>
#include <stack>
using namespace std;
 
void DFS(int u, int A[][8], int n) {
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    cout << u << " ";
    visited[u] = 1;
 
    int v = 0;
    while (!stk.empty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                stk.push(u); 
                u = v;  
                cout << u <<" ";
                visited[u] = 1;
                v = -1;
            }
            v++;
        }
        v = u;  
        u = stk.top();
        stk.pop();
    }
}
 
void dfs(int u, int A[][8], int n){
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    while (!stk.empty()){
        u = stk.top();
        stk.pop();
 
        if (visited[u] != 1)
        {
            cout << u << ", " << flush;
            visited[u] = 1;
            for (int v=n-1; v>=0; v--)
                if (A[u][v] == 1 && visited[v] == 0)
                    stk.emplace(v);
        }
    }
}
 
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;
    return 0;
}