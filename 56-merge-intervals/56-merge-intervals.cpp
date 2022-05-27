class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(merged.back()[1] < intervals[i][0]){
                merged.push_back(intervals[i]);
            }
            else{
                if(merged.back()[1] < intervals[i][1]){
                    vector<int> temp;
                    temp.push_back(merged.back()[0]);
                    temp.push_back(intervals[i][1]);
                    merged.pop_back();
                    merged.push_back(temp);
                }
            }
        }
        return merged;
    }
};