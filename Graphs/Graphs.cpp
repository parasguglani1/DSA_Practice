/* Graphs: collections of vertices (nodes) and edges (links): G = (V,E).
Graphs are very useful for solving problems. Many of real-world problems can be converted into graphs.

Concepts: Directed, self-loop (a node connected to itself), parallel edges (two nodes connected
to each other mutually), indegree of a vertex (n of edges pointing at it) and outdegree (n of edges
going out from it), adjacent vertices.
Simple Directed Graph/Digraph: no self-loops or parallel edges.
Graph/Non-Directed Graph: without directions. Nodes have degrees (n of edges connected to it). Assume
that directions can go either way.
Non-connected Graphs: two components (graphs) that aren't connected. The contrary: Connected Graph.
The nodes that are necessary to connect both components are called articulation points. If one more
edge connects the components, there will be no articulation points, they become bi-connected components,
or strongly connected components.
Strongly Connected: from every vertex we can reach any other vertex.
Path: set of all the vertices between a par of vertices, can be shorter-length or longer-length paths.
Cycle/Circular Path/Circuit: starting from a node, going through other vertices and coming back
to where it started.
Directed/Acyclic Graph: if you start from any vertex you can't reach the same vertex in any way.
Topological ordering: directed/acyclic graphs can be arranged linearly such that edges go in a
forward direction only.

Representation of undirected graphs:
1. Adjacency Matrix: if there's an edge between two vertices, 1, else, 0.
For weighed edges, put the weight instead of 1 (cost adjency matrix). Time complexity: n x n = O(n^2)
2. Adjacency List: an array (representing vertices) of linked lists (representing the vertices that
are linked to it by edges). In case there's weight, store them inside each node along with the vertex name.
Time complexity: |V|+2|E|, V for vertices in the array (n) and 2|E| since vertices are represented
twice = n + 2E
3. Compact List: using a simple array whose size is: |V|+2|E|+1 = 0 index vacant, first locations for
each vertex (starting index of the adjacent vertices will go here), next location vacant, start adding
the adjacent vertices for each vertex and add the starting index inside the previous locations.
This means that the first indices (after zero) represent the vertices and the number inside each
location will map to the starting index of their adjacent vertices. Between these locations there will
be a vacant space meant to store the size+1 index of the array to indicate where the last vertex's
adjacency list goes. For weighed graphs, a two-dimensional array would work.
Time complexity: |v|+2|E| = n + 2n = 3n = O(n)

Representation of directed graphs:
1. Adjacency Matrix: similar to undirected graphs, but the edges won't go both ways. Time: O(n^2)
Rows represent the edges going out (out-degree). Columns represent edges coming in (in-degree).
2. Adjacency List: similar to undirected. Not possible to know in-degrees as easily as in an
adjacency matrix, but instead you can make a inverse adjacency list. Time: |V|+|E|, n+e, n+n, O(n)
3. Compact List also possible, just like undirected graphs.

Breadth First Search:
Convert the graph into a tree (not necessarily a binary one) and take the level order.
You can start from any vertex. This tree is called "BFS Spanning Tree". When edges form a
cycle (they appear dotted in the tree) they are called cross edges.
1. Visiting (visiting any vertex) & Exploring (visiting all adjacent vertices).
Enqueue a vertex you visit. Then dequeue it and explore it (enqueueing each one you visit),
then, dequeue the next one and explore it, repeating the process.
There are many possible BF searches, depending on the starting vertices and the exploring order.
Time taken: O(n)

*/

// Performing BFS and DFS on graphs represented using adjacent matrices
/* Displaying edges of the minimum-cost spanning tree using: 
1. Djikstra, Jarnik and Prim's algorithm
2. Kruskal's algorithm*/
# include <iostream>
# include <queue>

using namespace std;
#define inf INT_MAX

void del2D(int** ar, int x)
{
    for(int i = 0; i < x; i++)
        delete[] ar[i];
    delete[] ar;
}
class Graph
{
    private:
    int** adj;
    int n;
    void fill(int*);
    int* init(int, int);
    int numEdges();
    int** onlyEdges(int);
    int find(int*, int);
    void Union(int*, int, int);
    void BreadthFirstSearch(int);
    void DFS(int*, int);
    public:
    Graph(int*, int);
    void BFS(int);
    void DFS(int);
    int** MSTPrims();
    int** MSTKruskal();
    ~Graph();
};
void Graph::fill(int* arr)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
            adj[i][j] = *(arr+(i-1)*(n-1)+(j-1)) == 0 ? inf : *(arr+(i-1)*(n-1)+(j-1));
    }
}
int* Graph::init(int toFill, int n)
{
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = toFill;
    return arr;
}
void Graph::BreadthFirstSearch(int start)
{
    queue<int> que; int* visit = init(0, n);
    cout << start << " ";
    visit[start] = 1;
    que.push(start);
    while(!que.empty())
    {
        start = que.front(); que.pop();
        for(int i = 1; i < n; i++)
        {
            if(adj[start][i] != inf && visit[i] == 0)
            {
                cout << i << " ";
                visit[i] = 1;
                que.push(i);
            }
        }
    }
    delete[] visit;
}
void Graph::DFS(int* visit, int start)
{
    if(visit[start] == 0)
    {
        cout << start << " ";
        visit[start] = 1;
        for(int i = 1; i < n; i++)
            if(adj[start][i] != inf)
                DFS(visit, i);
    }
}
Graph::Graph(int* arr, int x)
{
    n = (x > 0) ? x + 1 : 6;
    adj = new int*[n];
    for(int i = 0; i < n; i++)
        adj[i] = new int[n];
    fill(arr);
}
void Graph::BFS(int start)
{
    cout << "Graph in breadth-first search: ";
    BreadthFirstSearch(start); cout << "\n";
}
void Graph::DFS(int start)
{
    int* visit = init(0, n);
    cout << "Graph in depth-first search: ";
    DFS(visit, start); cout << "\n";
    delete[] visit;
}
int** Graph::MSTPrims()
{
    int* near = init(inf, n), **result = new int*[2];
    result[0] = new int[n-2]; result[1] = new int[n-2]; 
    // one-time procedure
    int min = inf, u, v;
    for(int i = 1; i < n; i++) // minimum in upper triangle
    {
        for(int j = i; j < n; j++)
        {
            if(adj[i][j] < min)
            {
                min = adj[i][j];
                u = i, v = j;
            }
        }
    }
    result[0][0] = u, result[1][0] = v; // push the edge
    near[u] = near[v] = 0; // zero out the indices
    for(int i = 1; i < n; i++) // set the least costliest
    {
        if(near[i] != 0)
        {
            if(adj[i][u] < adj[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    // repeating procedure
    for(int res = 1; res < n-2; res++)
    {
        min = inf;
        for(int i = 1; i < n; i++)
        {
            if(near[i] != 0 && adj[i][near[i]] < min)
            {
                min = adj[i][near[i]];
                u = i; // min cost index
            }
        }
        result[0][res] = u, result[1][res] = near[u]; // push the edge
        near[u] = 0; // zero out the vertex's index
        for(int i = 1; i < n; i++) // rejig the least costliest
        {
            if(near[i] != 0 && adj[i][u] < adj[i][near[i]])
                near[i] = u;
        }
    }
    return result;
}
int Graph::numEdges()
{
    int edgeSize = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(adj[i][j] != inf)
            {
                edgeSize++; // number of edges
            }
        }
    }
    return edgeSize;
}
int** Graph::onlyEdges(int edgeSize)
{
    int** edges = new int*[3]; // v1, v2, weight
    for(int i = 0; i < 3; i++)
        edges[i] = new int[edgeSize];
    int k = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(adj[i][j] != inf)
            {
                edges[0][k] = i;
                edges[1][k] = j;
                edges[2][k] = adj[i][j];
                k++;
            }
        }
    }
    return edges;
}
void Graph::Union(int* s, int u, int v)
{
    if(s[u] < s[v])
    {
        s[u] = s[u] + s[v];
        s[v] = u;
    }
    else
    {
        s[v] = s[u] + s[v];
        s[u] = v;
    }
}
int Graph::find(int* s, int u)
{
    while(s[u] > 0)
    {
        u = s[u];
    }
    return u;
}
int** Graph::MSTKruskal()
{
    int numEdge = numEdges();
    int** edgeWeights = onlyEdges(numEdge); // 2D matrix with dimensions 3*(numEdges)
    int* included = init(0, numEdge); // denotes which of the edges have been accounted for
    int* disjoint = init(-1, n); // prevents formation of cycles
    int** result = new int*[2]; // to return, the answer
    for(int i = 0; i < 2; i++)
        result[i] = new int[n-2];
    // the iterative operation
    int i = 0, min, k, u, v, p1, p2;
    while(i < n-2)
    {
        min = inf;
        for(int j = 0; j < numEdge; j++)
        {
            if(!included[j] && edgeWeights[2][j] < min)
            {
                min = edgeWeights[2][j];
                k = j; // index for minimum weight
            }
        }
        u = edgeWeights[0][k], v = edgeWeights[1][k];
        p1 = find(disjoint, u), p2 = find(disjoint, v); 
        if(p1 != p2) // if cycle is not formed (dissimilar parents)
        {
            result[0][i] = u;
            result[1][i] = v;
            Union(disjoint, p1, p2); // unionize
            i++;
        }
        included[k] = 1; // even if result does not have a new edge pushed
    }
    del2D(edgeWeights, 3);
    delete[] included;
    delete[] disjoint;
    return result;
}
Graph::~Graph()
{
    del2D(adj, n);
    cout << "Graph destructed\n";
}

int main()
{
    int n = 6, k = 3;
    // int s[n][n] = {{0, 25, 0, 0, 0, 5, 0},
    //                {25, 0, 12, 0, 0, 0, 10},
    //                {0, 12, 0, 8, 0, 0, 0},
    //                {0, 0, 8, 0, 16, 0, 14},
    //                {0, 0, 0, 16, 0, 20, 18},
    //                {5, 0, 0, 0, 20, 0, 0},
    //                {0, 10, 0, 14, 18, 0, 0}};
    int s[n][n] = {{0, 6, 9, 0, 0, 0},
                   {6, 0, 0, 11, 0, 0},
                   {9, 0, 0, 24, 0, 0},
                   {0, 11, 24, 0, 7, 5},
                   {0, 0, 0, 7, 0, 0},
                   {0, 0, 0, 5, 0, 0}};
    Graph g((int*)s, n);
    g.BFS(k);
    g.DFS(k);
    int** mstDJP = g.MSTPrims(), **mstK = g.MSTKruskal();
    cout << "Minimum-cost spanning tree edges:\n";
    cout << "1. Using Djikstra, Jarnik and Prim's algorithm:\n\t";
    for(int i = 0; i < n-1; i++)
        cout << "(" << mstDJP[0][i] << ", " << mstDJP[1][i] << ")\t";
    cout << "\n";
    cout << "2. Using Kruskal's algorithm:\n\t";
    for(int i = 0; i < n-1; i++)
        cout << "(" << mstK[0][i] << ", " << mstK[1][i] << ")\t";
    cout << "\n";
    del2D(mstDJP, 2); 
    del2D(mstK, 2);
    return 0;
}
