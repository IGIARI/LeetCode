class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int minSub = INT_MAX;
        if (num.size() < 3) {
            return 0;
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
                int sub = num[i] + num[j] + num[k] - target;
                minSub = (abs(sub) < abs(minSub)) ? sub : minSub;
                if (sub == 0) {
                    return target;
                } else if (sub > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return target + minSub;
    }
};