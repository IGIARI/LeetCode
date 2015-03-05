class Solution {
private:
    bool sorted = false;
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0) {
            return result;
        }
        if (num.size() == 1) {
            vector<int> singleResult;
            singleResult.push_back(num[0]);
            result.push_back(singleResult);
            return result;
        }
        if (!sorted) {
            sort(num.begin(), num.end());
            sorted = true;
        }
        for (int i = 0; i < num.size(); i++) {
            int first = num[i];
            num.erase(num.begin() + i);
            vector<vector<int> > r = permute(num);
            for (int j = 0; j < r.size(); j++) {
                vector<int> singleResult = r[j];
                singleResult.insert(singleResult.begin(), first);
                result.push_back(singleResult);
            }
            num.insert(num.begin() + i, first);
        }
        return result;
    }
};