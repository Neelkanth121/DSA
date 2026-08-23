class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++) {
            for(int j=i;j<s.size();j++) {
                if(dp[i][j] == -1) dp[i][j] = ispalindrome(i,j,s);
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }

    bool ispalindrome(int left, int right, string& s) {
        if(left > right) return true;

        if(s[left] != s[right]) return false;

        return ispalindrome(left+1,right-1,s);
    }
};