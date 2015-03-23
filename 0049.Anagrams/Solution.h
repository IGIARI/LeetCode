class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string>> strMap;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            strMap[tmp].push_back(strs[i]);
        }
        for (auto i = strMap.begin(); i != strMap.end(); i++) {
            if (i->second.size() > 1) {
                result.insert(result.end(), i->second.begin(), i->second.end());
            }
        }
        return result;
    }
};