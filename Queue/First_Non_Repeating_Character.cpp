// GFG FIRST NON REPEATING CHARACTER

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> count;
		    queue<int> q;
		    string ans = "";
		    
		    
		    //traverse through the a 
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        //increase the count 
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()] > 1){
		                //repeating character
		                q.pop();
		            }
		            else{
		                //non repeatig character 
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;
		}

};

