// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int matSearch (int n, int m, int matrix[][m], int x){
    int r = 0;
    int c = m-1;
    
    while(r<n && c>=0){
        if(x == matrix[r][c])
            return 1;
        else if(x > matrix[r][c])
            r++;
        else
            c--;
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