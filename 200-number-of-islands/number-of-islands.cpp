class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((visited[i][j] == 0) && (grid[i][j] == '1')) {
                    DFS(grid,visited,{i,j});
                    ans++;
                }
            }
        }
        return ans;
    }

    void DFS(vector<vector<char>>& board, vector<vector<int>>& visited, vector<int> position) {
        int n = board.size();
        int m = board[0].size();
        int i = position[0];
        int j = position[1];
        if(visited[i][j] == 1) return;
        visited[i][j] = 1;
        if((i + 1 < n) && (board[i + 1][j] == '1')) {
            DFS(board, visited, {i+1,j});
        }
        if((i - 1 >= 0) && (board[i - 1][j] == '1')) {
            DFS(board, visited, {i-1,j});
        }
        if((j + 1 < m) && (board[i][j + 1] == '1')) {
            DFS(board, visited, {i,j + 1});
        }
        if((j - 1 >= 0) && (board[i][j - 1] == '1')) {
            DFS(board, visited, {i,j - 1});
        }
    }
};