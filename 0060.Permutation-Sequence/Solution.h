class Solution {
public:
    string getPermutation(int n, int k) {
        int* flg = new int[n];
        for (int i = 0; i < n; i++) {
            flg[i] = 0;
        }
        string result = "";
        int originN = n;
        int f = factorial(n);
        while (n > 0) {
            f /= (n);
            int segment = (k - 1) / f + 1;
            k = (k - 1) % f + 1;
            int nextNumber = theKthOfN(segment, originN, flg);
            result += ('0' + nextNumber);
            flg[nextNumber - 1] = 1;
            n--;
        }
        delete[] flg;
        return result;
    }
    
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    int theKthOfN(int k, int n, int* flg) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (flg[i] == 1) {
                continue;
            }
            c++;
            if (c == k) {
                return i + 1;
            }
        }
    }
};