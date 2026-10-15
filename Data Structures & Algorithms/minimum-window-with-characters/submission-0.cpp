class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() == 0){ return ""; }
        unordered_map<char, int> countT, window;
        for(char c: t){ countT[c]+=1; }
        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int left = 0, right = 0;
        for(;right<s.size();right++){
            char c = s[right];
            window[c]+=1;
            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }
            while(have == need){
                if((right-left+1)< resLen){
                    resLen = right - left + 1;
                    res = {left, right};
                }
                window[s[left]]--;
                if(countT.count(s[left]) && window[s[left]]< countT[s[left]]){ have--; }
                left+=1;
            }
        }
        return resLen == INT_MAX? "": s.substr(res.first, resLen);
    }
};
