class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.size() == 0 ){
            ans.push_back(newInterval);
            return ans;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= curr[1]){
                if (intervals[i][1] >= curr[1]) curr[1] = intervals[i][1];
            }
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;

    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.size() == 0 ){
            ans.push_back(newInterval);
            return ans;
        }

        int idx = 0;
        while(idx < intervals.size() && intervals[idx][0] < newInterval[0]){
            idx++;
        }
        intervals.insert(intervals.begin() + idx, newInterval);
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= curr[1]){
                if (intervals[i][1] >= curr[1]) curr[1] = intervals[i][1];
            }
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;

    }
};



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        bool place = false;

        for (auto interval: intervals){
            if (interval[0] > right){
                if (!place){
                    ans.push_back({left, right});
                    place = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left){
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]); 
                right = max(right, interval[1]);
            }
        }
        if (!place){
            ans.push_back({left, right});
        }
        return ans;

    }
};