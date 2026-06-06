class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            unordered_map<char,int> hash;
            for(int j=i;j<s.size();j++) {
                hash[s[j]]++;
                int maxi = 0;
                int mini = INT_MAX;
                for(auto& it : hash) {
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                }
                ans = ans + (maxi - mini);
            }
        }
        return ans;
    }
};