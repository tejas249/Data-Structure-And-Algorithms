class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> um;

        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;

        for(auto i= um.begin(); i != um.end(); i++){
            minh.push({i->second, i->first});

            if(minh.size() > k){
               minh.pop();
            }
        }

        for(int i=0; i<k; i++){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
