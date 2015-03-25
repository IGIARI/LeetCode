class Solution {
public:
    double pow(double x, int n) {
        if (x == 0 || x == 1.0) return x;
        long long t = n;
        if (t < 0) return 1 / _pow(x, -1 * t);
        else return _pow(x, t);
    }
    
    double _pow(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        double d = _pow(x, n / 2);
        return (n % 2) ? (d * d * x) : (d * d);
    }
};