class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        string t = "1" + s + "1";

        vector<char> block;
        vector<int> len;

        char cur = t[0];
        int cnt = 1;

        for (int i = 1; i < t.size(); i++) {
            if (t[i] == cur) {
                cnt++;
            } else {
                block.push_back(cur);
                len.push_back(cnt);
                cur = t[i];
                cnt = 1;
            }
        }

        block.push_back(cur);
        len.push_back(cnt);

        int ans = totalOnes;

        for (int i = 1; i + 1 < block.size(); i++) {
            if (block[i - 1] == '0' &&
                block[i] == '1' &&
                block[i + 1] == '0') {

                ans = max(ans, totalOnes + len[i - 1] + len[i + 1]);
            }
        }

        return ans;
    }
};