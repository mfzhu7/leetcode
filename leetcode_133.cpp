class Solution {
public:
    void helper(Node* node, unordered_map<Node*, Node*>& hash, unordered_set<Node*>& path){
        if (!node) return;
        Node* temp = new Node(node->val);
        hash.insert({node, temp});
        path.insert(node);
        vector<Node*> nbr = node->neighbors;
        for (int i = 0;i < nbr.size(); i++){
            if (path.find(nbr[i]) == path.end()){
                helper(nbr[i],hash,path);
            }
        }
        return;
    }
    void dfs(Node* node, unordered_map<Node*, Node*>& hash, unordered_set<Node*>& path){
        if (!node) return;
        vector<Node*>nbr = node->neighbors;
        vector<Node*> n;
        path.insert(node);
        for (int i = 0; i < nbr.size(); i++){
            n.push_back(hash[nbr[i]]);
            if (path.find(nbr[i]) == path.end()){
                dfs(nbr[i],hash,path);
            }
        }
        hash[node]->neighbors = n;
        return;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        unordered_set<Node*> path1;
        unordered_set<Node*> path2;
        helper(node,hash,path1);
        dfs(node,hash,path2);
        return hash[node];    
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            vector<Node*> nbr = front->neighbors;
            for (auto &n : nbr){
                if (visited.find(n) == visited.end()){
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                visited[front]->neighbors.emplace_back(visited[n]);
            }
        }
        return visited[node];
        
    }
};