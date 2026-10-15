class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        if(s.size() != t.size()){ return false; }
        int vis[26] = {0};
        for(int i=0;i<s.size();++i){
            vis[s[i]-'a']+=1;
            vis[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(vis[i]!=0){ return false; }
        }
        return true;

    }
};
