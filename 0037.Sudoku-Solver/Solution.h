class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        Pos p = findNextEmpty(board);
        if (p.x == -1) {
            compFlg = true;
            return;
        }
        for (char c = '1'; c <= '9'; c++) {
            if (canFill(board, p.x, p.y, c)) {
                board[p.x][p.y] = c;
                solveSudoku(board);
                if (compFlg)
                    break;
            }
        }
        if (compFlg)
            return;
        board[p.x][p.y] = '.';
    }

private:
    bool compFlg = false;
    
    class Pos {
    public:
        int x = -1;
        int y = -1;
    };
    
    Pos findNextEmpty(vector<vector<char> > &board) {
        Pos p;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    p.x = i;
                    p.y = j;
                    return p;
                }
            }
        }
        return p;
    }
    
    bool canFill(vector<vector<char> > &board, int x, int y, char c) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][y] == c)
                return false;
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[x][j] == c)
                return false;
        }
        for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
            for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {
                if (board[i][j] == c)
                    return false;
            }
        }
    }
};