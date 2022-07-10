# Trees

> Unlike `Arrays`, `Linked Lists`, `Stack` and `queues`, which are linear data structures, **trees** are `hierarchical` data structures.

---

### Terminology:

- `Root` : The topmost node is called root of the tree.
- `Child` : The elements that are directly under an element are called its children.
- `Parent` : The element directly above something is called its parent.

>

    For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves.

                        tree
                        ----
                          j    <-- root
                        /   \
                      f      k
                    /   \      \
                   a     h      z    <-- leaves

---

## Why Trees?

- One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer:

  >

                      file system
                      -----------
                           /    <-- root
                      /         \
                    ...         home
                    /              \
                  ugrad           course
                  /            /      |     \
                 ...         cs101  cs112  cs113

- **Trees** (with some ordering e.g., `BST`) provide moderate access/search (quicker than `Linked List` and slower than `arrays`).
- **Trees** provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
- Like `Linked Lists` and unlike `Arrays`, **Trees** don’t have an upper limit on number of nodes as nodes are linked using pointers.

---

### Main applications of trees include:

1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms

---
