class Solution {

private:
    int n;
    int currentRow;
    int total;
    int* columns;
    int* slashes;
    int* backslashes;

public:
    int totalNQueens(int n) {
        this->n = n;
        currentRow = 0;
        total = 0;
        columns = new int[n];
        slashes = new int[2 * n - 1];
        backslashes = new int[2 * n - 1];
        for (int i = 0; i < n; i++)
            columns[i] = 0;
        for (int i = 0; i < 2 * n - 1; i++)
            slashes[i] = backslashes[i] = 0;
        backtracking();
        delete columns;
        delete slashes;
        delete backslashes;
        return total;
    }

    void backtracking() {
        if (currentRow >= n) {
            total++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(currentRow, i)) {
                columns[i] = 1;
                slashes[currentRow + i] = 1;
                backslashes[currentRow - i + n - 1] = 1;
                currentRow++;
                backtracking();
                currentRow--;
                columns[i] = 0;
                slashes[currentRow + i] = 0;
                backslashes[currentRow - i + n - 1] = 0;
            }
        }
    }
    
    bool isValid(int r, int c) {
        if (columns[c]) return false;
        if (slashes[r + c]) return false;
        if (backslashes[r - c + n - 1]) return false;
		return true;
    }

};