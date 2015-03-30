class Solution {
private:
    int n;
    int currentRow;
    vector<string> board;
    vector<vector<string> > result;
public:
    vector<vector<string> > solveNQueens(int n) {
        string row(n, '.');
        for (int i = 0; i < n; i++)
            board.push_back(row);
        this->n = n;
        currentRow = 0;
        backtracking();
        return result;
    }
    
    void backtracking() {
        if (currentRow >= n) {
            vector<string> r;
            for (int i = 0; i < n; i++)
                r.push_back(board[i]);
            result.push_back(r);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(currentRow, i)) {
                board[currentRow][i] = 'Q';
                currentRow++;
                backtracking();
                currentRow--;
                board[currentRow][i] = '.';
            }
        }
    }
    
    bool isValid(int r, int c) {
        for (int i = 0; i < n; i++) {
			if (board[i][c] == 'Q') return false;
		}
		for (int j = 0; j < n; j++) {
			if (board[r][j] == 'Q') return false;
		}
		for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q') return false;
		}
		for (int i = r + 1, j = c + 1; i < n && j < n; i++, j++) {
			if (board[i][j] == 'Q') return false;
		}
		
		for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q') return false;
		}
		for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
			if (board[i][j] == 'Q') return false;
		}
		return true;
    }
};