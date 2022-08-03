class Solution {
public:
    
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int p = start;
        for(int i=start; i<end; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[p++]);
            }
        }
        swap(nums[end], nums[p]);
        return p;
    }
    
    int quick(vector<int>& nums, int start, int end, int k){
        if(start > end){
            return INT_MIN;
        }
        int p = partition(nums, start, end);
        int l = nums.size()-p;
        if(l == k) return nums[p];
        else if(l > k) return quick(nums, p+1, end, k);
        else return quick(nums, start, p-1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quick(nums, 0, nums.size()-1, k);
    }
};