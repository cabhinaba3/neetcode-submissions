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
        // 2,20,4, 10,3,4,5
        int longest = 0;
        for(int num: nums){
            int length = 0;
            int index = 1;
            while(numSet.find(num+index)!=numSet.end()){
                numSet.erase(num+index);
                index+=1;
            }
            length += index;
            index=1;
            while(numSet.find(num-index)!=numSet.end()){
                numSet.erase(num-index);
                index+=1;
            }
            length += index-1;
            numSet.erase(num);
            longest = max(longest, length);
        }
        return longest;
    }
};
