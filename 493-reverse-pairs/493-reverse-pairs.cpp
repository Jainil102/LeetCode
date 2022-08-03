class Solution {
public:
    
    void merge(vector<int>& nums, int start, int mid, int end){
        vector<int> temp;
        int i = start;
        int j = mid+1;
        while(i<=mid && j<=end){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        for(int i=start; i<=end; i++){
            nums[i] = temp[i-start];
        }
    }    
    
    void mergeSort(vector<int>& nums, int start, int end, int* ans){
        if(start >= end){
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(nums, start, mid, ans);
        mergeSort(nums, mid+1, end, ans);
        
        int i = start;
        int j = mid+1;
        int count = 0;
        while(i<=mid){
            while(j<=end && nums[i] > ((long)2*nums[j])){
                j++;
                count++;
            }
            *ans = *ans + count;
            i++;
        }
        merge(nums, start, mid, end);
    }
    
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums, 0, nums.size()-1, &ans);
        return ans;
    }
};