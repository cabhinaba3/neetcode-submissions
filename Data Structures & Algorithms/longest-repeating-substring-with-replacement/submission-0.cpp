class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int maxFreq = INT_MIN;
        int left = 0, right = 0;
        unordered_map<char, int> freqCount;
        for(;right<s.size();){
            freqCount[s[right]]+=1;
            maxFreq = max(maxFreq, freqCount[s[right]]);

            while((right-left+1) - maxFreq > k){
                freqCount[s[left]]-=1;
                left+=1;
            }
            result = max(result, right - left+1);
            right+=1;
        }
        return result;
    }
};
