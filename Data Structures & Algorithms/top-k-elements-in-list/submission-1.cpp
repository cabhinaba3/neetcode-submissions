class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count the frequnecy of the elements
        unordered_map<int, int> mp;
        for(auto it: nums){ mp[it]++; }
        // I need a minheap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto it: mp){
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while(minHeap.size()>0){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
