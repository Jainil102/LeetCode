//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long merge(long long arr[], long long start, long long mid, long long end){
        long long ans = 0;
        vector<long long> temp;
        int i=start, j=mid+1;
        while(i<=mid && j<=end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                ans += mid - i + 1;
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=end){
            temp.push_back(arr[j++]);
        }
        for(int i=start; i<=end; i++){
            arr[i] = temp[i-start];
        }
        return ans;
    }
    
    long long mergeSort(long long arr[], long long start, long long end){
        if(start >= end){
            return 0;
        }
        
        long long mid = start + (end-start)/2;
        return mergeSort(arr, start, mid) + mergeSort(arr, mid+1, end) + merge(arr, start, mid, end);
    }
  
    long long int inversionCount(long long arr[], long long N){
        return mergeSort(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends