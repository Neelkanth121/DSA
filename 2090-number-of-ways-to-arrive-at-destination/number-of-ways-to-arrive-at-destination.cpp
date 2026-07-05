class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        // Use LLONG_MAX 
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        ways[0] = 1;
        dist[0] = 0;
        
        // Min-heap storing {distance, node}. Distance must be long long.
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dis > dist[node]) continue;
            
            for(auto it : adj[node]) {
                int adjnode = it.first;
                long long edgewt = it.second;
                
                // Found a shorter path to adjnode
                if(edgewt + dis < dist[adjnode]) {
                    dist[adjnode] = edgewt + dis;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node]; 
                }
                // Found another path of the same shortest length
                else if(edgewt + dis == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};