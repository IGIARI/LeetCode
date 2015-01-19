class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) {
            result.push_back("");
            return result;
        }
        if (digits.length() == 1) {
            return getLetters(digits[0]);
        } else {
            vector<string> head = getLetters(digits[0]);
            vector<string> append = letterCombinations(&digits[1]);
            for (int i = 0; i < head.size(); i++) {
                for (int j = 0; j < append.size(); j++) {
                    result.push_back(head[i] + append[j]);
                }
            }
        }
        return result;
    }
    
    vector<string> getLetters(char n) {
        vector<string> result;
        if (n >= '2' && n <= '6') {
            for (int i = 0; i < 3; i++) {
                char str[] = {'a' + (n - '2') * 3 + i, '\0'};
                result.push_back(str);
            }
        } else if (n == '7') {
            for (int i = 0; i < 4; i++) {
                char str[] = {'p' + i, '\0'};
                result.push_back(str);
            }
        } else if (n == '8') {
            for (int i = 0; i < 3; i++) {
                char str[] = {'t' + i, '\0'};
                result.push_back(str);
            }
        } else if (n == '9') {
            for (int i = 0; i < 4; i++) {
                char str[] = {'w' + i, '\0'};
                result.push_back(str);
            }
        } else {
            result.push_back("");
        }
        return result;
    }
};