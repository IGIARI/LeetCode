class Solution {
private:
    int ip;
public:
    int searchInsert(int A[], int n, int target) {
        ip = n;
        binSearchInsertPosition(A, 0, n - 1, target);
        return ip;
    }
    
    void binSearchInsertPosition(int A[], int l, int r, int target) {
        if (l == r) {
            ip = (A[l] >= target) ? min(l, ip) : min(l + 1, ip);
            return;
        }
        int m = (l + r) / 2;
        if (target > A[m]) {
            binSearchInsertPosition(A, m + 1, r, target);
        } else {
            ip = min(ip, m);
            binSearchInsertPosition(A, l, m, target);
        }
    }
};