//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({end[i],start[i]});
        }
        
        sort(vec.begin(), vec.end());
        
        int count = 1;
        int endtime = vec[0].first;
        for(int i=1; i<n; i++){
            if(vec[i].second > endtime){
                count++;
                endtime = vec[i].first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends