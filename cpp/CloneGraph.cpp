/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldToNew;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode* node1 = new UndirectedGraphNode(node->label);
        oldToNew[node] = node1;
        while(!q.empty()) {
            UndirectedGraphNode* top = q.front();
            q.pop();
            UndirectedGraphNode* top1 = oldToNew[top];
            for(int i=0;i<top->neighbors.size();i++) {
                if(oldToNew.find(top->neighbors[i]) == oldToNew.end()) {
                    UndirectedGraphNode* n = new UndirectedGraphNode(top->neighbors[i]->label);
                    oldToNew[top->neighbors[i]] = n;
                    top1->neighbors.push_back(n);
                    q.push(top->neighbors[i]);
                } else {
                    UndirectedGraphNode* n = oldToNew[top->neighbors[i]];
                    top1->neighbors.push_back(n);
                }
            }
        }
        return node1;
    }
};
