class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for (int k = 0; k < n; k++) {
            int cost = 0;

            for (int i = 0; i < n / 2; i++) {
                int left = (i + k) % n;
                int right = (n - 1 - i + k) % n;

                int diff = abs(s[left] - s[right]);

                cost += min(diff, 26 - diff);
            }

            ans = min(ans, k + cost);
        }

        return ans;
    }
};