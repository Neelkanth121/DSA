class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isvisited(n,false);
        int ans = 0;
        for(int i=0;i<isConnected.size();i++) {
            if(!isvisited[i]) {
                ans++;
                connected(isConnected,i,isvisited);
            }
        }
        return ans;
    }

    void connected(vector<vector<int>>& isConnected,int node,vector<bool>& isvisited) {
        if(isvisited[node]) return;
        isvisited[node] = true;
        for(int i=0;i<isConnected.size();i++) {
            if(isConnected[node][i] == 1) {
                connected(isConnected,i,isvisited);
            }
        }
    }

};