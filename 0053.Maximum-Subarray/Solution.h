class Solution {
public:
    int maxSubArray(int A[], int n) {
        int* sum = new int[n];
        int maxSubSum = sum[0] = A[0];
        for (int i = 1; i < n; i++) {
            sum[i] = max(A[i], A[i] + sum[i - 1]);
            maxSubSum = max(maxSubSum, sum[i]);
        }
        return maxSubSum;
    }
};