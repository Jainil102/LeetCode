class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // int lt[n];
        // lt[0] = height[0];
        // int rt[n];
        // rt[n-1] = height[n-1];
        // for(int i=1; i<n; i++){
        //     lt[i] = max(height[i],lt[i-1]);
        // }
        // for(int i=n-2; i>=0; i--){
        //     rt[i] = max(height[i],rt[i+1]);
        // }
        // int maxTrap = 0;
        // for(int i=0; i<n; i++){
        //     maxTrap += min(lt[i],rt[i]) - height[i];
        // }
        // return maxTrap;
        
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int maxTrap = 0;
//         left == right will be the highest tower
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax){
                maxTrap += leftMax - height[left];
                left++;
            }
            else{
                maxTrap += rightMax - height[right];
                right--;
            }
        }
        return maxTrap;
    }
};