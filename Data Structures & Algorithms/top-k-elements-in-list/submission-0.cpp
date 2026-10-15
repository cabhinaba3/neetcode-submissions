class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums){ mp[it]+=1; }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto it: mp){
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
