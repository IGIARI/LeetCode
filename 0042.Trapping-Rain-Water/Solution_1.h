class Solution {
public:
    int trap(int A[], int n) {
        int i = 0;
        int sum = 0;
        while (i < n - 1) {
            int j = i + 1, m = j;
            while (j < n) {
                if (A[j] >= A[i]) {
                    sum += calculate(A, i, j);
                    i = j;
                    break;
                } else {
                    if (A[j] > A[m]) {
                        m = j;
                    }
                }
                j++;
                if (j == n) {
                    sum += calculate(A, i, m);
                    i = m;
                    break;
                }
            }
        }
        return sum;
    }
    
    int calculate(int A[], int l, int r) {
        if (r <= l) {
            return 0;
        }
        int filledSum = 0;
        for (int i = l + 1; i < r; i++) {
            filledSum += A[i];
        }
        return (r - l - 1) * min(A[l], A[r]) - filledSum;
    }
};