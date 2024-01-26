class Solution {
public:
    bool subsetsum(vector<int>& nums, int sum, int n) {
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i <= n; i++)
            t[i][0] = true;     //store true in columns
        for (int j = 0; j <= sum; j++)
            t[0][j] = false;  //store the false in rows

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // checking the consition when we have to add it 
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                } 
                //if we are not adding it 
                else if (nums[i - 1] > j) {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        // Move the return statement outside the outer for loop
        return t[n][sum];   //returning the last box value T/F
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i]; 
        }

        if (sum % 2 != 0)         //sum is not even so patition not possible 
            return false;
        else
            return subsetsum(nums, sum / 2, n);    // if sum is getiing and if we get subsetsum of half sum
    }
};

   

  
