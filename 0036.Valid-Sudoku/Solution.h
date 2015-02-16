class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            if (!checkRow(board, i)) {
                return false;
            }
            if (!checkColumn(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!checkGrid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkRow(vector<vector<char> > &board, int row) {
        bool m[9] = {
            false, false, false,
            false, false, false,
            false, false, false
        };
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == '.') {
                continue;
            }
            if (m[board[row][j] - '1']) {
                return false;
            }
            m[board[row][j] - '1'] = true;
        }
        return true;
    }
    
    bool checkColumn(vector<vector<char> > &board, int column) {
        bool m[9] = {
            false, false, false,
            false, false, false,
            false, false, false
        };
        for (int i = 0; i < 9; i++) {
            if (board[i][column] == '.') {
                continue;
            }
            if (m[board[i][column] - '1']) {
                return false;
            }
            m[board[i][column] - '1'] = true;
        }
        return true;
    }
    
    bool checkGrid(vector<vector<char> > &board, int x, int y) {
        bool m[9] = {
            false, false, false,
            false, false, false,
            false, false, false
        };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x * 3 + i][y * 3 + j] == '.') {
                    continue;
                }
                if (m[board[x * 3 + i][y * 3 + j] - '1']) {
                    return false;
                }
                m[board[x * 3 + i][y * 3 + j] - '1'] = true;
            }
        }
        return true;
    }
};