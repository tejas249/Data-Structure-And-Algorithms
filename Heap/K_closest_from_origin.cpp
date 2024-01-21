class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        vector<vector<int>> ans;
        // create the maxheap
        priority_queue<pair<int,pair<int,int>>> maxh;
        //iterate through the array ans and key wil store two things distance and the points 
        for(int i=0; i<arr.size(); i++){
           maxh.push({arr[i][0]*arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
          //insert each points into the heap if size is > k then just pop
           if(maxh.size() > k){
               maxh.pop();
           }
        }
        // till heree we will left with two nearest points then store them in and vector and just return 
        while(maxh.size() > 0){
            pair<int,int> p = maxh.top().second;
            ans.push_back({p.first, p.second});
            maxh.pop();
        }
        return ans;
    }
};
