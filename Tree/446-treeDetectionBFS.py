'''
 given two lists of integers left and right, both of them the same length and representing a directed graph. 
 left[i] is the index of node i’s left child and right[i] is the index of node i’s right child. A null child is represented by -1. 
 Return whether left and right represents a binary tree.
For a graph to be a tree, it has to satisfy that: only one root, one connected component, and no cycles.
Constraints
n ≤ 100,000 where n is the length of left and right
Example 1
Input

1
2
left = [1, -1, 3, -1]
right = [2, -1, -1, -1]
Output
True

Example 2
Input

1
2
left = [0]
right = [0]
Output
False
Explanation
This is a circular node.

Hints:
Is Tree a DAG (Directed Acyclic Graph)?
Tree is not disjoint.
The trick here is to find the root of the tree!
DAG with an exactly single source, no node with in-degree > 1.
What about topological Sorting?
'''

from collections import defaultdict,deque

def treeDetection(left,right):
    n=len(left)
    data=defaultdict(int)  #for getting the root count
    for i in range(n):
        if left[i]!=-1:
            data[left[i]]+=1
        if right[i]!=-1:
            data[right[i]]+=1
    #determine if there is only one root of tree
    root=[x for x in range(n) if data[x]==0]
    if len(root)!=1:
        return False
    #determine if there is only one connected component and no cycle
    seen=set()
    q=deque([root[0]])
    while q:
        cur=q.popleft()
        if cur in seen:
            return False
        seen.add(cur)
        if left[cur]!=-1:
            q.append(left[cur])
        if right[cur]!=-1:
            q.append(right[cur])
    return len(seen)==n

left = [1, -1, 3, -1]
right = [2, -1, -1, -1]
print(treeDetection(left,right))