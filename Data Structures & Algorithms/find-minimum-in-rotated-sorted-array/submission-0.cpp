class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left+(right-left)/2;
            // if(nums[mid]>nums[mid+1]){ return nums[mid+1];}
            // if(nums[mid-1]>nums[mid]){ return nums[mid]; }
            // if(nums[0] < nums[mid] ){ left = mid+1; }
            if(nums[right] > nums[mid]){ right = mid; }
            else{ left = mid+1; }
        }
        return nums[left];
    }
};


// 1,2,3,4,5,6
// 5,6,1,2,3,4