class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> wordCount;
        for (int i = 0; i < L.size(); i++) {
            wordCount[L[i]]++;
        }
        vector<int> result;
        map<string, int> wordCountOfS;
        int wordLength = L[0].length();
        for (int i = 0; i < S.length() - wordLength * L.size() + 1; i++) {
            wordCountOfS.clear();
            int matchCount = 0;
            for (int j = i; j < S.length() - wordLength + 1; j += wordLength) {
                string word = S.substr(j, wordLength);
                if (++wordCountOfS[word] > wordCount[word]) {
                    break;
                } else {
                    matchCount++;
                }
            }
            if (matchCount == L.size()) {
                result.push_back(i);
            }
        }
        return result;
    }
};