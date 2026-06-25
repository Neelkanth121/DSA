class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<pre.size();i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> visited(numCourses);
        vector<int> ans;
        for(int i=0;i<numCourses;i++) {
            if(visited[i] == 0) {
                if(helper(i,adj,visited,ans)) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool helper(int src, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans) {
        visited[src] = 1;
        for(auto it: adj[src]) {
            if(visited[it] == 1) {
                ans = {};
                return true;
            }
            else if(visited[it] == 0) {
                if(helper(it,adj,visited,ans)) return true;
            }
        }
        ans.push_back(src);
        visited[src] = 2;
        return false;
    }
};