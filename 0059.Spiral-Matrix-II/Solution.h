class Solution {
private:
    int num = 1;
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        for (int i = 0; i < n; i++) {
            vector<int> line;
            for (int j = 0; j < n; j++) {
                line.push_back(0);
            }
            result.push_back(line);
        }
        
        for (int i = 0; i < (n + 1) / 2; i++) {
            makeResult(i, result, n);
        }
        return result;
    }
        void makeResult(int start, vector<vector<int> > &matrix, int n) {
            for (int j = start; j < n - start; j++)
                matrix[start][j] = num++;
            for (int i = start + 1; i < n - start; i++)
                matrix[i][n - start - 1] = num++;
            for (int j = n - start - 2; j >= start && (n - start - 1) > start; j--)
                matrix[n - start - 1][j] = num++;
            for (int i = n - start - 2; i > start && (n - start - 1) > start; i--)
                matrix[i][start] = num++;
        }
};