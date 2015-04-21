class Solution {
private:
    int m, n;
    vector<int> result;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        m = matrix.size();
        if (m < 1) return result;
        n = matrix[0].size();
        int mid = (min(m, n) + 1) / 2;
        for (int i = 0; i < mid; i++) {
            makeResult(i, matrix);
        }
        return result;
    }
    
    void makeResult(int start, vector<vector<int> > &matrix) {
        for (int j = start; j < n - start; j++)
            result.push_back(matrix[start][j]);
        for (int i = start + 1; i < m - start; i++)
            result.push_back(matrix[i][n - start - 1]);
        for (int j = n - start - 2; j >= start && (m - start - 1) > start; j--)
            result.push_back(matrix[m - start - 1][j]);
        for (int i = m - start - 2; i > start && (n - start - 1) > start; i--)
            result.push_back(matrix[i][start]);
    }
};