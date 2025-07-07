class Solution {
private:
    void solve(int col, vector<int> &lr, vector<int> &ld, vector<int> &ud, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(lr[row]==0 && ld[col+row]==0 && ud[n-1 + col-row]==0)
            {
                board[row][col]='Q';
                lr[row]=1;
                ld[col+row]=1;
                ud[n-1 + col-row]=1;
                solve(col+1,lr, ld, ud, ans, board, n);
                board[row][col]='.';
                lr[row]=0;
                ld[col+row]=0;
                ud[n-1 + col-row]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n,0), lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1, 0);
        solve(0, leftRow, lowerDiagonal, upperDiagonal, ans, board, n);
        return ans;
    }
};