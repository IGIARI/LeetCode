class Solution {
private:
    vector<vector<int> > makeResult(vector<int> &candidates, int n, int target) {
        vector<vector<int> > result;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && candidates[i] == candidates[i + 1]) {
                continue;
            }
            if (candidates[i] < target) {
                vector<vector<int> > r = makeResult(candidates, i, target - candidates[i]);
                for (int j = 0; j < r.size(); j++) {
                    r[j].push_back(candidates[i]);
                    result.push_back(r[j]);
                }
            } else if (candidates[i] == target) {
                vector<int> r;
                r.push_back(candidates[i]);
                result.push_back(r);
            }
        }
        return result;
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result = makeResult(num, num.size(), target);
        sort(result.begin(), result.end());
        return result;
    }
};