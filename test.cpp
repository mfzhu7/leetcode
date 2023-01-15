#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<stack>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= curr[1]){
                curr[1] = intervals[i][1];
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        return intervals;

    }
};



int main(){
    vector<vector<int>> a = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<int> test = {3, 5};
    a.insert(a.begin() + 4, test);
    for (auto i : a){
        cout << i[0] << " " << i[1] << endl;
    }
}
