class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         // Get the size of the input vector 'nums'
        int n = nums.size();
        
        // Create a vector of pairs, where each pair contains the index and the corresponding value of 'nums'
        vector<pair<int, int>> vals;
        for (int i = 0; i < n; ++i) {
            vals.push_back({i, nums[i]});
        }
        
        // Sort the vector of pairs in descending order based on the values (second element of each pair)
        sort(vals.begin(), vals.end(), [&](auto x1, auto x2) {
            return x1.second > x2.second;
        });
        
        // Sort the first 'k' elements of the vector of pairs based on the indices (first element of each pair)
        sort(vals.begin(), vals.begin() + k);
        
        // Create a vector 'ans' to store the values of the first 'k' elements after sorting by indices
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(vals[i].second);
        }
        
        // Return the final vector containing the values of the first 'k' elements after sorting by indices
        return ans;
    }
};



  



  
