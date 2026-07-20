class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        int i = 0;
        vector<bool> check(26,false);
        vector<int> vis(26,-1);
        for(int i=0;i<s.size();i++) {
            vis[s[i] - 'a'] = i;
        }

        for(int i=0;i<s.size();i++) {
            if(check[s[i] - 'a']) continue;
            while((!st.empty()) && (vis[st.top() - 'a'] > i) && (st.top()-'a' >= s[i]-'a')) {
                check[st.top() - 'a'] = false;
                st.pop();
            }
            check[s[i] - 'a'] = true;
            st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};