class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char,int> hash;
        while(r<s.size()){
            hash[s[r]]++;
            while((hash['a']>=1) && (hash['b']>=1) && (hash['c']>=1)){
                ans = ans + (s.size()-r);
                hash[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};