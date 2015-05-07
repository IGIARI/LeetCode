/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        bool flg = false;
        for (int i = 0; i < intervals.size(); i++) {
            Interval itv = intervals[i];
            if (canMerge(itv, newInterval)) {
                newInterval.start = min(newInterval.start, itv.start);
                newInterval.end = max(newInterval.end, itv.end);
            } else {
                if (itv.start > newInterval.start && !flg) {
                    result.push_back(newInterval);
                    flg = true;
                }
                result.push_back(itv);
            }
        }
        if (!flg)
            result.push_back(newInterval);
        return result;
    }
    
    bool canMerge(Interval a, Interval b) {
        return !(a.end < b.start || a.start > b.end);
    }
};