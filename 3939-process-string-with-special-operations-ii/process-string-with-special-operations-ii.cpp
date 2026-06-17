class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1,0);

        // Forward Pass
        for(int i=0;i<n;i++) {
            if(s[i] == '*') {
                len[i + 1] = max(0LL,len[i] - 1);
            }
            else if(s[i] == '#') len[i + 1] = 2 * len[i];
            else if(s[i] == '%') len[i + 1] = len[i];
            else{
                len[i + 1] = len[i] + 1;
            }
        }

        if(k >= len[n]) return '.';

        // Backward Pass
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '*') continue;
            else if(s[i] == '#') k = k % len[i];
            else if(s[i] == '%') k = len[i] - 1 - k;
            else{
                if(k == len[i]) return s[i];
            }
        }
        return '.';
    }
};