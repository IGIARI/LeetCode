class Solution {
private:
    string roman[4][3] = {
        {"I", "V", "X"},
        {"X", "L", "C"},
        {"C", "D", "M"},
        {"M", "-", "-"}
    };

    string makeRomanNumeral(int n, int p) {
        string* r = roman[p];
        switch(n) {
        case 0:
            return "";
            break;
        case 1:
            return r[0];
            break;
        case 2:
            return r[0] + r[0];
            break;
        case 3:
            return r[0] + r[0] + r[0];
            break;
        case 4:
            return r[0] + r[1];
            break;
        case 5:
            return r[1];
            break;
        case 6:
            return r[1] + r[0];
            break;
        case 7:
            return r[1] + r[0] + r[0];
            break;
        case 8:
            return r[1] + r[0] + r[0] + r[0];
            break;
        case 9:
            return r[0] + r[2];
            break;
        default:
            return "";
        }
    }

public:
    string intToRoman(int num) {
        int n = num;
        string result = "";
        int p = 0;
        while (n > 0) {
            result = makeRomanNumeral(n % 10, p) + result;
            p++;
            n = n / 10;
        }
        return result;
    }
};