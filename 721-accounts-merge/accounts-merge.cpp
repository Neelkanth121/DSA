class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
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
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mpmailnode;
        // Step 1 : making DSU
        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(mpmailnode.find(accounts[i][j]) == mpmailnode.end()) {
                    mpmailnode[accounts[i][j]] = i;
                }
                else{
                    ds.UnionByRank(i,mpmailnode[accounts[i][j]]);
                }
            }
        }
        // Step 2 : merging mails
        vector<vector<string>> merged(n); 
        for(auto it : mpmailnode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            merged[node].push_back(mail);
        }

        // step 3 : Sorting & merging 
        vector<vector<string>> ans;
        for(int i=0;i<n;i++) {
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merged[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;

    }
};