class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector<int> > result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i - 1] == num[i]) {
                continue;
            }
            for (int j = i + 1, k = num.size() - 1; j < k; ) {
                if (j > i + 1 && num[j - 1] == num[j]) {
                    j++;
                    continue;
                }
                if (k < num.size() - 1 && num[k] == num[k + 1]) {
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> answer;
                    answer.push_back(num[i]);
                    answer.push_back(num[j]);
                    answer.push_back(num[k]);
                    result.push_back(answer);
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};