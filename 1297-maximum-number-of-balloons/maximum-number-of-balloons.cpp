class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp = {{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
        string s = "balloon";
        unordered_map<char,int> hash;
        for(int i=0;i<text.size();i++) {
            hash[text[i]]++;
        }
        int ans = INT_MAX;
        for(int i=0;i<s.size();i++) {
            ans = min(ans,(hash[s[i]] / mp[s[i]]));
        }
        return ans;
    }
};