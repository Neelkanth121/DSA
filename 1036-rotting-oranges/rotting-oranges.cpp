class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto it = q.front();
                q.pop();
                int h = it.first;
                int v = it.second;
                if((h + 1 < n) && (grid[h + 1][v] == 1)) {
                    grid[h + 1][v] = 2;
                    q.push({h+1,v});
                }
                if((h - 1 >= 0) && (grid[h - 1][v] == 1)) {
                    grid[h - 1][v] = 2;
                    q.push({h-1,v});
                }
                if(((v + 1) < m) && (grid[h][v + 1] == 1)) {
                    grid[h][v + 1] = 2;
                    q.push({h,v+1});
                }
                if((v - 1 >= 0) && (grid[h][v - 1] == 1)) {
                    grid[h][v - 1] = 2;
                    q.push({h,v-1});
                }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return max(ans,0);
    }
};