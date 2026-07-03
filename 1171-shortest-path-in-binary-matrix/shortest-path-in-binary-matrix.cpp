class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            vector<vector<int>> dir = {{i-1,j},{i-1,j-1},{i,j-1},{i+1,j-1},{i-1,j+1},{i,j+1},{i+1,j+1},{i+1,j}};
            for(int j=0;j<dir.size();j++) {
                if(((dir[j][0] >= 0) && (dir[j][0] < n)) && ((dir[j][1] >= 0) && (dir[j][1] < n))) {
                    if(grid[dir[j][0]][dir[j][1]] == 0) {
                        if((1 + dis) < dist[dir[j][0]][dir[j][1]]) {
                            dist[dir[j][0]][dir[j][1]] = 1 + dis;
                            pq.push({1+dis,{dir[j][0],dir[j][1]}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1] + 1;
    }
};