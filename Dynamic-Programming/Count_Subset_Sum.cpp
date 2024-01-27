//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        //Base cases
       	
        if(n==0 && sum>0) return 0;
        if(sum==0 && n==0) return 1;
        
        if(n>0 && sum>=0){
            if(arr[n-1]<=sum)
                return perfectSum(arr,n-1,sum-arr[n-1]) + perfectSum(arr,n-1,sum);
            else 
                return perfectSum(arr,n-1,sum);
        }
        
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
