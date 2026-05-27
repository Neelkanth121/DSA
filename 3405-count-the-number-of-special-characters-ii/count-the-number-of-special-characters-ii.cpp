class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> hash;
        int ans = 0;
        for(int i=0;i<word.size();i++) {
            if(islower(word[i])) hash[word[i]]++;
        }
        unordered_map<char,int> hash1;
        for(int i=0;i<word.size();i++) {
            if(isupper(word[i])) {
                if((hash1[word[i] + 32] > 0) && (hash[word[i] + 32] == 0) && (hash[word[i]] != -1)) ans++;
                hash[word[i]] = -1;
                continue;
            }
            hash1[word[i]]++;
            hash[word[i]]--;
        }
        return ans;
    }
};