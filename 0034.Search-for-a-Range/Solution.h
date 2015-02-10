class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        markBounds(A, 0, n - 1, target, result);
        return result;
    }
    
    void markBounds(int A[], int l, int r, int target, vector<int>& result) {
        if (l == r) {
            if (A[l] == target) {
                if (result[0] == -1 || result[0] > l) {
                    result[0] = l;
                }
                if (result[1] < r) {
                    result[1] = l;
                }
            }
            return;
        }
        int m = (l + r) / 2;
        markBounds(A, l, m, target, result);
        markBounds(A, m + 1, r, target, result);
    }
};