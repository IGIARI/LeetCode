class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int startIndex = 0;
        int lastIndex[256];
        for (int i = 0; i < 256; i++) {
            lastIndex[i] = -1;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (lastIndex[c] >= 0) {
                if (i - startIndex > maxLen) {
                    maxLen = i - startIndex;
                }
                startIndex = lastIndex[c] + 1;
                for (int j = 0; j < 256; j++) {
                    if (lastIndex[j] < startIndex && lastIndex[j] >= 0) {
                        lastIndex[j] = -1;
                    }
                }
                lastIndex[c] = i;
            } else {
                lastIndex[c] = i;
            }
        }
        if (s.length() - startIndex > maxLen) {
            maxLen = s.length() - startIndex;
        }
        return maxLen;
    }
};
