class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0;i<graph.size();i++) {
            if(visited[i] == -1) DFS(i,graph,visited);
        }
        vector<int> ans;
        for(int i=0;i<graph.size();i++) {
            if(visited[i] == 1) ans.push_back(i);
        }
        return ans;
    }

    bool DFS(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 0;

        for(auto it : graph[node]) {
            if(visited[it] == -1) {
                if(!DFS(it,graph,visited)) return false;
            }
            else if(visited[it] == 0) {
                return false;
            }
        }

        visited[node] = 1;
        return true;
    }
};