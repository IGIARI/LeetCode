class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            string p1 = findLongestFromCenter(s, i, i);
            if (p1.length() > result.length()) {
                result = p1;
            }
            string p2 = findLongestFromCenter(s, i, i + 1);
            if (p2.length() > result.length()) {
                result = p2;
            }
        }
        return result;
    }
    
private:
    string findLongestFromCenter(string s, int l, int r) {
        while (l >= 0 && r < s.length()) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        return s.substr(l + 1, r - l - 1);
    }
};
