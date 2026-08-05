class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // 1. BFS to mark all suspicious methods reachable from k
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        
        // 2. Check if any non-suspicious method calls a suspicious method
        bool cannotRemove = false;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!vis[u] && vis[v]) {
                cannotRemove = true;
                break;
            }
        }
        
        // 3. Construct result
        vector<int> ans;
        if (cannotRemove) {
            // Return all methods
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
        } else {
            // Return only non-suspicious methods
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) {
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};