class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        makeParenthesis(result, "", n, n);
        return result;
    }
    
    void makeParenthesis(vector<string>& result, string s, int l, int r) {
        if (l == 0) {
            result.push_back(s.append(r, ')'));
            return;
        }
        makeParenthesis(result, s + "(", l - 1, r);
        if (l < r) {
            makeParenthesis(result, s + ")", l, r - 1);
        }
    }
};