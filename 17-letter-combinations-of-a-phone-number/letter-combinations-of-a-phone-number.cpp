class Solution {
public:
    void PrintLetterComb(int index, vector<string>& comb, string s, vector<string>& ans, string digits) {
        if(index == digits.size()) {
            ans.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        for(int i=0;i<comb[digit].size();i++) {
            PrintLetterComb(index+1, comb, s+comb[digit][i], ans, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> comb = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        PrintLetterComb(0, comb, s, ans, digits);
        return ans;        
    }
};