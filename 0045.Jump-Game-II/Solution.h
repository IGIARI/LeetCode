class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        int step = 0;
        int pos = 0;
        while (true) {
    		step++;
        	if (pos + A[pos] >= n - 1) {
        		break;
        	}
            int maxJump = 0;
            int maxJumpIndex = pos;
            for (int i = 0; i <= A[pos]; i++) {
                if (i + A[i + pos] > maxJump) {
                    maxJump = A[i + pos] + i;
                    maxJumpIndex = pos + i;
                }
            }
            pos = maxJumpIndex;
        }
        return step;
    }
};