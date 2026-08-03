class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(helper(0,i,j,board,word)) return true;
            }
        }
        return false;
    }

    bool isvalid(int row,int col,int m,int n) {
        return (row>=0 && row<m && col>=0 && col<n);
    }

    bool helper(int index, int row, int col, vector<vector<char>>& board, string& word) {

        if (board[row][col] != word[index])
            return false;

        if (index == word.size() - 1)
            return true;

        char temp = board[row][col];
        board[row][col] = '#';

        vector<int> r = {1,0,-1,0};
        vector<int> c = {0,1,0,-1};

        for (int i = 0; i < 4; i++) {
            int nr = row + r[i];
            int nc = col + c[i];

            if (isvalid(nr, nc, board.size(), board[0].size()) &&
                board[nr][nc] != '#') {
                if (helper(index + 1, nr, nc, board, word))
                    return true;
            }
        }

        board[row][col] = temp;
        return false;
    }
};