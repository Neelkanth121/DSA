class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        vector<int> ans;
        unordered_map<int,int> hash;
        for(int i=0;i<A.size();i++) {
            hash[A[i]]++;
            hash[B[i]]--;
            if(A[i] != B[i]) {
                if(hash[A[i]] == 0) count++;
                if(hash[B[i]] == 0) count++;
            }
            if(A[i] == B[i]) count++;
            ans.push_back(count);
        }
        return ans; 
    }
};