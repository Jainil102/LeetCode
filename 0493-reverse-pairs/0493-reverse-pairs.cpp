class Solution {
public:
    int pairs = 0;
    
    void merge(vector<int>& nums, int start, int mid, int end){
        int temp[end-start+1];
        int i = start;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=end){
            if(nums[i] < nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=end){
            temp[k++] = nums[j++];
        }
        for(int i=start; i<=end; i++){
            nums[i] = temp[i-start];
        }
    }
    
    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        
        int mid = start + (end-start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        
        int i = start;
        int j = mid+1;
        int count = 0;
        while(i<=mid){
            while(j<=end && nums[i] > (long)2*nums[j]){
                count++;
                j++;
            }
            i++;
            pairs += count;
        }       
        
        merge(nums, start, mid, end);
    }
    
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return pairs;
    }
};