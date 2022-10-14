//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                long newT = (long)k - arr[i] - arr[j];
                int p = j+1;
                int q = n-1;
                while(p < q){
                    if((long)arr[p]+arr[q] == newT){
                        ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                        while(p<q && arr[p] == arr[p+1]){
                            p++;
                        }
                        p++;
                        while(p<q && arr[q] == arr[q-1]){
                            q--;
                        }
                        q--;
                    }
                    else if (arr[p]+arr[q] > newT){
                        q--;
                    }
                    else{
                        p++;
                    }
                }
                while(j<n-2 && arr[j]==arr[j+1]){
                    j++;
                }
            }
            while(i<n-3 && arr[i]==arr[i+1]){
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends