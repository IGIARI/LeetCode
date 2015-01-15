class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sorted;
        for (int i = 0; i < numbers.size(); i++) {
            sorted.push_back(numbers[i]);
        }
        sort(sorted.begin(), sorted.end());
        
        vector<int> result;
        for (int i = 0, j = sorted.size() - 1; i < j; ) {
            if (sorted[i] + sorted[j] == target) {
                int i1 = findIndex1(numbers, sorted[i]);
                int i2 = findIndex2(numbers, sorted[j]);
                if (i1 > i2) {
                    int t = i1;
                    i1 = i2;
                    i2 = t;
                }
                result.push_back(i1);
                result.push_back(i2);
                break;
            }
            if (sorted[i] + sorted[j] > target) {
                j--;
                continue;
            } else if (sorted[i] + sorted[j] < target) {
                i++;
                continue;
            }
        }
        return result;
    }

private:
    int findIndex1(vector<int> &numbers, int n) {
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == n) {
                return i + 1;
            }
        }
        return 0;
    }

    int findIndex2(vector<int> &numbers, int n) {
        int firstIndex;
        int counter = 0;
        int i;
        for (i = 0; i < numbers.size(); i++) {
            if (numbers[i] == n) {
                if (counter == 0) {
                    counter++;
                    firstIndex = i + 1;
                } else {
                    return i + 1;
                }
            }
        }
        if (i >= numbers.size() && counter > 0) {
            return firstIndex;
        }
        return 0;
    }
};
