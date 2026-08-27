class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Try to put same character as target[i]
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {
                // We cannot match target anymore.
                // Find smallest character greater than target[i].
                for (int j = x + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        ans += char(j + 'a');
                        freq[j]--;

                        // Append remaining characters smallest first
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char(k + 'a');
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }

                // No greater character here.
                // Need to backtrack.
                break;
            }
        }

        // If we matched target completely, the answer is equal,
        // so we need to backtrack to make it strictly greater.
        for (int i = ans.size() - 1; i >= 0; i--) {

            int current = ans[i] - 'a';
            freq[current]++;

            int targetChar = target[i] - 'a';

            for (int j = targetChar + 1; j < 26; j++) {

                if (freq[j] > 0) {
                    ans.resize(i);
                    ans += char(j + 'a');
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char(k + 'a');
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};