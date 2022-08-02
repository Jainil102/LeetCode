class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int A[1001];
        fill_n(A, 1001, 0);
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int count = 1;
        
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                if(A[count] != 0){
                    return false;
                }
                A[count] = 1;
                count = 1;
            }
        }
        if(A[count] != 0){
            return false;
        }
        return true;
    }
};