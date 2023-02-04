class Solution {
public:
    vector<vector<int>> edges;
    vector<int> inedg;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        inedg.resize(numCourses);

        for(auto info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++inedg[info[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if(inedg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);

            for(auto v: edges[u]){
                --inedg[v];
                if(inedg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() != numCourses){
            return {};
        } else {
            return result;
        }


    }
};