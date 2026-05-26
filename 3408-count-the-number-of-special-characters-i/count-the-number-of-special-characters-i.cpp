class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> hash;
        for(int i=0;i<word.size();i++) {
            hash[word[i]]++;
        }
        int ans = 0;
        for(int i='A';i<='Z';i++) {
            if((hash[i] > 0) && (hash[i + 32] > 0)) ans++;
        }
        return ans;
    }
};