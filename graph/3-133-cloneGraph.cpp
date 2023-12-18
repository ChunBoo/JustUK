/**
 * Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.
OJ’s undirected graph serialization (so you can understand error output):

Nodes are labeled uniquely.We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer. You don’t need to understand the serialization to solve the problem.

Solution: Queue + Hashtable
Time complexity: O(V+E)
Space complexity: O(V+E)

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return nullptr;
    typedef UndirectedGraphNode Node;
    unordered_set<Node*> done;
    unordered_map<Node*, Node*> m;    
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      Node* s = q.front(); q.pop();
      if (done.count(s)) continue;
      done.insert(s);
      if (!m.count(s))
        m[s] = new Node(s->label);
      Node* t = m[s];
      for (Node* ss : s->neighbors) {
        if (!m.count(ss))
          m[ss] = new Node(ss->label);
        q.push(ss);        
        t->neighbors.push_back(m[ss]);
      }
    }    
    return m[node];
  }
};
