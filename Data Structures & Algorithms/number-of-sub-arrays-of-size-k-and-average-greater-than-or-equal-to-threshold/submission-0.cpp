class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0, curSum = 0;
        for(int i=0;i<k-1;i++){
            curSum += arr[i];
        }
        for(int left=0;left<=arr.size()-k;left+=1){
            curSum += arr[left+k-1];
            if(curSum >= k * threshold){ res+=1; }
            curSum -= arr[left];
        }
        return res;
    }
};