class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        
        int base = 2 * (nRows - 1);
        string* strArray = new string[nRows];
        for (int i = 0; i < s.length(); i++) {
            int j = i % base;
            if (j < nRows) {
                strArray[j] += s[i];
            } else {
                strArray[base - j] += s[i];
            }
        }
        string result;
        for (int i = 0; i < nRows; i++) {
            result += strArray[i];
        }
        delete[] strArray;
        return result;
    }
};