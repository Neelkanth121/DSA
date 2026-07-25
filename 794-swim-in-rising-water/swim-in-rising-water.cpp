class Solution {
public:
    bool isvalid(int row,int col,int n) {
        return (row>=0 && row<n && col>=0 && col<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;  
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = grid[0][0];
        while(!pq.empty()) {
            int wt = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            vector<int> dr = {-1,0,1,0};
            vector<int> dc = {0,-1,0,1};
            for(int i=0;i<4;i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(isvalid(row + dr[i],col + dc[i],n)) {
                    int maxi = max(wt,grid[newr][newc]);
                    if(vis[newr][newc] > maxi) {
                        vis[newr][newc] = maxi;
                        pq.push({maxi,{newr,newc}});
                    }
                }
            }
        }
        return vis[n-1][n-1];      
    }

};