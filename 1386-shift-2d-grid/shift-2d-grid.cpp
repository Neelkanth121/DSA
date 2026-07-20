class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0) return grid;
        vector<int> temp;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                temp.push_back(grid[i][j]);
            }
        }

        if(k > temp.size()) k = k % temp.size();
        int intial = temp.size() - k;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                grid[i][j] = temp[(intial) % (temp.size())];
                intial++;
            }
        }
        return grid;
    }
};