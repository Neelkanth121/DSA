class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++) {
            adj[roads[i][0] - 1].push_back({roads[i][1] - 1,roads[i][2]});
            adj[roads[i][1] - 1].push_back({roads[i][0] - 1,roads[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({INT_MAX,0});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]) {
                int adjnode = it.first;
                int edgewt = it.second;
                int distance = min(dis,edgewt);
                if(distance < dist[adjnode]) {
                    dist[adjnode] = distance;
                    pq.push({distance,adjnode});
                }
            }
        }
        return dist[n-1];
    }
};