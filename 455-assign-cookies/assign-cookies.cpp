class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gptr = 0;
        int sptr = 0;
        int ans = 0;
        while((sptr < s.size()) && (gptr < g.size())) {
            if(s[sptr] < g[gptr]) {
                sptr++;
                continue;
            }
            gptr++;
            sptr++;
            ans++; 
        }
        return ans;
    }
};