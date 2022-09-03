class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        if(milestones.size() == 1) return 1;
        
        long long total = 0;
        int maxx = 0;
        for(int i : milestones){
            total += i;
            maxx = max(maxx,i);
        }
        
        long long total_of_min = total - maxx;
        if(maxx > total_of_min){
            long long ans = 2*total_of_min + 1;
            return ans;
        }
        
        long long x = ceil(total/2.0);
        for(int i : milestones){
            if(i > x){
                total -= i-x;
            }
        }
                
        return total;
    }
};