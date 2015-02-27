class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.length() + num2.length(), '0');
        for (int i = num2.length() - 1; i >= 0; i--) {
            for (int j = num1.length() - 1; j >= 0; j--) {
                int n2 = num2[i] - '0';
                int n1 = num1[j] - '0';
                int b = n1 * n2 % 10;
                int p = n1 * n2 / 10;
                if (b > 0 || p > 0) addToString(result, b, p, i + j + 1);
            }
        }
        int zeroCount = 0;
        for (int i = 0; i < result.length(); i++) {
            if (result[i] != '0') {
                break;
            }
            zeroCount++;
        }
        if (zeroCount == result.length()) {
            zeroCount--;
        }
        result.erase(0, zeroCount);
        return result;
    }
    
    void addToString(string& result, int b, int p, int pos) {
        int r = result[pos] - '0' + b;
        p += r / 10;
        r = r % 10;
        result[pos] = '0' + r;
        while (p > 0) {
            int rr = result[pos - 1] - '0' + p;
            p = rr / 10;
            rr = rr % 10;
            result[pos - 1] = rr + '0';
            pos--;
        }
    }
};