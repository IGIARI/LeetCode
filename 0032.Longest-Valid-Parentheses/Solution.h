class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int start = 0, maxLen = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			} else if (s[i] == ')') {
				if (stk.empty()) {
					start = i + 1;
				} else {
					stk.pop();
					maxLen = max(maxLen, stk.empty() ? i - start + 1 : i - stk.top());
				}
			}
		}
		return maxLen;
	}
};