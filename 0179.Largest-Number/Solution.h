class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> numString;
        for (int i = 0; i < num.size(); i++) {
            numString.push_back(to_string(num[i]));
        }
        sort(numString.begin(), numString.end(), compareString);
        string result = "";
        for (int i = 0; i < numString.size(); i++) {
            result += numString[i];
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
    
    static bool compareString(string a, string b) {
        return a + b > b + a;
    }
};