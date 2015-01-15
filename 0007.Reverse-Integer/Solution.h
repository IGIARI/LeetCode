class Solution {
public:
    int reverse(int x) {
        double long y = 0;
        int maxInt = ~(1 << (8 * sizeof(int) - 1));
        bool flg = false;
        if (x < 0) {
            flg = true;
            x *= -1;
        }
        while (x > 0) {
            int i = x % 10;
            x /= 10;
            y *= 10;
            y += i;
            if (y > maxInt) {
                return 0;
            }
        }
        if (flg) {
            y *= -1;
        }
        return (int)y;
    }
};