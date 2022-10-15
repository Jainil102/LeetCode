class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;
        unordered_set<int> set;
        
        for(int i=0; i<s.length(); i++){
            if(set.find(s[i]) != set.end()){
                ans = ans<i-l ? i-l : ans;
                while(l<i && s[l] != s[i]){
                    set.erase(s[l]);
                    l++;
                }
                set.erase(s[l]);
                l++;
            }
            set.insert(s[i]);
        }
        ans = ans<s.length()-l ? s.length()-l : ans;
        
        return ans;
    }
};