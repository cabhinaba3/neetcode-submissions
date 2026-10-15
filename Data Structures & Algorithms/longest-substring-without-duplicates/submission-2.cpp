class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;
        int left=0, right = 0, result = 0;
        for(;right<s.size();){
            if(mp.find(s[right])!=mp.end()){
                result = max(result, right-left);
                mp.erase(s[left]);
                left+=1;
            }else{
                mp[s[right]] = true;
                right+=1;
            }
        }
        return max(result, (int)mp.size());
    }
};
