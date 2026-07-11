class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                int ver = 0;
                int ed = 0;
                BFS(adj,i,visited,ver,ed);
                if((ed / 2) == (ver * (ver - 1) / 2)) ans++;
            }
        }
        return ans;
    }

    void BFS(vector<vector<int>>& adj, int nd, vector<int>& visited, int& ver, int& ed) {
        queue<int> q;
        q.push(nd);
        visited[nd] = 1;
        ed = ed + adj[nd].size();
        ver++;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                    ver++;
                    ed = ed + adj[it].size();
                }
            }
        }
    }
};