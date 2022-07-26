class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count[52];
        for(int i=0; i<52; i++){
            count[i] = 0;
        }
        for(int i=0; i<stones.size(); i++){
            if(stones[i] <= 90){
                count[stones[i]-65]++;
            }
            else{
                count[stones[i]-97+26]++;
            }
        }
        int ans = 0;
        for(int i=0; i<jewels.size(); i++){
            if(jewels[i] <= 90){
                ans += count[jewels[i]-65];
            }
            else{
                ans += count[jewels[i]-97+26];
            }
        }
        return ans;
    }
};