class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        if(grid[0][0] == 1) health--;
        if(DFS(grid,health,vis,0,0)) return true;
        return false;
    }

    bool DFS(vector<vector<int>>& board, int health, vector<vector<int>>& vis,int i, int j) {
        int n = board.size();
        int m = board[0].size();
        if(vis[i][j] >= health) return false;
        vis[i][j] = health;
        if(((i == n-1) && (j == m-1)) && (health >= 1)) return true;
        if((i + 1 < n) && (board[i + 1][j] == 0)) {
            if(DFS(board, health, vis, i+1, j)) return true;
        }
        if((i - 1 >= 0) && (board[i - 1][j] == 0)) {
            if(DFS(board, health,vis, i-1,j)) return true;
        }
        if((j + 1 < m) && (board[i][j + 1] == 0)) {
            if(DFS(board, health, vis, i,j + 1)) return true;
        }
        if((j - 1 >= 0) && (board[i][j - 1] == 0)) {
            if(DFS(board, health, vis, i,j - 1)) return true;
        }
        if((i + 1 < n) && (board[i + 1][j] == 1) && (health > 1)) {
            if(DFS(board, health - 1, vis, i+1, j)) return true;
        }
        if((i - 1 >= 0) && (board[i - 1][j] == 1) && (health > 1)) {
            if(DFS(board, health - 1,vis, i-1,j)) return true;
        }
        if((j + 1 < m) && (board[i][j + 1] == 1) && (health > 1)) {
            if(DFS(board, health - 1, vis, i,j + 1)) return true;
        }
        if((j - 1 >= 0) && (board[i][j - 1] == 1) && (health > 1)) {
            if(DFS(board, health - 1, vis, i,j - 1)) return true;
        }

        return false;
    }
};