class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;
        int left = 0, result = 1, right = 0;
        for(;right<s.size();){
            if(mp.find(s[right])!=mp.end()){
                mp.erase(s[left]);
                left+=1;
                result = max(result, right-left+1);
            }else{
                mp[s[right]] = true;
                right+=1;
            }
            // result = max(result, right-left+1);
        }
        return max(result, (int)mp.size());
    }
};
