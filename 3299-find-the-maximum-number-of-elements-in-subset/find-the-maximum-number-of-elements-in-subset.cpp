class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (freq[cur] < 2) break;

                len += 2;

                // cur^2 cannot exist in the array
                if (cur > 31622) break;

                long long nxt = cur * cur;

                if (!freq.count(nxt)) break;

                cur = nxt;
            }

            if (freq[cur] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};