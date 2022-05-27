class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            int n1 = merged.size()-1;
            if(merged[n1][1] < intervals[i][0]){
                merged.push_back(intervals[i]);
            }
            else{
                if(merged[n1][1] < intervals[i][1]){
                    vector<int> temp;
                    temp.push_back(merged[n1][0]);
                    temp.push_back(intervals[i][1]);
                    merged.pop_back();
                    merged.push_back(temp);
                }
            }
        }
        return merged;
    }
};