class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1,0});
        sort(res.begin(),res.end());
        if(res.back()[0] != n) res.push_back({n,INT_MAX});

        int m = res.size();

        for(int i = 1; i < m; i++) {
            int dist = res[i][0] - res[i - 1][0];
            res[i][1] = min(res[i][1], res[i - 1][1] + dist);
        }
        
        for(int i = m - 2; i>=0; i--) {
            int dist = res[i + 1][0] - res[i][0];
            res[i][1] = min(res[i][1], res[i + 1][1] + dist);
        }

        int ans = 0;
        for(int i=1;i<m;i++) {
            int dist = res[i][0] - res[i - 1][0];
            int peak = (res[i][1] + res[i - 1][1] + dist) / 2;
            ans = max(ans,peak);
        }
        
        return ans;
    }
};