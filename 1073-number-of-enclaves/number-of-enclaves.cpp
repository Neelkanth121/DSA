class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // On boundaries
        vector<vector<int>> visited(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            if(grid[i][0] == 1) DFS(grid,visited,{i,0});
            if(grid[i][m - 1] == 1) DFS(grid,visited,{i,m-1});
        }
        for(int i=0;i<m;i++) {
            if(grid[0][i] == 1) DFS(grid,visited,{0,i});
            if(grid[n - 1][i] == 1) DFS(grid,visited,{n-1,i});
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((!visited[i][j]) && (grid[i][j] == 1)) ans++;
            }
        }
        return ans;
    }
    void DFS(vector<vector<int>>& board, vector<vector<int>>& visited, vector<int> p) {
        int n = board.size();
        int m = board[0].size();
        int i = p[0];
        int j = p[1];
        if(visited[i][j]) return;
        visited[i][j] = 1;
        if((i + 1 < n) && (board[i + 1][j] == 1)) {
            DFS(board, visited, {i+1,j});
        }
        if((i - 1 >= 0) && (board[i - 1][j] == 1)) {
            DFS(board, visited, {i-1,j});
        }
        if((j + 1 < m) && (board[i][j + 1] == 1)) {
            DFS(board, visited, {i,j + 1});
        }
        if((j - 1 >= 0) && (board[i][j - 1] == 1)) {
            DFS(board, visited, {i,j - 1});
        }     
    }
};