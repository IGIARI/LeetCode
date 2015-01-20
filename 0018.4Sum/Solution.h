class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector<int> > result;
		if (num.size() < 4) {
			return result;
		}
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size() - 3; i++) {
			if (i > 0 && num[i - 1] == num[i]) {
				continue;
			}
			for (int j = i + 1; j < num.size() - 2; j++) {
				if (j > i + 1 && num[j - 1] == num[j]) {
					continue;
				}
				for (int k = j + 1, l = num.size() - 1; k < l; ) {
					if (k > j + 1 && num[k - 1] == num[k]) {
						k++;
						continue;
					}
					if (l < num.size() - 1 && num[l] == num[l + 1]) {
						l--;
						continue;
					}
					int sum = num[i] + num[j] + num[k] + num[l];
					if (sum == target) {
						vector<int> answer;
						answer.push_back(num[i]);
						answer.push_back(num[j]);
						answer.push_back(num[k]);
						answer.push_back(num[l]);
						result.push_back(answer);
						k++;
						l--;
					} else if (sum > target) {
						l--;
					} else {
						k++;
					}
				}
			}
		}
		return result;
    }
};