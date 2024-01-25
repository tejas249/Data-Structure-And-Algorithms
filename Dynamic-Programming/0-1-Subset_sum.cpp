#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {

        int n = arr.size();

        // Base conditions
        if (sum > 0 && n == 0) {
            return false;
        }
        if (sum == 0) {
            return true;
        }

        // 0th row and 0th columns cases
        bool t[n + 1][sum + 1];

        for (int i = 0; i <= sum; i++) {
            t[0][i] = false;
        }
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }

        // Knapsack for the subset sum
        // Three changes: 1. No val arr (remove it)
        // 2. Replace wt with arr
        // 3. Replace max operation with OR ||
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class
    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;

    cout << sol.isSubsetSum(arr, sum) << endl;

    return 0;
}
