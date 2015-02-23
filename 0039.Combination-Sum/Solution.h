class Solution {
private:
    vector<vector<int> > makeResult(vector<int> &candidates, int n, int target) {
        vector<vector<int> > result;
        for (int i = n - 1; i >= 0; i--) {
            if (candidates[i] < target) {
                vector<vector<int> > r = makeResult(candidates, i + 1, target - candidates[i]);
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return makeResult(candidates, candidates.size(), target);
    }
};