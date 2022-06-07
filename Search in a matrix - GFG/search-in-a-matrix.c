// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int matSearch (int n, int m, int matrix[][m], int target){
    if(target < matrix[0][0] || target > matrix[n-1][m-1]){
        return 0;
    }
    
    for(int i=0; i<n; i++){
        if(target >= matrix[i][0] && target <= matrix[i][m-1]){
            int l2 = 0;
            int h2 = m-1;
            int m2;
            while(l2 <= h2){
                m2 = l2 + (h2-l2)/2;
                if(matrix[i][m2] == target)
                    return 1;
                else if(matrix[i][m2] > target)
                    h2 = m2 - 1;
                else
                    l2 = m2 + 1;
            }       
        }
    }
    
    return 0;
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--)
	{
        int n, m;
		scanf("%d", &n);
		scanf("%d", &m);
		int matrix[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		   
		int x;
		scanf("%d", &x);
		
        int result = matSearch (n, m, matrix, x);
        printf("%d", result);
		printf("\n");
    }
    return 0;
}
  // } Driver Code Ends