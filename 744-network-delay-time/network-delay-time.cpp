class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++) {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k-1] = 0;
        pq.push({0,k-1});

        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]) {
                int adjnode = it.first;
                int edgewt = it.second;
                int distance = dis + edgewt;
                if(distance < dist[adjnode]) {
                    dist[adjnode] = distance;
                    pq.push({distance,adjnode});
                }
            }
        }
        int ans = -1;
        for(auto it : dist) {
            if(it == INT_MAX) return -1;
            ans = max(ans,it);
        }
        return ans;
    }
};