 # Priority Queue 
-   Extension of Queue (FIFO) data structure. 
-   Data is inserted similar to insertion happens in Queue.
-   Data extraction happens according to priority or importance factor.
    >   Ex: decresing sorting order i.e. max element first.
 
---

### Types:
1.  ```Min Priority Queue``` : Elements sorted in increasing order.
2.  ```Max Priority Queue``` : Elements sorted in decreasing order. 

###  Which Data Structure could be best suited for PriorityQueue
 >        
|   DS                  |   Insert  |  getMin/Max   |   removeMin/Max   |
| -----------------     | --------- | ------------- | ----------------- |  
| Array(unsorted)       |   O(1)    |   O(n)        |       O(n)        |
| Array(sorted)         |   O(n)    |   O(1)        |       O(n)        |
| LinkedList(unsorted)  |   O(1)    |   O(n)        |       O(n)        |
| LinkedList(sorted)    |   O(n)    |   O(1)        |       O(1)        |
| BST                   |   O(h)    |   O(h)        |       O(h)        |
| Balanced BST          |   O(logn) |   O(logn)     |       O(logn)     |
| HashMap               |   O(1)    |   O(n)        |       O(n)        |

-   Seeing above table , ```Balanced BST``` seems the best data structure for it.
-   But we need to maintain :
    1.  Balancing 
    2.  Storing in sorted order.

-   So new Data structure - ```Heap``` is choosen for it which is a complete binary tree.
  
---

## Heap :
-   Two properties:
    1.  **Complete Binary Tree (CBT)**:
        -   All the levels except last level should be completely filled.
        -   last level also should be filled from left to right.
    2.  Element can be inserted/deleted in the last level from left to right order.

-   **Minimum number of nodes in CBT** : ```2^(h-1)```<br>
    **Maximum number of nodes in CBT** : ```2^h - 1```<br>
    >
        => log(n+1) <= h <= logn+1
        => logn <= h <= logn
-   How to store efficiently in CBT:
    -   We can backed the heap by an array.
        -   left child index = ```2*i + 1```
        -   right child index = ```2*i + 2```
        -   parent index from child = ```(childIndex-1)/2```

---