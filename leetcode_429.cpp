class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        vector<int> temp = {root->val};
        ans.push_back(temp);
        int level_cnt = 1;
        while(!q.empty()){
            int temp = 0;
            vector<int> level;
            for(int i = 0;i < level_cnt; i++){
                Node* front = q.front();
                q.pop();
                for(auto it: (*front).children){
                    q.push(it);
                    temp++;
                    level.push_back(it->val);
                }
            }
            if(level.size()){
                ans.push_back(level);
            }
            level_cnt = temp;
        }
        return ans;

        
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; i++){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for (auto it: curr->children){
                    q.push(it);
                }
            }
            ans.push_back(move(level));
        }
        return ans;
        
    }
};