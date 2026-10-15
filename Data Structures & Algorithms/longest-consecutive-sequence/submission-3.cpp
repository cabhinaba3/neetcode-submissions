class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        // sort(nums.begin(), nums.end());
        // int maxStreak = 1;
        // int currStreak = 1;
        // int left = 1;
        // while(left < nums.size()){
        //     if(nums[left]-nums[left-1]==1){
        //         currStreak+=1;
        //     }else if(nums[left]-nums[left-1]>1){
        //         maxStreak = max(currStreak, maxStreak);
        //         currStreak = 1;
        //     }
        //     left+=1;
        // }
        // return max(maxStreak, currStreak);
        unordered_map<int,int> numSet;
        for(auto it: nums){
            numSet[it]+=1;
        }
        // int minValue
        int longest = 0;
        for(int num: nums){
            if(numSet.find(num-1) == numSet.end()){
                int length = 1;
                while(numSet.find(num+length)!=numSet.end()){
                    length +=1;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
