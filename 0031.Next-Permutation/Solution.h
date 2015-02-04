class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) {
            return;
        }
        vector<int> tmp;
        int head = -1;
        int i = 0;
        for (i = num.size() - 1; i > 0; i--) {
            tmp.push_back(num[i]);
            if (num[i - 1] < num[i]) {
                head = num[i - 1];
                break;
            }
        }
        if (i == 0) {
            tmp.push_back(num[0]);
        }
        sort(tmp.begin(), tmp.end());
        if (head == -1) {
            sort(num.begin(), num.end());
        } else {
            bool flg = false;
            for (int i = 0; i < tmp.size(); i++) {
                if (!flg && tmp[i] > head) {
                    num[num.size() - tmp.size() - 1] = tmp[i];
                    num[num.size() - tmp.size() + i] = head;
                    flg = true;
                } else {
                    num[num.size() - tmp.size() + i] = tmp[i];
                }
            }
        }
    }
};