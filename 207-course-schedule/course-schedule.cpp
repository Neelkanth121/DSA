class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<pre.size();i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> visited(numCourses);
        for(int i=0;i<numCourses;i++) {
            if(visited[i] == 0) {
                if(helper(i,adj,visited)) return false;
            }
        }
        return true;
        
    }
    bool helper(int src, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = 1;
        for(auto it : adj[src]) {
            if(visited[it] == 1) return true;
            else if(visited[it] == 0){
                if(helper(it,adj,visited)) return true;
            }
        }

        visited[src] = 2;
        return false;
    }
};