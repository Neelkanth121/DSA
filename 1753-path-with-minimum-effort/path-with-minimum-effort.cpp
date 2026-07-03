class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            vector<vector<int>> dir = {{i-1,j},{i,j-1},{i,j+1},{i+1,j}};
            for(int x=0;x<dir.size();x++) {
                if(((dir[x][0] >= 0) && (dir[x][0] < n)) && ((dir[x][1] >= 0) && (dir[x][1] < m))) {
                    int effort = max(abs(grid[i][j] - grid[dir[x][0]][dir[x][1]]),dis);
                    if((effort) < dist[dir[x][0]][dir[x][1]]) {
                        dist[dir[x][0]][dir[x][1]] = effort;
                        pq.push({effort,{dir[x][0],dir[x][1]}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};