class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        int j = 0;
        for(int i=0;i<nums.size();i++) {
            while ((j < n) && ((nums[j] - nums[i]) <= maxDiff)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                j++;
            }
        }

        vector<int> visited(n,0);
        vector<int> connect(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                BFS(adj,i,visited,connect,cnt);
                cnt++;
            }
        }

        vector<bool> ans;
        for(int i=0;i<queries.size();i++) {
            if(connect[queries[i][0]] == connect[queries[i][1]]) {
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }

    void BFS(vector<vector<int>>& adj, int nd, vector<int>& visited, vector<int>& connect,int cnt) {
        queue<int> q;
        q.push(nd);
        visited[nd] = 1;
        connect[nd] = cnt;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                    connect[it] = cnt;
                }
            }
        }
    }
};