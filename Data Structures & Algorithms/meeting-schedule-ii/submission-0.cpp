/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 bool comp(Interval &p1, Interval &p2){
    return p1.start < p2.start;
 }
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(const auto& interval: intervals){
            if(!minHeap.empty() && minHeap.top() <= interval.start){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
