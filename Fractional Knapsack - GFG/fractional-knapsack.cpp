//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<double,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({(double)arr[i].value/arr[i].weight, i});
        }
        
        sort(vec.begin(), vec.end());
        
        int i=n-1;
        double ans = 0.0;
        while(i>=0 && W!=0){
            if(arr[vec[i].second].weight <= (double)W){
                ans += arr[vec[i].second].value;
                W -= arr[vec[i].second].weight;
            } 
            else{
                ans += vec[i].first*W;
                break;
            }
            i--;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends