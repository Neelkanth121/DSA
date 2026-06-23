class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int ref = grid[sr][sc];
        if(ref == color) return grid;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        grid[sr][sc] = color;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto it = q.front();
                q.pop();
                int h = it.first;
                int v = it.second;
                if((h + 1 < n) && (grid[h + 1][v] == ref)) {
                    q.push({h+1,v});
                    grid[h + 1][v] = color;
                }
                if((h - 1 >= 0) && (grid[h - 1][v] == ref)) {
                    q.push({h-1,v});
                    grid[h - 1][v] = color;
                }
                if(((v + 1) < m) && (grid[h][v + 1] == ref)) {
                    q.push({h,v+1});
                    grid[h][v + 1] = color;
                }
                if((v - 1 >= 0) && (grid[h][v - 1] == ref)) {
                    q.push({h,v-1});
                    grid[h][v - 1] = color;
                }
            }
        }
        return grid;
    }
};