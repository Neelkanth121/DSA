class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function for quick binary exponentiation
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // Number of nodes is edges.size() + 1
        vector<vector<int>> adj(n + 1);
        
        // Build an undirected graph
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // BFS to find the maximum depth from the root (node 1)
        queue<pair<int, int>> q; // stores {node, current_depth}
        vector<bool> visited(n + 1, false);
        
        q.push({1, 0});
        visited[1] = true;
        int maxDepth = 0;
        
        while (!q.empty()) {
            auto [curr, depth] = q.front();
            q.pop();
            
            maxDepth = max(maxDepth, depth);
            
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        
        
        if (maxDepth == 0) return 0; // Edge case: only 1 node
        return power(2, maxDepth - 1);
    }
};