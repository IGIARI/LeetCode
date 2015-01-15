class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) {
            return *s == 0;
        }
        if (*(p + 1) == '*') {
            while (isEqual(*s, *p)) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
        } else {
            return (isEqual(*s, *p) && isMatch(s + 1, p + 1));
        }
        return false;
    }
    
    bool isEqual(char s, char p) {
        return (p == '.' && s != '\0') ? true : (p == s);
    }
};