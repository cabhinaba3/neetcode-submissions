class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        sort(nums.begin(), nums.end());
        int maxStreak = 1;
        int currStreak = 1;
        int left = 1;
        while(left < nums.size()){
            if(nums[left]-nums[left-1]==1){
                currStreak+=1;
            }else{
                maxStreak = max(currStreak, maxStreak);
                currStreak = 1;
            }
            left+=1;
        }
        return max(maxStreak, currStreak)+1;

    }
};
