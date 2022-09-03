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
        
        long long rest_total = total - maxx;
        if(maxx > rest_total){
            long long ans = 2*rest_total + 1;
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