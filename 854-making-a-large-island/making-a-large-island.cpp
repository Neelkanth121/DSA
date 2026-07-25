class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int v, int u) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        // Attach smaller tree under larger tree
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    bool isvalid(int row,int col, int n) {
        return (row>=0 && row<n && col>=0 && col<n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // Making Connected Components
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                if(grid[row][col] == 0) continue;
                vector<int> dr = {-1,0,1,0};
                vector<int> dc = {0,-1,0,1};
                for(int i=0;i<4;i++) {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if((isvalid(newr,newc,n) && (grid[newr][newc] == 1))) {
                        ds.UnionBySize((row * n + col),(newr * n + newc));
                    }
                }
            }
        }
        // Traversing 
        int maxi = 0;
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                if(grid[row][col] == 1) continue;
                unordered_set<int> st;
                vector<int> dr = {-1,0,1,0};
                vector<int> dc = {0,-1,0,1};
                for(int i=0;i<4;i++) {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if((isvalid(newr,newc,n) && (grid[newr][newc] == 1))) {
                        st.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int totalsize = 0;
                for(auto it : st) {
                    totalsize = totalsize + ds.size[it];
                }
                maxi = max(maxi,totalsize + 1);
            }
        }
        // If the grid consist of only ones.
        for(int i=0;i<n*n;i++) {
            maxi = max(maxi,ds.size[ds.findUPar(i)]);
        }

        return maxi;
    }
};