#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthLargest(int k, int arr[], int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            int element = arr[i];
            pq.push(element);
        }
        
        for(int i = k; i < n; i++){
            int element = arr[i];
            if(pq.top() < element){
                pq.pop();
                pq.push(element);
            }
        }
        return pq.top();
    }
};
