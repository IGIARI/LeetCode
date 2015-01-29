class Solution {
public:
    int divide(int dividend, int divisor) {
        int ddFlg = dividend >= 0 ? 1 : -1, drFlg = divisor >= 0 ? 1 : -1;
        long dd = dividend * (long)ddFlg, dr = divisor * (long)drFlg;
        int ldd = 0, ldr = 0;
        if (dr == 0) {
            return INT_MAX;
        } else if (dr == 1) {
            if (ddFlg * drFlg > 0) {
                return (dd > INT_MAX) ? INT_MAX * ddFlg * drFlg : dd * ddFlg * drFlg;
            } else {
                return dd * ddFlg * drFlg;
            }
        }
        if (dd < dr) {
            return 0;
        }
        int result = 0;
        int tmpResult = 1;
        while (dr << 1 <= dd) {
            dr <<= 1;
            tmpResult <<= 1;
        }
        do {
            if (dd >= dr) {
                result += tmpResult;
                dd -= dr;
            }
            dr >>= 1;
            tmpResult >>= 1;
        } while (dd > 0 && tmpResult > 0);
        return result * ddFlg * drFlg;
    }
};