class Solution {
public:
    int trap(int A[], int n) {
        return calc(A, 0, n-1);
    }
    
    int calc(int A[], int l, int r) {
    	if (r <= l + 1) {
    		return 0;
    	}
    	int h = (A[l] < A[r]) ? A[l] : A[r];
    	int middleMaxH = 0, m = 0;
    	for (int i = l + 1; i < r; i++) {
    		if (A[i] > middleMaxH) {
    			middleMaxH = A[i];
    			m = i;
    		}
    	}
    	if (middleMaxH <= h) {
    		int filledSum = 0;
            for (int i = l + 1; i < r; i++) {
                filledSum += A[i];
            }
            return (r - l - 1) * h - filledSum;
    	} else {
    		return calc(A, l, m) + calc(A, m, r);
    	}
    }
};