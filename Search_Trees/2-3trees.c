/*
  B-trees are balanced multiway search trees.
  Multiway means they have more than two degrees, in the case of 2-3 trees.
  We are talking about degree three, degree three meaning three is the maximum
  number of children a node can have.
  Each node in turn contains two keys, hence 2-3 trees, these are stored
  in an array.
  According to the n/2 formula with n being the degree of a tree
  a 2-3 tree node must have at least two children.
  Keys must be sorted horizontal and vertically.
  Root has three children, l, m and r.
  The keys in l must be less than the root's first key.
  The keys in m must be greater than root's first key and less than the second.
  The keys in r must be greater than the root's second key
  IMPORTANT PROPERTY OF 23 TREE:
  -If a node has children and one value the amount of children will always be two, never three
  -A node won't have three children unless it has its two keys set to a value
  For inserting I will show a diagram covering all cases
  where new nodes are created
  
  
  
  case 1:     xx      ->         xo
                              /     \
                             xo    xo
 
  case 2:         xo          ->        xx
               /      \             /   |   \
              xx      xo          xo   xo   xo
              ^
 
                                              xo
  case 3:    -> root        xx     ->     /       \
                                          xo     xo
                         /  |  \         /  \   /   \
                        xx  xo  xo      xo  xo xo  xo
  
  This tree is always built upwards and that is the reason
  it is always balanced
*/
 
#include <stdio.h>
#include <stdlib.h>
 
typedef enum {false, true} bool;
 
struct Node {
  int *keys;
  struct Node* left;
  struct Node* middle;
  struct Node* right;
  bool isRoot;
} *root=NULL;
 
 
struct Node* newNode(struct Node * p, int x, bool isRoot) {
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->left = t->right = t->middle = NULL;
  t->keys = (int *)malloc(2*sizeof(int));
  t->isRoot = isRoot;
  t->keys[0] = x;
  t->keys[1] = -1;
  return t;
}
 
void recursivePrint(struct Node *p){
    
  if(p) {
    if (!p->left && !p->middle && !p->right){ // It is a leaf node
 
            /* Here print node's value/values */
      for(int i = 0; i < 2; i++) { if(p->keys[i] == -1) continue; printf("%d ", p->keys[i]); }
 
 
    } else if (p->left && p->right && !p->middle){ // Node has two children
 
      recursivePrint(p->left);
      for(int i = 0; i < 2; i++) { if(p->keys[i] == -1) continue; printf("%d ", p->keys[i]); }
      recursivePrint(p->right);
 
    } else{ // If node has three children
 
      recursivePrint(p->left);
      if(p->keys[0] == -1){
            
      } else {
        printf("%d ", p->keys[0]);
      }
      recursivePrint(p->middle);
      if(p->keys[1] == -1){
            
      } else {
          printf("%d ", p->keys[1]);
      }
      recursivePrint(p->right);
 
    }
 
        /* Shouldn't be other cases in 2-3 trees */
    }
}
 
 
void growUpwardsIfRootIsFull(struct Node * p, int x) {
  struct Node *lChild = NULL; // At most we will have to split twice
  struct Node *rChild = NULL;
  struct Node *newRoot = NULL;
  if(x < p->keys[0]) {
    lChild = newNode(lChild, x, false);
    rChild = newNode(rChild, p->keys[1], false);
    newRoot = newNode(newRoot, p->keys[0], true);
    newRoot->isRoot = true;
    newRoot->left = lChild;
    newRoot->middle = p->middle;
    newRoot->right = rChild;
    root = p = newRoot;
    p->isRoot = false;
    return;
  }
  if(x > p->keys[1]) {
    lChild = newNode(lChild, p->keys[0], false);
    rChild = newNode(rChild, x, false);
    newRoot = newNode(newRoot, p->keys[1], true);
    newRoot->isRoot = true;
    newRoot->left = lChild;
    newRoot->middle = p->middle;
    newRoot->right = rChild;
    p->isRoot = false;
    root = p = newRoot;
    return;
  }
  lChild = newNode(lChild, p->keys[0], false);
  rChild = newNode(rChild, p->keys[1], false);
  newRoot->isRoot = true;
  newRoot = newNode(newRoot, x, true);
  newRoot->left = lChild;
  newRoot->middle = p->middle;
  newRoot->right = rChild;
  p->isRoot = false;
  root = p = newRoot;
  return;
}
 
void case2(struct Node *p, struct Node *q, int end, int middle, int up, int x){
    // Middle always goes to the parent note that p will be either left or right child because
    // in this case parent is always xo, check properties of 2-3 tree
    // If it is xo it has two children, if xx three
  struct Node *t = NULL;
  struct Node *r = NULL;
  t = newNode(t, end, false); // Left or right depending on which one we are doing it
  r = newNode(r, middle, false);
  if(x < p->keys[0]){ // If we are on the left child
    q->keys[1] = q->keys[0];
    q->keys[0] = up;
    q->left = t;
    q->middle = r;
  } else if(x < p->keys[1]){ // If x lies between key1 and key2 of parent
    if(x < q->keys[0]) { // if we are on the left child
      q->keys[1] = q->keys[0];
      q->keys[0] = up;
      q->left = t;
      q->middle = r;
    } else {
      q->right = t; // If we are on the right child
      q->middle = r;
      q->keys[1] = up; // If we are on the right child because x is greater than p->keys[1]
      }
    } else {
      q->keys[1] = up;
      q->right = t;
      q->middle = r;
    }
  return;
}
 
void case3(struct Node *p, struct Node *q, struct Node *w, int lChild, int rChild, int parent, int top, int x) {
    // For case three we have to check for left, middle and right
  struct Node *newParent = NULL;
  struct Node *newRoot = NULL;
  struct Node *t = NULL; // At most we will have to split twice
  struct Node *r = NULL;
  struct Node *tempLeft = NULL;
  struct Node *tempRight = NULL;
  t = newNode(t, lChild, false);  // left child
  r = newNode(r, rChild, false); // right child
  newParent = newNode(newParent, parent, false);
  newParent->left = t;
  newParent->right = r;
  if(q->isRoot) newRoot = newNode(newRoot, top, true); // We know the parent node's value because if we are on the left child, whichever key we pick will be smaller than any of the parent's keys
  else newRoot = newNode(newRoot, top, false);
  q->keys[0] = q->keys[1];
  q->keys[1] = -1;
  if(q->left == p) { // If we are on the left child
    newRoot->left = newParent;
    newRoot->right = q;
    q->left = q->middle;
    q->middle = NULL;
    if(w != NULL) {
      w->left = newRoot; // We rearrange the treee nicely, setting our temporary root
      return;
    }
    newRoot->isRoot = true;
    root = newRoot;
    return;
    } else if(q->right == p) {
      newRoot->right = newParent;
      newRoot->left = q;
      q->right = q->middle;
      q->middle = NULL;
      if(w != NULL){ // If our new root has a parent to attach itself to
        w->right = newRoot;
        return;
      }
      newRoot->isRoot = true;
      root = newRoot;
      return;
    } else if(w != NULL && q->middle == p){ // If we are on the middle child and there is a parent we attach our new root to
        if(w->keys[0] != -1 && w->keys[1] != -1){ // If the parent we are attaching the root to is xx
          tempLeft = newParent->left; // Since we have a separate node with middle elements from the previous node as children we have to preserve the sorted order
          tempRight = newParent->right; //So we assign our new parent's left value to its right node
          newParent->left = q->left; //And its right value to the previous node's left node
          newParent->right = tempLeft; // The right value of the new parent will be the value for the previous node's left node
          q->left = tempRight;
          q->middle = NULL;
          newRoot->left = newParent;
          newRoot->right = q;
          w->middle = newRoot;
          return;
        } else { // If the parent we are attaching the root to is xo
          tempLeft = newParent->left; // Since we have a separate node with middle elements from the previous node as children we have to preserve the sorted order
          tempRight = newParent->right; //So we assign our new parent's left value to its right node
          newParent->left = q->left; //And its right value to the previous node's left node
          newParent->right = tempLeft; // The right value of the new parent will be the value for the previous node's left node
          q->left = tempRight;
          q->middle = NULL;
          newRoot->left = newParent;
          newRoot->right = q;
          if(newRoot->keys[0] < w->keys[0]) {
            w->left = newRoot;
            return;
          }
          w->right = newRoot;
          return;
        }
    } else { // If q is the root and we are on the middle child
        tempLeft = newParent->left; // Since we have a separate node with middle elements from the previous node as children we have to preserve the sorted order
        tempRight = newParent->right; //So we assign our new parent's left value to its right node
        newParent->left = q->left; //And its right value to the previous node's left node
        newParent->right = tempLeft; // The right value of the new parent will be the value for the previous node's left node
        q->left = tempRight;
        q->middle = NULL;
        newRoot->left = newParent;
        newRoot->right = q;
        newRoot->isRoot = true;
        root = newRoot;
        return;
    }
}
 
void iInsert(struct Node* p, int x) {
  struct Node *t = NULL;
  struct Node *q = NULL;
  struct Node *w = NULL; // We will use this pointer for case three to add new root as a child to it
  // and create four nodes: a new parent, two new children for the parent
  // and a new root, because we grow the tree upwards, we call it root to match the diagram of case 3
  // but it is not a new root when we find case 3 at a lower level down the tree
  // Children will be referred to as t and r
  if(p == NULL) {
    t = newNode(t, x, true);
    p = t;
    root = p;
    return;
  }
  if(!p->left && !p->right && !p->middle){
    if(p->keys[0] != -1 && p->keys[1] != -1){ // If case 1
        growUpwardsIfRootIsFull(p, x);
        return;
    }
    if(x > p->keys[0]){
      p->keys[1] = x;
      return;
    }
    p->keys[1] = p->keys[0];
    p->keys[0] = x;
    return;
  } else { // If root is full and tree is built
    while(p != NULL){
        if(x == p->keys[0] || x == p->keys[1]) return;
        if(q != NULL && q->keys[0] != -1 && q->keys[1] != -1) { // If parent xx we may have case 3 depending on whether p is xx or not and what child p is
            // We know for sure p is one of left, middle and right children
            if(p->keys[0] != -1 && p->keys[1] != -1){ // If current is xx
                if(x < p->keys[0]){ //
                    if(!p->left){
                        if(q->left == p){
                            case3(p, q, w, p->keys[0], p->keys[1], x, q->keys[0], x);
                        } else if(q->right == p){
                            case3(p, q, w, x, p->keys[1], p->keys[0], q->keys[1], x);
                        } else {
                            case3(p, q, w, x, p->keys[1], q->keys[0], p->keys[0], x);
                        }
                        return;
                    }
                    w = q; // parent's parent we keep track of this for case 3
                    q = p; // parent
                    p = p->left;
                } else if(x > p->keys[0] && x < p->keys[1]){ // x lies between first and second key
                    if(!p->middle){ // we have to know what children it is on so we can set the new root's value
                        if(q->left == p){
                            case3(p, q, w, p->keys[0], p->keys[1], x, q->keys[0], x);
                        } else if(q->right == p){
                            case3(p, q, w, p->keys[0], p->keys[1], x, q->keys[1], x);
                        } else {
                            case3(p, q, w, p->keys[0], p->keys[1], q->keys[0], x, x);
                        }
                        return;
                    }
                    w = q; // parent's parent we keep track of this for case 3
                    q = p; // parent
                    p = p->left;
                } else { // If x > p->keys
                    if(!p->right){
                        if(q->left == p){
                            case3(p, q, w, p->keys[0], x, p->keys[1], q->keys[0], x);
                        } else if(q->right == p){
                            case3(p, q, w, p->keys[0], x, p->keys[1], q->keys[1], x);
                        } else {
                            case3(p, q, w, p->keys[0], x, q->keys[1], p->keys[1], x);
                        }
                        return;
                    }
                    w = q;
                    q = p;
                    p = p->right;
                }
            } else if(x > p->keys[0]){ // If current is xo and previous is xx
                if(!p->right){
                    p->keys[1] = x;
                    return;
                }
                w = q;
                q = p;
                p = p->right;
            } else {
                if(!p->left) {
                    p->keys[1] = p->keys[0];
                    p->keys[0] = x;
                    return;
                }
                w = q;
                q = p;
                p = p->left;
            }
        } else if(q != NULL){ // If parent xo
            if(p->keys[0] != 1 && p->keys[1] != -1){ // If current xx we have case 2
                if(x < p->keys[0]){
                    if(!p->left){
                        case2(p, q, x, p->keys[1], p->keys[0], x);
                        return;
                    }
                    w = q;
                    q = p;
                    p = p->left;
                } else if(x > p->keys[0] && x < p->keys[1]) {
                    if(!p->middle){
                        case2(p, q, p->keys[0], p->keys[1], x, x);
                        return;
                    }
                    w = q;
                    q = p;
                    p = p->middle;
                } else if(!p->right){
                    case2(p, q, x, p->keys[0], p->keys[1], x);
//                    recursivePrint(root);
//                    printf("\n");
                    return;
                } else {
                    w = q;
                    q = p;
                    p = p->right;
                }
            } else if(x > p->keys[0]){
                if(!p->right){
                    p->keys[1] = x;
//                    recursivePrint(root);
                    return;
                }
                w = q;
                q = p;
                p = p->right;
            } else if(!p->left){
                p->keys[1] = p->keys[0];
                p->keys[0] = x;
                return;
            } else{
                w = q;
                q = p;
                p = p->left;
            }
        } else if(p->keys[0] != -1 && p->keys[1] != -1){ // p is root and xx
                if(x > p->keys[0] && x < p->keys[1]) {
                    w = q;
                    q = p;
                    p = p->middle;
                } else if(x < p->keys[0]){
                    w = q;
                    q = p;
                    p = p->left;
                } else {
                    w = q;
                    q = p;
                    p = p->right;
                }
        } else if(x > p->keys[0]) {
            w = q;
            q = p;
            p = p->right;
        } else { // If x < p->keys[0]
            w = q;
            q = p;
            p = p->left;
        }
    }
  }
}
 
int main() {
  iInsert(root, 20);
  iInsert(root, 30);
  iInsert(root, 40);
  iInsert(root, 50);
  iInsert(root, 60);
  iInsert(root, 10);
  iInsert(root, 15);
  iInsert(root, 70);
  iInsert(root, 80);
  recursivePrint(root);
  return 0;
}
 