class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto it: nums){
            if(mp.find(it)!=mp.end()){ return true; }
            else { mp[it]=true; }
        }
        return false;
    }
};