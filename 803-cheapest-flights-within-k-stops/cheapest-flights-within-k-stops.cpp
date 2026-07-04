class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        dist[src] = 0;
        q.push({0,{0,src}});

        while(!q.empty()) {
            int stops = q.front().first;
            int dis = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(stops > k) continue;

            for(auto it : adj[node]) {
                int adjnode = it.first;
                int edgewt = it.second;
                int distance = dis + edgewt;
                if(distance < dist[adjnode]) {
                    dist[adjnode] = distance;
                    q.push({stops+1,{distance,adjnode}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};