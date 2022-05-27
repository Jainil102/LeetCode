class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // edge cases
        if(n == 0){
            return;
        }
        if(m == 0){
            for(int i=0; i<n; i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        
        int p1 = m-1;
        int p2 = n-1;
        int p3 = n+m-1;
        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] >= nums2[p2]){
                nums1[p3--] = nums1[p1--];
            }
            else{
                nums1[p3--] = nums2[p2--];
            }
        }
        if(p1 < 0){
            for(int i=0; i<=p2; i++){
                nums1[i] = nums2[i];
            }
        }
    }
};