class Solution {
public:
    int search(int A[], int n, int target) {
        return binSearch(A, 0, n - 1, target);
    }
    
    int binSearch(int A[], int l, int r, int target) {
        if (l > r) {
            return -1;
        }
        int m = (l + r) / 2;
        if (A[m] == target) {
            return m;
        }
        if (A[m] < target) {
            return (A[r] >= A[m] && A[r] < target) ?
                binSearch(A, l, m - 1, target) :
                binSearch(A, m + 1, r, target);
        } else {
            return (A[l] <= A[m] && A[l] > target) ?
                binSearch(A, m + 1, r, target) :
                binSearch(A, l, m - 1, target);
        }
    }
};