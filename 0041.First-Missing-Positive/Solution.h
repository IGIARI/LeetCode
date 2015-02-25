class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n <= 0) {
            return 1;
        }
        int tmp = 0, i = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                tmp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = tmp;
                i--;
            }
        }
        for (i = 0; i < n; i++) {
            if (A[i] != (i + 1)) {
                return i + 1;
            }
        }
        return i + 1;
    }
};