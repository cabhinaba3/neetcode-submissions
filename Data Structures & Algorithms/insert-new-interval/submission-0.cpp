class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            return {newInterval};
        }
        int target = newInterval[0];
        int left = 0, right = intervals.size()-1;
        while(left <=right){
            int mid = (left + right)/2;
            if(intervals[mid][0] < newInterval[0]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        intervals.insert(intervals.begin()+left, newInterval);
        vector<vector<int>> res;
        for(auto &interval: intervals){
            if(res.empty() || res.back()[1]< interval[0]){
                res.push_back(interval);
            }else{
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
