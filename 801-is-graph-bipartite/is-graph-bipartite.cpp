class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0;i<graph.size();i++) {
            if(visited[i] == -1) if(!DFS(graph,visited,i % 2,i)) return false;
        }
        return true;
    }

    bool DFS(vector<vector<int>>& graph, vector<int>& visited, int color, int index) {
        if(visited[index] != -1) {
            return (visited[index] == color);
        }
        visited[index] = color;
        int nextcol = 1 - color;

        for(int i=0;i<graph[index].size();i++) {
            int neighbor = graph[index][i];
            if(!DFS(graph,visited,nextcol,neighbor)) return false;
        }

        return true;
    }
};