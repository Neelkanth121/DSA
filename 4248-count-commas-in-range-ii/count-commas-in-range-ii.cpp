class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long ans = 0;
        ans = n - 1e3 + 1;
        if(n >= 1e6) ans = ans + (n - 1e6) + 1;
        if(n >= 1e9) ans = ans + (n - 1e9) + 1;
        if(n >= 1e12) ans = ans + (n - 1e12) + 1;
        if(n == 1e15) ans++;
        return ans; 
    }
};