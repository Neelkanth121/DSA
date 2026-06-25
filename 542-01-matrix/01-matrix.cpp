class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i,j},1});
                }
            }
        }

        while(!q.empty()) {
            int h = q.front().first.first;
            int v = q.front().first.second;
            int level = q.front().second;
            q.pop();
                if((h + 1 < n) && (mat[h + 1][v] == 1)) {
                    if(!visited[h + 1][v]) {
                        mat[h + 1][v] = level;
                        q.push({{h + 1,v},level+1});
                        visited[h + 1][v] = 1;
                    }
                }
                if((h - 1 >= 0) && (mat[h - 1][v] == 1)) {
                    if(!visited[h - 1][v]) {
                        mat[h - 1][v] = level;
                        q.push({{h - 1,v},level+1});
                        visited[h-1][v] = 1;
                    }
                }
                if(((v + 1) < m) && (mat[h][v + 1] == 1)) {
                    if(!visited[h][v + 1]) {
                        mat[h][v + 1] = level;
                        q.push({{h,v + 1},level+1});
                        visited[h][v+1] = 1;
                    }
                }
                if((v - 1 >= 0) && (mat[h][v - 1] == 1)) {
                    if(!visited[h][v - 1]) {
                        mat[h][v - 1] = level;
                        q.push({{h,v - 1},level+1});
                        visited[h][v-1] = 1;
                    }
                }
        }
        return mat;
    }
};