/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool sortInterval(Interval a, Interval b) {
    if (a.start < b.start) return true;
    if (a.start == b.start) return a.end < b.end;
    return false;
}
    
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.size() < 1) return result;
        sort(intervals.begin(), intervals.end(), sortInterval);
        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= prev.end) {
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.push_back(prev);
                prev = intervals[i];
            }
        }
        result.push_back(prev);
        return result;
    }
};