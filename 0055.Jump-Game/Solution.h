class Solution {
public:
    bool canJump(int A[], int n) {
        if (A[0] >= n - 1) return true;
        int maxDistance = A[0];
        for (int i = 1; i <= maxDistance; i++) {
            if (A[i] + i > maxDistance) {
                maxDistance = A[i] + i;
                if (maxDistance >= n - 1) return true;
            }
        }
        return false;
    }
};