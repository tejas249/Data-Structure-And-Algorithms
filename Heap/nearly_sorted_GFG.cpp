//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
      
        // Your code here
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> ans;
        
        //added elements in the heap until size becomes k
        for(int i=0; i<num; i++){
            minh.push(arr[i]);
            
            //if size of heap is k then store the top element(min)
            if(minh.size() > K){
                ans.push_back(minh.top());
                minh.pop();
            }
        }
      
        //add all the remaining elements(top) in the vector and return it
        while(minh.size() > 0){
            ans.push_back(minh.top());
            minh.pop();
        }
    return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends
