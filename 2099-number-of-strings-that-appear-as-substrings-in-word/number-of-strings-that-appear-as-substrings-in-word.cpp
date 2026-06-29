class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> hash;
        for(int i=0;i<word.size();i++) {
            string temp = "";
            for(int j=i;j<word.size();j++) {
                temp = temp + word[j];
                hash[temp]++;
            }
        }

        int ans = 0;
        for(int i=0;i<patterns.size();i++) {
            if(hash[patterns[i]] > 0) ans++;
        }
        
        return ans;
    }
};