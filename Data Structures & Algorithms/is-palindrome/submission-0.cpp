class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(!alphaNum(s[left])){
                left+=1;
                continue;
            }
            if(!alphaNum(s[right])){
                right-=1;
                continue;
            }
            if(tolower(s[left])!= tolower(s[right])){ return false; }
            left+=1;
            right-=1;
        }
        return true;
    }
    bool alphaNum(char c){
        return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
    }
};
