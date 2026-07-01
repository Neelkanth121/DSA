class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if((grid[0][0] == 1) || (grid[n - 1][n - 1] == 1)) return 0;
        // BFS to mark distance from 1.
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> distance(n,vector<int> (n,-1));

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    q.push({{i,j},0});
                    distance[i][j] = 0;
                }
            }
        }
        int max_level = INT_MIN;

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int level = q.front().second;
            max_level = max(max_level,level);
            q.pop();
            if((i + 1 < n) && (distance[i + 1][j] == -1)) {
                distance[i+1][j] = level + 1;
                q.push({{i+1,j},level+1});
            }
            if((i - 1 >= 0) && (distance[i - 1][j] == -1)) {
                distance[i-1][j] = level + 1;
                q.push({{i-1,j},level+1});
            }
            if(((j + 1) < n) && (distance[i][j + 1] == -1)) {
                distance[i][j+1] = level + 1;
                q.push({{i,j+1},level+1});
            }
            if((j - 1 >= 0) && (distance[i][j - 1] == -1)) {
                distance[i][j-1] = level + 1;
                q.push({{i,j-1},level+1});
            }
        }

        // Binary Search for max safe factor
        int left = 0;
        int right = max_level;
        int ans = 0;

        while(left <= right) {
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            int mid = (left + right) / 2;
            if(BFS(distance,mid)) {
                ans = max(ans,mid);
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;

    }

    bool BFS(vector<vector<int>>& dis, int v) {
        int n = dis.size();

        if(dis[0][0] < v) return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i == n-1 && j == n-1)
                return true;

            // Down
            if(i + 1 < n && !vis[i+1][j] && dis[i+1][j] >= v) {
                vis[i+1][j] = true;
                q.push({i+1, j});
            }

            // Up
            if(i - 1 >= 0 && !vis[i-1][j] && dis[i-1][j] >= v) {
                vis[i-1][j] = true;
                q.push({i-1, j});
            }

            // Right
            if(j + 1 < n && !vis[i][j+1] && dis[i][j+1] >= v) {
                vis[i][j+1] = true;
                q.push({i, j+1});
            }

            // Left
            if(j - 1 >= 0 && !vis[i][j-1] && dis[i][j-1] >= v) {
                vis[i][j-1] = true;
                q.push({i, j-1});
            }
        }

        return false;
    }
};